import json

import Lista 
import Arbol
import ListaSemestre
class LecturaCurso:
  def lectura(path,tipo,Estudiantes,tareas):
    print(tareas)
    contador=0;
    contadorFecha=0
    contadorAnio=0;
    copis=""
    avl = Arbol.AVL()
    if(tipo=="curso"):
      with open(path,encoding="utf8") as file:
        data = json.load(file)
        for carnets in data['Estudiantes']:
          lista = Lista.ListaDoble()
          for iterador in range(len(Estudiantes)):
            if(Estudiantes[iterador].find(carnets["Carnet"])!=-1):
              
                  
              for anios in carnets["Años"]:
                listaSemen = ListaSemestre.ListaDoble() 
                listaMeses = ListaSemestre.ListaDoble() 
                for semestre in anios["Semestres"]:
                    listaSemen.insertar(semestre["Semestre"])


                for iterador2 in range(len(tareas)):
                  if(tareas[iterador2].find(carnets["Carnet"])!=-1):
                    for datos in tareas[iterador2].split(","):
                      contador=contador+1;
                      if(contador==5):
                        for mes in datos.split("/"):
                          contadorFecha=contadorFecha+1;

                          
                          if(contadorFecha==2):
                                copia=mes;
                                print(mes)  
                          if(contadorFecha==3):
                            copis=mes
                            
                            
                            
                            if(anios["Año"]==copis):
                              
                                listaMeses.insertar(copia)
                        contadorFecha=0;
                    contador=0;
                      
                
                lista.insertar(anios["Año"],listaSemen,listaMeses)
              avl.insert(int(carnets["Carnet"]),Estudiantes[iterador],lista)
              
    avl.preShow(avl.root)
