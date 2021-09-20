

class Archivo:
  
  def __init__(self):
    self.usuario ="";
    self.task ="";
    self.todo=""
  def lectura(self,ruta,tipo):
    contador=0;
    contadorTarea=0;
    datos=""
    
    archivo = open(ruta,encoding="utf8")
    solo=""
    if(tipo=="estudiante" or tipo=="task"):

      for d in archivo.readlines():
        if(d !="¿$element?\n"):
          contador+=contador+1
          if(contador != 1):
            if(d.find("\n")!=-1):
                sinSalto = d.rstrip()
                if(sinSalto.find("user")!=-1):
                  separadas = sinSalto.split("=")
                  solo =  separadas[1].rstrip("?").replace('"','')
                  
                  datos+=solo+","
                else:
                  if(sinSalto.find("task")!=-1):
                    separadas = sinSalto.split("=")
                    contadorTarea+=contadorTarea+1
                    if(contadorTarea==1):
                      solo =  "%"+separadas[1].rstrip("?").replace('"','')
                    else:
                      solo =  separadas[1].rstrip("?").replace('"','')
                  
                    datos+=solo+","
                  else:
                    separadas = sinSalto.split("=")
                    solo = separadas[1].rstrip("$?").replace(' "','').replace('" ','')
                  
                    datos+=solo+","

    
      self.todo = datos.split("%");
      self.usuario= self.todo[0].split("user,")
      self.usuario.pop(0)
      self.task = self.todo[1].split("task,")
      self.task.pop(0)
      
  def estudiante(self):
    return self.usuario
  
      
  def tareas(self):
    contador=0
    contador2=0
    anios = []
    task2=""
    
 
    for datos in self.todo[1].split("task,"):
        for fecha in datos.split(","):
          contador=contador+1
          if(contador==5):
            for nuevo in fecha.split("/"):
              contador2=contador2+1
              if(contador2==3):
               
                anios.append(int(nuevo))
            contador2=0;
        contador=0
                
                
        
        menor = list(set(anios))
        
        
    for uno in range(len(menor)):
      for dato in self.todo[1].split("task,"):
        if(dato.find("/"+str(menor[uno]))!=-1):
          task2=task2+dato+"*";
          task = task2[:-1]
    
    return task.split("*")
        

      
        
