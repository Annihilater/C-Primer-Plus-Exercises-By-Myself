//
// Created by klause on 2020/6/23.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    char ch[40];
    unsigned long len;
    printf("Please input a word: ");
    scanf("%s", ch);

    len = strlen(ch);
    for (unsigned long j = len; j > 0; j--) {
        printf("%c", ch[j - 1]);
    }

    return 0;
}
