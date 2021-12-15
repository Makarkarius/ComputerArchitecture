#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <fstream>
#include "hotel.h"

Hotel *hotel;
pthread_mutex_t mutex;
std::ifstream fin;
std::ofstream fout;

void *visit(void *args) {
    auto *visitor = static_cast<Visitor *>(args);

    usleep(visitor->arrival * 1000);

    pthread_mutex_lock(&mutex);
    bool flag = hotel->checkIn(visitor);
    if (!flag) {
        fout << (visitor->is_male ? "Male " : "Female ") << "Visitor " << visitor->name
             << " left because there are no vacant rooms\n";
    } else {
        fout << (visitor->is_male ? "Male " : "Female ") << "Visitor " << visitor->name << " checked in the " <<
             (visitor->in_double ? "double " : "single ") <<
             "room number " << visitor->room_number + 1 << "\n";
    }
    pthread_mutex_unlock(&mutex);

    if (!flag) {
        return nullptr;
    }

    usleep(visitor->stay_time * 1000);

    pthread_mutex_lock(&mutex);
    hotel->checkOut(visitor);
    fout << (visitor->is_male ? "Male " : "Female ") << "Visitor " << visitor->name << " checked out the " <<
         (visitor->in_double ? "double " : "single ") <<
         "room number " << visitor->room_number + 1 << "\n";
    pthread_mutex_unlock(&mutex);

    return nullptr;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Invalid parameters!\nPlease, enter the input and the output file names.\n";
        return 0;
    }
    fin.open(argv[1]);
    fout.open(argv[2]);
    if (!fin.is_open() || !fout.is_open()) {
        std::cout << "File can't be opened!\n";
        return 0;
    }
    hotel = new Hotel;
    int visitor_count;
    fin >> visitor_count;
    auto *threads = new pthread_t[visitor_count];
    auto *visitors = new Visitor[visitor_count];
    pthread_mutex_init(&mutex, nullptr);

    for (int i = 0; i < visitor_count; ++i) {
        fin >> visitors[i];
    }
    for (int i = 0; i < visitor_count; ++i) {
        pthread_create(&threads[i], nullptr, visit, &visitors[i]);
    }
    std::cout << "Start\n";
    for (int i = 0; i < visitor_count; ++i) {
        pthread_join(threads[i], nullptr);
    }
    std::cout << "Stop\n";
    pthread_mutex_destroy(&mutex);
    delete[] visitors;
    delete hotel;
    return 0;
}
