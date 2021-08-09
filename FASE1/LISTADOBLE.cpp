#include <iostream>
#include <cstring>
using namespace std;
class nodoT{
  public:
  string datok;
  nodoT* siguiente;
  nodoT* atras;
};

class ListaDoble{
public:
nodoT* primero1=NULL;
nodoT* ultimo1=NULL;
int contadorll=0;
void insertar(string datoNuevo){
  
  nodoT* nuevo = new nodoT();
  nuevo->datok=datoNuevo;
 
  if(primero1 == NULL){
    primero1 = nuevo;
    primero1 -> siguiente = NULL;
    primero1-> atras=NULL;
    ultimo1 = primero1; 
    
  }else{
    ultimo1->siguiente=nuevo;
    nuevo->siguiente=NULL;
    nuevo->atras=ultimo1;
    ultimo1=nuevo;
    

  }

}
void desplegar(){
  int conta=0;
  nodoT* actual2 = new nodoT();
  actual2 = primero1;
  if (primero1!=NULL)
  {
    while(actual2 !=NULL)
    {
      conta++;
    cout<<actual2->datok + ": "+ to_string(conta)<<endl;
     actual2=actual2->siguiente;
    } 
   
  }else{
    cout<<"la lista se encuentra vacia"<<endl;
  }
  
};
void buscarNodo(){
  nodoT* actual = new nodoT();
  actual = primero1;
  bool encontrado = false;
  string nodoBuscado;
  cin>>nodoBuscado;
  if (primero1!=NULL)
  {
   while (actual!=NULL && encontrado !=true)
   {
     if(actual->datok ==nodoBuscado){
       cout<<nodoBuscado<<endl;
       encontrado =true;
     }
     actual=actual->siguiente;

   }
   if(!encontrado){
     cout<<"nod no encontrado"<<endl;
   }
  }else{
    cout<<"la lista se encuentra vacia"<<endl;
  }
}
void modificarNodo(string cadenaTarea,int valorTotal){
  nodoT* actual = new nodoT();
  actual = primero1;
  bool encontrado = false;
  string nodoBuscado;
 contadorll=0;
  if (primero1!=NULL)
  {
   while (contadorll!=valorTotal )
   {
      contadorll++;
     
     if(contadorll==valorTotal){
       cout<<  contadorll<<endl;
       cout<<valorTotal<<endl;
     if(actual->datok=="-1"){
       
       cout<<actual->datok<<endl;
       actual->datok = cadenaTarea;
       cout<<actual->datok<<endl;
       encontrado =true;
       
     }else{
       cout<<"no se ingreso el dato"<<endl;;
     }  
     }
     
     actual=actual->siguiente;
    

   }
   if(!encontrado){
     cout<<"nodo no encontrado"<<endl;
   }
  }else{
    cout<<"la lista se encuentra vacia"<<endl;
  }
}
};
