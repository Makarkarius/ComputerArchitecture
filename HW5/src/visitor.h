#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>

class Visitor {
public:
    Visitor();

    friend std::istream &operator>>(std::istream &stream, Visitor &v);

    std::string name;
    int room_number;
    bool in_double;
    bool is_male;
    uint64_t arrival, stay_time;
};

#endif //VISITOR_H
