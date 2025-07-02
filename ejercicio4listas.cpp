#include <iostream>
using namespace std;

// Nodo base
typedef struct nodo* pnodo;
typedef struct nodo {
	int dato;
	pnodo siguiente;
};

// Iniciar pila
void iniciar_pila(pnodo &pila) {
	pila = NULL;
}

// Push (apilar)
void push(pnodo &pila, int valor) {
	pnodo nuevo = new nodo;
	nuevo->dato = valor;
	nuevo->siguiente = pila;
	pila = nuevo;
}

// Pop (desapilar)
int pop(pnodo &pila) {
	if (pila == NULL) {
		cout << "Pila vacía" << endl;
		return -1; // Valor de error
	} else {
		int valor = pila->dato;
		pnodo temp = pila;
		pila = pila->siguiente;
		delete temp;
		return valor;
	}
}

// Mostrar pila
void mostrar_pila(pnodo pila) {
	cout << "Pila: ";
	while (pila != NULL) {
		cout << pila->dato << " -> ";
		pila = pila->siguiente;
	}
	cout << "NULL" << endl;
}
// Cola con inicio, fin y contador
typedef struct cola {
	pnodo inicio;
	pnodo fin;
	int contador;
} tcola;

// Iniciar cola
void iniciar_cola(tcola &c) {
	c.inicio = NULL;
	c.fin = NULL;
	c.contador = 0;
}

// Encolar (agregar al final)
void encolar(tcola &c, int valor) {
	pnodo nuevo = new nodo;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
	
	if (c.inicio == NULL) {
		c.inicio = nuevo;
	} else {
		c.fin->siguiente = nuevo;
	}
	c.fin = nuevo;
	c.contador++;
}

// Desencolar (eliminar del inicio)
int desencolar(tcola &c) {
	if (c.inicio == NULL) {
		cout << "Cola vacía" << endl;
		return -1;
	}
	
	int valor = c.inicio->dato;
	pnodo temp = c.inicio;
	c.inicio = c.inicio->siguiente;
	delete temp;
	
	if (c.inicio == NULL) {
		c.fin = NULL;
	}
	
	c.contador--;
	return valor;
}

// Mostrar cola
void mostrar_cola(tcola c) {
	cout << "Cola: ";
	pnodo i = c.inicio;
	while (i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
	cout << "Elementos en la cola: " << c.contador << endl;
}
int main() {
	// PILA
	pnodo pila;
	iniciar_pila(pila);
	
	push(pila, 10);
	push(pila, 20);
	push(pila, 30);
	mostrar_pila(pila);
	
	cout << "Elemento desapilado: " << pop(pila) << endl;
	mostrar_pila(pila);
	
	// COLA
	tcola miCola;
	iniciar_cola(miCola);
	
	encolar(miCola, 5);
	encolar(miCola, 15);
	encolar(miCola, 25);
	mostrar_cola(miCola);
	
	cout << "Elemento desencolado: " << desencolar(miCola) << endl;
	mostrar_cola(miCola);
	
	return 0;
}
