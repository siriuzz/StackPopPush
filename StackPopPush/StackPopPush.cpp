#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include "StackPopPush.h"

using namespace std;

//estructura nodo
struct Nodo
{
	int dato;
	Nodo* siguiente;
};

//funcion para agregar dato a la pila
void agregarPila(Nodo*& pila, int n) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

//funcion para eliminar dato de la pila
void sacarPila(Nodo*& pila, int& n) {
	Nodo* aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

string ValidarNumero(string str) {
	bool notNum = false;
	int i = 0;
	while ((str[i] != '\0') && (notNum != true)) { //'\0' es el character que marca el final del string	
		if (isdigit(str[i]) == false) {
			str = "";
			notNum = true;
			break;
		}
		i++;
	}
	return str; //devuelve un str igual si no se encontraron letras
}

int main()
{
	int dato; // dato que se agrega a la pila en la opcion 1
	string strDato; // valor dato antes de validarse en la opcion 1
	Nodo* pila = NULL; //valor inicial de la pila
	string option = ""; //la opcion seleccionada, antes de validarse
	int intOption = 0; //opcion convertida a int para comparaciones
	int counter = 0; //contiene la cantidad de nodos dentro del stack (sin contar NULL)

	while (intOption != 4) {
		cout << "Que operacion desea realizar?\n(1) Push()\n(2) Pop()\n(3) Mostrar datos\n(4) Salir\n>>";
		cin >> option;

		//validar opcion insertada
		if (ValidarNumero(option) != option) {
			cout << "La opcion seleccionada no es valida" << endl;
			system("PAUSE");
			system("CLS");
			continue;
		}

		//se convierte a numero luego de validar
		intOption = stoi(option);

		//opciones del menu
		switch (intOption) {
		case 1: //opcion 1: Push()
			cout << "Inserte un numero: ";
			cin >> strDato;

			if (ValidarNumero(strDato) != strDato) {
				cout << "Solo se permite insertar numero al stack, intente de nuevo" << endl;

			}
			else {
				dato = stoi(strDato);
				agregarPila(pila, dato);
				counter++;
			}
			break;

		case 2: //opcion 2: Pop();
			if (pila != NULL) {
				sacarPila(pila,		);

				cout << "Se elimino el nodo correctamente" << endl;

				counter--;
			}
			else {
				cout << "La pila esta vacia" << endl;
			}
			break;

		case 3: //opcion 3: Mostrar datos
			Nodo * aux; //nodo auxiliar para iterar
			aux = pila;

			if (pila != NULL) {
				cout << "Los datos dentro del stack son:\n";
				for (int i = 0; i < counter; i++) {//itera por cada dato de cada nodo
					cout << "----------------\n";
					cout << "> " << aux->dato << endl;
					aux = aux->siguiente;

				}
				cout << "----------------\n";
			}
			else {
				cout << "La pila esta vacia" << endl;
			}

			break;
		case 4: //opcion 4: Salir
			exit(0);
			break;
		default: //caso en el que se inserte un numero que no se encuentre en el menu
			cout << "Numero insertado no se encuentra en el menu, intente de nuevo" << endl;
			break;
		}

		system("PAUSE");
		system("CLS");
	}
}

