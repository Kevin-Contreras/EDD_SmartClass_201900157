#include <iostream>
#include <fstream>

using namespace std;

class Leer{
  public:
   void leerArchivo(string url){
      string archivoCadena;
      string archivoCadena2;
      fstream archivo;
      int contadorEstudiantes=0;
      archivo.open(url, ios::in);
      if(archivo.fail()){
        cout<<"EL ARCHIVO NO SE PUDO ABRIR";
      };
      while (getline(archivo,archivoCadena))
      {
       contadorEstudiantes++;
       archivoCadena2 += archivoCadena+"\n";  

      };
      string carnet[contadorEstudiantes];
      string dpi[contadorEstudiantes];
      string nombre[contadorEstudiantes];
      string carrera[contadorEstudiantes];
      string password[contadorEstudiantes];
      string creditos[contadorEstudiantes];
      string edad[contadorEstudiantes];
      string correo[contadorEstudiantes];

     for (int i = 0; i < archivoCadena2.length(); i++)
     {
       
     }
     
      
      cout<<contadorEstudiantes<<endl;
      cout<<archivoCadena2<<endl;
      
      
      
    }
};