#include <iostream>
#include <cstring>
using namespace std;
class ListaCircularDoble{
public:
struct nodo{
  string dato;
  nodo *siguiente;
  nodo *anterior;

};
nodo *primer = NULL;
nodo*ultimo = NULL;


void ingresar_datos(string datos){
  nodo*nuevo_nodo = new nodo();
  
  nuevo_nodo->dato=datos;
  if(primer == NULL){
    primer = nuevo_nodo;
    primer->siguiente=primer;
    primer->anterior=primer;
    ultimo=primer;
  }else
  {
    ultimo -> siguiente=nuevo_nodo;
    nuevo_nodo->siguiente=primer;
    nuevo_nodo->anterior=ultimo;
    ultimo=nuevo_nodo;
    primer->anterior=ultimo;
  }
  
}
void mostrar(){
  nodo * aux = new nodo();
  aux = primer;
  if(primer != NULL){
    do
    {
     cout<<"["<<aux->dato<<"]";
     aux=aux->siguiente;
    } while (aux != primer);
    
  }else{
    cout<<"la lista esta vacia";
  }
};
void buscarNodo(string dpi){
  nodo* actual = new nodo();
  actual = primer;
  bool encontrado = false;
  int nodoBuscar = 0;
  if(primer != NULL){
    do{

      if(actual->dato.find(dpi)!=-1){
        cout<<"el nodo con el dato ("<< dpi<<") encontrado"<<endl;
        encontrado = true;
      }
      actual = actual->siguiente;
    }while(actual!=primer && encontrado != true);
    if(!encontrado){
      cout<<"nodo no encontrado";

    }
  }else{
    cout<<"la lista se encuentra vacia"<<endl;
  }
  
};
 
 void modificarNodo(string dpi){

 nodo* actual = new nodo();
  actual = primer;
  bool encontrado = false;
  int nodoBuscar = 0;
  string campos;
  string campos2;

  int contador =0;
  int contador2 =0;
  int sn1=0;
  string todos;
  string carnetNuevo;
  string dpiNuevo;
  string nombreNuevo;
  string carreraNuevo;
  string contraNuevo;
  string creditosNuevo;
  string edadNuevo;
  string correoNuevo;
  if(primer != NULL){
    do{
      if(actual->dato.find(dpi)!=-1){
        stringstream  datobuscado(actual->dato);
        stringstream  datobuscado2(actual->dato);
        cout<<"el nodo con el dato ("<< dpi<<") encontrado"<<endl;
         while (getline(datobuscado,campos2,',')){
           contador2++;
            if(contador2==1){
              cout<<"CARNET: "+campos2<<endl;
            }
            if(contador2==2){
              cout<<"DPI: "+campos2<<endl;
            }
            if(contador2==3){
              cout<<"NOMBRE: "+campos2<<endl;
            }
            if(contador2==4){
              cout<<"CARRERA: "+campos2<<endl;
            }
            if(contador2==5){
              cout<<"PASSWORD: "+campos2<<endl;
            }
            if(contador2==6){
              cout<<"CREDITOS: "+campos2<<endl;
            }
            if(contador2==7){
              cout<<"EDAD: "+campos2<<endl;
            }
            if(contador2==8){
              cout<<"CORREO: "+campos2<<endl;
            }
         };
        while (getline(datobuscado2,campos,','))
        {
          
          contador++;
          if(contador==1){
            cout<<"¿DESEA MODIFICAR EL CARNET? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              cin>>carnetNuevo;
            }else{
             carnetNuevo=campos;

          }
          }
          if(contador==2){
            cout<<"¿DESEA MODIFICAR EL DPI? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              cin>>dpiNuevo;
            }else{
             dpiNuevo=campos;

          }
          }
          if(contador==3){
            cout<<"¿DESEA MODIFICAR EL NOMBRE? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
             getline(cin,nombreNuevo);
            }else{
             nombreNuevo=campos;

          }
          }

          if(contador==4){
            cout<<"¿DESEA MODIFICAR LA CARRERA? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              getline(cin,carreraNuevo);
            }else{
             carreraNuevo=campos;

          }
          }
          if(contador==5){
            cout<<"¿DESEA MODIFICAR LA CONTRASEÑA? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              cin>>contraNuevo;
            }else{
             contraNuevo=campos;

          }
          }
          if(contador==6){
            cout<<"¿DESEA MODIFICAR LOS CREDITOS? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              cin>>creditosNuevo;
            }else{
             creditosNuevo=campos;

          }
          }
          if(contador==7){
            cout<<"¿DESEA MODIFICAR LA EDAD? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              cin>>edadNuevo;
            }else{
             edadNuevo=campos;

          }
          }
          if(contador==8){
            cout<<"¿DESEA MODIFICAR EL CORREO? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
            cin>>sn1;
            if(sn1==1){
              cout<<"INGRESAR VALOR"<<endl;
              cin>>correoNuevo;
            }else{
             correoNuevo=campos;

          }
          }
        }
        todos = carnetNuevo+","+dpiNuevo+","+nombreNuevo+","+carreraNuevo+","+contraNuevo+","+creditosNuevo+","+""+edadNuevo+","+correoNuevo+",";
        actual->dato=todos;
        encontrado = true;
      }
      actual = actual->siguiente;
    }while(actual!=primer && encontrado != true);
    if(!encontrado){
      cout<<"nodo no encontrado";

    }
  }else{
    cout<<"la lista se encuentra vacia"<<endl;
  }
  
 };
 void Eliminar(string dpi){
   int l;
   cout<<"¿DESEAS ELIMINAR EL REGISTRO? (SI (COLOCAR UN 1) O NO (COLOCAR UN 0))"<<endl;
   cin>>l;
   if(l==1){
  nodo* actual = new nodo();
	actual = primer;
	nodo* anteriorKK = new nodo();
	anteriorKK = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	
	
	if(primer!=NULL){
		do{
			
			if(actual->dato.find(dpi)!=-1){
				cout << "\n Nodo con el dato ( " << dpi << " ) Encontrado";
				
				if(actual==primer){
					primer = primer->siguiente;
					primer->anterior = ultimo;
					ultimo->siguiente = primer;
				}else if(actual==ultimo){
					ultimo = anteriorKK;
					ultimo->siguiente = primer;
					primer->anterior = ultimo;
				}else{
					anteriorKK->siguiente = actual->siguiente;
					actual->siguiente->anterior = anteriorKK;
				}
				
				cout << "\n Nodo Eliminado\n\n";
				encontrado = true;				
			}
			
			anteriorKK = actual;
			actual = actual->siguiente;
		}while(actual!=primer && encontrado != true);
		
		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}
		
	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
   }else{
     cout<<"EL REGISTRO NO HA SIDO ELIMINADO"<<endl;
   }
 } 
};
