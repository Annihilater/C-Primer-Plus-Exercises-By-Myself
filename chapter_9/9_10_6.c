//
// Created by klause on 2020/6/25.
//

#include <stdio.h>

void alter(int *, int *);

int main(void) {
    int x, y;
    printf("Please enter two integer: ");

    while (scanf("%d %d", &x, &y) != 2) {
        scanf("%s");
        printf("Please enter two integer: ");
    }
    alter(&x, &y);
    return 0;
}

void alter(int *a, int *b) {
    int addition, subduction;
    addition = *a + *b;
    subduction = *a - *b;

    *a = addition;
    *b = subduction;

    printf("x=%d y=%d", *a, *b);
}
