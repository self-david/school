#include "in_to_post.h"

In_to_post::In_to_post() {

}

vector<string> In_to_post::convertir(string entrada) {
    ///separa la cadena en operadores y operandos
    string cadena;
    vector<string> v;
    contador = 0;

    for (size_t i = 0; i < entrada.length(); i++) {
        if(entrada[i] == '+' or entrada[i] == '-' or entrada[i] == '*' or entrada[i] == '/' or entrada[i] == '!' or
            entrada[i] == '%' or entrada[i] == '^' or entrada[i] == '<' or entrada[i] == '(' or entrada[i] == ')') {
            //si es un operador...
            if(cadena.size() > 0) {
                //si hay un operando lo agrega al vector
                v.push_back(cadena);
                //despues limpia la cadena
                cadena.resize(0);
            }
            cadena = entrada[i];
            //guarda el operador
            v.push_back(cadena);
            //despues lo agrega el vector
            cadena.resize(0);
            //y limpia la cadena
            contador = 0;
        } else {
            //si es un operando o un operador de mas de un caracter...
            if(contador>0 and isdigit(entrada[i-1]) and isalpha(entrada[i])) {
                v.push_back(cadena);
                cadena.resize(0);
            }
            cadena.resize(cadena.size());
            //agrega un espacio
            cadena.push_back(entrada[i]);
            //empuja el operando al final
            if(cadena == "ln" or cadena == "log" or cadena == "sin" or cadena == "cos" or cadena == "tan") {
                //si resulta que la cadena es un operador
                v.push_back(cadena);
                //las empuja al vector, ya que estos son operadores y no operando
                cadena.resize(0);
            }
            contador++;
        }

    }
    if(cadena.size() > 0) {
        //si al terminar de ver la cadena quedo un operando en la variable la recoge
        //y la empuja al vector
        v.push_back(cadena);
    }
    return v;
}

int In_to_post::precedencia(string op1) {
    int valorOp1 = 0;

    if(op1 == "(") { valorOp1 = 0; }
    else if(op1 == "+" or op1 == "-") { valorOp1=1; }
    else if(op1 == "*" or op1 == "/" or op1 == "%") { valorOp1=2; }
    else if(op1 == "^" or op1 == "<" or op1 == "!") { valorOp1=3; }
    else if(op1 == "ln" or op1 == "log" or op1 == "sin" or op1 == "cos" or op1 == "tan") { valorOp1=4; }

    return  valorOp1;
}

bool In_to_post::es_operador(string c) {
    if(c=="("||c==")"||c=="+"||c=="-"||c=="*"||c=="/"||c=="%"||c=="^"||c=="<"||c=="!"||c=="ln"||c=="log"||c=="sin"||c=="cos"||c=="tan"){
        return true;
    }
    return false;
}

