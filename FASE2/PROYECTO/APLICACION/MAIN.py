from flask import Flask,request,render_template,jsonify
from random import randrange
import os
import LECTURAFASE1
import LecturaCurso
import Lista
import ListaSemestre
import lecturaPensum
import listaMeses
import matrizDisperza
import arbolB

app = Flask(__name__)
archivoFase1= LECTURAFASE1.Archivo()
lecturaCurso = LecturaCurso.LecturaCurso()
lecturaPen = lecturaPensum.LecturaPensum()
path_desktop = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
os.mkdir(path_desktop+"/reportes_F3")
nombre=""

@app.route("/login",methods=["POST"])
def login():
  if(request.method=="POST"):
    dato = request.get_json()
    if(dato["usuario"]=="admin" and dato["password"]=="admin"):
      print(dato['usuario'])
      return {"admin":"admin"}
    else:
      nombre=archivoFase1.decrypt(dato["usuario"],dato["password"])
      return  jsonify(nombre)
@app.route("/usuario",methods=["GET"])
def usuarioPrincipal():
  if(request.method=="GET"):
    print(archivoFase1.todo["nombre"])
    return jsonify(archivoFase1.todo)
@app.route("/reporteEstudiantes",methods=["GET"])
def reporteEstudiante():
  archivoFase1.avll.graficar("encrypt")
  archivoFase1.avll2.graficar("decrypt")

@app.route("/registro",methods=["POST"])
def registro():
  if(request.method=="POST"):
    dato = request.get_json()
    archivoFase1.insertar(dato)
    return "hola"
@app.route("/pensum",methods=["POST"])
def pen():
  if(request.method == "POST"):
    dato =  request.get_json();
    print(dato)
    lecturaPen.Pensum2(dato)
    return "Se ha ingresado a la estructura de datos en el servidor"
@app.route("/cargaUsuario",methods=["POST"])
def user():
  if(request.method == "POST"):
    dato =  request.get_json();
    archivoFase1.jsonEstudiante(dato)
    return "Se ha ingresado a la estructura de datos en el servidor"
@app.route("/carga",methods=["POST","GET"])
def carga():
  if(request.method == "POST"):
    dato =  request.get_json();
    if(dato["tipo"]=="cursoPensum"):
      lecturaPen.Pensum(dato["path"],dato["tipo"])
    if(dato["tipo"]=="estudiante" or dato["tipo"]=="recordatorio" ):
        archivoFase1.lectura(dato["path"],dato["tipo"])
    else:

      lecturaCurso.lectura(dato["path"],dato["tipo"],archivoFase1.estudiante(),archivoFase1.tareas())
      
      """
      lecturaCurso.avl.buscar(201901425)
      lecturaCurso.avl.iterar(lecturaCurso.avl.root)
      lecturaCurso.avl.nodoNuevo2.buscar("2019").recorrer()
      """
    return "se ha ingresado exitasamente"


@app.route("/estudiante",methods=["POST","GET","PUT"])
def crudEstudiantes():
  if(request.method=="POST"):
    datoEstudiante = request.get_json()
    datosConcatenados = datoEstudiante["carnet"]+","+datoEstudiante["DPI"]+","+datoEstudiante["nombre"]+","+datoEstudiante["carrera"]+","+datoEstudiante["correo"]+","+datoEstudiante["password"]+", "+str(datoEstudiante["creditos"])+" , "+str(datoEstudiante["edad"])+",";
    lecturaCurso.avl.insert(int(datoEstudiante["carnet"]),datosConcatenados,Lista.ListaDoble())
    return "SE INGRESO EL ESTUDIANTE AL ARBOL AVL"

  elif(request.method =="GET"):
    re = request.get_json()
    lecturaCurso.avl.buscar(int(re["carnet"]))
    lecturaCurso.avl.iterar(lecturaCurso.avl.root)
    return lecturaCurso.avl.curr_node3
  elif(request.method == "PUT"):
    datoEstudiante2 = request.get_json()
    datosConcatenados2 = datoEstudiante2["carnet"]+","+datoEstudiante2["DPI"]+","+datoEstudiante2["nombre"]+","+datoEstudiante2["carrera"]+","+datoEstudiante2["correo"]+","+datoEstudiante2["password"]+", "+str(datoEstudiante2["creditos"])+" , "+str(datoEstudiante2["edad"])+","
    lecturaCurso.avl.buscar2(int(datoEstudiante2["carnet"]))
    lecturaCurso.avl.actualizar(lecturaCurso.avl.root,datosConcatenados2)
    return "SE ACTUALIZO EL ESTUDIANTE"
