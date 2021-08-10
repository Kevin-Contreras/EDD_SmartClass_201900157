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
    int numeroMenu;
    int mes;
    int idEliminar;
    int idCambiar;
    int dia;
    int c=0;
    int hora;
    Leer lecturaEstudiantes;
    LeerTarea lecturaTarea;
    sepa nose;
    string cadena [2];

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
            lecturaTarea.id=0;
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
           cadenaToda += to_string(++lecturaTarea.id);
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
            cout<<"INGRESE LA FECHA: ";
            cin>>fecha;
            cadenaToda +=fecha+",";
            cout<<"INGRESE EL ESTADO: ";
            cin>>estado;
            cadenaToda +=estado+",";
            lecturaTarea.id--;
           for (int u=0;u<2;u++){
              cout<<(u)<<endl;
           }
           
          lecturaTarea.listadobleEnlazada.modificarNodo(cadenaToda,(mes-1)*30*24+(dia-1)*24+hora);
           lecturaTarea.listadobleEnlazada.desplegar();
           cadenaToda="";
            break;
          case 2:
          cout<<"COLOCAR EL ID DE LA TAREA"<<endl;
          cin>>idCambiar;
          lecturaTarea.listadobleEnlazada.cambiarDatos(idCambiar);
           cout<<"SE ELIMINARON LOS DATOS DE LOS LAS TAREAS"<<endl; 
          
          
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
        do
        {
            cout<<"******************SUBMENU REPORTES***************"<<endl;
            cout<<"1- LISTA USUARIOS"<<endl;
            cout<<"2- LINEALIZACION TAREAS"<<endl;
            cout<<"3- SALIR"<<endl;
            cout<<"INGRESE UN NUMERO PARA CONTINUAR"<<endl;
            cin>> variableReporte;
          switch (variableReporte)
          {
          case 1:
          cout<<"SE MOSTRO LA LISTA"<<endl;
          //COLOCAR CODIGO AQUI 
            break;
          case 2:
          cout<<"SE LINEALIZO"<<endl;
          //COLOCAR CODIGO AQUI 
          break;
          case 3:
            break;
          }
        } while (variableReporte!=3);
        
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

