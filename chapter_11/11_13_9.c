//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>

#define SIZE 40

void reverse(char *);

int main(void) {
    char s[SIZE];

    printf("Please input a string:");
    while (1) {
        scanf("%s", s);
        if (strcmp(s, "quit") == 0)
            break;
        printf("Your string is   :  %s\n", s);
        reverse(s);
        printf("Reverse string is:  %s\n", s);
        printf("Please input next string:");
    }

    return 0;
}

// 原地反转字符串
void reverse(char *str) {
    char ch;
    int n;
    n = (int) strlen(str);
    for (int i = 0; i < (n / 2); ++i) {
        ch = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = ch;
    }
}
