//
// Created by klause on 2020/6/19.
//

#include <stdio.h>

#define NAME "Damon Salvatore"

int main(void) {
    int width;
    printf("\"%s\"\n", NAME);
    printf("%20s\n", NAME);
    printf("%-20s\n", NAME);
    width = strlen(NAME) + 3;
    printf("%*s\n", width, NAME);
    return 0;
}
