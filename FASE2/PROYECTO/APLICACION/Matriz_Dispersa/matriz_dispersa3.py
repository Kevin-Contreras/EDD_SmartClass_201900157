from nodoMatriz import *
from nodoCabezera import *

class matriz:
    def __init__(self):
        self.nombre = None
        self.eFilas = listaEcabezado()
        self.eColumnas = listaEcabezado()
    
    def insertar(self, fila, col, valor):
        nuevo = Node1(fila, col, valor)

        #Insercion encabezado por filas
        eFila = self.eFilas.getEncabezado(fila)
        if eFila == None:
            eFila = nodoEncabezado(fila)
            eFila.accesoNodo = nuevo
            self.eFilas.setEncabezado(eFila)
        else:
            if nuevo.col < eFila.accesoNodo.col:
                nuevo.derecha = eFila.accesoNodo
                eFila.accesoNodo.izquierda = nuevo
                eFila.accesoNodo = nuevo
            else:
                actual = eFila.accesoNodo
                while actual.derecha != None:
                    if nuevo.col < actual.derecha.col:
                        nuevo.derecha = actual.derecha
                        actual.derecha.izquierda = nuevo
                        nuevo.izquierda = actual
                        actual.derecha = nuevo
                        break
                    actual = actual.derecha
                if actual.derecha == None:
                    actual.derecha = nuevo
                    nuevo.izquierda = actual
        #Insercion encabezado por columnas
        eColumna = self.eColumnas.getEncabezado(col)
        if eColumna == None:
            eColumna = nodoEncabezado(col)
            eColumna.accesoNodo = nuevo
            self.eColumnas.setEncabezado(eColumna)
        else:
            if nuevo.fila < eColumna.accesoNodo.fila:
                nuevo.abajo = eColumna.accesoNodo
                eColumna.accesoNodo.arriba = nuevo
                eColumna.accesoNodo = nuevo
            else:
                actual = eColumna.accesoNodo
                while actual.abajo != None:
                    if nuevo.fila < actual.abajo.fila:
                        nuevo.abajo = actual.abajo
                        actual.abajo.arriba = nuevo
                        nuevo.arriba = actual
                        actual.abajo = nuevo
                        break
                    actual = actual.abajo
                if actual.abajo == None:
                    actual.abajo = nuevo
                    nuevo.arriba = actual

    def recorreFilas(self):
        contador_filas = 1
        f_actual = self.eFilas.getEncabezado(contador_filas)
        while f_actual == None:
            contador_filas += 1
            f_actual = self.eFilas.getEncabezado(contador_filas)
            
        while f_actual != None:
            print()
            datos = f_actual.accesoNodo
            formatImg = ""
            while datos != None:
                formatImg += datos.valor
                formatImg += "\t"
                datos = datos.derecha
            print(formatImg)
            f_actual = f_actual.siguiente


x = matriz()
x.insertar(1,1,"1")
x.insertar(1,2,"2")
x.insertar(1,3,"3")
x.insertar(1,4,"4")
x.insertar(1,5,"5")
x.insertar(1,1,"6")
x.insertar(2,1,"7")
x.insertar(2,2,"8")
x.insertar(2,3,"9")
x.insertar(2,4,"10")
x.insertar(2,5,"11")
x.insertar(3,1,"12")
x.insertar(3,2,"13")
x.insertar(3,4,"15")
x.insertar(3,5,"16")
x.insertar(4,1,"17")
x.insertar(4,2,"18")
x.insertar(4,3,"19")
x.insertar(4,4,"20")
x.insertar(4,5,"21")
x.insertar(5,1,"22")
x.insertar(5,2,"23")
x.insertar(5,3,"24")
x.insertar(5,4,"25")
x.insertar(5,5,"26")

print("agrega datos")
x.recorreFilas()