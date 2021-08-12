#include <iostream>
#include <cstring>
using namespace std;
class nodoCola2{
  public:
  string datosCola;
  nodoCola2*siguientes;
};
class cola2{
  public:
  nodoCola2*primeros=NULL;
  nodoCola2* ultimos=NULL;
  void insertar(string datos){
    nodoCola2* nuevo = new nodoCola2();
    nuevo->datosCola=datos;
    cout<<nuevo->datosCola<<" datos de  la cola"<<endl;
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
    void eliminar(){
    nodoCola2 * actuals = new nodoCola2();
    actuals = primeros;
    nodoCola2 * anterior = new nodoCola2();
    anterior=NULL;
    bool encontrado=false;
    int nodoBuscado = 0;
    if(primeros!=NULL){
      while(actuals!=NULL &&  encontrado !=true){
      
         
          if(actuals ==primeros){
              primeros=primeros->siguientes;
          }else if(actuals==ultimos){
            anterior->siguientes=NULL;
            ultimos=anterior;
          }else{
              anterior->siguientes=actuals->siguientes;
          }
          encontrado=true;
        
        anterior = actuals;
        actuals=actuals->siguientes;
      }
      if(!encontrado){
        cout<<"nodo no encontrado"<<endl;
      }
    }else{
      cout<<"LA COLA ESTA VACIA "<<endl;
    }
  }
  int desplegar(){
    int contador=0;

    nodoCola2 * actual = new nodoCola2();
    actual = primeros;
    if(primeros!=NULL){
     
      while(actual!=NULL){
        contador++;
        cout<<actual->datosCola<<endl;
        actual=actual->siguientes;
      }
    return contador;
    }
  }
     string datosd(int insertar){
    string cadena;

    nodoCola2 * actual = new nodoCola2();
    actual = primeros;
    
    for (int i = 0; i < insertar+1; i++)
    {
      
       cadena =  actual->datosCola;
        actual=actual->siguientes;
        
    }
        return cadena;
      
    
    
  };
 


};
