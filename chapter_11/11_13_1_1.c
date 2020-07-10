//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>

#define MAX 40

char *get_string(char *str, int n);

int main(void) {
    char str[MAX];
    int i;
    int n = 20;

    puts("Please enter a n characters: ");
    get_string(str, n);

    for (i = 0; i < n; i++)
        putchar(str[i]);
    return 0;
}

char *get_string(char *str, int n) {
    int i = 0;
    while (i < n && (*str++ = (char) getchar()) != '\0')
        i++;
    return str;
}
