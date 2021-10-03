from nodoMatriz import nodoEncabezado, Nodo
class listaEcabezado:
    def __init__(self, primero=None):
        self.primero = primero
    def obtenerEncabezado(self, aux):
        if self.primero == None:
            self.primero = aux
        elif aux.id < self.primero.id:
            aux.siguiente = self.primero
            self.primero.anterior = aux
            self.primero = aux
        else:
            mm = self.primero
            while mm.siguiente != None:
                if aux.id < mm.siguiente.id:
                    aux.siguiente = mm.siguiente
                    mm.siguiente.anterior = aux
                    aux.anterior = mm
                    mm.siguiente = aux
                    break
                mm = mm.siguiente
            if mm.siguiente == None:
                mm.siguiente = aux
                aux.anterior = mm

    def sEncabezado(self, id):
        mm = self.primero
        while mm != None:
            if mm.id == id:
                return mm
            mm = mm.siguiente
        return None

