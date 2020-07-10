//
// Created by klause on 2020/6/22.
//

#include <stdio.h>

#define M_TO_H 60

int main(void) {
    int min, mins, hours;
    mins = 60;
    while (mins > 0) {
        hours = mins / M_TO_H;
        min = mins % M_TO_H;
        printf("%d hours %d mins!\n", hours, min);
        printf("Please input next value:\n");
        scanf("%d", &mins);
    }

    return 0;
}
