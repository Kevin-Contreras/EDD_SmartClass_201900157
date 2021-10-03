#include <iostream>
#include "./LECTURA.cpp"
#include "./LECTURATAREA.cpp"
#include "./separacion.cpp"
#include <string.h>
#include <cstring>

#include<windows.h>

using namespace std;


class Menu{
public:
  Menu(){
    SetConsoleOutputCP(CP_UTF8);
    int s = 0;
    int valorkk=0;
    int contadorError=0;
    int contadorEstudiante=0;
    int contadorTareas=0;
    int eliminado=0;
    int eliminado2=0;
    int coi=0;
    string carnetAgregar;
    string dpiAgregar;
    string nombreAgregar;
    string carreraAgregar;
    string passwordAgregar;
    string creditosAgregar;
    string edadAgregar;
    string correoAgregar;
    string total;
    string buscardpi;
    string buscardpi2;
    string carnetTarea;
    string nombreTarea;
    string descripcion;
    string materia;
    string fecha;
    string estado;
    string cadenaToda;
    string *p;
    string ruta;
    string final1;
    string variable1;
    string variable2;
    int numeroMenu;
    int mes;
    int idEliminar;
    int idCambiar;
    int dia;
    int c=0;
    int hora;
    int mes1=0;
    int dia1=0;
    int hora1=0;
    int mes2=0;
    int dia2=0;
    int hora2=0;
    Leer lecturaEstudiantes;
    LeerTarea lecturaTarea;
    sepa nose;
    string cadena [2];
     fstream  archivoEstudiante;
     fstream archivoTAREA;
     fstream archivoSalida;

    do{
      
      cout<<"******************MENU***************"<<endl;
      cout<<"1- CARGA DE USUARIO"<<endl;
      cout<<"2- CARGA DE TAREAS"<<endl;
      cout<<"3- INGRESO MANUEAL"<<endl;
      cout<<"4- REPORTES"<<endl;
      cout<<"5- SALIR"<<endl;
      cout<<"INGRESE EL NUMERO PARA CONTINUAR:"<<endl;
      cin>>numeroMenu;
      
      switch(numeroMenu){
        case 1:
        cout<<"---> INGRESE LA RUTA DEL ARCHIVO DEL USUARIO"<<endl;
        char pathEstudiante[250];
        cin>>pathEstudiante;
        //COLOCAR CODIGO AQUI 
        lecturaEstudiantes.leerArchivo(string(pathEstudiante));
        break;
        case 2:
        char pathTask[250];
        cout<<"SELECCIONO EL SEGUNDO OPCION"<<endl;
        cin>> pathTask;
        //COLOCAR CODIGO AQUI 
          s=1;
          valorkk=1;
          p = lecturaTarea.cadenea(string(pathTask),lecturaEstudiantes.carnet);
          for (int u =0; u<2;u++){
              cadena[u]=*(p+u);
          }
         lecturaTarea.leerArchivo(cadena);
        lecturaTarea.listadobleEnlazada.desplegar();
        for (int i = 0; i < lecturaTarea.cola.desplegar(); i++)
        {
          lecturaEstudiantes.nodoLista.insertar(lecturaTarea.cola.datosd(i));
        }
        lecturaTarea.cola.eliminar();
        
        break;
        case 3:
         int submenu;
        do{
          cout<<"******************SUBMENU***************"<<endl;
          cout<<"1- USUARIOS"<<endl;
          cout<<"2- TAREAS"<<endl;
          cout<<"3- SALIR"<<endl;
          cout<<"INGRESE UN NUMERO PARA CONTINUAR"<<endl;
          cin>>submenu;
          switch (submenu)
          {
          case 1:
          int submenu2;
            do{
          cout<<"******************SUBMENU ESTUDIANTES***************"<<endl;
          cout<<"1- INGRESAR"<<endl;
          cout<<"2- MODIFICAR"<<endl;
          cout<<"3- ELIMMINAR" <<endl;
          cout<<"4- SALIR"<<endl;
          cout<<"INGRESE UN NUMERO PARA CONTINUAR"<<endl;
          cin>> submenu2;
          switch (submenu2)
          {
          case 1:
            
            cout<<"INGRESE LOS DATOS DEL ESTUDIANTE"<<endl;
            cout<<"CARNET: ";
            cin>>carnetAgregar;
            cout<<"DPI: ";
            cin>>dpiAgregar;
            cout<<"NOMBRE: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,nombreAgregar);
            cout<<"CARRERA: ";
           
            getline(cin,carreraAgregar);
            cout<<"PASSWORD: ";
            cin>>passwordAgregar;
            cout<<"CREDITOS: ";
            cin>>creditosAgregar;
            cout<<"EDAD: ";
            cin>>edadAgregar;
            cout<<"CORREO: ";
            cin>>correoAgregar;
            total = carnetAgregar+","+dpiAgregar+","+nombreAgregar+","+carreraAgregar+","+passwordAgregar+","+creditosAgregar+","+edadAgregar+","+correoAgregar+",";
            lecturaEstudiantes.lista.ingresar_datos(total);
            lecturaEstudiantes.lista.copia();
            nose.separar(lecturaEstudiantes.lista.datosTodos);
            if(s==1){
            
            p = lecturaTarea.cadenea(string(pathTask),lecturaEstudiantes.carnet);
            for (int u =0; u<2;u++){
              cadena[u]=*(p+u);
              }
          
            lecturaEstudiantes.lista.datosTodos="";
            nose.carnet="";
            
            }
            
            break;
          case 2:
          cout<<"INGRESE EL DPI PARA PODER REALIZAR LOS CAMBIOS"<<endl;
          cin>>buscardpi;

            lecturaEstudiantes.lista.modificarNodo(buscardpi);
            lecturaEstudiantes.lista.copia();
            nose.separar(lecturaEstudiantes.lista.datosTodos);
          if(s==1){
            lecturaTarea.id=0;
         
            p = lecturaTarea.cadenea(string(pathTask),lecturaEstudiantes.carnet);
            for (int u =0; u<2;u++){
              cadena[u]=*(p+u);
            }
             nose.carnet="";
             lecturaEstudiantes.lista.datosTodos="";
             
          };
          lecturaEstudiantes.nodoLista.eliminar(buscardpi);
        
          //COLOCAR CODIGO AQUI 
          break;
          case 3:
          cout<<"INGRESE EL DPI PARA PODER ELIMINAR EL DATO"<<endl;
          cin>>buscardpi2;
          lecturaEstudiantes.lista.Eliminar(buscardpi2);
          lecturaEstudiantes.lista.copia();
          nose.separar(lecturaEstudiantes.lista.datosTodos);
          if(s==1){
          lecturaTarea.id=0;
          p = lecturaTarea.cadenea(string(pathTask),lecturaEstudiantes.carnet);
          for (int u =0; u<2;u++){
              cadena[u]=*(p+u);
          }
          nose.carnet="";
          lecturaEstudiantes.lista.datosTodos="";
          
           
          }
          //COLOCAR CODIGO AQUI
           
          break;  
          case 4:
          break;
         
          }
            }while(submenu2!=4);
          break;
          case 2:
            int submenu3;
            do{
            cout<<"******************SUBMENU TAREAS***************"<<endl;
            cout<<"1- INGRESAR"<<endl;
            cout<<"2- MODIFICAR"<<endl;
            cout<<"3- ELIMMINAR" <<endl;
            cout<<"4- SALIR"<<endl;
            cout<<"INGRESE UN NUMERO PARA CONTINUAR"<<endl;
            cin>> submenu3;
          switch (submenu3)
          {
          case 1:
          cadenaToda="";
           
            cout<<"SE INGRESARON LOS DATOS DE LAS TAREAS"<<endl;
            cout<<"INGRESE EL MES: ";
            cin>>mes;
            cout<<"INGRESE EL DIA: ";
            cin>>dia;
            cout<<"INGRESE LA HORA: ";
            cin>>hora;
            cout<<"INGRESE EL CARNET: ";
            cin>>carnetTarea;
             cadenaToda +=","+carnetTarea+",";
            cout<<"INGRESE EL NOMBRE: ";
              
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
             getline(cin,nombreTarea);
             cadenaToda +=nombreTarea+",";
            cout<<"INGRESE LA DESCRIPCION: ";
             getline(cin,descripcion);
             cadenaToda +=descripcion+",";
             cout<<"INGRESE LA MATERIA: ";
             getline(cin,materia);
             cadenaToda +=materia+",";
            cout<<"INGRESE LA FECHA: ";
            cin>>fecha;
            cadenaToda +=fecha+",";
            cadenaToda+=to_string(hora)+",";
            cout<<"INGRESE EL ESTADO: ";
            cin>>estado;
            cadenaToda +=estado+",";
           
        
          lecturaTarea.listadobleEnlazada.modificarNodo(to_string((dia-1)+30*((hora-8)+9*(mes-7)))+cadenaToda,(dia-1)+30*((hora-8)+9*(mes-7))+1);
           lecturaTarea.listadobleEnlazada.desplegar();
           cadenaToda="";
            break;
          case 2:
          cout<<"COLOCAR EL ID DE LA TAREA"<<endl;
          cin>>idCambiar;
          lecturaTarea.listadobleEnlazada.cambiarDatos(idCambiar);
          lecturaEstudiantes.nodoLista.eliminar("id: "+to_string(idCambiar));
            
         
          break;
          case 3:
          cout<<"COLOCAR EL ID DE LA TAREA"<<endl;
          cin>>idEliminar;
          lecturaTarea.listadobleEnlazada.eliminar(to_string(idEliminar));
          lecturaTarea.listadobleEnlazada.desplegar();
          
          break;  
          case 4:
          break;
          default:
            break;
          }
            }while(submenu3!=4);
          break;
          case 3:
          break;
          
          }
        }while (submenu!=3);
        break;
        case 4:
        int variableReporte;
        if(lecturaEstudiantes.nodoLista.desplegar()==1){
          
                  do
        {
            cout<<"******************SUBMENU REPORTES***************"<<endl;
            cout<<"1- LISTA USUARIOS"<<endl;
            cout<<"2- LISTA TAREAS"<<endl;
            cout<<"3- BUSQUEDA EN ESTRUCTURA LINEALIZADA"<<endl;
            cout<<"4- BUSQUEDA DE POSICION EN LISTA ENLAZADA"<<endl;
            cout<<"5- CODIGO GENERADO"<<endl;
            cout<<"6- SALIR"<<endl;
            cout<<"INGRESE UN NUMERO PARA CONTINUAR"<<endl;
            cin>> variableReporte;
          switch (variableReporte)
          {
          case 1:
          contadorEstudiante++;
         
          archivoEstudiante.open("ESTUDIANTES"+to_string(contadorEstudiante)+".dot",ios::out);
          if(archivoEstudiante.fail()==true){
            cout<<"EL ARCHIVO NO SE PUDO ABRIR"<<endl;
          }else{
            string m1= "";
            string m2= "";
            string nosed2="";
            for (int i = 1; i < lecturaEstudiantes.lista.indice(); i++)
            {
                
             m1+="a"+to_string(i)+"[ label ="+"\""+"calificacion "+lecturaEstudiantes.lista.recorrer(i)+"\""+"]";
             if(i==1){
              m2+="a"+to_string(i);
             }
             if(i==lecturaEstudiantes.lista.indice()-1){
                nosed2+="a"+to_string(i)+"->"+m2;
            }else{
                nosed2+="a"+to_string(i)+"->";
            }
            }
            archivoEstudiante<<"digraph G {rankdir=\"LR\";subgraph cluster_0 {style=filled;color=green;node [style=filled,color=white];"+m1+nosed2+"[dir=\"both\"];}}";
             archivoEstudiante.close();
             string ruta2 = "dot -Tsvg ESTUDIANTES"+to_string(contadorEstudiante)+".dot -o imagenEstudiante"+to_string(contadorEstudiante)+".svg";
            const char * comm2 = ruta2.c_str();
            system(comm2);
          }
          //COLOCAR CODIGO AQUI 
            break;
          case 2:
            contadorTareas++;
         cout<<lecturaTarea.listadobleEnlazada.mostrarALaux()<<endl;
          archivoTAREA.open("TAREAS"+to_string(contadorTareas)+".dot",ios::out);
          if(archivoTAREA.fail()==true){
            cout<<"EL ARCHIVO NO SE PUDO ABRIR"<<endl;
          }else{
            string m1= "";
            string nuevos="";
            int y=0;
            stringstream  input_dat(lecturaTarea.listadobleEnlazada.indice());
            string nosed2="";
           while(getline(input_dat,nuevos,'*')){
             m1+="a"+to_string(y)+"[ label ="+"\""+nuevos+"\""+"]";
             
             
                nosed2+="a"+to_string(y)+"->";
            
            y++;
           }
           string st = nosed2.substr(0, nosed2.size()-2);
            lecturaTarea.listadobleEnlazada.conca="";
            archivoTAREA<<"digraph G {rankdir=\"LR\";subgraph cluster_0 {style=filled;color=blue;node [style=filled,color=white];"+m1+st+"[dir=\"both\"];}}";
             archivoTAREA.close();
             string ruta3 = "dot -Tsvg TAREAS"+to_string(contadorTareas)+".dot -o imagenTareas"+to_string(contadorTareas)+".svg";
            const char * comm3 = ruta3.c_str();
            system(comm3);
            lecturaTarea.listadobleEnlazada.conta=0;
          }
          //COLOCAR CODIGO AQUI 
          break;
          case 3:
          
          cout<<"INGRESE EL MES"<<endl;
          cin>>mes1;
          cout<<"INGRESE EL DIA"<<endl;
          cin>>dia1;
          cout<<"INGRESE LA HORA"<<endl;
          cin>>hora1;

          lecturaTarea.listadobleEnlazada.mostrarTarea((dia1-1)+30*((hora1-8)+9*(mes1-7))+1);
            break;
           case 4:
           cout<<"INGRESE EL MES"<<endl;
          cin>>mes2;
          cout<<"INGRESE EL DIA"<<endl;
          cin>>dia2;
          cout<<"INGRESE LA HORA"<<endl;
          cin>>hora2;
          lecturaTarea.listadobleEnlazada.mostrarPosicion((dia2-1)+30*((hora2-8)+9*(mes2-7))+1,mes2,dia2,hora2);
            break;

             case 5:
             archivoSalida.open("archivoSalida.txt",ios::out);
             if(archivoSalida.fail()==true){
               cout<<"EL ARCHIVO NO SE PUDO ABRIR"<<endl;
             }else{
               string concatenarEstudiantes;
               int contadorEstu=0;
               int contadorTarea=0;
               for (int i = 0; i < lecturaEstudiantes.lista.indice(); i++)
               {
                 if(i>0){
                   string study;
                 stringstream  dataEstudiantes(lecturaEstudiantes.lista.recorrer(i));
                 while (getline(dataEstudiantes,study,','))
                 {
                   contadorEstu++;
                   if(contadorEstu==1){
                     concatenarEstudiantes+="   ¿item Carnet = \""+study+"\" $?"+"\n";
                   }
                   if(contadorEstu==2){
                     concatenarEstudiantes+="   ¿item DPI = \""+study+"\" $?"+"\n";
                   }
                   if(contadorEstu==3){
                     concatenarEstudiantes+="   ¿item Nombre = \""+study+"\" $?"+"\n";
                   }
                   if(contadorEstu==4){
                     concatenarEstudiantes+="   ¿item Carrera = \""+study+"\" $?"+"\n";
                   }
                   if(contadorEstu==5){
                     concatenarEstudiantes+="   ¿item Password = \""+study+"\" $?"+"\n";
                   }
                   if(contadorEstu==6){
                     concatenarEstudiantes+="   ¿item Creditos = "+study+" $?"+"\n";
                   }
                   if(contadorEstu==7){
                     concatenarEstudiantes+="   ¿item Edad = "+study+" $?"+"\n";
                   }
                   if(contadorEstu==8){
                     concatenarEstudiantes+="   ¿item Correo = \""+study+"\" $?"+"\n";
                   }
                   
                 }
                 contadorEstu=0;
                 final1+="¿element type=\"user\"?\n"+concatenarEstudiantes+"¿$element?"+"\n";
                 concatenarEstudiantes="";

                 }
                 
               }
               stringstream  input_dat2(lecturaTarea.listadobleEnlazada.indice());
               while(getline(input_dat2,variable1,'*')){
                 stringstream  input_dat3(variable1);
                 while (getline(input_dat3,variable2,','))
                 {
                   contadorTarea++;
                   if(contadorTarea==2){
                     concatenarEstudiantes+="   ¿item Carnet = \""+variable2+"\" $?"+"\n";
                   }
                   if(contadorTarea==3){
                     concatenarEstudiantes+="   ¿item Nombre = \""+variable2+"\" $?"+"\n";
                   }
                   if(contadorTarea==4){
                     concatenarEstudiantes+="   ¿item Descripcion = \""+variable2+"\" $?"+"\n";
                   }
                   if(contadorTarea==5){
                     concatenarEstudiantes+="   ¿item Materia = \""+variable2+"\" $?"+"\n";
                   }  
                   if(contadorTarea==6){
                     concatenarEstudiantes+="   ¿item Fecha = \""+variable2+"\" $?"+"\n";
                   }
                   if(contadorTarea==7){
                     concatenarEstudiantes+="   ¿item Hora = \""+variable2+":00\" $?"+"\n";
                   }
                   if(contadorTarea==8){
                     concatenarEstudiantes+="   ¿item Estado = \""+variable2+"\" $?"+"\n";
                   }
                 }
                 contadorTarea=0;
                 final1+="¿element type=\"task\"?\n"+concatenarEstudiantes+"¿$element?"+"\n";
                 concatenarEstudiantes="";
               }
               archivoSalida<<"¿Elements?\n"+final1+"¿$Elements?";
               final1="";
               archivoSalida.close();
               
             }
            break;
             case 6:

            break;
          }
        } while (variableReporte!=6);
        
        }else{
          contadorError++;
          fstream  archivoError;
          archivoError.open("error"+to_string(contadorError)+".dot",ios::out);
          cout<<"HAY ERRORES NO SE PUEDE GENERAR NINGUN REPORTE"<<endl;
          if(archivoError.fail()==true){
            cout<<"el archivo no se pudo abrir"<<endl;
          }else{
            string m= "";
            string nosed="";
            for (int i = 0; i < lecturaEstudiantes.nodoLista.desplegar2(); i++)
            {
              m+="a"+to_string(i)+"[ label ="+"\""+lecturaEstudiantes.nodoLista.datosds(i)+"\""+"]";
              
              if(i==lecturaEstudiantes.nodoLista.desplegar2()-1){
                nosed+="a"+to_string(i);
            }else{
                  nosed+="a"+to_string(i)+"->";
            }
            
            
          }

          archivoError<<"digraph G {rankdir=\"LR\";subgraph cluster_0 {style=filled;color=red;node [style=filled,color=white];"+m+nosed+";}}";
          archivoError.close();
          ruta = "dot -Tsvg error"+to_string(contadorError)+".dot -o imagenError"+to_string(contadorError)+".svg";
          const char * comm = ruta.c_str();
            system(comm);
        }
        
         
        }

        break;

        case 5:
        break;
        default:
        cout<<"ESTA OPCION NO EXISTE EN EL PROGRAMA"<<endl;
        break;
      }
    }while(numeroMenu!=5);
  };
};

//FUNCION PRINCIPAL PARA INICIAR LA CLASE MENU
int main(){

Menu menu;
}
//-----------------------------

