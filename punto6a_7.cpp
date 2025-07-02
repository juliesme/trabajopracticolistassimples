
#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;
 struct tnodo{
	int dato;
	pnodo siguiente;
};

void crear_nodo(pnodo &nuevo){
	nuevo = new tnodo;
	if(nuevo != NULL){
		cout << "Ingrese valor: ";
		cin >> nuevo -> dato;
		nuevo -> siguiente = NULL;
	}else{
		cout << "Memoria insuficiente" <<
		endl;
	}
}
void iniciar(pnodo &lista){
	lista=NULL;
}
void agregar_inicio (pnodo &lista, pnodo nuevo){
	nuevo -> siguiente = lista;
	lista = nuevo;
}
void agregar_final(pnodo &lista, pnodo nuevo){
	pnodo i;
	if(lista == NULL){
		lista = nuevo;
	}else{
		for(i = lista; i->siguiente != NULL;i=i->siguiente);
		i->siguiente = nuevo;
	}
}

pnodo eliminar_inicio(pnodo &lista){
	pnodo borrado;
	if(lista==NULL){
		borrado = NULL;
	}else{
		borrado = lista;
		lista = lista->siguiente;
		borrado->siguiente = NULL;
	}
	return borrado;
}

pnodo eliminar_final(pnodo &lista){
	pnodo borrado, i;
	
	if(lista == NULL){
		borrado = NULL;
	}else{
		if(lista->siguiente == NULL){
			borrado=lista;
			lista=NULL;
		}else{
			for(i=lista; (i->siguiente)->siguiente != NULL;i=i->siguiente);
			borrado = i->siguiente;
			i->siguiente = NULL;
		}
	}
	return borrado;
}

void mostrar(pnodo lista){
    pnodo i;
    if(lista != NULL){
        for(i = lista; i != NULL; i = i->siguiente){
            cout << "Nodo: " << i->dato << endl;
        }
    }
    else{
        cout << "Lista vacía" << endl;
    }
}

int buscar_primos(pnodo lista){
	pnodo i;
	int cont=0;
	bool primo;
	if(lista != NULL){
		for(i=lista; i != NULL ;i=i->siguiente){
			if(i->dato <= 1){
				primo = false;
			}else if(i->dato == 2){
                primo = true;
            }else if(i->dato % 2 == 0){
                primo = false;
            }else{
				primo = true;
			for(int j = 3; j * j <= i->dato; j += 2){
                    if(i->dato % j == 0){
                        primo = false;
                        break; // Si encontramos un divisor, no es primo
                    }
                }
            }
            
            if(primo){
                cont++;
            }
        }
    }
    return cont;
}
void liberar_nodo(pnodo nodo){
    if(nodo != NULL){
        delete nodo;
        nodo=NULL;
    }
}		
	
int main(){
	pnodo Lista;
	pnodo nuevoNodo;
	pnodo nodoEliminado;
	int op;
	
	iniciar(Lista);
	
	do{
        cout<<endl<< " ====== MENU ======" <<endl;
        cout<< "1. Agregar al inicio" <<endl;
        cout<< "2. Agregar al final" <<endl;
        cout<< "3. Eliminar del inicio" <<endl;
        cout<< "4. Eliminar del final" <<endl;
        cout<< "5. Mostrar lista" <<endl;
        cout<< "6. Buscar primos" <<endl;
        cout<< "0. Salir" <<endl;
        cout<< "Seleccione una opcion: ";
        cin>> op;
        
        switch(op){
            case 1:
                crear_nodo(nuevoNodo);
                if(nuevoNodo != NULL){
                    agregar_inicio(Lista, nuevoNodo);
                    cout<< "Elemento agregado al inicio." <<endl;
                }
                break;
                
            case 2:
                crear_nodo(nuevoNodo);
                if(nuevoNodo != NULL){
                    agregar_final(Lista, nuevoNodo);
                    cout<< "Elemento agregado al final." <<endl;
                }
                break;
                
            case 3:
                nodoEliminado = eliminar_inicio(Lista);
                if(nodoEliminado != NULL){
                    cout<< "Elemento eliminado del inicio: " << nodoEliminado->dato <<endl;
                    liberar_nodo(nodoEliminado);
                }
                else{
                    cout<< "La lista está vacía." <<endl;
                }
                break;
                
            case 4:
                nodoEliminado = eliminar_final(Lista);
                if(nodoEliminado != NULL){
                    cout<< "Elemento eliminado del final: " << nodoEliminado->dato <<endl;
                    liberar_nodo(nodoEliminado);
                }
                else{
                    cout<< "La lista está vacía." <<endl;
                }
                break;
                
            case 5:
                mostrar(Lista);
                break;
                
            case 6:
				cout<< "cantidad de numeros primos: " << buscar_primos(Lista) <<endl;
                break;
            case 0:
                cout<< "Saliendo..." <<endl;
                break;
                
            default:
                cout<< "Opción inválida." <<endl;
                break;
        }
    } while(op != 0);
	
	return 0;
}
