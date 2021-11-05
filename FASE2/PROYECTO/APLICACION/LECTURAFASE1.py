
import hashlib
import json
import Arbol

from cryptography.fernet import Fernet
class Archivo:
  
  def __init__(self):
    self.usuario ="";
    self.task ="";
    self.todo=""
    self.clave=""
    self.f=""
    self.token=""
    self.token2=""
    self.claves=[]
    self.contra=[]
    self.correo=[]
    self.comodin=False
    self.fase3Usuarios=""
    self.todo=""
    self.avll=Arbol.AVL()
    self.avll2=Arbol.AVL()
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
        
  def jsonEstudiante(self,dato):
    self.fase3Usuarios = json.loads(dato)
    self.comodin=True
    for usuario in self.fase3Usuarios["estudiantes"]:
      self.avll2.insert(usuario["carnet"],"carnet: "+str(usuario["carnet"])+" \n "+"password: "+str(usuario["password"])+" \n "+"DPI: "+str(usuario["DPI"])+" \n "+"nombre: "+usuario["nombre"]+" \n "+"carrera: "+usuario["carrera"]+" \n "+"correo: "+str(usuario["correo"])+"\n"+"edad: "+str(usuario["edad"])+" \n ")
      cadena = hashlib.sha256(bytes(usuario["password"], 'utf-8'))
      str_cadena =cadena.hexdigest()
      self.clave = Fernet.generate_key()
      self.f = Fernet(self.clave)
      self.token2 = self.f.encrypt(bytes(usuario["correo"], 'utf-8'))
      self.token = self.f.encrypt(bytes(str_cadena, 'utf-8'))
      self.avll.insert(usuario["carnet"],"carnet: "+str(usuario["carnet"])+" \n "+"password: "+self.token.decode("utf-8")+" \n "+"DPI: "+str(usuario["DPI"])+" \n "+"nombre: "+usuario["nombre"]+" \n "+"carrera: "+usuario["carrera"]+" \n "+"correo: "+self.token2.decode("utf-8")+"\n"+"edad: "+str(usuario["edad"]))
      self.claves.append(self.f)
      self.contra.append(self.token)
      self.correo.append(self.token2)


    
  def decrypt(self,carnet,password):
    if(self.comodin==True):
      contrase =hashlib.sha256(bytes(password, 'utf-8'))
      sha=contrase.hexdigest()
      contador=0
      cont = []
      cont2=[]
      clave = Fernet.generate_key()
      ff = Fernet(clave)
      en = ff.encrypt(bytes(sha,'utf-8'))
      desU = ff.decrypt(en)
      for dec in range(len(self.claves)):
        des = self.claves[dec].decrypt(self.correo[dec])
        des2 = self.claves[dec].decrypt(self.contra[dec])
        print(des2)
        print(des)
        cont.append(des2)
        cont2.append(des)
        print(sha)
      self.avll2.actualizar(self.avll2.root,carnet,password)
      if(self.avll2.vare==True):
        self.avll2.vare=False
        self.todo = {
          "carnet":self.avll2.arr[0],
          "dpi":self.avll2.arr[2],
          "nombre":self.avll2.arr[3],
          "carrera":self.avll2.arr[4],
          "correo":self.avll2.arr[5],
          "edad":self.avll2.arr[6]
          }
     
         
        return self.todo
        
      return { "error":"no encontro el usuario"}
  def insertar(self,datos):
    self.comodin=True
    print(datos["password"])
    c =hashlib.sha256(bytes(datos["password"], 'utf-8'))
    sha2=c.hexdigest()
    clave = Fernet.generate_key()
    ff3 = Fernet(clave)
    en = ff3.encrypt(bytes(sha2,'utf-8'))
    correo = ff3.encrypt(bytes(datos["correo"],'utf-8'))
    des = ff3.decrypt(en)
    des2 = ff3.decrypt(correo)
    self.avll.insert(int(datos["carnet"]),"carnet: "+datos["carnet"]+"\n"+"password: "+en.decode("utf-8")+"\n"+datos["dpi"]+"\n"+datos["nombre"]+"\n"+datos["carrera"]+"\n"+correo.decode("utf-8")+"\n"+datos["edad"]+"\n")

    self.avll2.insert(int(datos["carnet"]),"carnet: "+datos["carnet"]+" \n "+"password: "+datos["password"]+" \n "+datos["dpi"]+" \n "+datos["nombre"]+" \n "+datos["carrera"]+" \n "+datos["correo"]+" \n "+datos["edad"]+" \n ")


    

        
    
      
        
