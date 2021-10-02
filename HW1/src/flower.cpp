//------------------------------------------------------------------------------
// flower.cpp - содержит функции обработки цветка
//------------------------------------------------------------------------------

#include "flower.h"

//------------------------------------------------------------------------------
// Ввод параметров цветка из потока
void In(flower &f, std::ifstream &ifst) {
    int place;
    ifst >> place >> f.name;
    switch (place) {
        case 1:
            f.flow_type = flower::flower_type::DOMESTIC;
            break;
        case 2:
            f.flow_type = flower::flower_type::GARDEN;
            break;
        case 3:
            f.flow_type = flower::flower_type::WILD;
            break;
        default:
            f.flow_type = flower::flower_type::INVALID_PLACE_NUMBER;
    }
}

// Случайный ввод параметров цветка
void InRnd(flower &f) {
    switch (Random() % 3) {
        case 0:
            f.flow_type = flower::flower_type::DOMESTIC;
            break;
        case 1:
            f.flow_type = flower::flower_type::GARDEN;
            break;
        case 2:
            f.flow_type = flower::flower_type::WILD;
            break;
        default:
            f.flow_type = flower::flower_type::INVALID_PLACE_NUMBER;
    }
    for (size_t i = 0; i < MAX_NAME_SIZE; ++i) {
        f.name[i] = static_cast<char>('a' + Random());
    }
    f.name[MAX_NAME_SIZE - 1] = '\0';
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в поток
void Out(flower &f, std::ofstream &ofst) {
    ofst << "It is flower: flower type = ";
    switch (f.flow_type) {
        case flower::DOMESTIC:
            ofst << "domestic";
            break;
        case flower::GARDEN:
            ofst << "garden";
            break;
        case flower::WILD:
            ofst << "wild";
            break;
        case flower::INVALID_PLACE_NUMBER:
            ofst << "Invalid place number!";
    }
    ofst << ", name = " << f.name
         << ". Quotient = " << Quotient(f) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного от деления числа гласных букв
// в названии цветка на общую длину его названия

double Quotient(flower &f) {
    // переменная для подсчёта гласных в названии цветка
    size_t number_of_vowels = 0;
    for (auto it: f.name) {
        char current_symbol = tolower(it);
        if (current_symbol == 'a' || current_symbol == 'e' || current_symbol == 'i' ||
            current_symbol == 'o' || current_symbol == 'u' || current_symbol == 'y') {
            ++number_of_vowels;
        }
    }
    return number_of_vowels / (double) strlen(f.name);
}
