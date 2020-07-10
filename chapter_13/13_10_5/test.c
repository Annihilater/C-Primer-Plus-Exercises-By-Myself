//
// Created by klause on 2020/7/2.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    if (strchr("words", 'o'))
        printf("good");
    else
        printf("not good");
    return 0;
}
