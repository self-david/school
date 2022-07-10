#ifndef DATA_H
#define DATA_H

#include <iostream>

class Rand {
private:
    long value;

public:
    Rand();
    Rand(const Rand &);

    long redo();

    Rand operator = (const Rand &elem);
    bool operator == (const Rand &elem)const;
    bool operator != (const Rand &elem)const;
    bool operator < (const Rand &elem)const;
    bool operator > (const Rand &elem)const;
    bool operator <= (const Rand &elem)const;
    bool operator >= (const Rand &elem)const;
        //Serializar el objeto
    friend std::ostream &operator << (std::ostream& os, Rand& elem);


};

#endif // DATA_H
