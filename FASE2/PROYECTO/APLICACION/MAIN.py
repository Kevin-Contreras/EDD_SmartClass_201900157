from flask import Flask,request
import LECTURAFASE1
import LecturaCurso
app = Flask(__name__)
archivoFase1= LECTURAFASE1.Archivo()
@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"

@app.route("/carga",methods=["POST","GET"])

def carga():
  
  if(request.method == "POST"):
    dato =  request.get_json();
    if(dato["tipo"]!="curso"):
        archivoFase1.lectura(dato["path"],dato["tipo"])
        print(archivoFase1.tareas())
    else:
      LecturaCurso.LecturaCurso.lectura(dato["path"],dato["tipo"],archivoFase1.estudiante(),archivoFase1.tareas())
    return "se ha ingresado exitasamente"
    