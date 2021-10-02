//------------------------------------------------------------------------------
// shrub.cpp - содержит функции обработки кустарника
//------------------------------------------------------------------------------

#include "shrub.h"

//------------------------------------------------------------------------------
// Функция для определения месяца цветения по его номеру
shrub::month GetMonth(const int &month_number) {
    switch (month_number) {
        case 1:
            return shrub::month::JANUARY;
        case 2:
            return shrub::month::FEBRUARY;
        case 3:
            return shrub::month::MARCH;
        case 4:
            return shrub::month::APRIL;
        case 5:
            return shrub::month::MAY;
        case 6:
            return shrub::month::JUNE;
        case 7:
            return shrub::month::JULY;
        case 8:
            return shrub::month::AUGUST;
        case 9:
            return shrub::month::SEPTEMBER;
        case 10:
            return shrub::month::OCTOBER;
        case 11:
            return shrub::month::NOVEMBER;
        case 12:
            return shrub::month::DECEMBER;
        default:
            return shrub::month::INVALID_MONTH_NUMBER;
    }
}

/*
// Функция для определения месяца цветения по его номеру второй вариант
shrub::month GetMonth(const int &month_number) {
    return shrub::month(month_number - 1);
}
*/

// Ввод параметров кустарника из потока
void In(shrub &s, std::ifstream &ifst) {
    int month_number;
    ifst >> month_number >> s.name;
    s.flowering_month = GetMonth(month_number);
}

// Случайный ввод параметров кустарника
void InRnd(shrub &s) {
    s.flowering_month = GetMonth(Random() % 12 + 1);
    for (size_t i = 0; i < MAX_NAME_SIZE; ++i) {
        s.name[i] = static_cast<char>('a' + Random());
    }
    s.name[MAX_NAME_SIZE - 1] = '\0';
}

//------------------------------------------------------------------------------
// Вывод параметров кустарника в поток
void Out(shrub &s, std::ofstream &ofst) {
    ofst << "It is shrub: flowering season = ";
    switch (s.flowering_month) {
        case shrub::JANUARY:
            ofst << "january";
            break;
        case shrub::FEBRUARY:
            ofst << "february";
            break;
        case shrub::MARCH:
            ofst << "march";
            break;
        case shrub::APRIL:
            ofst << "april";
            break;
        case shrub::MAY:
            ofst << "may";
            break;
        case shrub::JUNE:
            ofst << "june";
            break;
        case shrub::JULY:
            ofst << "july";
            break;
        case shrub::AUGUST:
            ofst << "august";
            break;
        case shrub::SEPTEMBER:
            ofst << "september";
            break;
        case shrub::OCTOBER:
            ofst << "october";
            break;
        case shrub::NOVEMBER:
            ofst << "november";
            break;
        case shrub::DECEMBER:
            ofst << "december";
            break;
        case shrub::INVALID_MONTH_NUMBER:
            ofst << "Invalid month number!";
    }
    ofst << ", name = " << s.name
         << ". Quotient = " << Quotient(s) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного от деления числа гласных букв
// в названии кустарника на общую длину его названия

double Quotient(shrub &s) {
    // переменная для подсчёта гласных в названии кустарника
    size_t number_of_vowels = 0;
    for (auto it: s.name) {
        char current_symbol = tolower(it);
        if (current_symbol == 'a' || current_symbol == 'e' || current_symbol == 'i' ||
            current_symbol == 'o' || current_symbol == 'u' || current_symbol == 'y') {
            ++number_of_vowels;
        }
    }
    return number_of_vowels / (double) strlen(s.name);
}