vector<string> In_to_post::infijo_a_postfijo(string entrada) {
    string aux;
    vector<string> infijo = convertir(entrada);
    //creo mi vector con string ya seccionados para un facil manejo
    limpiar();
    //limpia la cola postfija para reutilizarla

    if(infijo[0] == "+" or infijo[0] == "-") {
        //esto convirte el + ó - en parte del operando
        //infijo[1] = infijo[0] + infijo[1];
        //infijo.erase(infijo.begin());
        infijo.insert(infijo.begin(), "0");
    }

    for (size_t i = 0;i<infijo.size(); i++) {


        if(!es_operador(infijo[i])) {
            //si es un operando lo agrega a la cola de salida
            //si entra una variable debe asignarle su valor
            //si esa variable no contiene algun valor avisar al usuario

            cola.resize(cola.size());
            cola.push_back(infijo[i]);
            if(i > 0 and isalpha(infijo[i].front()) and isdigit(infijo[i-1].front())) {
                pila.push("*");
                //s es un caracter,
            }
        } else {
            //si es un operador...

            /***************************************************************/
            //CASOS EPECIALES
            if(i > 0 and infijo[i] == "(" and (!es_operador(infijo[i-1]) or infijo[i-1] == ")") ) {
                //casos cuando entra un parentesis
                // revisa si el anteriro fue un operador
                //ejemplo: 5(4)
                //no existe la multiplicacion, pero la crea en momento
                //esto pasa solo cuando no existe un operador
                //con ecepcion de ')' ya que tambien puede existir...
                // (4)(5) que genera un producto
                //al inicio no puede haber una operador por eso (i != 0)
                pila.push("*");
            }

            if(i > 0 and infijo[i] == "(" and infijo[i-1] == "!") {
                //casos cuando hay un factorial en el anterior
                cola.resize(cola.size());
                cola.push_back(pila.top());
                pila.pop();
                pila.push("*");
            }

            if(i > 0 and (infijo[i] == "+" or infijo[i] == "-") and infijo[i-1] == "(") {
                //esto convirte el + ó - que esta despues de un '(' en parte del operando siguiente
                //infijo[i+1] = infijo[i] + infijo[i+1];
                //infijo.erase(infijo.begin()+i);
                infijo.insert(infijo.begin()+i, "0");
                i--;
                continue;
            }
            /***************************************************************/

            if(pila.empty()) {
                if(infijo[i] != ")") {
                    //agregar siempre que no sea parentesis de cierre
                    //si la pila esta vacia lo agrega
                    pila.push(infijo[i]);
                }
            } else {
                if(infijo[i] == ")") {
                    //si encuentro un parentesis de cierre...
                    while (!pila.empty() and pila.top() != "(") {
                        //mientras que no se encuentre el parentesis de apertura
                        //o no este vacia la pila
                        aux = pila.top();
                        //guardo el tope
                        pila.pop();
                        //libero el tope
                        cola.resize(cola.size());
                        cola.push_back(aux);
                    }
                    if(!pila.empty()) {
                        //si la pila no esta vacia entonces...
                        //tiene '(' en su tope, y tiene que ser eliminado
                        pila.pop();
                    }

                    /********************************************************************/
                    if(infijo.size() > i+1 and precedencia(infijo[i+1]) == 4) {
                        //analiza si el operador siguiente es  un logarimo o una trigonometrica
                        pila.push("*");
                    }
                    if(infijo.size() > i+1 and !es_operador(infijo[i+1])) {
                        //si existe el sigueinte y...
                        //si el sigueinte valor es un operando
                        pila.push("*");
                    }

                    /*******************************************************************/

                } else if(precedencia(infijo[i]) == precedencia(pila.top())) {
                    if(infijo[i] == "(") {
                        //si encuentra un parentesis de apertura solo salta al siguente
                        //ya que el anterior tambien fue otro parentesis
                        pila.push(infijo[i]);
                        //siempre se debe empujar a la pila para mantener los bloques
                        continue;
                    }
                    //analizar antes de agregar

                    //si el operador es igual hacer pop luego push
                    aux = pila.top();
                    //guardo el tope de la pila
                    pila.pop();
                    //libero el tope
                    pila.push(infijo[i]);
                    //guardo el nuevo operado
                    cola.resize(cola.size());
                    cola.push_back(aux);
                    //recupero el operador anterior
                } else if(precedencia(infijo[i]) > precedencia(pila.top())) {
                    //agregar al tope
                    pila.push(infijo[i]);
                } else if(precedencia(infijo[i]) < precedencia(pila.top())) {
                    //sacar todos

                    while (infijo[i] != "(" and !pila.empty() and pila.top() != "(" ) {

                        cola.resize(cola.size());
                        cola.push_back(pila.top());
                        pila.pop();
                    }
                    if(infijo[i] != "(" and !pila.empty()) {
                        //si la pila no esta vacia entonces...
                        //tiene '(' en su tope, y tiene que ser eliminado
                        pila.pop();
                    }
                    pila.push(infijo[i]);

                }

            }
        }
    }
    while (!pila.empty()) {
        cola.resize(cola.size());
        cola.push_back(pila.top());
        pila.pop();
    }
    size = cola.size();
    return cola;
}

void In_to_post::limpiar() {
    cola.resize(0);
    while (!pila.empty()) {
        pila.pop();
    }
}
