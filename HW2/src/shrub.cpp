//------------------------------------------------------------------------------
// shrub.cpp - содержит функции обработки кустарника
//------------------------------------------------------------------------------

#include "shrub.h"

//------------------------------------------------------------------------------
// Ввод параметров кустарника из потока
void Shrub::In(FILE *file) {
    name = new char[20];
    int month_number;
    fscanf(file, "%d", &month_number);
    fscanf(file, "%s", name);
    flowering_month = GetMonth(month_number);
}

// Случайный ввод параметров кустарника
void Shrub::InRnd() {
    name = new char[20];
    flowering_month = GetMonth(Plant::rndMonth.Get());
    for (size_t i = 0; i < 20; ++i) {
        name[i] = static_cast<char>('a' + Plant::rnd20.Get());
    }
    name[19] = '\0';
}

//------------------------------------------------------------------------------
// Вывод параметров кустарника в поток
void Shrub::Out(FILE *file) {
    fprintf(file, "It is Shrub: flowering season = ");
    switch (flowering_month) {
        case Shrub::JANUARY:
            fprintf(file, "january");
            break;
        case Shrub::FEBRUARY:
            fprintf(file, "february");
            break;
        case Shrub::MARCH:
            fprintf(file, "march");
            break;
        case Shrub::APRIL:
            fprintf(file, "april");
            break;
        case Shrub::MAY:
            fprintf(file, "may");
            break;
        case Shrub::JUNE:
            fprintf(file, "june");
            break;
        case Shrub::JULY:
            fprintf(file, "july");
            break;
        case Shrub::AUGUST:
            fprintf(file, "august");
            break;
        case Shrub::SEPTEMBER:
            fprintf(file, "september");
            break;
        case Shrub::OCTOBER:
            fprintf(file, "october");
            break;
        case Shrub::NOVEMBER:
            fprintf(file, "november");
            break;
        case Shrub::DECEMBER:
            fprintf(file, "december");
            break;
        case Shrub::INVALID_MONTH_NUMBER:
            fprintf(file, "Invalid month number!");
    }
    fprintf(file, ", name = %s, Quotient = %f\n", name, Quotient());
}
