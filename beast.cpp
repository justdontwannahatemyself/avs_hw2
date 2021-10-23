//
// Created by sasha on 23.10.2021.
//

#include "beast.h"
#include "stdio.h"
#include <stdexcept>

void Beast::In(FILE * file) {
    char namee[11];
    fscanf_s(file, "%s", namee, sizeof(namee));
    fscanf_s(file, "%d", &meal_index);
    fscanf_s(file, "%d", &weight);
    name = new char [11];
    for (int i = 0; i < 11; ++i) {
        name[i] = namee[i];
    }
    if (weight <= 0 || weight >= 1000000) {
        throw std::invalid_argument("Incorrect input. Check name and weight.");
    }

}
void Beast:: InRnd() {
    weight = Random(1, 100000);
    meal_index = Random(0, 3);
    // Не знаю, как генерить имя, так что имя у нас будет состоять из 10 случайных чаров.
    name = new char[10];
    for (int i = 0; i < 10; ++i) {
        name[i] = ((char) Random(97,122));
    }
}
void Beast::Out( FILE* file) {
    std::string meal;
    switch (meal_index) {
        case predators:
            meal = "predator";
            break;
        case herbivores:
            meal = "herbivores";
            break;
        case insectivores:
            meal = "insectivores";
            break;
        default:
            meal = "none";
    }
    std::string namee = "";
    for (int i = 0; i < 11; ++i) {
        namee+=name[i];
    }
    fprintf(file, "It's beast. Name is %s Meal is %s, weight is %d, fraction is %f \n", namee.c_str(), meal.c_str(), weight, Fraction());
}
double Beast::Fraction() {
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        cnt += (int)name[i];
    }
    return cnt / (double)weight;
}
