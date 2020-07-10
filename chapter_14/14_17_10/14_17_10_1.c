//
// Created by klause on 2020/7/6.
//

#include <stdio.h>

struct gas {
    float distance;
    float gals;
    float mpg;
};

float helper(struct gas tmp);

int main(void) {
    struct gas gas1 = {100, 5};

    gas1.mpg = helper(gas1);

    printf("distance=%.2f, gals=%.2f, mpg=%.2f", gas1.distance, gas1.gals, gas1.mpg);
    return 0;
}

float helper(struct gas tmp) {
    if (tmp.gals > 0)
        return tmp.distance / tmp.gals;
    else
        return (float) -1.0;
}
