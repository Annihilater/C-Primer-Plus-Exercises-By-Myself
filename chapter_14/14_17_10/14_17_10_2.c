//
// Created by klause on 2020/7/6.
//

#include <stdio.h>

struct gas {
    float distance;
    float gals;
    float mpg;
};

void helper(struct gas *tmp);

int main(void) {
    struct gas gas1 = {100, 5};
    struct gas *pb;//申明一个指向 gas 结构的指针

    pb = &gas1;//将 gas 类型的数据 gas1 的地址赋值给 pb 指针
    helper(pb);

    printf("distance=%.2f, gals=%.2f, mpg=%.2f", gas1.distance, gas1.gals, gas1.mpg);
    return 0;
}

void helper(struct gas *tmp) {
    if (tmp->gals > 0)
        tmp->mpg = tmp->distance / tmp->gals;
    else
        tmp->mpg = (float) -1.0;
}
