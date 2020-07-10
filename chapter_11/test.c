//
// Created by klause on 2020/6/28.
//

#include <stdio.h>

int main(void) {
    char st[10];
    int n = 10;

    printf("Please input string:");
    fgets(st, n, stdin);
    printf("%s", st);
    return 0;
}
