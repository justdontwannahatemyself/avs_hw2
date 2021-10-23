//
// Created by sasha on 23.10.2021.
//

#ifndef AVS_DZ2_ANIMAL_H
#define AVS_DZ2_ANIMAL_H
#include <stdio.h>
class Animal {
protected:
char* name;
int weight;
public:
    virtual ~Animal(){};
    static Animal *StaticIn(FILE* file);
    virtual void In(FILE* file) = 0;
    static Animal *StaticInRnd();
    virtual void InRnd() = 0;
    virtual void Out(FILE* file) = 0;
    virtual double Fraction() = 0;
};
#endif //AVS_DZ2_ANIMAL_H
