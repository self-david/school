#ifndef FECHA_H
#define FECHA_H

#include <ctime>

class Fecha {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

public:
    int getYear() const;
    void setYear();

    int getMonth() const;
    void setMonth();

    int getDay() const;
    void setDay();

    int getHour() const;
    void setHour();

    int getMinute() const;
    void setMinute();

    int getSecond() const;
    void setSecond();

    void generate();

    tm getGenerator();

};

#endif // FECHA_H
