#include <iostream>
using namespace std;

// Definición del nodo
typedef struct nodo* pnodo;

typedef struct nodo {
	int dato;
	pnodo siguiente;
};

// Iniciar la lista
void iniciar_lista(pnodo &lista) {
	lista = NULL;
}

// Crear nodo
void crear_nodo(pnodo &nuevo, int valor) {
	nuevo = new nodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
	} else {
		cout << "Memoria insuficiente" << endl;
	}
}

// Agregar al final
void agregar_final(pnodo &lista, pnodo nuevo) {
	if (lista == NULL) {
		lista = nuevo;
	} else {
		pnodo i = lista;
		while (i->siguiente != NULL)
			i = i->siguiente;
		i->siguiente = nuevo;
	}
}

// Mostrar la lista
void mostrar_lista(pnodo lista) {
	pnodo i = lista;
	while (i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
}
// Ordenar la lista usando selección
void ordenar_por_seleccion(pnodo &lista) {
	for (pnodo i = lista; i != NULL; i = i->siguiente) {
		pnodo min = i;
		for (pnodo j = i->siguiente; j != NULL; j = j->siguiente) {
			if (j->dato < min->dato) {
				min = j;
			}
		}
		// Intercambiar datos
		if (min != i) {
			int temp = i->dato;
			i->dato = min->dato;
			min->dato = temp;
		}
	}
}
// Combinar dos listas (sin importar el orden)
void combinar_listas_desordenadas(pnodo &resultado, pnodo l1, pnodo l2) {
	pnodo aux;
	
	while (l1 != NULL) {
		crear_nodo(aux, l1->dato);
		agregar_final(resultado, aux);
		l1 = l1->siguiente;
	}
	
	while (l2 != NULL) {
		crear_nodo(aux, l2->dato);
		agregar_final(resultado, aux);
		l2 = l2->siguiente;
	}
}
// Combinar dos listas ordenadas en una lista ordenada final
void combinar_listas_ordenadas(pnodo &resultado, pnodo l1, pnodo l2) {
	pnodo aux;
	
	while (l1 != NULL && l2 != NULL) {
		if (l1->dato < l2->dato) {
			crear_nodo(aux, l1->dato);
			l1 = l1->siguiente;
		} else {
			crear_nodo(aux, l2->dato);
			l2 = l2->siguiente;
		}
		agregar_final(resultado, aux);
	}
	
	while (l1 != NULL) {
		crear_nodo(aux, l1->dato);
		agregar_final(resultado, aux);
		l1 = l1->siguiente;
	}
	
	while (l2 != NULL) {
		crear_nodo(aux, l2->dato);
		agregar_final(resultado, aux);
		l2 = l2->siguiente;
	}
}
int main() {
	pnodo lista1, lista2, lista_comb;
	
	iniciar_lista(lista1);
	iniciar_lista(lista2);
	iniciar_lista(lista_comb);
	
	pnodo nuevo;
	
	// Cargar lista 1
	crear_nodo(nuevo, 4); agregar_final(lista1, nuevo);
	crear_nodo(nuevo, 2); agregar_final(lista1, nuevo);
	crear_nodo(nuevo, 9); agregar_final(lista1, nuevo);
	
	// Cargar lista 2
	crear_nodo(nuevo, 5); agregar_final(lista2, nuevo);
	crear_nodo(nuevo, 1); agregar_final(lista2, nuevo);
	crear_nodo(nuevo, 8); agregar_final(lista2, nuevo);
	
	cout << "Lista 1: "; mostrar_lista(lista1);
	cout << "Lista 2: "; mostrar_lista(lista2);
	
	// Ordenar ambas listas antes de combinar con orden
	ordenar_por_seleccion(lista1);
	ordenar_por_seleccion(lista2);
	
	cout << "Lista 1 ordenada: "; mostrar_lista(lista1);
	cout << "Lista 2 ordenada: "; mostrar_lista(lista2);
	
	// Combinar con orden
	combinar_listas_ordenadas(lista_comb, lista1, lista2);
	cout << "Lista combinada ordenada: "; mostrar_lista(lista_comb);
	
	return 0;
}
