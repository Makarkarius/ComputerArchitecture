//------------------------------------------------------------------------------
// flower.cpp - содержит функции обработки цветка
//------------------------------------------------------------------------------

#include "flower.h"

//------------------------------------------------------------------------------
// Ввод параметров цветка из потока
void Flower::In(FILE *file) {
    name = new char[20];
    int place;
    fscanf(file, "%d", &place);
    fscanf(file, "%s", name);
    switch (place) {
        case 1:
            flow_type = flower_type::DOMESTIC;
            break;
        case 2:
            flow_type = flower_type::GARDEN;
            break;
        case 3:
            flow_type = flower_type::WILD;
            break;
        default:
            flow_type = flower_type::INVALID_PLACE_NUMBER;
    }
}

// Случайный ввод параметров цветка
void Flower::InRnd() {
    name = new char[20];
    switch (Plant::rnd3.Get()) {
        case 0:
            flow_type = flower_type::DOMESTIC;
            break;
        case 1:
            flow_type = flower_type::GARDEN;
            break;
        case 2:
            flow_type = flower_type::WILD;
            break;
        default:
            flow_type = flower_type::INVALID_PLACE_NUMBER;
    }
    for (size_t i = 0; i < 20; ++i) {
        name[i] = static_cast<char>('a' + Plant::rnd20.Get());
    }
    name[19] = '\0';
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в поток
void Flower::Out(FILE *file) {
    fprintf(file, "It is flower: flower type = ");
    switch (flow_type) {
        case flower_type::DOMESTIC:
            fprintf(file, "domestic");
            break;
        case flower_type::GARDEN:
            fprintf(file, "garden");
            break;
        case flower_type::WILD:
            fprintf(file, "wild");
            break;
        case flower_type::INVALID_PLACE_NUMBER:
            fprintf(file, "Invalid place number!");
    }
    fprintf(file, ", name = %s, Quotient = %f\n", name, Quotient());
}

