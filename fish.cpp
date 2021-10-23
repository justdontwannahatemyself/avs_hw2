//
// Created by sasha on 23.10.2021.
//

#include "fish.h"
#include "stdio.h"
#include <stdexcept>
#include "rnd.h"

void Fish::In(FILE* file) {
    char namee[11];
    fscanf_s(file, "%s", namee, sizeof(namee));
    fscanf_s(file, "%d", &area_index);
    fscanf_s(file, "%d", &weight);
    name = new char[11];
    for (int i = 0; i < 11; ++i) {
        name[i] = namee[i];
    }
    if (weight <= 0 || weight >= 1000000) {
        throw std::invalid_argument("Incorrect input. Check name and weight.");
    }
}
void Fish::InRnd() {
    weight = Random(1, 1000000);
    area_index = Random(0, 3);
    // Не знаю, как генерить имя, так что имя у нас будет состоять из 10 случайных чаров.
    name = new char[10];
    for (int i = 0; i < 10; ++i) {
        name[i] = ((char) Random(97,122));
    }
}
void Fish:: Out(FILE* file) {
    std::string area;
    switch (area_index)
    {
        case LAKE:
            area = "lake";
            break;
        case SEA:
            area = "sea";
            break;
        case RIVER:
            area = "river";
            break;
        default:
            area = "none";
    }
    std::string namee = "";
    for (int i = 0; i < 11; ++i) {
        namee+=name[i];
    }
    fprintf(file, "It's fish. Name is %s Area is %s, weight is %d, fraction is %f \n",namee.c_str(), area.c_str(), weight, Fraction());
}
double Fish:: Fraction() {
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        cnt += (int)name[i];
    }
    return cnt / (double)weight;
}
