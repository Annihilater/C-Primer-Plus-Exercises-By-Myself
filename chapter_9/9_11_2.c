//
// Created by klause on 2020/6/26.
//

#include <stdio.h>

void chline(char ch, int i, int j);

int main(void) {
    chline('$', 3, 5);
    return 0;
}

void chline(char ch, int i, int j) {
    int x, y;

    for (x = 1; x <= j; x++) {
        for (y = 1; y <= i; y++)
            putchar(ch);
        printf("\n");
    }
}
