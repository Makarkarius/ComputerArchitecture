//------------------------------------------------------------------------------
// plant.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "plant.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
plant* In(std::ifstream &ifst) {
    plant *pl;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            pl = new plant;
            pl->k = plant::TREE;
            In(pl->t, ifst);
            return pl;
        case 2:
            pl = new plant;
            pl->k = plant::SHRUB;
            In(pl->s, ifst);
            return pl;
        case 3:
            pl = new plant;
            pl->k = plant::FLOWER;
            In(pl->f, ifst);
            return pl;
        default:
            pl = new plant;
            pl->k = plant::INVALID_PLANT_TYPE;
            char tmp[MAX_NAME_SIZE];
            ifst >> tmp >> tmp;
            return pl;
    }
}

// Случайный ввод обобщенной фигуры
plant *InRnd() {
    plant *pl;
    int k = Random() % 3;
    switch(k) {
        case 0:
            pl = new plant;
            pl->k = plant::TREE;
            InRnd(pl->t);
            return pl;
        case 1:
            pl = new plant;
            pl->k = plant::SHRUB;
            InRnd(pl->s);
            return pl;
        case 2:
            pl = new plant;
            pl->k = plant::FLOWER;
            InRnd(pl->f);
            return pl;
        default:
            pl = new plant;
            pl->k = plant::INVALID_PLANT_TYPE;
            return pl;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(plant &pl, std::ofstream &ofst) {
    switch(pl.k) {
        case plant::TREE:
            Out(pl.t, ofst);
            break;
        case plant::SHRUB:
            Out(pl.s, ofst);
            break;
        case plant::FLOWER:
            Out(pl.f, ofst);
            break;
        default:
            ofst << "Invalid plant type!\n";
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от деления числа гласных букв
// в названии растения на общую длину его названия
double Quotient(plant &pl) {
    switch(pl.k) {
        case plant::TREE:
            return Quotient(pl.t);
        case plant::SHRUB:
            return Quotient(pl.s);
        case plant::FLOWER:
            return Quotient(pl.f);
        default:
            return 0.0;
    }
}
