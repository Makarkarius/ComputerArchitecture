#ifndef HOTEL_H
#define HOTEL_H

#include "visitor.h"

class Hotel {
public:
    Hotel();

    ~Hotel();

    bool checkIn(Visitor *visitor);

    void checkOut(Visitor *visitor);

    struct Single;

    struct Double;

private:
    Single *singles;
    Double *doubles;
};

#endif //HOTEL_H
