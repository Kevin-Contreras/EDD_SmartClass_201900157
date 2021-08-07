#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
class sepa{
public:
string carnet;
string archivoCadena2;
void separar(string dato){
string archivoCadena;
string archivoCadena2;
string archivocadena4;
string coma;

string dpi;
string nombre;
string carrera;
string passwords;
string creditos;
string edad;
string correo;
int contador3=0;
int contador2=0;
int contadorEstudiantes =0;
  stringstream iss(dato);
   while (getline(iss,archivoCadena))
      {
        coma = archivoCadena+",";
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
};
};