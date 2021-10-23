//
// Created by sasha on 23.10.2021.
//

#ifndef AVS_DZ2_CONTAINER_H
#define AVS_DZ2_CONTAINER_H

#include "animal.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container(int s);
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(FILE* file);
    // Случайный ввод содержимого контейнера
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный поток
    void Out(FILE* file);
    // Вычисление суммы периметров всех фигур в контейнере
    void ShellSort();
private:
    void Clear();    // Очистка контейнера от данных
    int len; // текущая длина
    Animal** storage;
    int size;
};


#endif //AVS_DZ2_CONTAINER_H
