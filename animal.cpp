//
// Created by sasha on 23.10.2021.
//

#include "animal.h"
#include "bird.h"
#include "beast.h"
#include "fish.h"
#include "random"

Animal* Animal::StaticIn(FILE *file) {
    int k;
    fscanf(file, "%d", &k);
    Animal* al = nullptr;
    switch (k) {
        case 1:
            al = new Fish;
            break;
        case 2:
            al = new Beast;
            break;
        case 3:
            al = new Bird;
            break;
        default:
            return nullptr;
    }
    al->In(file);
    return al;
}
Animal* Animal::StaticInRnd() {
    auto k = rand() % 3 + 1;
    Animal* al = nullptr;
    switch (k) {
        case 1:
            al = new Fish;
            break;
        case 2:
            al = new Beast;
        break;
        case 3:
            al = new Bird;
            break;
    }
    al->InRnd();
    return al;
}
