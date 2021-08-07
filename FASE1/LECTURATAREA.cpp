#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <regex>

#include<windows.h>
using namespace std;

class LeerTarea{
 
  public: string nombre;

  public:
  
   void leerArchivo(string url,string carnetsEstudiantes){
      SetConsoleOutputCP(CP_UTF8);
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
    
      archivo.open(url, ios::in);
      if(archivo.fail()){
        cout<<"EL ARCHIVO NO SE PUDO ABRIR";
      };
      while (getline(archivo,archivoCadena))
      {
        stringstream  streamEstudiante(carnetsEstudiantes);
        while (getline(streamEstudiante,archivoCadena2,',') )
        {
            
          if(archivoCadena.find(archivoCadena2)!=-1){
            cout<<"existe en los estudiantes "<<archivoCadena <<endl;
          }
        }

        
        
        coma = archivoCadena+",";
        
    }
    cout<<carnetsEstudiantes;
    carnetsEstudiantes;
   }
  
};