@app.route("/recordatorios",methods=["POST","GET","PUT","DELETE"])
def recordatorio():
  if(request.method=="GET"):
    recorda = request.get_json();
    lecturaCurso.avl.buscar(int(recorda["Carnet"]))
    lecturaCurso.avl.iterar(lecturaCurso.avl.root)
    if(lecturaCurso.avl.nodoNuevo2.buscarAo(recorda["Fecha"].split("/")[2])==recorda["Fecha"].split("/")[2]):
      if(lecturaCurso.avl.nodoNuevo2.mes.buscar(recorda["Fecha"].split("/")[1])==recorda["Fecha"].split("/")[1]):
        
        lecturaCurso.avl.nodoNuevo2.mes.matriz.buscarMatriz(int(recorda["Hora"].split(":")[0]),int(recorda["Fecha"].split("/")[0]))
        tarea = lecturaCurso.avl.nodoNuevo2.mes.matriz.listaTarea.unaTarea(recorda["Posicion"])
       
    return tarea
  elif(request.method=="POST"):
    recorda2 = request.get_json();
    texto = recorda2["Carnet"]+","+recorda2["Nombre"]+","+recorda2["Descripcion"]+","+recorda2["Materia"]+","+recorda2["Fecha"]+","+recorda2["Hora"]+","+recorda2["Estado"]
    lecturaCurso.avl.buscar(int(recorda2["Carnet"]))
    lecturaCurso.avl.iterar(lecturaCurso.avl.root)
    if(lecturaCurso.avl.nodoNuevo2.buscarAo(recorda2["Fecha"].split("/")[2])==recorda2["Fecha"].split("/")[2]):
      if(lecturaCurso.avl.nodoNuevo2.mes.buscar(recorda2["Fecha"].split("/")[1])==recorda2["Fecha"].split("/")[1]):
        
        lecturaCurso.avl.nodoNuevo2.mes.matriz.buscarAgregar(int(recorda2["Hora"].split(":")[0]),int(recorda2["Fecha"].split("/")[0]),texto)
        lecturaCurso.avl.nodoNuevo2.mes.matriz.suma(int(recorda2["Hora"].split(":")[0]),int(recorda2["Fecha"].split("/")[0]))
      else:
        agregar = matrizDisperza.matriz()
        lecturaCurso.avl.nodoNuevo2.mes.insertar(recorda2["Fecha"].split("/")[1],agregar)
        
        agregar.insertar(int(recorda2["Hora"].split(":")[0]),int(recorda2["Fecha"].split("/")[0]),texto)
        
    return "SE CREO UNA NUEVA TAREA"
  elif(request.method=="PUT"):
    recorda23 = request.get_json();
    texto2 = recorda23["Carnet"]+","+recorda23["Nombre"]+","+recorda23["Descripcion"]+","+recorda23["Materia"]+","+recorda23["Fecha"]+","+recorda23["Hora"]+","+recorda23["Estado"]
    lecturaCurso.avl.buscar(int(recorda23["Carnet"]))
    lecturaCurso.avl.iterar(lecturaCurso.avl.root)
    if(lecturaCurso.avl.nodoNuevo2.buscarAo(recorda23["Fecha"].split("/")[2])==recorda23["Fecha"].split("/")[2]):
      if(lecturaCurso.avl.nodoNuevo2.mes.buscar(recorda23["Fecha"].split("/")[1])==recorda23["Fecha"].split("/")[1]):
        lecturaCurso.avl.nodoNuevo2.mes.matriz.buscarMatriz(int(recorda23["Hora"].split(":")[0]),int(recorda23["Fecha"].split("/")[0]))
        lecturaCurso.avl.nodoNuevo2.mes.matriz.listaTarea.actualizar(recorda23["Posicion"],texto2)
       
    return "SE ACTUALIZO LA TAREA SELECCIONADA"
  elif(request.method=="DELETE"):
    eliminar = request.get_json();
    lecturaCurso.avl.buscar(int(eliminar["Carnet"]))
    lecturaCurso.avl.iterar(lecturaCurso.avl.root)
    if(lecturaCurso.avl.nodoNuevo2.buscarAo(eliminar["Fecha"].split("/")[2])==eliminar["Fecha"].split("/")[2]):
      if(lecturaCurso.avl.nodoNuevo2.mes.buscar(eliminar["Fecha"].split("/")[1])==eliminar["Fecha"].split("/")[1]):
        lecturaCurso.avl.nodoNuevo2.mes.matriz.buscarMatriz(int(eliminar["Hora"].split(":")[0]),int(eliminar["Fecha"].split("/")[0]))
        lecturaCurso.avl.nodoNuevo2.mes.matriz.buscarEliminar(int(eliminar["Hora"].split(":")[0]),int(eliminar["Fecha"].split("/")[0]))
        lecturaCurso.avl.nodoNuevo2.mes.matriz.listaTarea.eliminar(eliminar["Posicion"])
    lecturaCurso.avl.preShow(lecturaCurso.avl.root)
    return "SE ELIMINO LA TAREA SELECCIONADA"
