#ifndef __plant__
#define __plant__

//------------------------------------------------------------------------------
// plant.h - содержит описание обобщающённого растения
//------------------------------------------------------------------------------

#include <fstream>
#include "rnd.h"

//------------------------------------------------------------------------------
// класс, обобщающий все имеющиеся растения
class Plant {
protected:
    char *name;
    static Random rnd20;
    static Random rnd3;
    static Random rndMonth;

public:
    virtual ~Plant();

    // Ввод обобщенного растения
    static Plant *StaticIn(FILE *file);

    // Ввод обобщенного растения
    virtual void In(FILE *file) = 0;

    // Случайный ввод обобщенного растения
    static Plant *StaticInRnd();

    // Виртуальный метод ввода случайного растения
    virtual void InRnd() = 0;

    // Вывод обобщенного растения
    virtual void Out(FILE *file) = 0;

    // Вычисление необходимой функции для растения
    virtual double Quotient();
};


#endif //__plant__