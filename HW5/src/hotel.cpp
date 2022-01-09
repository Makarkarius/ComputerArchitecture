#include "hotel.h"
#include <iostream>

struct Hotel::Single {
    Single() : is_vacant(true) {
    }

    bool is_vacant;
};

struct Hotel::Double {
    Double() : type(NONE), is_vacant(true) {
    }

    enum {
        MALE,
        FEMALE,
        NONE
    } type;
    bool is_vacant;
};

Hotel::Hotel() {
    singles = new Single[10];
    doubles = new Double[15];
}

Hotel::~Hotel() {
    delete[] singles;
    delete[] doubles;
}

bool Hotel::checkIn(Visitor *visitor) {
    for (int i = 0; i < 10; ++i) {
        if (singles[i].is_vacant) {
            visitor->room_number = i;
            visitor->in_double = false;
            singles[i].is_vacant = false;
            return true;
        }
    }
    for (int i = 0; i < 15; ++i) {
        if (doubles[i].is_vacant) {
            if (doubles[i].type == Hotel::Double::NONE) {
                visitor->room_number = i;
                visitor->in_double = true;
                doubles[i].type = visitor->is_male ? Double::MALE : Double::FEMALE;
                return true;
            }
            if (doubles[i].type == Double::MALE && visitor->is_male ||
                doubles[i].type == Double::FEMALE && !visitor->is_male) {
                visitor->room_number = i;
                visitor->in_double = true;
                doubles[i].is_vacant = false;
                return true;
            }
        }
    }
    return false;
}

void Hotel::checkOut(Visitor *visitor) {
    if (visitor->in_double) {
        if (doubles[visitor->room_number].is_vacant) {
            doubles[visitor->room_number].type = Double::NONE;
        } else {
            doubles[visitor->room_number].is_vacant = true;
        }
    } else {
        singles[visitor->room_number].is_vacant = true;
    }
}
