import nodo;
class ListaDoble:
  def __init__(self):
    self.primero=None;
    self.ultimo=None;
    self.mes=None
    self.semestre=None

  def insertar(self,dato,listaSemestres,meses):
    nuevo = nodo.Nodo(dato,listaSemestres,meses)
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
        self.primero.atras =None
        eliminado =True
      elif( self.ultimo.dato ==dato):
        self.ultimo=self.ultimo.atras
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
          return aux.semestres
          
        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")
  def buscarAo(self,dato):
    aux = self.primero
    if(aux != None):
      while(aux!=None):
        
        if(dato==aux.dato):
          self.semestre=aux.semestres
          self.mes=aux.meses
          return aux.dato
          
        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")
  def buscarMeses(self,dato):
    aux = self.primero
    if(aux != None):
      while(aux!=None):
        
        if(dato==aux.meses.buscar(dato)):
          return aux.meses
          
        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")
  
  def recorrer(self):
    aux = self.primero
    if(aux != None):
      while(aux!=None):
        print(aux.dato)
        aux.semestres.recorrer()
        aux.meses.recorrer()
        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")
  def recorrerSemestre(self):
    aux = self.primero
    if(aux != None):
      while(aux!=None):
        aux.semestres.recorrer()
        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")  



    
    
    

    
