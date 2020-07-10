//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 40

void remove_space(char *);

int main(void) {
    char s[SIZE];

    printf("Please input a string:");
    while (1) {
        fgets(s, 40, stdin);
        if (strcmp(s, "quit\n") == 0)
            break;
        remove_space(s);
        printf("%s\n", s);
        printf("Please input a string:");
    }

    return 0;
}

// 删除字符串中的空格
void remove_space(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (isspace(str[i])) {
            for (int j = i; j < strlen(str); ++j) {
                str[j] = str[j + 1];
            }
        }
    }
}
