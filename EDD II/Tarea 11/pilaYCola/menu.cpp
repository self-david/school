#include "menu.h"
#include <string.h>

using namespace std;

Menu::Menu() {
 string continue_, operation;
 do{
 cout << "\t\t\t\t.:MENU:." << endl << endl
 << "Introduce una operacion infija: ";
 getline(cin, operation);
 converter(operation);/*convierte operacion infija a posfija*/
 cout << endl << "Desea introducir otra operacion: S/N" << endl;
 getline(cin, continue_);
 cout << endl << endl;
 } while(continue_ == "S" or continue_ == "s");
}

void Menu::converter(const string &infija) {
// int count = 0; ///con esto vere el inicio y fin de los parentesis
 Stack<char> pila;
 Queue<char> cola;
 for (size_t i = 0; i < infija.size(); i++) {
 cola.enqueue(infija.c_str()[i]);/*mete todos los datos en la cola*/
 }
 while (!cola.empty()) {
 /*mentras haya algun dato*/
 if(operatorValid(cola.getFront())) {
 /*si es un operador*/
 if(precedencia(cola.getFront()) == 4){
 /*insertar en pila*/
 pila.push(cola.getFront());
 }
 if(precedencia(cola.getFront()) == 5) {
 while (!pila.isEmpty() and pila.getTop() != '(') {
 /*extraer elemento de la pila y mostrarlo*/
 cout << pila.pop();
 }
 if(pila.getTop() == '(') {
 /*sacarlo de la pila pero sin mostrarlo*/
 pila.pop();
 }
 }
 if(precedencia(cola.getFront()) < 4) {
 /*si es un operador*/
 while(!pila.isEmpty() and precedencia(pila.getTop()) >=
precedencia(cola.getFront()) and precedencia(pila.getTop() != 4)) {
 /*mientras que la pila no este vacia y su tope tenga una precedencia
mayor*/
 /*sacar el untilo elemento y mostrarlo*/
 cout << pila.pop();
 }
 pila.push(cola.getFront());
 }
 } else {
 cout << cola.getFront();
 }
 cola.dequeue();
 }
 while (!pila.isEmpty()) {
 cout << pila.pop();
 }
}

bool Menu::operatorValid(const char &data) {
 char operators[8] = "+-*/^()";
 for (size_t i = 0; i < 7; i++) {
 if(operators[i] == data) {
 return true;
 }
 }
 return false;
}

int Menu::precedencia(const char &operator_) {
 switch (operator_) {
 case '+':
 case '-': return 1;
 case '*':
 case '/': return 2;
 case '^': return 3;
 case '(': return 4;
 case ')': return 5;
 }
 return 0;
}
