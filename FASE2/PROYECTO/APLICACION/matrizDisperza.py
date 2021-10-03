from nodoMatriz import *
from nodoCabezera import *
import os
import ListaTareas;
class matriz:
    def __init__(self):
        self.nuevo = None
        self.Ncolumnas = listaEcabezado()
        self.listaTarea=None
        self.contadorTodo=0;
        self.Nfilas = listaEcabezado()
    def insertar(self, fila, col, valor):
        #aqui se ingresaran los nodos
        if(fila  != None or col !=None or valor!=None):
            contador2=0;
            listaTareas = ListaTareas.ListaDoble()
            for nodoInsertado in valor.split(",$"):
                if(nodoInsertado!=""):

                    listaTareas.insertar(nodoInsertado)
                    contador2=contador2+1
            self.contadorTodo=contador2
            self.nuevo = Nodo(fila, col, valor,listaTareas,self.contadorTodo)
           
            eFila = self.Nfilas.sEncabezado(fila)
            if eFila == None:
                eFila = nodoEncabezado(fila)
                eFila.acesso = self.nuevo
                self.Nfilas.obtenerEncabezado(eFila)
            else:
                if self.nuevo.col < eFila.acesso.col:
                    self.nuevo.derecha = eFila.acesso
                    eFila.acesso.izquierda = self.nuevo
                    eFila.acesso = self.nuevo
                elif self.nuevo.col > eFila.acesso.col:
                    actual = eFila.acesso
                    while actual.derecha != None:
                        if self.nuevo.col < actual.derecha.col:
                            self.nuevo.derecha = actual.derecha
                            actual.derecha.izquierda = self.nuevo
                            self.nuevo.izquierda = actual
                            actual.derecha = self.nuevo
                            break
                        actual = actual.derecha
                    if actual.derecha == None:
                        actual.derecha = self.nuevo
                        self.nuevo.izquierda = actual
            eColumna = self.Ncolumnas.sEncabezado(col)
            if eColumna == None:
                eColumna = nodoEncabezado(col)
                eColumna.acesso = self.nuevo
                self.Ncolumnas.obtenerEncabezado(eColumna)
            else:
                if self.nuevo.fila < eColumna.acesso.fila:
                    self.nuevo.abajo = eColumna.acesso
                    eColumna.acesso.arriba = self.nuevo
                    eColumna.acesso = self.nuevo
                elif self.nuevo.fila > eColumna.acesso.fila:
                    actual = eColumna.acesso
                    while actual.abajo != None:
                        if self.nuevo.fila < actual.abajo.fila:
                            self.nuevo.abajo = actual.abajo
                            actual.abajo.arriba = self.nuevo
                            self.nuevo.arriba = actual
                            actual.abajo = self.nuevo
                            break
                        actual = actual.abajo
                    if actual.abajo == None:
                        actual.abajo = self.nuevo
                        self.nuevo.arriba = actual
    def buscarMatriz(self,hora,dia):
        contador_filas = 1
        f_actual = self.Nfilas.sEncabezado(contador_filas)
        while f_actual == None:
            contador_filas += 1
            f_actual = self.Nfilas.sEncabezado(contador_filas)
            
        while f_actual != None:
            datos = f_actual.acesso
            formatImg = ""
            while datos != None:
                if(datos.fila==hora and datos.col == dia ):
                   
                    
                    self.listaTarea=datos.lista
                   
                
                datos = datos.derecha

           
            f_actual = f_actual.siguiente
    def buscarEliminar(self,hora,dia):
        contador_filas = 1
        f_actual = self.Nfilas.sEncabezado(contador_filas)
        while f_actual == None:
            contador_filas += 1
            f_actual = self.Nfilas.sEncabezado(contador_filas)
            
        while f_actual != None:
            datos = f_actual.acesso
            formatImg = ""
            while datos != None:
                if(datos.fila==hora and datos.col == dia ):
                   
                    datos.cantidad=datos.cantidad-1
                   
                   
                
                datos = datos.derecha

           
            f_actual = f_actual.siguiente
    def suma(self,hora,dia):
        contador_filas = 1
        f_actual = self.Nfilas.sEncabezado(contador_filas)
        while f_actual == None:
            contador_filas += 1
            f_actual = self.Nfilas.sEncabezado(contador_filas)
            
        while f_actual != None:
            datos = f_actual.acesso
            formatImg = ""
            while datos != None:
                if(datos.fila==hora and datos.col == dia ):
                   
                    datos.cantidad=datos.cantidad+1
                   
                   
                
                datos = datos.derecha

           
            f_actual = f_actual.siguiente
    def buscarAgregar(self,hora,dia,dato):
        contador_filas = 1
        contadorBusca=0;
        trues=False
        f_actual = self.Nfilas.sEncabezado(contador_filas)
        while f_actual == None:
            contador_filas += 1
            f_actual = self.Nfilas.sEncabezado(contador_filas)
            
        while f_actual != None:
            datos = f_actual.acesso
            formatImg = ""
            while datos != None:
                if(datos.fila==hora and datos.col==dia ):
                    datos.lista.insertar(dato)
                    trues=True
                
                datos = datos.derecha
            f_actual = f_actual.siguiente
        if(trues==False):
            self.insertar(hora,dia,dato)
            self.nuevo.cantidad

    def recorreFilas(self):
        contador_filas = 1
       
        f_actual = self.Nfilas.sEncabezado(contador_filas)
        while f_actual == None:
            contador_filas += 1
            f_actual = self.Nfilas.sEncabezado(contador_filas)
            
        while f_actual != None:
            datos = f_actual.acesso
            formatImg = ""
            
            while datos != None:
                print(str(datos.cantidad)+"  holaaaaaaaaaaaaa2")
                if(self.contadorTodo!=None):

                    formatImg +="cantidad de tareas en una hora: "+ str(self.contadorTodo)
                    formatImg += "\t"
                else:
                    formatImg +="cantidad de tareas en una hora: "+ str(datos.cantidad)
                    formatImg += "\t"

                datos = datos.derecha

            
            f_actual = f_actual.siguiente


    def graficar(self,comodin):
        contador_filas = 1
        contador_columna = 1
        concatenar =""
        concatenar2 =""
        concatenar3 =""
        tont=""
        tont2=""
        tont3=""
        tont4=""
        tontTotal=""
        tontTotal2=""
        same1=""
        same2=""
        same3=""
        datodd=""
        datodd2=""
        datodd3=""

        otra=""
        concatenarTotal =""
        
        cona=0
        cona2=0
        
        f_actual = self.Nfilas.sEncabezado(contador_filas)
        while f_actual == None:
            contador_filas += 1
            f_actual = self.Nfilas.sEncabezado(contador_filas)
            
        while f_actual != None:
            datos = f_actual.acesso
            formatImg = ""
          
            while datos != None:
                if(concatenar.find(str(datos.fila)+"[")==-1):
                    cona=cona+1
                    concatenar=concatenar+"fila"+str(datos.fila)+"[label = "+str(datos.fila)+"    width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n"
                    if(cona==1):
                        tont=tont+'Matriz->'+"fila"+str(datos.fila);
                    else:
                        tont=tont+" -> "+"fila"+str(datos.fila);
                    
                else:
                    print(str(datos.fila)+"[")
                datos = datos.derecha
            concatenar=concatenar+"\n"
            f_actual = f_actual.siguiente



        f_actual2 = self.Nfilas.sEncabezado(contador_filas)
        while f_actual2 == None:
            contador_filas += 1
            f_actual2 = self.Nfilas.sEncabezado(contador_filas)
            
        while f_actual2 != None:
            datos2 = f_actual2.acesso
            formatImg = ""    
            while datos2 != None:
                if(concatenar2.find(str(datos2.col)+"[")==-1):
                    cona2=cona2+1
                    concatenar2=concatenar2+str(datos2.col)+"[label = "+str(datos2.col)+"    width = 1.5 style = filled, fillcolor = bisque1, group = 2 ];\n" 
                    if(cona2==1):
                        tont2=tont2+'Matriz->'+str(datos2.col);
                    else:
                        tont2=tont2+" -> "+str(datos2.col);
                    same1=same1+str(datos2.col)+";"
                else:
                    print(str(datos2.col)+"[")
            
                datos2 = datos2.derecha
            concatenar2=concatenar2+"\n"
            f_actual2 = f_actual2.siguiente
        


        f_actual3 = self.Nfilas.sEncabezado(contador_filas)
        while f_actual3 == None:
            contador_filas += 1
            f_actual3 = self.Nfilas.sEncabezado(contador_filas)
            
        while f_actual3 != None:
            datos3 = f_actual3.acesso
            tont3=""
            tont4=""  
            same3=""   
            while datos3 != None:
                if(self.contadorTodo!=0):
                    concatenar3=concatenar3+"Dato"+str(datos3.fila)+str(datos3.col)+"[label = "+str(datos3.cantidad)+"    width = 1.5 style = filled, fillcolor = bisque1, group = 2 ];\n" 
                    
                else:
                    concatenar3=concatenar3+"Dato"+str(datos3.fila)+str(datos3.col)+"[label = "+str(datos3.cantidad)+"    width = 1.5 style = filled, fillcolor = bisque1, group = 2 ];\n" 
                
                if(concatenar3.find("Dato"+str(datos3.fila)+str(datos3.col))!=-1):
                    tontTotal= "fila"+str(datos3.fila)
                    
                    otra="{ rank = same;"+tontTotal+";"
                    tont3=tont3+" -> "+"Dato"+str(datos3.fila)+str(datos3.col)
                    
                    same3 = same3+"Dato"+str(datos3.fila)+str(datos3.col)+";"
               
                datos3 = datos3.derecha
            datodd=datodd+tontTotal+tont3+'[dir="both"]'+"\n"+otra+same3+"}\n"
            
            f_actual3 = f_actual3.siguiente


        f_actual4 = self.Ncolumnas.sEncabezado(contador_columna)
        while f_actual4 == None:
            contador_columna += 1
            f_actual4 = self.Ncolumnas.sEncabezado(contador_columna)
            
        while f_actual4 != None:
            datos4 = f_actual4.acesso
            tont3=""
            tont4=""  
            same3=""   
            while datos4 != None:
                
                tontTotal2= str(datos4.col)
                
                tont4=tont4+" -> "+"Dato"+str(datos4.fila)+str(datos4.col)
               
               
                datos4 = datos4.abajo
            datodd2=datodd2+tontTotal2+tont4+'[dir="both"]'+"\n"
            
            f_actual4 = f_actual4.siguiente
            

        concatenarTotal='digraph Sparce_Matrix {node [shape=box]Matriz[ label = "MATRIZ", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];\n'+concatenar+tont+'\n{ rank = same;Matriz;'+same1+'}\n'+concatenar2+tont2+concatenar3+datodd+datodd2

        file = open("MatrizDispersa2.dot","w",encoding='utf-8')
        file.write(concatenarTotal)
        file.write("}")
        file.close()
        path_desktop = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        os.system('dot -Tsvg MatrizDispersa2.dot -o '+path_desktop+"/reportes_F2/MATRIZ_"+str(comodin)+".svg")