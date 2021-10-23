//
// Created by sasha on 10.10.2021.
//

#include "bird.h"
#include "stdio.h"
#include <stdexcept>
#include "rnd.h"

void Bird::In(FILE *file) {
    char namee[11];
    fscanf_s(file, "%s", namee, sizeof(namee));
    fscanf_s(file, "%d", &migration);
    fscanf_s(file, "%d", &weight);
    name = new char [11];
    for (int i = 0; i < 11; ++i) {
        name[i] = namee[i];
    }
    if (weight <= 0 || weight >= 1000000) {
        throw std::invalid_argument("Incorrect input. Check name and weight.");
    }

}
void Bird:: InRnd() {
    weight = Random(1, 100000);
    migration = Random(0, 2);
    // Не знаю, как генерить имя, так что имя у нас будет состоять из 10 случайных чаров.
    name = new char[10];
    for (int i = 0; i < 10; ++i) {
        name[i] = ((char) Random(97,122));
    }
}
void Bird::Out( FILE* file) {
    std::string migrationn;
    if (migration) {
        migrationn = "has";
    }
    else {
        migrationn = "hasn't";
    }
    std::string namee = "";
    for (int i = 0; i < 11; ++i) {
        namee+=name[i];
    }
    fprintf(file, "It's a bird. Name is %s, %s ability migrate, weight is %d, fraction is %f \n", namee.c_str(), migrationn.c_str(), weight, Fraction());
}
double Bird::Fraction() {
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        cnt += (int)name[i];
    }
    return cnt / (double)weight;
}
