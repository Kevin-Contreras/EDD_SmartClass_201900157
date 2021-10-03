import os
import nodoTareas;
class ListaDoble:
  def __init__(self):
    self.primero=None;
    self.ultimo=None;
    self.indice = 0;

  def insertar(self,dato):
    self.indice = self.indice+1
    nuevo = nodoTareas.Nodo(dato)
    if(self.primero ==None):
      self.primero = nuevo;
      self.ultimo =self.primero;
    else:
      nuevo.atras = self.ultimo
      self.ultimo.siguiente = nuevo
      self.ultimo = nuevo 

      
  def eliminar(self,dato):
      contador=0;
      actual = self.primero
      eliminado =False;
      if(actual is None):
        eliminado =False;
      elif(self.indice ==1):
        self.primero=None
        self.ultimo=None
      elif(1==dato):
        self.indice=self.indice-1;
        self.primero=actual.siguiente
        self.primero.atras =None
        eliminado =True
      elif( self.indice ==dato):
        self.indice=self.indice-1;
        self.ultimo=self.ultimo.atras
        self.ultimo.siguiente=None
        eliminado=True
      else:
        
        while actual:
          contador=contador+1
          if(contador==dato):
            self.indice=self.indice-1;
            actual.atras.siguiente = actual.siguiente
            actual.siguiente.atras = actual.atras
            eliminado=True
          actual =actual.siguiente
      


      
  def unaTarea(self,contador):
    aux = self.primero
    sumaTarea=0
    if(aux != None):
      while(aux!=None):
        sumaTarea=sumaTarea+1
        if(contador==sumaTarea):

          return aux.dato

        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")
  def actualizar(self,contador,dato):
    aux = self.primero
    sumaTarea=0
    if(aux != None):
      while(aux!=None):
        sumaTarea=sumaTarea+1
        if(contador==sumaTarea):
          aux.dato=dato
          return aux.dato

        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")

  def recorrer(self):
    aux = self.primero
    if(aux != None):
      while(aux!=None):
        print(aux.dato)

        aux = aux.siguiente;
    else:
      print("la lista se encuentra vacia")
  def graficar(self,comodin):
    aux = self.primero
    aux2 = self.primero
    contador=0
    contador1=0

    cadena=""
    datoss=""
    flecha=""
    if(aux != None):
      while(aux!=None):
        contador=contador+1
        datoss=str(contador)+"[label = "+'"'+aux.dato+'"'+"    width = 1.5 style = filled, fillcolor = bisque1, group = 2 ];\n"
        cadena=cadena+datoss

        aux = aux.siguiente;
      while(aux2!=None):
        contador1=contador1+1;
        if(contador1!=1):
          flecha=flecha+"->"+str(contador1)

        aux2 = aux2.siguiente;
      cadena=cadena+"1"+flecha
      file = open("listaTarea.dot","w",encoding='utf-8')
      file.write("digraph structs {rankdir=\"LR\"")
      file.write("node [shape=record];")
      file.write(cadena)
      file.write("}")
      file.close()
      path_desktop = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
      os.system('dot -Tsvg listaTarea.dot -o '+path_desktop+"/reportes_F2/TAREAS_"+str(comodin)+".svg")
    else:
      print("la lista se encuentra vacia")




    

    
