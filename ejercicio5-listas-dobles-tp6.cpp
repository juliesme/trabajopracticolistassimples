#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista {
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista) {
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}

void MostrarLista(tlista lista) {
	pnodo actual = lista.inicio;
	while (actual != NULL) {
		cout << actual->dato << " ";
		actual = actual->sig;
	}
	cout << endl;
}

void EliminarMultiplosDe3(tlista &lista) {
	pnodo actual = lista.inicio;
	
	while (actual != NULL) {
		pnodo siguiente = actual->sig;
		
		if (actual->dato % 3 == 0) {
			// Desconectar nodo actual
			if (actual->ant != NULL)
				actual->ant->sig = actual->sig;
			else
				lista.inicio = actual->sig;
			
			if (actual->sig != NULL)
				actual->sig->ant = actual->ant;
			else
				lista.fin = actual->ant;
			
			delete actual;
		}
		
		actual = siguiente;
	}
}

int main() {
	tlista miLista;
	pnodo nodo;
	
	IniciarLista(miLista);
	
	int valores[] = {3, 5, 6, 7, 9, 10, 12};
	int n = sizeof(valores) / sizeof(valores[0]);
	
	for (int i = 0; i < n; i++) {
		CrearNodo(nodo, valores[i]);
		AgregarFinal(miLista, nodo);
	}
	
	cout << "Lista original: ";
	MostrarLista(miLista);
	
	EliminarMultiplosDe3(miLista);
	
	cout << "Lista actualizada (sin múltiplos de 3): ";
	MostrarLista(miLista);
	
	return 0;
}
