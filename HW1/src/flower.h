#ifndef __flower__
#define __flower__

//------------------------------------------------------------------------------
// flower.h - содержит описание цветка
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "constant.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// цветок
struct flower {
    enum flower_type { // типы цветков
        DOMESTIC, GARDEN, WILD, INVALID_PLACE_NUMBER
    };
    flower_type flow_type; // тип цветка
    char name[MAX_NAME_SIZE]; // название цветка
};

// Ввод параметров цветка из файла
void In(flower &f, std::ifstream &ifst);

// Случайный ввод параметров цветка
void InRnd(flower &f);

// Вывод параметров цветока в форматируемый поток
void Out(flower &f, std::ofstream &ofst);

// Вычисление частного от деления числа гласных букв
// в названии цветка на общую длину его названия
double Quotient(flower &f);

#endif //__flower__