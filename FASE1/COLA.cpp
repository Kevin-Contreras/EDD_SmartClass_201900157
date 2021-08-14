#include <iostream>
#include <cstring>
using namespace std;
class nodoCola{
  public:
  string datosCola;
  nodoCola*siguientes;
};
class cola{
  public:
  nodoCola*primeros=NULL;
  nodoCola* ultimos=NULL;
  void insertar(string datos){
    nodoCola* nuevo = new nodoCola();
    nuevo->datosCola=datos;
   
    if(primeros ==NULL){
      primeros=nuevo;
      primeros->siguientes=NULL;
      ultimos= primeros;
     
    }else
    {
      ultimos->siguientes=nuevo;
      nuevo->siguientes=NULL;
      ultimos=nuevo;
    }
     
  };
    void eliminar(string eliminarNodo){
    nodoCola * actuals = new nodoCola();
    actuals = primeros;
    nodoCola * anterior = new nodoCola();
    anterior=NULL;
    bool encontrado=false;
    int nodoBuscado = 0;
    if(primeros!=NULL){
      while(actuals!=NULL ){
        if(actuals->datosCola.find(eliminarNodo)!=-1){
          
          if(actuals ==primeros){
              primeros=primeros->siguientes;
          }else if(actuals==ultimos){
            anterior->siguientes=NULL;
            ultimos=anterior;
          }else{
              anterior->siguientes=actuals->siguientes;
          }
          encontrado=true;
        }
        anterior = actuals;
        actuals=actuals->siguientes;
      }
      if(!encontrado){
        cout<<"nodo no encontrado"<<endl;
      }
    }
  }
  int desplegar(){
    nodoCola * actual = new nodoCola();
    actual = primeros;
    if(primeros!=NULL){
     
      while(actual!=NULL){
       
        actual=actual->siguientes;
      }
    return 0;
    }else{
      
      return 1;
    }
  };
  int desplegar2(){
    int contador=0;

    nodoCola * actual = new nodoCola();
    actual = primeros;
    if(primeros!=NULL){
     
      while(actual!=NULL){
        contador++;
       
        actual=actual->siguientes;
      }
    return contador;
    }
  }
   string datosds(int insertar){
    string cadena;

    nodoCola * actual = new nodoCola();
    actual = primeros;
    
    for (int i = 0; i < insertar+1; i++)
    {
      
       cadena =  actual->datosCola;
        actual=actual->siguientes;
        
    }
        return cadena;
      
    
    
  };
 
 


};
