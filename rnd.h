//
// Created by sasha on 23.10.2021.
//

#ifndef AVS_DZ2_RND_H
#define AVS_DZ2_RND_H
#include "random"

inline auto Random(int a, int b) {
    return a + (rand() % (abs((a - b)) + 1));
}

#endif //AVS_DZ2_RND_H
