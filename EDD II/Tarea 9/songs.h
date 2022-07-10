#ifndef SONGS_H
#define SONGS_H

#include <iostream>
#include "cursor.h"

class Songs {
private:
        std::string title;/*titulo de la cancion*/
        std::string author;/*autor*/
        std::string interprete;/* interprete*/
        std::string duration;/*duraccion de la cancion*/
        int ranking;/*posicion en el ranking*/

public:
        int order;
        Songs();
        Songs(const Songs &);

        Songs operator=(const Songs &);
        bool operator==(const Songs &) const;
        bool operator!=(const Songs &) const;
        bool operator<(const Songs &) const;
        bool operator>(const Songs &) const;
        bool operator<=(const Songs &) const;
        bool operator>=(const Songs &) const;

        std::string toString();

        //Funcion Amiga para Serealizar el objeto
        friend std::ostream &operator<<(std::ostream &, const Songs &);

        std::string getTitle() const;
        void setTitle(const std::string &);

        std::string getAuthor() const;
        void setAuthor(const std::string &);

        std::string getInterprete() const;
        void setInterprete(const std::string &);

        std::string getDuration() const;
        void setDuration(const std::string &);

        int getRanking() const;
        void setRanking(const int &value);

        bool validTime(const std::string &);

        int getOrder() const;
        void setOrder(const int &);
};

#endif // SONGS_H
