#include "operar.h"


Operar::Operar() {

}

string Operar::analizar(vector<string> entrada) {
    while (entrada.size() > 1) {
        for (size_t i = 0; i < entrada.size(); i++) {
            if(es_operador(entrada[i])) {
                //usa la herencia de In_to_post

                if(es_unario(entrada[i])) {
                    entrada[i-1] = resultado(entrada[i], entrada[i-1]);
                    //entra el operador y el operando
                    // inc ax
                    entrada.erase(entrada.begin()+i);

                } else {
                    entrada[i-2] = resultado(entrada[i], entrada[i-2], entrada[i-1]);
                    //entra epoerador, operando, operando
                    // mov ax, bx
                    entrada.erase(entrada.begin()+i);
                    entrada.erase(entrada.begin()+i-1);
                }
                break;


            }
        }
    }
    return entrada[0].c_str();
}

bool Operar::es_unario(string entrada) {
    if(entrada == "<" or entrada == "!" or entrada == "sin" or entrada == "cos" or entrada == "tan" or entrada == "ln" or entrada == "log") {
        return true;
    }
    //si el operador no es unario es binario
    return false;
}

string Operar::resultado(string op, string value) {
    if(op == "<") {
        return raiz(value);
    } else if(op == "!") {
        return factorial(value);
    } else if(op == "sin") {
        return seno(value);
    } else if(op == "cos") {
        return coseno(value);
    } else if(op == "tan") {
        return tangente(value);
    } else if(op == "ln") {
        return ln(value);
    } else if(op == "log") {
        return logarimo(value);
    }
    return "0";
}

string Operar::resultado(string op, string value1, string value2) {
    if(op == "+") {
        return suma(value1,value2);
    } else if(op == "-") {
        return resta(value1,value2);
    } else if(op == "*") {
        return multiplicacion(value1,value2);
    } else if(op == "/") {
        return divicion(value1,value2);
    } else if(op == "%") {
        return modulo(value1,value2);
    } else if(op == "^") {
        return potencia(value1,value2);
    }
    return "0";
}

string Operar::suma(string a, string b) {
    return to_string(atof(a.c_str()) + atof(b.c_str()));
}

string Operar::resta(string a, string b) {
    return to_string(atof(a.c_str()) - atof(b.c_str()));
}

string Operar::multiplicacion(string a, string b) {
    return to_string(atof(a.c_str()) * atof(b.c_str()));
}

string Operar::divicion(string a, string b) {
    return to_string(atof(a.c_str()) / atof(b.c_str()));
}

string Operar::modulo(string a, string b) {
    int c, d;
    c = atoi(a.c_str());
    d = atoi(b.c_str());
    return to_string(c % d);
}

string Operar::potencia(string a, string b) {
    return to_string(pow(atof(a.c_str()), atof(b.c_str())));
}

string Operar::raiz(string a) {
    return to_string(sqrt(atof(a.c_str())));
}

string Operar::factorial(string a) {
    int f = atoi(a.c_str());
    int i = f;
    while (i > 1) {
        f *= --i;
    }
    return to_string(f);
}

string Operar::seno(string a) {
    return to_string(sin(atof(a.c_str())*PI/180));
}

string Operar::coseno(string a) {
    return to_string(cos(atof(a.c_str())*PI/180));
}

string Operar::tangente(string a) {
    return to_string(tan(atof(a.c_str())*PI/180));
}

string Operar::logarimo(string a) {
    return to_string(log10(atof(a.c_str())));
}

string Operar::ln(string a) {
    return to_string(log(atof(a.c_str())));
}
