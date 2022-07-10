//
//  list.cpp
//  Estrucutra de datos
//
//  Created by <David gutierrez alvarez> on 24/01/2019.
///IMPLEMENTACION
#include "list.h"
//#inclde "listException"///excepcion

using namespace std;


template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValidPos(const int &position) {
    if(position < 0 or position > last) {
        return false;
    }
    return true;
}/*Completo*/


template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE> &l) {
    int i(0);

    while(i <= l.last) {
        this->data[i] = l.data[i];
        i++;
    }
    this->last = l.last;
    return *this;
}/*Complet*/

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List() : last(-1) {
    cout << "mames";
}/*Completo*/

//template <class T, int ARRAYSIZE>
//List<T, ARRAYSIZE>::List(const List &l) {
//    copyAll(l);
//    return this;
//}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty() {
    return last == -1;
}/*Completo*/

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull() {
    return last == ARRAYSIZE-1;
}/*Completo*/

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertData(const int &position, const T &e) {
    if(isFull()) {
//      throw listException("lista llena, InsertData");
        cout << "lista llena, insertData" << endl;
    }

    if(position != -1 and !isValidPos(position)) {
//        throw listException("posicion invalida, insertData");
        cout << "posicion invalida, insertData" << endl;
    }
    int i(last);

    while(i > position) {
        data[i + 1] = data[i];
        i--;
    }
    data[position + i] = e;
    last++;
} /*completo*/

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteData(const int &position) {
    if(!isValidPos(position)) {
//        throw listException("posicion invalida, deleteData");
        cout << "posicion invalida, deleteData" << endl;
    }
    int i(position);

    while (i < last) {
        data[i] = data[i + 1];
        i++;
    }
}/**Completo*/

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirsPos() {
    if (isEmpty()) {
        return -1;
    }
    return 0;
}/*Completa*/

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPos() {
    return last;
}/*Completo*/

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPrevPos(const int &position) {
    if(position == 0 or !isValidPos(position)){
         return -1;
    }
    return position-1;
}


template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPos(const int &position) {
    if(position == 0 or !isValidPos(position)) {
        return -1;
    }
    return position + 1;
}


template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findData(const int &) {
    /*pendiente*/
    cout << "en construccion" << endl;
    return 0;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataL(const T &e) {
    /*pendiente*/
    for (size_t i = 0; i <= last; i++) {
        if(data[i] == e) {
            return i;
        }
    }
    return -1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataB(const T &e) {
    int i(0), j(last),  m;

    while (i <= j) {
        m = (i+j) / 2;

        if(data[m] == e) {
            return m;
        }
        if(e < data[m]) {
            j = m-1;
        } else {
            i = m+1;
        }
    }
}


template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::retrieve(const int &position) {
    if(!isValidPos(position)) {
        /*error*/
        cout << "error retrieve" << endl;
	}
}

template<class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::burble() {
	int i(last), j;
	bool flag;

	do{
		flag = false;
		j = 0;

		while(j < i) {
			if(data[j] > data[j+1]) {
				sortData(data[j], data[j+1]);
				flag = true;
			}
			j++;
		}
		i--;
	} while(flag);

}

template<class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::shell() {
	float factor(3.0 / 4.0);
	int diferencial(last * factor), i, limit;

	while(diferencial > 0) {
		i = 0;
		limit = last -diferencial;

		while (i <= limit) {
			if(data[i] > data[i+diferencial]) {
				sortData(data[i], data[i+diferencial]);
			}
		}

		diferencial *= factor;
	}

}

template<class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortData(T &a, T &b) {
	T aux(a);
	a = b;
	b = aux;
}


template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortData() {
    /*A Completar*/
}


template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::print() {
    int i(0);

    while(i <= last) {
        cout << data[i] << endl;
        i++;
    }
}/*Completo*/


template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteAll() {
    last = -1;
}/*Completo*/



//template <class T, int ARRAYSIZE>
//List<T, ARRAYSIZE>&List<T, ARRAYSIZE>::operator = (const List<T, ARRAYSIZE > &l) {
//    copyAll(l);
//    return this;
//}/*Completo*/

//#endif // LIST_H_INCLUDED
