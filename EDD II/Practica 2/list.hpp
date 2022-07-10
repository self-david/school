//
//  list.hpp
//  Estrucutra de datos
//
//  Created by <author> on 24/01/2019.
//
//

#ifndef list_hpp
#define list_hpp


class List<t> {
  private:
    int List<t>[100];
    int 

  public:
    void initialize();

    bool isEmpty();
    bool isFull();

    void insertData(const int &, const int &); /*posicion, elemento*/
    void deleteData(const int &);

    int getFirsPos();
    int hetLastPos();
    int getPrevPos(const int &);
    int getNextPos(const int &);

    int findData(const int &);

    int retrieve(const int &);

    void sortData();

    void print();

    void deleteAll();
};


#endif /* list_hpp */
