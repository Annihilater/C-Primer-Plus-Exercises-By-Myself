//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>

#define MAX 40

char *get_word(char *str);

int main(void) {
    char str[MAX];
    int i;

    puts("Please enter some characters: ");
    get_word(str);
    for (i = 0; str[i] != '\0'; i++)
        putchar(str[i]);
    return 0;
}

char *get_word(char *str) {
    scanf("%s", str);
    while (getchar() != '\n')
        continue;
    return str;
}
