#include <iostream>
#include "./LECTURA.cpp"
using namespace std;


class Menu{
public:
  Menu(){

    int numeroMenu;
     
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
        Leer lecturaEstudiantes;
        lecturaEstudiantes.leerArchivo(string(pathEstudiante));

        
        
        break;
        case 2:
        char pathTask[250];
        cout<<"SELECCIONO EL SEGUNDO OPCION"<<endl;
        cin>> pathTask;
        //COLOCAR CODIGO AQUI 
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
            cout<<"SE INGRESARON LOS DATOS DEL ESTUDIANTE"<<endl;
            //COLOCAR CODIGO AQUI 
            break;
          case 2:
          cout<<"SE MODIFICARON LOS DATOS DEL ESTUDIANTE"<<endl;
          //COLOCAR CODIGO AQUI 
          break;
          case 3:
          cout<<"SE ELIMINARON LOS DATOS DEL ESTUDIANTE"<<endl;
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
            cout<<"SE INGRESARON LOS DATOS DE LAS TAREAS"<<endl;
            //COLOCAR CODIGO AQUI 
            break;
          case 2:
          cout<<"SE MODIFICARON LOS DATOS DE LAS TAREAS"<<endl;
          //COLOCAR CODIGO AQUI 
          break;
          case 3:
          cout<<"SE ELIMINARON LOS DATOS DE LOS LAS TAREAS"<<endl;
          //COLOCAR CODIGO AQUI 
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

