#include <stdio.h>
#include <stdlib.h>

// Definición del nodo (a)
typedef struct tnodo {
	int dato;
	struct tnodo *sig;
	struct tnodo *ant;
} tnodo;

typedef tnodo *pnodo;

// Definición de la lista doble
typedef struct {
	pnodo inicio;
	pnodo fin;
} tlista;

void inicializarLista(tlista *lista) {
	lista->inicio = NULL;
	lista->fin = NULL;
}

pnodo crearNodo(int valor) {
	pnodo nuevo = (pnodo)malloc(sizeof(tnodo));
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
	return nuevo;
}

void insertarInicio(tlista *lista, int valor) {
	pnodo nuevo = crearNodo(valor);
	if (nuevo == NULL) return;
	
	nuevo->sig = lista->inicio;
	if (lista->inicio != NULL)
		lista->inicio->ant = nuevo;
	else
		lista->fin = nuevo;  // Lista estaba vacía
	
	lista->inicio = nuevo;
}


void insertarFinal(tlista *lista, int valor) {
	pnodo nuevo = crearNodo(valor);
	if (nuevo == NULL) return;
	
	nuevo->ant = lista->fin;
	if (lista->fin != NULL)
		lista->fin->sig = nuevo;
	else
		lista->inicio = nuevo;  // Lista estaba vacía
	
	lista->fin = nuevo;
}

void insertarOrdenado(tlista *lista, int valor) {
	pnodo nuevo = crearNodo(valor);
	if (nuevo == NULL) return;
	
	if (lista->inicio == NULL || valor < lista->inicio->dato) {
		insertarInicio(lista, valor);
		return;
	}
	
	pnodo actual = lista->inicio;
	while (actual != NULL && valor > actual->dato)
		actual = actual->sig;
	
	if (actual == NULL) {
		insertarFinal(lista, valor);
	} else {
		nuevo->sig = actual;
		nuevo->ant = actual->ant;
		if (actual->ant)
			actual->ant->sig = nuevo;
		actual->ant = nuevo;
	}
}

void extraerInicio(tlista *lista) {
	if (lista->inicio == NULL) return;
	
	pnodo aux = lista->inicio;
	lista->inicio = aux->sig;
	if (lista->inicio)
		lista->inicio->ant = NULL;
	else
		lista->fin = NULL;  // Lista quedó vacía
	
	free(aux);
}

void extraerFinal(tlista *lista) {
	if (lista->fin == NULL) return;
	
	pnodo aux = lista->fin;
	lista->fin = aux->ant;
	if (lista->fin)
		lista->fin->sig = NULL;
	else
		lista->inicio = NULL;  // Lista quedó vacía
	
	free(aux);
}
void extraerValor(tlista *lista, int valor) {
	pnodo actual = lista->inicio;
	
	while (actual != NULL && actual->dato != valor)
		actual = actual->sig;
	
	if (actual == NULL) return; // No se encontró el valor
	
	if (actual->ant)
		actual->ant->sig = actual->sig;
	else
		lista->inicio = actual->sig;
	
	if (actual->sig)
		actual->sig->ant = actual->ant;
	else
		lista->fin = actual->ant;
	
	free(actual);
}

pnodo buscar(tlista lista, int valor) {
	pnodo actual = lista.inicio;
	while (actual != NULL) {
		if (actual->dato == valor)
			return actual;
		actual = actual->sig;
	}
	return NULL;
}

void mostrarLista(tlista lista) {
	pnodo actual = lista.inicio;
	printf("Lista: ");
	while (actual != NULL) {
		printf("%d <-> ", actual->dato);
		actual = actual->sig;
	}
	printf("NULL\n");
}





int main() {
	tlista miLista;
	inicializarLista(&miLista);
	
	insertarOrdenado(&miLista, 10);
	insertarOrdenado(&miLista, 5);
	insertarOrdenado(&miLista, 20);
	insertarInicio(&miLista, 2);
	insertarFinal(&miLista, 25);
	
	mostrarLista(miLista);
	
	extraerInicio(&miLista);
	extraerFinal(&miLista);
	extraerValor(&miLista, 10);
	
	mostrarLista(miLista);
	
	pnodo encontrado = buscar(miLista, 5);
	if (encontrado != NULL)
		printf("Valor %d encontrado.\n", encontrado->dato);
	else
		printf("Valor no encontrado.\n");
	
	return 0;
}
