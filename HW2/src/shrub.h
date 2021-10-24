#ifndef __shrub__
#define __shrub__

//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарника
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "plant.h"

//------------------------------------------------------------------------------
// кустарник
class Shrub : public Plant {
public:
    virtual ~Shrub() {}

    // Ввод параметров кустарника из файла
    virtual void In(FILE *file);

    // Случайный ввод параметров кустарника
    virtual void InRnd();

    // Вывод параметров кустарника в форматируемый поток
    virtual void Out(FILE *file);

private:
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

    // Функция для определения месяца цветения по его номеру
    month GetMonth(const int &month_number) {
        return month(month_number - 1);
    }

    month flowering_month; // месяц цветения
};

#endif //__shrub__