//
// Created by sasha on 23.10.2021.
//

#ifndef AVS_DZ2_FISH_H
#define AVS_DZ2_FISH_H
#include <stdio.h>
#include "animal.h"
//# include "rnd.h"
class Fish : public Animal {
public:
    virtual ~Fish() {};
    virtual void In(FILE* file);
    virtual void InRnd();
    virtual void Out(FILE* file);
    virtual double Fraction();

private:
    enum area { RIVER = 0, SEA, LAKE };
    int area_index;
};
#endif //AVS_DZ2_FISH_H
