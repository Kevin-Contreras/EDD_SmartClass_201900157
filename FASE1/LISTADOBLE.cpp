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
int conta=0;
int idNuevo=0;
string conca;
nodoT* primero1=NULL;
nodoT* ultimo1=NULL;
int contadorll=0;
int contadorll2=0;
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
  conta=0;
  nodoT* actual2 = new nodoT();
  actual2 = primero1;
  if (primero1!=NULL)
  {
    while(actual2 !=NULL)
    {
      if(actual2->datok !="-1"){
        conta++;
      
      }
      
     actual2=actual2->siguiente;
    } 
   
  }else{
    cout<<"la lista se encuentra vacia"<<endl;
  }
  
};
string indice(){
 nodoT* actual2 = new nodoT();
  actual2 = primero1;
 conca="";
  if (primero1!=NULL)
  {
    while(actual2 !=NULL)
    {
      if(actual2->datok !="-1"){
      
        conca+=actual2->datok+"*";
      
      }
      
     actual2=actual2->siguiente;
    } 
    return conca;
   
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
     cout<<"nodo no encontrado"<<endl;
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
      
     if(actual->datok=="-1"){
       idNuevo++;
      
       actual->datok ="id "+cadenaTarea;
       
       encontrado =true;
       
     }else{
       cout<<"ESA FECHA YA ESTA OCUPADA POR UNA TAREA NO SE INGRESO LA TAREA"<<endl;;
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
              cout<<"HORA: "+datos<<endl;
            }
            if(contador2==8){
              cout<<"ESTADO: "+datos<<endl;
            }
       };
       
       stringstream  datobuscado(actual->datok);
       actual->datok = "-1";
        cout<<"INGRESE LOS DATOS A MODIFICAR"<<endl;
        while (getline(datobuscado,datos2,','))
        {
          
          contador++;
          
          if(contador==1){
            cout<<" MODIFICAR MES"<<endl;
              cin>>mes;
         
         
            cout<<" MODIFICAR DIA"<<endl;
            cin>>dia;
         
          
            cout<<" MODIFICAR HORA"<<endl;
            cin>>hora;
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
         if(contador==8){
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
     todos = "id "+to_string(idDat)+","+carnet+","+nombre+","+descripcion+","+materia+","+fecha+","+to_string(hora)+","+estado+",";
      modificarNodo(todos,(mes-1)*30*24+(dia-1)*24+hora);
      
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
void mostrarTarea(int valorTotal){
   int contador2=0;
   string datos;
  nodoT* actualT = new nodoT();
  actualT = primero1;
  bool encontrado = false;
  string nodoBuscado;
 contadorll2=0;
  if (primero1!=NULL)
  {
   while (contadorll2!=valorTotal )
   {
      contadorll2++;
     
     if(contadorll2==valorTotal){
       stringstream  inter2(actualT->datok);
      
        encontrado=true;
       while (getline(inter2,datos,','))
       {
             contador2++;
             
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
              cout<<"HORA: "+datos<<endl;
            }
            if(contador2==8){
              cout<<"ESTADO: "+datos<<endl;
            }
       };
       
       
     }
     
     actualT=actualT->siguiente;
    

   }
   if(!encontrado){
     cout<<"nodo no encontrado"<<endl;
   }
  }else{
    cout<<"la lista se encuentra vacia"<<endl;
  }
}
void mostrarPosicion(int valorTotal){
   int contador2=0;
   string datos;
  nodoT* actualT = new nodoT();
  actualT = primero1;
  bool encontrado = false;
  string nodoBuscado;
 contadorll2=0;
  if (primero1!=NULL)
  {
   while (contadorll2!=valorTotal )
   {
      contadorll2++;
     
     if(contadorll2==valorTotal){
     
       cout<<"POSICION EN LA LISTA: "+to_string(contadorll2) +" (ACLARACION ESTA POSICION EN LA LISTA ES CON RESPECTO A 12 MESES A 30 DIAS Y A 24 HORAS)"<<endl;
        encontrado=true;
      
       
       
     }
     
     actualT=actualT->siguiente;
    

   }

  }else{
    cout<<"la lista se encuentra vacia"<<endl;
  }
}

};
