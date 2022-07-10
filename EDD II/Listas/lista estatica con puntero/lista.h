#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <exception>
#include <iostream>
#include <string>

template <typename Type, int ARRAYSIZE = 1024> class List {
private:
    Type** data;
    int last;

    void copyAll(const List& l) {
        deleteAll();

        for(last = -1; last < l.last; data[++last] = new Type(*l.data[last])){
            if (data[last] == nullptr)
                throw ListException("Something went wrong in List constructor, memory not available");
        }
    }

    bool validPos(const int& p) {
        return p >= 0 or p <= last;
    }

    void sortData(const int& l, const int& r) {
        if(l >= r)
            return;

        if (l + 1 == r) {
            if(*data[l] > *data[r]){
                std::swap(data[l], data[r]);
            }
          return;
          }

        int i = l, j = r;

        while(i < j) {
            while(i < j and *data[i] <= *data[r]) {
                i++;
            }
            while(i < j and *data[j] >= *data[r]) {
                j--;
            }

            if(i != j) {
                std::swap(data[i], data[j]);
            }
        }

        if(i != r){
            std::swap(data[i], data[r]);
        }

        if(i > l) {
            sortData(l, i - 1);
        }

        if(i < j) {
            sortData(i + 1, j);
        }
    }

public:
    class ListException : public std::exception {
        private:
            std::string msg;

        public:
          explicit ListException(const char* message) : msg(message) { }
          explicit ListException(const std::string& message) : msg(message) { }
          virtual ~ListException() throw () { }
          virtual const char* what() const throw () { return msg.c_str(); }
    };

    List() {
      if((data = new Type*[ARRAYSIZE]) == nullptr) {
          throw ListException("Something went wrong in List constructor, memory not available");
    }

      for(last = ARRAYSIZE; last >= 0; data[--last] = nullptr);
    }

    List(const List& l) : List() {
        copyAll(l);
    }

    ~List() {
        deleteAll();

        delete[] *data;
    }

    bool Empty() {
        return last == -1;
    }

    bool full() {
        return last == ARRAYSIZE - 1;
    }

    void insert(int p, const Type &e) {
        if(full()) {
            throw ListException("Can not insert data in a full List");
        }

        if(p != -1 and !validPos(p)) {
            throw ListException("There is an invalid position, trying to insert data into List");
        }

        for(int i = last++; i > p; data[i + 1] = data[i]);

        if((data[p + 1] = new Type(e)) == nullptr) {
            throw ListException("Something went wrong inserting new data in List");
        }
    }

    void insert(const Type &e) {
        insert(getLast(), e);
    }

    void erase(int p) {
        if(!validPos(p)) {
            throw ListException("There is an invalid position, trying to delete data from List");
        }

        for(int i = p; i < last; data[i] = data[++i]);

        delete data[last--];
      }

    int getFirs() {
        return last == -1 ? -1 : 0;
    }

    int getLast() {
        return last;
    }

    int getPrev(const int& p) {
        return p == 0 or !validPos(p) ? -1 : p - 1;
    }

    int getNext(const int& p) {
        return p == last or !validPos(p) ? -1 : p + 1;
    }

    int find(const Type &e) {
        for(int i = 0; i <= last; i++) {
            if(data[i] == e) {
                return i;
            }
        }
        return -1;
    }

    Type retrieve(const int p) {
        if(!validPos(p)) {
            throw ListException("Invalid position, trying to retrieve data from List");
        }
        return *data[p];
    }

    void sort() {
        sortData(0, last);
    }

    void print() {
      for(int i = 0; i <= last; i++) {
          std::cout << *data[i] << std::endl;
      }
    }

    void deleteAll() {
        for( ; last >= 0; delete data[last], data[last--] = nullptr);
    }

    List& operator = (const List& l) {
        deleteAll();

        copyAll(l);

        return *this;
    }

    friend std::ostream& operator << (std::ostream& os, List& l) {
        for(int i = 0; i <= l.last; i++) {
            os << l.data[i] << std::endl;
        }
        return os;
    }

    friend std::istream& operator >> (std::istream& is, List& l) {
        Type myT;
        int i = 0;
        while (is >> myT)
            if((l.data[i++] = new Type(myT)) == nullptr) {
                throw ListException("There is an invalid position, trying to insert data into List in >> operator");
        }
        return is;
    }
};

#endif // LIST_H_INCLUDED
