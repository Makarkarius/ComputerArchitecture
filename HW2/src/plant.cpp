//------------------------------------------------------------------------------
// plant.cpp - содержит процедуры связанные с обработкой обобщенного растения
// и создания произвольного растения
//------------------------------------------------------------------------------

#include "tree.h"
#include "shrub.h"
#include "flower.h"

//------------------------------------------------------------------------------
Random Plant::rnd20(0, 19);
Random Plant::rnd3(0, 2);
Random Plant::rndMonth(1, 12);

//------------------------------------------------------------------------------
// Деструктор растения
Plant::~Plant() {
    delete name;
}

//------------------------------------------------------------------------------
// Ввод параметров обобщенного растения
Plant *Plant::StaticIn(FILE *file) {
    Plant *pl = nullptr;
    int k;
    fscanf(file, "%d", &k);
    switch (k) {
        case 1:
            pl = new Tree;
            break;
        case 2:
            pl = new Shrub;
            break;
        case 3:
            pl = new Flower;
            break;
    }
    pl->In(file);
    return pl;
}

// Случайный ввод обобщенного растения
Plant *Plant::StaticInRnd() {
    int k = Plant::rnd3.Get();
    Plant *pl = nullptr;
    switch (k) {
        case 0:
            pl = new Tree;
            break;
        case 1:
            pl = new Shrub;
            break;
        case 2:
            pl = new Flower;
            break;
    }
    pl->InRnd();
    return pl;
}

//------------------------------------------------------------------------------
// Вычисление частного от деления числа гласных букв
// в названии цветка на общую длину его названия
double Plant::Quotient() {
    // переменная для подсчёта гласных в названии цветка
    size_t number_of_vowels = 0;
    for (int i = 0; i < strlen(name); ++i) {
        char current_symbol = tolower(name[i]);
        if (current_symbol == 'a' || current_symbol == 'e' || current_symbol == 'i' ||
            current_symbol == 'o' || current_symbol == 'u' || current_symbol == 'y') {
            ++number_of_vowels;
        }
    }
    return number_of_vowels / (double) strlen(name);
}