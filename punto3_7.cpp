/*3. Utilizando la implementación de lista del punto 2. Realice las siguientes funciones
a. Función buscar_indice que busque un valor dentro de la lista y retorne un
índice numérico (int) correspondiente a su posición lógica dentro de la lista, si
el valor no se encuentra retorna -1.
b. Función buscar_por_indice que busque un valor dentro de la lista según su
posición lógica, y si existe retorne un puntero con la dirección del elemento
buscado, caso contrario la función debe devolver NULL.*/
#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;
 struct tnodo{
	int dato;
	pnodo siguiente;
};
 struct tlista{
	pnodo inicio;
	pnodo fin;
	int contador;
};
void crear_nodo(pnodo &nuevo){
 nuevo = new tnodo;
 if(nuevo != NULL){
 cout << "Ingrese valor: ";
 cin >> nuevo -> dato;
 nuevo -> siguiente = NULL;
 }
 else{
 cout << "Memoria insuficiente" <<
endl;
 }
}
void iniciar (tlista &lista){
	lista.inicio = NULL;
    lista.fin = NULL;
    lista.contador=0;
}
void agregar_inicio (tlista &lista, pnodo nuevo){
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}else{
		nuevo->siguiente = lista.inicio;
		lista.inicio = nuevo;
	}
	lista.contador++;
}
void agregar_final (tlista &lista, pnodo nuevo){
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}else{
		lista.fin->siguiente = nuevo;
		lista.fin = nuevo;
	}
	lista.contador++;
}

pnodo eliminar_inicio(tlista &lista){
	pnodo borrado;
	if(lista.inicio==NULL){
		borrado = NULL;
	}else{ //solo un elemento
		if(lista.inicio == lista.fin){
			borrado = lista.inicio;
			lista.inicio = NULL;
			lista.fin = NULL;
		}else{ //mas de uno
			borrado = lista.inicio;
			lista.inicio = lista.inicio ->siguiente;
			borrado ->siguiente = NULL;
		}
		lista.contador --;
	}
			
	return borrado;
}

pnodo eliminar_final(tlista &lista){
	pnodo borrado, i;
	if(lista.inicio == NULL){
		borrado = NULL;
	}
	else{
		if(lista.inicio == lista.fin){ 
		borrado = lista.inicio;
		lista.inicio = NULL;
		lista.fin = NULL;
		}else{
			for(i = lista.inicio; (i->siguiente)->siguiente != NULL;i=i->siguiente);
			borrado = lista.fin;
			lista.fin = i;
			lista.fin->siguiente = NULL;
		}
		lista.contador--;
	}
	return borrado;
}

void mostrar(tlista lista){
    pnodo i;
    if(lista.inicio != NULL){
        for(i = lista.inicio; i != NULL; i = i->siguiente){
            cout << "Nodo: " << i->dato << endl;
        }
    }
    else{
        cout << "Lista vacía" << endl;
    }
}

void cant_elementos(tlista lista){
	cout<<"cantidad de elementos en la lista: "<<lista.contador<<endl;
}
int buscar_indice(tlista lista, int valor){
	pnodo i;
	int indice=0;
	bool encontrado = false;
	if(lista.inicio != NULL){
		for(i=lista.inicio; i != NULL && encontrado == false;i=i->siguiente){
			if(i->dato == valor){
			encontrado = true;
			}
			else{
				indice++;
			}
		}
	}
	if(encontrado == false){
		indice=-1;
	}
	return indice;
}

pnodo buscar_por_indice(tlista lista,int indice_buscado){
    pnodo i;
    int indice_act = 0;
    pnodo nodo_encontrado = NULL;
    
    if(indice_buscado >= 0 && lista.inicio != NULL){  // Validar que el índice no sea negativo y que la lista no esté vacía
        
        for(i=lista.inicio; (i != NULL) && (indice_act <= indice_buscado); i = i->siguiente){ 
            if(indice_act == indice_buscado){ //Cuando indice_act==indice_buscado, guarda el nodo
                nodo_encontrado = i;
                break;  // Salimos del bucle cuando encontramos la posición
            }
            indice_act++;
        }
    }
    
    return nodo_encontrado;
}
	
void liberar_nodo(pnodo nodo){
    if(nodo != NULL){
        delete nodo;
        nodo=NULL;
    }
}		
	
int main(){
	tlista Lista;
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
        cout<< "6. Mostrar cantidad de elementos" <<endl;
        cout<< "7. Buscar" <<endl;
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
                cant_elementos(Lista);
                break;
                
            case 7:
				int valor;
				cout<< "Ingrese numero a buscar" <<endl; cin>> valor;
				cout<< "Indice del numero buscado: " << buscar_indice(Lista,valor) <<endl;
				cout<< "Puntero con la direccion del numero buscado: " <<buscar_por_indice(Lista,buscar_indice(Lista,valor)) <<endl;
                break;
            case 0:
                cout<< "Saliendo..." <<endl;
                break;
                
            default:
                cout<< "Opción inválida." <<endl;
                break;
        }
    } while(op != 0);
	
}