@app.route("/cursosEstudiante",methods=["POST"])
def crudCursoEstudiante():
  if(request.method=="POST"):
      curso = request.get_json();
      m=lecturaCurso;
      for estudiante in curso["Estudiantes"]:
        m.avl.buscar(int(estudiante["Carnet"]))
        m.avl.iterar(lecturaCurso.avl.root)
        for año in estudiante["Años"]:
          if(m.avl.nodoNuevo2.buscarAo(año["Año"])==año["Año"]):
            for semestre in año["Semestres"]:
              if(m.avl.nodoNuevo2.semestres.buscar(semestre["Semestre"])==semestre["Semestre"]):
                for curso in semestre["Cursos"]:
                  m.avl.cursoConta=lecturaCurso.avl.cursoConta+1
                  m.avl.nodoNuevo2.semestres.arbolCurso.insert((lecturaCurso.avl.cursoConta,curso["codigo"]+"\n"+curso["Nombre"]))
              else:
                contador2=0;
                arbolBbb=arbolB.arbolB.BTree(5)
                m.avl.nodoNuevo2.semestres.insertar(semestre["Semestre"],arbolBbb)
                for curso in semestre["Cursos"]:
                  contador2=contador2+1
                  arbolBbb.insert((contador2,curso["Codigo"]+"\n"+curso["Nombre"]))
                arbolBbb.print_tree(arbolBB.root)
          else:
            listaSemestres= ListaSemestre.ListaDoble()
            listaMeses2=listaMeses.ListaDoble()
            m.avl.nodoNuevo2.insertar(año["Año"],listaSemestres,listaMeses2)
            contador1=0;
            for semestre in año["Semestres"]:
              arbolBB=arbolB.BTree(5)
              listaSemestres.insertar(semestre["Semestre"],arbolBB)
              for curso in semestre["Cursos"]:
                contador1=contador1+1
                arbolBB.insert((contador1,curso["Codigo"]+curso["Nombre"]))
          arbolBB.print_tree(arbolBB.root)
  return "SE INGRESARON LOS CURSOS"
@app.route("/cursosPensum",methods=["POST"])
def pensum():
  if(request.method=="POST"):
    pem=lecturaPen
    dato = request.get_json()
    for curso in dato["Cursos"]:
      pem.contador=pem.contador+1
      pem.arbol.insert((pem.contador,curso["Codigo"]+curso["Nombre"]))
    pem.arbol.print_tree(pem.arbol.root)
    return "SE AGREGO UN NUEVO CURSO"
@app.route("/reporte",methods=["GET"])
def reportes():
  if(request.method=="GET"):
      dato = request.get_json()
      if(len(dato)==1):
        if(dato["tipo"]==0):
          lecturaCurso.avl.graficar()
        if(dato["tipo"]==3):
          lecturaPen.arbol.ConcatenarArbolB(lecturaPen.arbol.root)
          lecturaPen.arbol.graficar("Pensum"+str(randrange(21)))
      elif(len(dato)==4):
        if(dato["tipo"]==4):
          re = request.get_json()
          lecturaCurso.avl.buscar(int(re["carnet"]))
          lecturaCurso.avl.iterar(lecturaCurso.avl.root)
          lecturaCurso.avl.nodoNuevo2.buscarAo(re["año"])
          lecturaCurso.avl.nodoNuevo2.semestre.buscar(re["semestre"])
          lecturaCurso.avl.nodoNuevo2.semestre.arbolCurso.ConcatenarArbolB(lecturaCurso.avl.nodoNuevo2.semestre.arbolCurso.root)
          lecturaCurso.avl.nodoNuevo2.semestre.arbolCurso.graficar("Estudiante"+str(randrange(21)))
        if(dato["tipo"]==1):
          re = request.get_json()
          lecturaCurso.avl.buscar(int(re["carnet"]))
          lecturaCurso.avl.iterar(lecturaCurso.avl.root)
          lecturaCurso.avl.nodoNuevo2.buscarAo(re["año"])
          if(len(str(re["mes"]))==2):
            lecturaCurso.avl.nodoNuevo2.mes.buscar(str(re["mes"]))
            
          else:
            lecturaCurso.avl.nodoNuevo2.mes.buscar("0"+str(re["mes"]))
          lecturaCurso.avl.nodoNuevo2.mes.matriz.graficar(str(randrange(21)))
      elif(len(dato)==6):
        if(dato["tipo"]==2):
          recorda = request.get_json();
          lecturaCurso.avl.buscar(int(recorda["carnet"]))
          lecturaCurso.avl.iterar(lecturaCurso.avl.root)
          lecturaCurso.avl.nodoNuevo2.buscarAo(recorda["año"])
          if(len(str(recorda["mes"]))==2):
            lecturaCurso.avl.nodoNuevo2.mes.buscar(str(recorda["mes"]))
            lecturaCurso.avl.nodoNuevo2.mes.matriz.buscarMatriz(int(recorda["hora"]),int(recorda["dia"]))
            lecturaCurso.avl.nodoNuevo2.mes.matriz.listaTarea.graficar(str(randrange(21)))
          else:
            lecturaCurso.avl.nodoNuevo2.mes.buscar("0"+str(recorda["mes"]))
            lecturaCurso.avl.nodoNuevo2.mes.matriz.buscarMatriz(int(recorda["hora"]),int(recorda["dia"]))
            lecturaCurso.avl.nodoNuevo2.mes.matriz.listaTarea.graficar(str(randrange(21)))
      return "SE REALIZO EL REPORTE"