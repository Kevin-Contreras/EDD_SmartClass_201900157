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
      string concatenar;
      string concatenar2;
      //VARIABLES CON LOS VALORES
      string mes;
      string dia;
      string hora;
      string carnet;
      string nombreTarea;
      string descripcion;
      string materia;
      string fecha;
      string estado;
      //----------------
      string coma;
      fstream archivo;
      int contador2=0;
      int id =0;
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
             stringstream  streamTareas(archivoCadena);
             id++;
             concatenar2 += to_string(id) +",";
            while (getline(streamTareas,archivocadena4,',')){
               contador2++;
          if(contador2==1){
            mes += archivocadena4+",";
            concatenar +=archivocadena4;
            if(stoi(archivocadena4)>6 && stoi(archivocadena4)<12 ){
                  cout<<"el mes esta en el intervalo "<<archivocadena4<<endl;
            }else{
              // ENVIAR EL ERROR EN UNA COLA MES
              cout<<"el mes no esta en el intervalo que se desea ERROR. en el id: "<< id <<endl;
            }
          }
          if(contador2==2){
            dia += archivocadena4+",";
            concatenar +="/"+archivocadena4+"/";
            if(stoi(archivocadena4)<31 && stoi(archivocadena4)>0 ){
                  cout<<"el DIA esta en el intervalo "<<archivocadena4<<endl;
            }else{
              // ENVIAR EL ERROR EN UNA COLA MES
              cout<<"el DIA no esta en el intervalo que se desea ERROR.en el id: "<< id<<endl;
            }
          }
          if(contador2==3){
            
            hora += archivocadena4+",";
            concatenar +=archivocadena4+",";
            if(stoi(archivocadena4)>7 && stoi(archivocadena4)<17 ){
                  cout<<"la HORA esta en el intervalo "<<archivocadena4<<endl;
            }else{
              // ENVIAR EL ERROR EN UNA COLA MES
              cout<<"LA HORA no esta en el intervalo que se desea ERROR.en el id: "<< id<<endl;
            }
          }
          if(contador2==4){
            
            carnet += archivocadena4+",";
            concatenar2 +=archivocadena4+",";
          }
          if(contador2==5){
            nombreTarea += archivocadena4+",";
             concatenar2 +=archivocadena4+",";
          }
          if(contador2==6){
            descripcion += archivocadena4+",";
             concatenar2 +=archivocadena4+",";
          }
          if(contador2==7){
            materia += archivocadena4+",";
             concatenar2 +=archivocadena4+",";
          }
          regex expReg("^\\d{4}([\\-/.])(0?[1-9]|1[0-2])\\1(3[01]|[12][0-9]|0?[1-9])$");
          if(contador2==8){
            concatenar2 +=archivocadena4+",";
            if(regex_match(archivocadena4,expReg)==true){
              cout<<"la FECHA ESTA BIEN ESCRITA"<<archivocadena4<<endl;
            }else{
              // ENVIAR EL ERROR EN UNA COLA MES
              cout<<"la fecha no esta bien escrita.en el id: "<< id<<"("<<archivocadena4<<")"<<endl;
            }
            fecha += archivocadena4+",";
          }
          if(contador2==9){
            concatenar2 +=archivocadena4+"-";
            estado += archivocadena4+",";
          }
         
            }
            
            contador2=0;
          }
         
          
        }
        
        coma = archivoCadena+",";
        
    }
 
  stringstream  streamdata(concatenar);
  stringstream  streames(concatenar2);
  string nose;
  string nose2;
  string matrizFecha[id];
  string matrizDatos[id];
  int contadornose=0;
    int contadornose2=0;
   while(getline(streamdata,nose,',')){
      matrizFecha[contadornose]=nose;
      contadornose++;
   }
   while(getline(streames,nose2,'-')){
      matrizDatos[contadornose2]=nose2;
      contadornose2++;
   }
   for (int i = 0; i < id; i++)
   {
     cout<<matrizFecha[i]<<endl;
   }
   
    //AQUI SE CREO LA MATRIZ PARA REALIZAR EL COLUMN MAJOR (CARNET IMPAR)
    string datoss[12][30][24];
   
    int sol=0;
    for (int i = 0; i < 12; i++){
      for (int j = 0; j <30 ; j++)
      {
         sol=0;
        for (int k = 0; k < 24; k++)
        {
          sol=0;
          for (int l = 0; l < id; l++)
          {
            if(to_string(i+1)+"/"+to_string(j+1)+"/"+to_string(k+1)==matrizFecha[l]){
               cout<<to_string(i+1)+","+to_string(j+1)+","+to_string(k+1)<<endl;
                datoss[i][j][k]=matrizDatos[l];
            }else{
              sol++;
              if(sol==id){
                datoss[i][j][k]="-1";
              }
              
            }
          }
          
        }
      }
    }
    int u =0;
    
    
    cout<<datoss[6][0][10]<<endl;
    string mesValor;
    string diaValor;
    string horaValor;

    stringstream  streamMes(mes);
    
    
    int contadorMes;
    int contadordia=0;
    int contadorhora;

cout<<contadordia<<endl;   
      
      
   
    //
    cout<<carnetsEstudiantes;
    carnetsEstudiantes;
   }
  
};