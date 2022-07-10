#include "fecha.h"


tm Fecha::getGenerator(){
    time_t tiempoReal = time(nullptr);/*esto guarda el tiempo actual*/
    struct tm today = *localtime(&tiempoReal);
    return today;
}

void Fecha::setYear() {
    year = getGenerator().tm_year + 1900;
}/*ya que empieza en 1900*/

void Fecha::setMonth() {
    month = getGenerator().tm_mon + 1;
}/*empieza a contar desde el 0*/

void Fecha::setDay(){
    day = getGenerator().tm_mday;
}

void Fecha::setHour() {
    hour = getGenerator().tm_hour;
}

void Fecha::setMinute() {
    minute = getGenerator().tm_min;
}

void Fecha::setSecond() {
    second = getGenerator().tm_sec;
}

void Fecha::generate() {/*esto inicializa la fecha*/
    setYear();
    setMonth();
    setDay();
    setHour();
    setMinute();
    setSecond();
}

int Fecha::getYear() const {
    return year;
}

int Fecha::getMonth() const {
    return month;
}

int Fecha::getDay() const {
    return day;
}

int Fecha::getHour() const {
    return hour;
}

int Fecha::getMinute() const {
    return minute;
}

int Fecha::getSecond() const {
    return second;
}
