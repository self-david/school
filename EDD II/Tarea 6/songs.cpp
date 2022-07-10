#include "songs.h"

using namespace std;

int Songs::getOrder() const {
    return order;
}

void Songs::setOrder(const int &ord) {
    order = ord;
}

Songs::Songs() : order(0) { }

Songs::Songs(const Songs &copy) : title(copy.title), author(copy.author), interprete(copy.interprete), duration(copy.duration), ranking(copy.ranking){ }

Songs Songs::operator=(const Songs &copy) {
    title = copy.title;
    author = copy.author;
    interprete = copy.interprete;
    duration = copy.duration;
    ranking = copy.ranking;
    return *this;
}

bool Songs::operator==(const Songs &comp) const {
    if(comp.order == 0) {
        return this->title == comp.title;
    }
    return this->interprete == comp.interprete;
}

bool Songs::operator!=(const Songs &comp) const {
    if(comp.order == 0) {
        return this->title != comp.title;
    }
    return this->interprete != comp.interprete;
}

bool Songs::operator>(const Songs &comp) const {
    if(comp.order == 0) {
        return this->title > comp.title;
    }
    return this->interprete > comp.interprete;
}

bool Songs::operator<(const Songs &comp) const {
    if(comp.order == 0) {
        return this->title < comp.title;
    }
    return this->interprete < comp.interprete;
}

bool Songs::operator<=(const Songs &comp) const {
    if(comp.order == 0) {
        return this->title <= comp.title;
    }
    return this->interprete <= comp.interprete;
}

bool Songs::operator>=(const Songs &comp) const {
    if(comp.order == 0) {
        return this->title >= comp.title;
    }
    return this->interprete >= comp.interprete;
}

ostream &operator<<(ostream &os,const Songs &song) {/*toString*/
    Cursor cursor;

    cursor.Gotoxy(8, cursor.wherey());
    os << "| ";
    os << song.getTitle();
    cursor.Gotoxy(32, cursor.wherey());
    os << "| ";
    os << song.getAuthor();
    cursor.Gotoxy(56, cursor.wherey());
    os << "| ";
    os << song.getInterprete();
    cursor.Gotoxy(80, cursor.wherey());
    os << "| ";
    os << song.getDuration();
    cursor.Gotoxy(91, cursor.wherey());
    os << "| ";
    cursor.Gotoxy(96, cursor.wherey());
    os << song.getRanking();
    cursor.Gotoxy(101, cursor.wherey());
    os << "| " << endl;
    return os;
}

string Songs::getTitle() const {
        return title;
}

void Songs::setTitle(const string &value) {
        title = value;
}

string Songs::getAuthor() const {
        return author;
}

void Songs::setAuthor(const string &value) {
        author = value;
}

string Songs::getInterprete() const {
        return interprete;
}

void Songs::setInterprete(const string &value) {
        interprete = value;
}

string Songs::getDuration() const {
        return duration;
}

void Songs::setDuration(const string &value) {
        duration = value;
}


int Songs::getRanking() const {
        return ranking;
}

void Songs::setRanking(const int &value) {
        ranking = value;
}

bool Songs::validTime(const string &value) {
        if(value.size() != 5) {
                /*si no tiene estilo de tiempo '01:23' no es valido
                5 digitos*/
                return false;
        }
        for (int i = 0; i < 5; i++) {
                if(i != 2) {
                        /*aqui solo analisa los digitos*/
                        if(value[i] < 48 or value[i] > 57) {
                                /*aqui se revisa que si sean digitos*/
                                return false;
                        }
                } else if(value[i] != 58) {
                        /*aqui se revisa el ':'*/
                        return false;
                }
        }
        /*si paso todo sin retornar falso, el dato introduccido es valido*/
        return true;
}


