#include <iostream>
#include <limits> // Para usar INT_MAX

using namespace std;

// Definici�n del nodo
typedef struct tnodo* pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

// Iniciar lista
void iniciar_lista(pnodo &lista) {
	lista = NULL;
}

// Crear un nuevo nodoooo help 
void crear_nodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
	} else {
		cout << "Memoria insuficiente" << endl;
	}
}

// Agregar al inicio
void agregar_inicio(pnodo &lista, pnodo nuevo) {
	nuevo->siguiente = lista;
	lista = nuevo;
}

// Mostrar la lista
void mostrar_lista(pnodo lista) {
	if (lista == NULL) {
		cout << "Lista vac�a." << endl;
	} else {
		pnodo i = lista;
		while (i != NULL) {
			cout << i->dato << " -> ";
			i = i->siguiente;
		}
		cout << "NULL" << endl;
	}
}

// Funci�n m�nimo e: devuelvee el menor valor de una lista desordenada.
int minimo(pnodo lista) {
	if (lista == NULL) {
		cout << "La lista est� vac�a." << endl;
		return -1; // Valor de error
	}
	
	int minValor = numeric_limits<int>::max();
	pnodo i = lista;
	
	while (i != NULL) {
		if (i->dato < minValor) {
			minValor = i->dato;
		}
		i = i->siguiente;
	}
	
	return minValor;
}

int main() {
	pnodo lista;
	iniciar_lista(lista);
	
	// Crear y agregar nodos
	pnodo nuevo;
	
	crear_nodo(nuevo, 10);
	agregar_inicio(lista, nuevo);
	
	crear_nodo(nuevo, 5);
	agregar_inicio(lista, nuevo);
	
	crear_nodo(nuevo, 12);
	agregar_inicio(lista, nuevo);
	
	crear_nodo(nuevo, 1);
	agregar_inicio(lista, nuevo);
	
	cout << "Lista: ";
	mostrar_lista(lista);
	
	int menor = minimo(lista);
	cout << "El valor m�nimo es: " << menor << endl;
	
	return 0;
}







