#include "visitor.h"

Visitor::Visitor() :
        is_male(false), arrival(0), stay_time(0), room_number(-1), in_double(false) {
}

std::istream &operator>>(std::istream &stream, Visitor &v) {
    stream >> v.name >> v.is_male >> v.arrival >> v.stay_time;
    return stream;
}
