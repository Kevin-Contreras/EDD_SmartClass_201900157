class Nodo():
    def __init__(self, fila, col, valor,lista,cantidad):
        self.fila = fila
        self.abajo = None
        self.lista = lista
        self.cantidad = cantidad
        self.derecha = None
        self.col = col
        self.arriba = None
        self.valor = valor
        self.izquierda = None
    
class nodoEncabezado():
    def __init__(self, id):
        self.id = id
        self.acesso = None
        self.siguiente = None
        self.antterior = None
        

