from flask import Flask,request
import arra
app = Flask(__name__)

@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"

@app.route("/carga",methods=["POST","GET"])
def carga():
  if(request.method == "POST"):
    dato =  request.get_json(force=True);
    
    arra.Archivo.lectura(dato["path"])
    for numero in range(len(dato["cursos"])):

      print( dato["cursos"][numero]["nombre"])
    return "se ha ingresado exitasamente"
    