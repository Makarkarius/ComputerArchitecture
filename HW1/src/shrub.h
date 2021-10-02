#ifndef __shrub__
#define __shrub__

//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарника
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "constant.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// кустарник
struct shrub {
    enum month { // месяца года
        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER,
        INVALID_MONTH_NUMBER
    };
    month flowering_month; // месяц цветения
    char name[MAX_NAME_SIZE]; // название кустарника
};

// Ввод параметров кустарника из файла
void In(shrub &s, std::ifstream &ifst);

// Случайный ввод параметров кустарника
void InRnd(shrub &s);

// Вывод параметров кустарника в форматируемый поток
void Out(shrub &s, std::ofstream &ofst);

// Вычисление частного от деления числа гласных букв
// в названии кустарника на общую длину его названия
double Quotient(shrub &s);

#endif //__shrub__