#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <regex>
#include "./LISTADOBLE.cpp"
#include "./COLA2.cpp"
#include<windows.h>
using namespace std;

class LeerTarea{
 
  public: string nombre;
  public:
  int id =0;
  cola2 cola;
  public: ListaDoble listadobleEnlazada;
   void leerArchivo(string carnetsEstudiantes[]){
    
     id = id+listadobleEnlazada.idNuevo;
    
  string mes;
  stringstream  streamdata(carnetsEstudiantes[1]);
  stringstream  streames(carnetsEstudiantes[0]);
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
   
    string datoss[5][30][9];
   
    int sol=0;
     int contadorhora=0;
    for (int i = 0; i < 5; i++){
      for (int j = 0; j <30 ; j++)
      {
         sol=0;
        for (int k = 0; k < 9; k++)
        {
          sol=0;
          for (int l = 0; l < id; l++)
          {
            if(to_string(i+7)+"/"+to_string(j+1)+"/"+to_string(k+8)==matrizFecha[l]){
              
                datoss[i][j][k]= matrizDatos[l];
                contadorhora++;
            }else{
              sol++;
              if(sol==id){
                datoss[i][j][k]=string("-1");
                contadorhora++;
              }
              
            }
          }
          
        }
      }
    }
    int u =0;
    
    
    
    string mesValor;
    string diaValor;
    string horaValor;

    stringstream  streamMes(mes);
    
    
    int contadorMes=0;
    int contadordia=0;
    

  
      
    //AQUI SE CREO LA MATRIZ PARA REALIZAR EL COLUMN MAJOR (CARNET IMPAR)
   
    string matrizColumnMajor[contadorhora];
    
    
    for (int i = 0; i < 5; i++){
      for(int j=0; j<30; j++){
        for (int k = 0; k < 9; k++)
        {
         contadorMes++;
         //FORMULA PARA COLUMNMAJOR
         
          matrizColumnMajor[j+30*(k+9*i)]=datoss[i][j][k];
        //

        }
        
      }
    }
   
  
        for (int k = 0; k < 1350; k++)
        {

          listadobleEnlazada.insertar( matrizColumnMajor[k]);
        }
        
     
    
    
   

    contadorhora=0;

   }
   string* cadenea(string url,string carnetsEstudiantes){
      SetConsoleOutputCP(CP_UTF8);
      
      string archivoCadena;
      string archivoCadena2;
      string archivocadena4;
      string concatenar;
      string concatenar2;
      string fechaseparada;
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
      string hora2;
      //----------------
      string coma;
      string nueva;
      fstream archivo;
      string fechaNueva;
      int contador2=0;
      int mes2=0;
      int dia2=0;
      int hora21=0;
      archivo.open(url, ios::in);
      if(archivo.fail()){
        cout<<""<<endl;
      };
      while (getline(archivo,archivoCadena))
      {
        
        stringstream  streamEstudiante(carnetsEstudiantes);
        while (getline(streamEstudiante,archivoCadena2,',') )
        {
            
          if(archivoCadena.find(archivoCadena2)!=-1){
             stringstream  streamTareas(archivoCadena);
             id++;
             
            while (getline(streamTareas,archivocadena4,',')){
               contador2++;
          if(contador2==1){
            mes += archivocadena4+",";
            mes2=stoi(archivocadena4);
            if(archivocadena4.substr(0,1)=="0"){
              concatenar +=archivocadena4.substr(1,2);
            }else{
              concatenar +=archivocadena4;
            }
            
            if(stoi(archivocadena4)>6 && stoi(archivocadena4)<12 ){
              if(archivocadena4.length()==1){
                fechaNueva+="0"+archivocadena4+"/";
              }else{
                 fechaNueva+=archivocadena4+"/";
              }
              
                 
            }else{
              // ENVIAR EL ERROR EN UNA COLA MES
              if(archivocadena4.length()==1){
                fechaNueva+="0"+archivocadena4+"/";
              }else{
                 fechaNueva+=archivocadena4+"/";
              }
              cola.insertar("TYPO:TAREA, EL MES NO ESTA EN EL RANGO ADECUADO id: "+ to_string(id));
              
            }
          }
          if(contador2==2){
            dia += archivocadena4+",";
            dia2=stoi(archivocadena4);
              if(archivocadena4.substr(0,1)=="0"){
                
              concatenar +="/"+archivocadena4.substr(1,2)+"/";
            }else{
              concatenar +="/"+archivocadena4+"/";
            }
            
            if(stoi(archivocadena4)<31 && stoi(archivocadena4)>0 ){
              if(archivocadena4.length()==1){
                fechaNueva+="0"+archivocadena4;
              }else{
                 fechaNueva+=archivocadena4;
              }
              
                 
            }else{
              // ENVIAR EL ERROR EN UNA COLA MES
              if(archivocadena4.length()==1){
                fechaNueva+="0"+archivocadena4+"/";
              }else{
                 fechaNueva+=archivocadena4+"/";
              }
              cola.insertar("TYPO:TAREA, el DIA no esta en el intervalo que se desea ERROR.en el id: "+ to_string(id));
              
            }
          }
          if(contador2==3){
            
            hora += archivocadena4+",";
            hora2=archivocadena4;
            hora21=stoi(archivocadena4);
             if(archivocadena4.substr(0,1)=="0"){
              concatenar +=archivocadena4.substr(1,2)+",";
            }else{
              concatenar +=archivocadena4+",";
            }
            if(stoi(archivocadena4)>7 && stoi(archivocadena4)<17 ){
                 
            }else{
              // ENVIAR EL ERROR EN UNA COLA MES
              cola.insertar("TYPO:TAREA, LA HORA no esta en el intervalo que se desea ERROR.en el id: "+ to_string(id));
              
            }
          }
          if(contador2==4){
            carnet += archivocadena4+",";
            concatenar2 +="id "+to_string((dia2-1)+30*((hora21-8)+9*(mes2-7)))+",";
            concatenar2 +=archivocadena4+",";
            if(archivocadena4.length()==9){
              
            }else{
               cola.insertar("TYPO:TAREA, EL CARNET no tiene la cantidad de numero adecuada ERROR.en el id: "+ to_string((dia2-1)+30*((hora21-8)+9*(mes2-7))));
             
            }
            
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
          string anio="";
          string mes="";
          string diaw="";
          int contadorfecha =0;
          if(contador2==8){
            
            
            stringstream  streamfecha("2021/"+fechaNueva+"/");
            fechaNueva="";
            while(getline(streamfecha,fechaseparada,'/')){
              contadorfecha++;
              if(contadorfecha==1){
                anio=fechaseparada;
              }else if (contadorfecha == 2)
              {
                mes=fechaseparada+"/";
              }else if(contadorfecha == 3){
                diaw=fechaseparada+"/";
              }
              
            }
           
            concatenar2 +=diaw+mes+anio+",";
             concatenar2+=hora2+",";
            if(regex_match(archivocadena4,expReg)==true){
              
            }else{
              // ENVIAR EL ERROR EN UNA COLA MES
              cola.insertar("TYPO:TAREA, la fecha no esta bien escrita.en el id: "+ to_string((dia2-1)+30*((hora21-8)+9*(mes2-7))));
              
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
   
   static string datos [2]={concatenar2,concatenar};
    return datos;
   
   }
  
};