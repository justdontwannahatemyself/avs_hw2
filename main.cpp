//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <cstring>
#include <time.h>
#include "container.h"

void errMessage1() {
    printf( "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }
    printf("Start\n");
    Container c{10000};
    if(!strcmp(argv[1], "-f")) {
        FILE *file;
        file = fopen(argv[2], "rt");
        try {
            c.In(file);
        }
        catch (std::invalid_argument e){
            printf(e.what());
            return 3;
        }
        fclose(file);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("%s %i %s",
                   "incorrect number of figures =", size,
                   ". Set 0 < number <= 10000\n");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }
    // Вывод содержимого контейнера в файл
    FILE *file;
    file = fopen(argv[3], "w");
    fprintf(file, "Filled container: \n");
    c.Out(file);
    // Вторая часть задания, сортируем перед выводом.
    FILE *file1 = fopen(argv[4], "w");
    fprintf(file1, "Sorted container: \n");
    c.ShellSort();
    c.Out(file1);
    printf("End\n");
}