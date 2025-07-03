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
		cout << actual->dato;
		actual = actual->sig;
	}
	cout << endl;
}

void DecimalABinario(int decimal, tlista &lista) {
	IniciarLista(lista);
	if (decimal == 0) {
		pnodo nodo;
		CrearNodo(nodo, 0);
		AgregarFinal(lista, nodo);
		return;
	}
	
	while (decimal > 0) {
		int residuo = decimal % 2;
		pnodo nodo;
		CrearNodo(nodo, residuo);
		AgregarFinal(lista, nodo);
		decimal = decimal / 2;
	}
}

int main() {
	int numero;
	tlista listaBinaria;
	
	cout << "Ingrese un número decimal: ";
	cin >> numero;
	
	DecimalABinario(numero, listaBinaria);
	
	cout << "Número en binario: ";
	MostrarLista(listaBinaria);
	
	return 0;
}
