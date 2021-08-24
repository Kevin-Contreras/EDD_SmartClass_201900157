#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <regex>
#include "./COLA.cpp"
#include "./NODO.cpp"
#include<windows.h>
using namespace std;

class Leer{
 
  public: string nombre;
  public: ListaCircularDoble lista;
  public:
   string carnet;
   cola nodoLista;
   void leerArchivo(string url){
      SetConsoleOutputCP(CP_UTF8);
      string archivoCadena;
      string archivoCadena2;
      string archivocadena4;
      //VARIABLES CON LOS VALORES
     
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
        cout<<""<<endl;
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
        
        }else{
          contadorCarnet++;
          nodoLista.insertar("TYPO: ESTUDIANTE, EL CARNET: "+carnetValor+" NO ESTA BIEN ESCRITO ID: "+ dpivalor );
          
        };
        if(dpivalor.length()==13){
          contadorDpi++;
          
        }else{
          nodoLista.insertar("TYPO: ESTUDIANTE, EL DPI: "+dpivalor+" NO ESTA BIEN ESCRITO ID: "+ dpivalor );
          
        };
        regex expReg("^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\\.[a-zA-Z0-9-]+)*$");
        if(regex_match(correoValor,expReg)==true){
          
        }else{
          contadorCorreo++;
          nodoLista.insertar("TYPO: ESTUDIANTE, EL CORREO :"+correoValor+" NO ESTA BIEN ESCRITO ID: "+ dpivalor );
         
        }
      }
      
      
      
    }
    
  
};