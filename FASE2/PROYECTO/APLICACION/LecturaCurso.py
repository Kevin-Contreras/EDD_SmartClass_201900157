import json
import arbolB
import Lista 
import Arbol
import ListaSemestre
import listaMeses
import matrizDisperza
import ListaTareas;
class LecturaCurso:
  def __init__(self):
    self.avl=Arbol.AVL()
  def lectura(self,path,tipo,Estudiantes,tareas):
    sinLista=""
    contador=0;
    contadorFecha=0
    contadorAnio=0;
    sin=""
    fechaM=""
    copis=""
    diaHora=""
    horauwu=""
    fechall=""
    copia=""
    conca=""
    conca2=""
    nose=""
    contad=1;
    dia=0
    cursoConta=0;
    if(tipo=="curso"):
      with open(path,encoding="utf8") as file:
        data = json.load(file)
        for carnets in data['Estudiantes']:
          lista = Lista.ListaDoble()
          for iterador in range(len(Estudiantes)):
            if(Estudiantes[iterador].find(carnets["Carnet"])!=-1):

              sinLista = sinLista+Estudiantes[iterador]+"$"
              for anios in carnets["Años"]:
                
                listaSemen = ListaSemestre.ListaDoble() 
                listaMesess = listaMeses.ListaDoble() 
                for semestre in anios["Semestres"]:
                  B=arbolB.BTree(5)
                  self.cursoConta=0;
                  for cursos in semestre["Cursos"]:
                    
                    B.insert((int(cursos["Codigo"]),cursos["Codigo"]+"\n"+cursos["Nombre"]))
                    self.cursoConta=self.cursoConta+1;
                  
                  listaSemen.insertar(semestre["Semestre"],B)
                    

                for iterador2 in range(len(tareas)):
                  if(tareas[iterador2].find(carnets["Carnet"])!=-1 and tareas[iterador2].find("/"+anios["Año"])!=-1):
                    
                    for datos in tareas[iterador2].split(","):
                      contador=contador+1;
                      if(contador==5):
                        fechaM=datos;
                        fechall=datos+",";
                      if(contador==6):
                        
                        horauwu=datos;
                        for fecha in fechaM.split("/"):
                          contadorFecha=contadorFecha+1;
                          if(contadorFecha==1):
                            dia=int(fecha);
                          if(contadorFecha==2):
                                copia=fecha;
                                if(conca2[:-1].find(copia)==-1):
                                  x = matrizDisperza.matriz();
                                conca=conca+fecha+",";
                                for d in conca[:-1].split(","):
                                  if(d==fecha):
                                    conca2=conca2+d+","; 
                          if(contadorFecha==3):
                            copis=fecha
                            for ue in tareas:
                                
                                if(ue.find(fechall+horauwu)!=-1 and ue.find(carnets["Carnet"])!=-1):
                                  nose =nose+ue+"$"; 
                                  
                            if(anios["Año"]==copis):
                              

                              x.insertar(int(datos.split(":")[0]),dia,nose)
                              nose=""
                              fechayhora=""
                              
                              listaMesess.insertar(copia,x)
                        
                        contadorFecha=0;
                    contador=0;
                conca2=""   
                lista.insertar(anios["Año"],listaSemen,listaMesess)
              self.avl.insert(int(carnets["Carnet"]),Estudiantes[iterador],lista)

              
      for estu in sinLista[:-1].split("$"):
        Estudiantes.remove(estu);
      for agregar in Estudiantes:
        self.avl.insert(int(agregar.split(",")[0]),agregar,Lista.ListaDoble())
            
              
                
               
                
                
                
      
          
              
    
