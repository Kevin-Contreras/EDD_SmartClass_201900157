import NodoSemestre;
class ListaDoble:
  def __init__(self):
    self.primero=None;
    self.ultimo=None;

  def insertar(self,dato):
    nuevo = NodoSemestre.Nodo(dato)
    if(self.primero ==None):
      self.primero = nuevo;
      self.ultimo =self.primero;
    else:
      nuevo.atras = self.ultimo
      self.ultimo.siguiente = nuevo
      self.ultimo = nuevo 
      
      
      
      
      
      
  def eliminar(self,dato):
      actual = self.primero
      eliminado =False;
      if(actual is None):
        eliminado =False;
      elif(actual.dato==dato):
        self.primero=actual.siguiente
        self.primero.antras =None
        eliminado =True
      elif( self.ultimo.dato ==dato):
        self.ultimo=self.ultimo.antras
        self.ultimo.siguiente=None
        eliminado=True
      else:
        while actual:
          if(actual.dato==dato):
            actual.atras.siguiente = actual.siguiente
            actual.siguiente.atras = actual.atras
            eliminado=True
          actual =actual.siguiente
      


      


  def recorrer(self):
    aux = self.primero
    if(aux != None):
      while(aux!=None):
        print(aux.dato)
        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")  



    
    
    

    
