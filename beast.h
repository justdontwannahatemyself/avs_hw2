//
// Created by sasha on 23.10.2021.
//

#ifndef AVS_DZ2_BEAST_H
#define AVS_DZ2_BEAST_H
#include <stdio.h>
#include "animal.h"
# include "rnd.h"
class Beast : public Animal {
public:
    virtual ~Beast() {};
    virtual void In(FILE* file);
    virtual void InRnd();
    virtual void Out(FILE* file);
    virtual double Fraction();

protected:
    enum meal { predators = 0, herbivores, insectivores };
    int meal_index;
};
#endif //AVS_DZ2_BEAST_H
