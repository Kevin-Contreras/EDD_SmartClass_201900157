import arbolB
import json
class LecturaPensum:
  def __init__(self):
    self.arbol = arbolB.BTree(5)
    self.contador=0
  def Pensum(self,path,tipo):
    if(tipo=="cursoPensum"):
      with open(path,encoding="utf8") as file:
        data = json.load(file)
        for curso in data["Cursos"]:
          self.contador=self.contador+1
          self.arbol.insert((self.contador,curso["Codigo"]+curso["Nombre"]))
      self.arbol.print_tree(self.arbol.root)