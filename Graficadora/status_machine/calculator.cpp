#include "calculator.h"

calculator::calculator() {
    vacio="";
    var.push_back("e");
    val.push_back("2.718281828");
    var.push_back("pi");
    val.push_back("3.141592653");
}

Estado calculator::gramatica(string &entrada) {
    actual = Estado::Inicial;
    // inicializamos el estado de nuestro automata
    size_t i = 0;
    parentesis = contador = 0;
    bool cadenaRechazada = false;//al iniciar la cadena es aceptada
    error_code = "";

    while (i < entrada.length() and !cadenaRechazada) {
        char simbolo = entrada[i];

        funcion = actual == Estado::q4 ? funcion+simbolo : vacio+simbolo;
        //operador ternario que cuenta las letras consecutivas
        //con esto se realizara un validador de las funciones
        //y guardar las posibles funciones
        //(ln, log, sin, con, tan)
        actual = simbolo == ')' and parentesis == 0 ? Estado::ERROR : actual;
        //obtiene el estado de error
        error_code = simbolo == ')' and parentesis == 0 ? "Parentesis erroneo." : error_code;
        //obtiene el tipo de error

        switch (actual) {
        case Estado::Inicial:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '+' or simbolo == '-') {
                //verifica suma o resta
                actual = Estado::q5;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '(' ) {
                // verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else {
                error_code = "El inicio de cadena es invalido";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q1:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(simbolo == '.') {
                //verifica punto decimal
                actual = Estado::q2;
            }else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '+' or simbolo == '-') {
                //verifica suma o resta
                actual = Estado::q5;
            } else if(simbolo == '*' or simbolo == '/' or simbolo == '%') {
                //verifica producto, divicion o modulo
                actual = Estado::q6;
            } else if(simbolo == '^') {
                //verifica la potencia
                actual = Estado::q7;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '!') {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q9;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else if(simbolo == ')') {
                //verifica parentesis de cierre
                actual = Estado::q12;
                parentesis--;
            } else {
                actual = Estado::ERROR;
            }
            break;
        case Estado::q2:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos(decimal)
                actual = Estado::q3;
            } else {
                error_code = "Faltan dijitos despues del punto";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q3:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q3;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '+' or simbolo == '-') {
                //verifica suma o resta
                actual = Estado::q5;
            } else if(simbolo == '*' or simbolo == '/' or simbolo == '%') {
                //verifica producto, divicion o modulo
                actual = Estado::q6;
            } else if(simbolo == '^') {
                //verifica la potencia
                actual = Estado::q7;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else if(simbolo == ')') {
                //verifica parentesis de cierre
                actual = Estado::q12;
                parentesis--;
            } else if(simbolo == '.') {
                error_code = "Solo es valido un punto decimal";
                actual = Estado::ERROR;
            } else {
                error_code = "Factorial no se aplica a flotantes";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q4:
            if(isalpha(simbolo) and !isfunction(funcion)) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '+' or simbolo == '-') {
                //verifica suma o resta
                actual = Estado::q5;
            } else if(simbolo == '*' or simbolo == '/' or simbolo == '%') {
                //verifica producto, divicion o modulo
                actual = Estado::q6;
            } else if(simbolo == '^') {
                //verifica la potencia
                actual = Estado::q7;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '!') {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q9;
            } else if(isfunction(funcion)) {
                //verifica fincon trogonometria o logaritmos
                actual = Estado::q10;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else if(simbolo == ')') {
                //verifica parentesis de cierre
                actual = Estado::q12;
                parentesis--;

            } else {
                error_code = "Falta un operador";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q5:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else {
                error_code = "Falta un operando";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q6:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else {
                error_code = "Falta un operando";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q7:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else {
                error_code = "Falta un operando";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q8:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '-') {
                //verifica caracteres si es raiz
                error_code = "El genativo no tiene raiz";
                actual = Estado::ERROR;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else {
                error_code = "Falta un operando";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q9:
            if(simbolo == '+' or simbolo == '-') {
                //verifica suma o resta
                actual = Estado::q5;
            } else if(simbolo == '*' or simbolo == '/' or simbolo == '%') {
                //verifica producto, divicion o modulo
                actual = Estado::q6;
            } else if(simbolo == '^') {
                //verifica la potencia
                actual = Estado::q7;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '!') {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q9;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else if(simbolo == ')') {
                //verifica parentesis de cierre
                actual = Estado::q12;
                parentesis--;

            } else {
                error_code = "Falta un operador";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q10:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else {
                error_code = "Falta un operando";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q11:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '+' or simbolo == '-') {
                //verifica suma o resta
                actual = Estado::q5;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else if(simbolo == ')') {
                //verifica parentesis de cierre
                error_code = "No puede haber parentesis vacio";
                actual = Estado::ERROR;
                parentesis--;
            } else {
                error_code = "El operador no es valido";
                actual = Estado::ERROR;
            }
            break;
        case Estado::q12:
            if(isdigit(simbolo)) {
                //isdigit() verifica caracteres numericos
                actual = Estado::q1;
            } else if(isalpha(simbolo) ) {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q4;
            } else if(simbolo == '+' or simbolo == '-') {
                //verifica suma o resta
                actual = Estado::q5;
            } else if(simbolo == '*' or simbolo == '/' or simbolo == '%') {
                //verifica producto, divicion o modulo
                actual = Estado::q6;
            } else if(simbolo == '^') {
                //verifica la potencia
                actual = Estado::q7;
            } else if(simbolo == '<' ) {
                //verifica caracteres si es raiz
                actual = Estado::q8;
            } else if(simbolo == '!') {
                //isalpha() verifica caracteres alfabeticos
                actual = Estado::q9;
            } else if(simbolo == '(' ) {
                //verifica parentesis de apertura
                actual = Estado::q11;
                parentesis++;
            } else if(simbolo == ')') {
                //verifica parentesis de cierre
                actual = Estado::q12;
                parentesis--;
            } else {
                error_code = "No se puede colocar el punto en esta posicion";
                actual = Estado::ERROR;
            }
            break;
        case Estado::ERROR:
            cadenaRechazada = true;
            break;
        }
        i++;
        contador++;
    }
    if(parentesis != 0 and error_code == "") {
        //puede dejar de leer una cadena al encotnrar un error
        //solo cargar este error, si no existe uno anterior
        error_code = "Parentesis incoerentes";
        actual = Estado::ERROR;
    }
    if(error_code == "" and !terminal(actual)) { actual = Estado::ERROR; }

    if(actual == Estado::ERROR) {
        for (size_t j=0;j<contador+2;j++) {
            cout << " ";
        }
        cout << "^~~~" << endl;
    }
    return actual;
}

bool calculator::isfunction(string fun) {
    if(fun == "ln" or fun == "log" or fun == "sin" or fun == "cos" or fun == "tan")
        return true;
    return false;
}

bool calculator::reservada(string palabra) {
    if(palabra == "e" or palabra == "pi" or palabra == "cls" or palabra == "break")
        return true;
    return false;
}

bool calculator::terminal(Estado e) {
    if(e == Estado::q1 or e == Estado::q3 or e == Estado::q4 or
            e == Estado::q9 or e == Estado::q12) {
        return true;
    }
    error_code = "El ultimo dato no es terminal";
    return false;
}

string calculator::variable(string &entrada) {
    actual = Estado::Inicial;
    variable_nueva = "";//vaciar la caja
    bool cadenaRechazada = false;//al iniciar la cadena es aceptada
    size_t i=0;
    string restante, resultado = entrada;

    while (i < entrada.length() and !cadenaRechazada) {
        char simbolo = entrada[i];

        switch (actual) {
        case Estado::Inicial:
            if(isalpha(simbolo)) {
                //verifica la variable
                actual = Estado::q1;
                variable_nueva += simbolo;
                resultado.erase(resultado.begin());
            } else {
                error_code = "Variable invalida";
                actual = Estado::ERROR;
                cadenaRechazada = true;
            }
            break;
        case Estado::q1:
            if(isalpha(simbolo)) {
                actual = Estado::q1;
                variable_nueva += simbolo;
                resultado.erase(resultado.begin());
            } else if(simbolo == '=') {
                actual = Estado::q2;
                i = entrada.length();
                resultado.erase(resultado.begin());
                //si cumple la condicion termina
            } else {
                error_code = "Variable invalida";
                actual = Estado::ERROR;
                cadenaRechazada = true;
            }
            break;
        }
        i++;
    }
    return resultado;
    //retorna la operacio asignada en la variable
    //si el estado final es
}

string calculator::asignacion(string entrada) {
    vector<string> postfijo;
    actual = Estado::Inicial;
    string resultado = variable(entrada), valor;
    size_t contador_variables=0;//cuenta si existe la variable
    //aqui guarda el resultado de la operacion
    if(actual == Estado::ERROR) {
        // esto detecta un error al asignar la variable
        return error_code;
    }
    if(reservada(variable_nueva)) {
        //impide que el usuario pueda manipular las constantes
        //o usar palabras reservadas
        return variable_nueva + " es una palabra reservada.";
    }
    if(isfunction(variable_nueva)) {
        return variable_nueva + " es una funcion.";
    }
    if(gramatica(resultado) != Estado::ERROR) {
        //si no genera error la gramatica...
        postfijo = infijo_a_postfijo(resultado);
        //convierte el resultado en notacion postfija
        buscar_variables(postfijo);
        //busco las variables y las sustituyo por su valor
        valor = analizar(postfijo);
        //analiza el postfijo y hace las operaciones
        //retorna el resultado de esas operaciones
        for(size_t i = 0; i < var.size(); i++) {
            if(variable_nueva == var[i]) {
                //si la variable ya existe modifica su valor
                val[i] = valor;//modifica el valor de la variable
                contador_variables++;
                break;
            }
        }
        if(contador_variables==0) {
            //si no existe la variable la agrega
            var.push_back(variable_nueva);//guarda la variable
            val.push_back(valor);//guarda el valor de la variable
        }
        return variable_nueva + " = "+ valor;
    } else {
        return error_code;
        //en caso de que no sea correcto, nos dara el error dado
    }
}

string calculator::asignacion2(string cadena) {
    bool contador_de_variables;
    vector<string> postfijo;
    string valor;
    if(gramatica(cadena) != Estado::ERROR) {
        //si no genera error la gramatica...
        postfijo = infijo_a_postfijo(cadena);
        //convierte el resultado en notacion postfija
        contador_de_variables = buscar_variables(postfijo);
        //busco las variables y las sustituyo por su valor
        //si no existe un valor para esa variable genera la funcion para graficar

        if(contador_de_variables) {
            //si hay una variable para graficar...
            for (int i = -250; i < 250; i++) {
                //recta(postfijo, grafica, to_string(i));
                grafica_final.push_back(analizar(recta(postfijo, grafica, to_string(i))));
                //sera una lista de puntos para la grafica
            }
            return "funcion: " + cadena;
        }else {
            valor = analizar(postfijo);
            //hace la operacion y retorna el valor...

            grafica_final.push_back(valor);
            //solo contendra un valor en el caso de no haber una variable para graficar

            return "funcion: " + valor;
        }
    } else {
        return error_code;
        //en caso de que no sea correcto, nos dara el error dado
    }
}

bool calculator::buscar_variables(vector<string> &postfijo) {
    bool existe = false;
    size_t total_varialbes = 0;
    if(var.empty()) {
        return false;
    }
    for(size_t i = 0; i < postfijo.size(); i++) {
        if(!isfunction(postfijo[i]) and isalpha(postfijo[i].front()) ) {
            //esto buscara las variables...
            existe = false;
            for(size_t j = 0; j < var.size(); j++) {
                //buscar dentro de las variables

                if(postfijo[i] == var[j]) {
                    //si la variable escrita esta en el vector...
                    postfijo[i] = atof(val[j].c_str()) == atoi(val[j].c_str()) ? to_string(atoi(val[j].c_str())) : val[j];
                    //el ternario analiza si es enteo o flotante y genera los decimales necesarios

                    //la variables se sustituira por su valor

                    existe = true;
                    //analizar si se encuentra el valor de la variable
                    //si no es asi, se graficara respecto a esa funcion
                    //si hay mas de uno que no contiene el valor, dar error

                }
            }
            if(!existe and !isfunction(postfijo[i]) and !reservada(postfijo[i])) {
                //al no tener variables existentes...
                //se agregaran a una lista

                if(total_varialbes > 0 and grafica == postfijo[i]) {
                    //total_variables inicia valiendo 0
                    //al obtener la primer variable no entra en este if
                    //al obtener la segunda variable revisa si es igual a la anterior
                    //si esto ocurre las variables son la misma
                    continue;
                }
                total_varialbes++;
                //si cuenta mas de una variable sin asignar no debe permitir
                //graficar la funcion
                //si no hay ni una variable sin asignar, solo graficara un punto
                //en el caso de que haya una sola variable sin asignar debe graficar...

                grafica = postfijo[i];
                //solo guardara la ultima, ya que solo nos importa el caso donde hay unsa sola variable
            }
        }
    }
    if(total_varialbes == 1) {
        return true;
    }
    return false;
}


vector<string> calculator::recta(vector<string> postfijo, string variable_, string constante) {
    for(size_t i = 0; i < postfijo.size(); i++) {
        if(postfijo[i] == variable_) {
            postfijo[i] = constante;
        }
    }
    return postfijo;
}
