#include<iostream>
using namespace std;
//iniciando 
typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista)
{
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
	nuevo = new tnodo;
	if(nuevo != NULL)
	{
		nuevo -> dato = valor;
		nuevo -> sig = NULL;
		nuevo -> ant = NULL;
	}
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo){
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}
	
	void QuitarInicio(tlista &lista) {
		if (lista.inicio == NULL) return;  
		
		pnodo aux = lista.inicio;           
		if (lista.inicio == lista.fin) { 
			lista.inicio = NULL;
			lista.fin = NULL;
		} else {
			lista.inicio = aux->sig;       
			lista.inicio->ant = NULL;       
		}
		
		delete aux;                        
	}
	
	void QuitarFinal(tlista &lista) {
		if (lista.fin == NULL) return;   
		
		pnodo aux = lista.fin;             
		
		if (lista.inicio == lista.fin) {  
			lista.inicio = NULL;
			lista.fin = NULL;
		} else {
			lista.fin = aux->ant;          
			lista.fin->sig = NULL;   
		}
		
		delete aux;                     
	}
	
	int main(){
		
		return 0;
	}
		
