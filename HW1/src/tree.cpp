//------------------------------------------------------------------------------
// tree.cpp - содержит функции обработки дерева
//------------------------------------------------------------------------------

#include "tree.h"

//------------------------------------------------------------------------------
// Ввод параметров дерева из потока
void In(tree &t, std::ifstream &ifst) {
    ifst >> t.age >> t.name;
}

// Случайный ввод параметров дерева
void InRnd(tree &t) {
    t.age = Random();
    for (size_t i = 0; i < MAX_NAME_SIZE; ++i) {
        t.name[i] = static_cast<char>('a' + Random());
    }
    t.name[MAX_NAME_SIZE - 1] = '\0';
}

//------------------------------------------------------------------------------
// Вывод параметров дерева в поток
void Out(tree &t, std::ofstream &ofst) {
    ofst << "It is tree: age = "
         << t.age << ", name = " << t.name
         << ". Quotient = " << Quotient(t) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного от деления числа гласных букв
// в названии дерева на общую длину его названия

double Quotient(tree &t) {
    // переменная для подсчёта гласных в названии дерева
    size_t number_of_vowels = 0;
    for (auto it: t.name) {
        char current_symbol = tolower(it);
        if (current_symbol == 'a' || current_symbol == 'e' || current_symbol == 'i' ||
            current_symbol == 'o' || current_symbol == 'u' || current_symbol == 'y') {
            ++number_of_vowels;
        }
    }
    return number_of_vowels / (double)strlen(t.name);
}
