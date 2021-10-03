import NodoSemestre;
class ListaDoble:
  def __init__(self):
    self.primero=None;
    self.ultimo=None;
    self.matriz =None

  def insertar(self,dato,dato2):
    nuevo = NodoSemestre.Nodo(dato,dato2)
    if(self.primero ==None):
      self.primero = nuevo;
      self.ultimo =self.primero;
    else:
      aux=self.primero
      ci =False
      while(aux!=None):
        if(aux.dato==nuevo.dato):
          ci =True;
        aux=aux.siguiente
      if(ci==False):
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
      


      
  def buscar(self,dato):
    aux = self.primero
    if(aux != None):
      while(aux!=None):
        
        if(dato==aux.dato):
          self.matriz=aux.dato2;
          return aux.dato
        
          
        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")

  def recorrer(self):
    aux = self.primero
    if(aux != None):
      while(aux!=None):
        

        aux.dato2.recorreFilas()
        print(aux.dato)
        
        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")  



    
    
    

    
