//
// Created by sasha on 23.10.2021.
//

#ifndef AVS_DZ2_BIRD_H
#define AVS_DZ2_BIRD_H
#include <stdio.h>
#include "animal.h"
//# include "rnd.h"
class Bird : public Animal {
public:
    virtual ~Bird() {};
    virtual void In(FILE* file);
    virtual void InRnd();
    virtual void Out(FILE* file);
    virtual double Fraction();

protected:
    bool migration;
};
#endif //AVS_DZ2_BIRD_H
