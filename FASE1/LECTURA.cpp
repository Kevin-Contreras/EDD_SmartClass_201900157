#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <regex>
#include "./NODO.cpp"
using namespace std;

class Leer{
  public: string nombre;
  public: ListaCircularDoble lista;
  public:
  
   void leerArchivo(string url){
      string archivoCadena;
      string archivoCadena2;
      string archivocadena4;
      //VARIABLES CON LOS VALORES
      string carnet;
      string dpi;
      string nombre;
      string carrera;
      string passwords;
      string creditos;
      string edad;
      string correo;
      //----------------
      string coma;
      fstream archivo;
      int contador=0;
      int contador2=0;
      int contador3=0;
      int contadorEstudiantes=0;

      archivo.open(url, ios::in);
      if(archivo.fail()){
        cout<<"EL ARCHIVO NO SE PUDO ABRIR";
      };
      while (getline(archivo,archivoCadena))
      {
        coma = archivoCadena+",";
        lista.ingresar_datos(coma);
        contador3++;
        if(contador3!=1){
           stringstream  input_stringstream(archivoCadena);
        while (getline(input_stringstream,archivocadena4,','))
        {
          contador2++;
          if(contador2==1){
            carnet += archivocadena4+",";
          }
          if(contador2==2){
            dpi += archivocadena4+",";
          }
          if(contador2==3){
            nombre += archivocadena4+",";
          }
          if(contador2==4){
            carrera += archivocadena4+",";
          }
          if(contador2==5){
            passwords += archivocadena4+",";
          }
          if(contador2==6){
            creditos += archivocadena4+",";
          }
          if(contador2==7){
            edad += archivocadena4+",";
          }
          if(contador2==8){
            correo += archivocadena4+",";
          }
        }
        contador2=0;
        contadorEstudiantes++;
       archivoCadena2 += archivoCadena+","+"\n"; 
        }
      };
      
      string carnets[contadorEstudiantes];
      string dpis[contadorEstudiantes];
      string nombres[contadorEstudiantes];
      string carreras[contadorEstudiantes];
      string password[contadorEstudiantes];
      string creditoss[contadorEstudiantes];
      string edads[contadorEstudiantes];
      string correos[contadorEstudiantes];
      stringstream  input_stringstreams(dpi);
      stringstream  input_stringstream(carnet);
      stringstream  correoStream(correo);
      string carnetValor;
      string dpivalor;
      string correoValor;
      //VARIABLES CONTADOR PARA VER CUANTOS ERRORES EXISTEN.
      int contadorCarnet = 0;
      int contadorDpi = 0;
      int contadorCorreo = 0;
      

      while (getline(input_stringstream,carnetValor,',')&& getline(input_stringstreams,dpivalor,',') && getline(correoStream,correoValor,','))
      {
        if(carnetValor.length()==9){
          cout<<"EL CARNET ES CORRECTO!!"<<endl;
        }else{
          contadorCarnet++;
          cout<<"Mensaje Error: El numero de Carnet no es correcto"<<endl;
        };
        if(dpivalor.length()==13){
          contadorDpi++;
          cout<<"EL DPI ES CORRECTO!!"<<endl;
        }else{
          cout<<"Mensaje Error: El numero de DPI no es correcto"<<endl;
        };
        regex expReg("^[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?$");
        if(regex_match(correoValor,expReg)==true){
          cout<<"el correo se encuentra bien escrito"<<endl;
        }else{
          contadorCorreo++;
          cout<<"el correo no se encuentra bien escrito"<<endl;
        }
      }
      
      
      
    }
  
};