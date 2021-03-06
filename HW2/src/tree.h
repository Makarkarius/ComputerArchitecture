#ifndef __tree__
#define __tree__

//------------------------------------------------------------------------------
// tree.h - содержит описание дерева и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "plant.h"

//------------------------------------------------------------------------------
// дерево
class Tree : public Plant {
public:
    virtual ~Tree() {}

    // Ввод параметров дерева из файла
    virtual void In(FILE *file);

    // Случайный ввод параметров дерева
    virtual void InRnd();

    // Вывод параметров дерева в форматируемый поток
    virtual void Out(FILE *file);

private:
    long int age; // возраст дерева
};


#endif //__tree__