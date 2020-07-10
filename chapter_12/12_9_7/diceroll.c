//
// Created by klause on 2020/7/1.
//

#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0;

static int rollem(int sides) {
    int roll;

    roll = rand() % sides + 1;
    ++roll_count;

    return roll;
}

int roll_n_dice(int dice, int sides) {
    int d;
    int total = 0;
    if (sides < 2) {//骰子面数小于 2 报错
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1) {//骰子面数小于 1 报错
        printf("Need at least 1 die.\n");
        return -1;
    }

    for (d = 0; d < dice; ++d) {//按照骰子个数依次掷骰子
        total += rollem(sides);
    }
    return total;
}
