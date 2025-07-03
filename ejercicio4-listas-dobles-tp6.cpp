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

void MostrarMayorYMenor(tlista lista) {
	if (lista.inicio == NULL) {
		cout << "La lista está vacía." << endl;
		return;
	}
	
	int mayor = lista.inicio->dato;
	int menor = lista.inicio->dato;
	
	pnodo actual = lista.inicio->sig;
	while (actual != NULL) {
		if (actual->dato > mayor)
			mayor = actual->dato;
		if (actual->dato < menor)
			menor = actual->dato;
		
		actual = actual->sig;
	}
	
	cout << "Mayor valor en la lista: " << mayor << endl;
	cout << "Menor valor en la lista: " << menor << endl;
}

int main() {
	tlista miLista;
	pnodo nuevoNodo;
	
	IniciarLista(miLista);
	
	int valores[] = {15, 3, 27, 8, 10};
	int n = sizeof(valores) / sizeof(valores[0]);
	
	for (int i = 0; i < n; i++) {
		CrearNodo(nuevoNodo, valores[i]);
		AgregarFinal(miLista, nuevoNodo);
	}
	
	MostrarMayorYMenor(miLista);
	
	return 0;
}
