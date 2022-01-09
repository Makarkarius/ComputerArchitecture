#ifndef __flower__
#define __flower__

//------------------------------------------------------------------------------
// flower.h - содержит описание цветка
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "plant.h"

//------------------------------------------------------------------------------
// цветок
class Flower : public Plant {
public:
    virtual ~Flower() {}

    // Ввод параметров цветка из файла
    virtual void In(FILE *file);

    // Случайный ввод параметров цветка
    virtual void InRnd();

    // Вывод параметров цветка в форматируемый поток
    virtual void Out(FILE *file);

private:
    enum flower_type { // типы цветков
        DOMESTIC, GARDEN, WILD, INVALID_PLACE_NUMBER
    };
    flower_type flow_type; // тип цветка
};

#endif //__flower__