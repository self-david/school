//
//  list.hpp
//  Estrucutra de datos
//
//  Created by <author> on 24/01/2019.
//
//

#ifndef list_hpp
#define list_hpp

#include <iostream>


///Definicion

template <class T = int, int ARRAYSIZE = 255>
class List {
  private:
    T data[ARRAYSIZE];
    int last;

    bool isValidPos(const int &);/*valida si la posicion es posible*/
    void copyAll(const List&);

  public:

    List();

    bool isEmpty();
    bool isFull();

    void insertData(const int &, const T &); /*posicion, elemento*/
    void deleteData(const int &);

    int getFirsPos();
    int getLastPos();
    int getPrevPos(const int &);
    int getNextPos(const int &);

    int findData(const int &);
    int findDataL(const T &);/*lineal*/
    int findDataB(const T &);/*binario*/

    T retrieve(const int &);

	void burble();
	void shell();
	void sortData(T &, T &);

    void sortData();
    void print();
    void deleteAll();
};


#endif /* list_hpp */
