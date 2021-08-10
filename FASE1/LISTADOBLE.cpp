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
int idNuevo=0;
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
      if(actual2->datok !="-1"){
        conta++;
      cout<<actual2->datok + ": "+ to_string(conta)<<endl;
      }
      
     actual2=actual2->siguiente;
    } 
   conta=0;
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
       idNuevo++;
       cout<<actual->datok<<endl;
       actual->datok ="id "+cadenaTarea;
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
void eliminar(string idTarea){
  nodoT* actual = new nodoT();
  actual = primero1;
  bool encontrado = false;
  string nodoBuscado;
  int siono =0;
  if (primero1!=NULL)
  {
   while (actual!=NULL && encontrado !=true)
   {
     if(actual->datok.find("id "+idTarea)!=-1){
       cout<<"¿DESEA ELIMINAR LA TAREA  SI(1) NO(0)?"<<endl;
      cin>>siono;
      if(siono==1){
      actual->datok = "-1";
       encontrado =true;
      }
      
       
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
void cambiarDatos(int idDat){
  int siono =0;
  string datos;
  string datos2;
  string todos;
  int sn1=0;
  int contador=0;
  int contador2=0;
  int mes;
  int dia;
  int hora;
  string carnet;
  string nombre;
  string descripcion;
  string fecha;
  string estado;
  string materia;
  cout<<"¿DESEA CAMBIAR LA TAREA  SI(1) NO(0)?"<<endl;
  cin>>siono;
  if(siono==1){
  nodoT* actual = new nodoT();
  actual = primero1;
  bool encontrado = false;
  string nodoBuscado;
  if (primero1!=NULL)
  {
   while (actual!=NULL && encontrado !=true)
   {
     if(actual->datok.find("id "+to_string(idDat))!=-1){

       stringstream  datobuscadoa(actual->datok);
        
       while (getline(datobuscadoa,datos,','))
       {
             contador2++;
             cout<<datos<<endl;
            if(contador2==2){
              cout<<"CARNET: "+datos<<endl;
            }
            if(contador2==3){
              cout<<"NOMBRE: "+datos<<endl;
            }
            if(contador2==4){
              cout<<"DESCRIPCION: "+datos<<endl;
            }
            if(contador2==5){
              cout<<"MATERIA: "+datos<<endl;
            }
            if(contador2==6){
              cout<<"FECHA: "+datos<<endl;
            }
            if(contador2==7){
              cout<<"ESTADO: "+datos<<endl;
            }
       };
       stringstream  datobuscado(actual->datok);
        cout<<"INGRESE LOS DATOS A MODIFICAR"<<endl;
        while (getline(datobuscado,datos2,','))
        {
          
          contador++;
          cout<<contador<<" : contador : "<<datos2<<endl;
          if(contador==1){
            cout<<" MODIFICAR MES"<<endl;
              cin>>mes;
         
         
            cout<<" MODIFICAR DIA"<<endl;
            cin>>dia;
         
          
            cout<<" MODIFICAR HORA"<<endl;
            cin>>sn1;
          }
            
        

          if(contador==2){
            cout<<"¿DESEA MODIFICAR EL CARNET? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              
              cin>>carnet;
            }else{
             carnet=datos2;

          }
          }
          if(contador==3){
            cout<<"¿DESEA MODIFICAR EL NOMBRE DE LA TAREA? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
              getline(cin,nombre);
            }else{
             nombre=datos2;

          }
          }
          if(contador==4){
            cout<<"¿DESEA MODIFICAR LA DESCRIPCION? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
              getline(cin,descripcion);
            }else{
             descripcion=datos2;

          }
          }
          if(contador==5){
            cout<<"¿DESEA MODIFICAR LA MATERIA? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
              getline(cin,materia);
              
            }else{
             materia=datos2;

          }
          }
          if(contador==6){
            cout<<"¿DESEA MODIFICAR LA FECHA? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
              getline(cin,fecha);;
            }else{
             fecha=datos2;

          }
         
        }
         if(contador==7){
            cout<<"¿DESEA MODIFICAR EL ESTADO? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
              getline(cin,estado);
            }else{
              cout<<datos2<<endl;
             estado=datos2;

          }
          }
       
     }
     todos = "id "+to_string(idDat)+","+carnet+","+nombre+","+descripcion+","+materia+","+fecha+","+estado+",";
      modificarNodo(todos,(mes-1)*30*24+(dia-1)*24+hora);
      actual->datok = "-1";
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
}

};
