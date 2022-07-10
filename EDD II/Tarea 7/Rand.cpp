#include "Rand.h"
#include <random>
#include <chrono>

Rand::Rand() : value(redo()) { }

Rand::Rand(const Rand &copy) : value(copy.value) { }

long Rand::redo() {
    std::default_random_engine engine{std::chrono::steady_clock::now().time_since_epoch().count()};
    std::uniform_int_distribution<int> range{0, 1000000};

    long random_generated = range(engine);
    return random_generated;
}


Rand Rand::operator =(const Rand &element) {
    value = element.value;
    return *this;
}

bool Rand::operator ==(const Rand &element) const {
    return this->value ==element.value;
}

bool Rand::operator !=(const Rand &element) const {
    return this->value !=element.value;
}

bool Rand::operator <=(const Rand &element) const {
    return this->value <=element.value;
}
bool Rand::operator >=(const Rand &element) const {
    return this->value >=element.value;
}
bool Rand::operator <(const Rand &element) const {
    return this->value < element.value;
}
bool Rand::operator >(const Rand &element) const {
    return this->value > element.value;
}

std::ostream& operator << (std::ostream& os, Rand &element){
 os << element.value << " ";
 return os;
}
