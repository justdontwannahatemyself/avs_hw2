//
// Created by sasha on 23.10.2021.
//

#include "container.h"
#include <iostream>
//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(int s): len{0}, size{s} {
    storage = new Animal*[s];
}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
    delete[] storage;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE* file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; ++i) {
        fprintf(file, "%d :", i+1);
        storage[i]->Out(file);
    }

}
//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE* file) {
    while (!feof(file)) {
        if ((storage[len] = Animal::StaticIn(file)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int s) {
    if(s > size) {
        s = size;
    }
    while(len < s) {
        if((storage[len] = Animal::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

// Сортировка контейнера алгоритмом Шелла
void Container::ShellSort(){
    int d = len / 2;
    while (d != 0){
        for (int i = d; i < len; i += d) {
            int j = i;
            while (j > 0 && (storage[j - d]->Fraction()) > (storage[j]->Fraction())){
                std::swap(storage[j - d], storage[j]);
                j -= d;
            }
        }
        d /= 2;
    }
}
