class Node1():
    def __init__(self, fila, col, valor):
        self.fila = fila
        self.col = col
        self.valor = valor
        self.derecha = None
        self.izquierda = None
        self.arriba = None
        self.abajo = None
    
class nodoEncabezado():
    def __init__(self, id):
        self.id = id
        self.siguiente = None
        self.antterior = None
        self.accesoNodo = None

