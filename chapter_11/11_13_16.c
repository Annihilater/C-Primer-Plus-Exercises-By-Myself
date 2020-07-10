//
// Created by klause on 2020/6/30.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10000

void show(char *str);

void to_capitalization(char *str);

void to_lowercase(char *str);

int main(int argc, char *argv[]) {
    char str[SIZE];

    printf("Please input a string:\n");
    fgets(str, SIZE, stdin);//会输入最后的换行符
    printf("Your string is: %s\n", str);

    if (argc == 1) {
        printf("按照 -p 参数的要求原样打印输入:\n");
        show(str);
    } else if (argc == 2) {
        if (strcmp(argv[1], "-p") == 0) {
            printf("原样打印:\n");
            show(str);
        }
        if (strcmp(argv[1], "-u") == 0) {
            printf("把输入全部转换成大写:\n");
            to_capitalization(str);
        }
        if (strcmp(argv[1], "-l") == 0) {
            printf("把输入全部转换成小写:\n");
            to_lowercase(str);
        }
    } else
        printf("参数错误!\n");

    return 0;
}

void show(char *str) {
    printf("%s\n", str);
}

//小写转大写
void to_capitalization(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (islower(str[i])) {
            str[i] = (char) toupper(str[i]);
        }
    }
    printf("%s\n", str);
}

//大写转小写
void to_lowercase(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (isupper(str[i])) {
            str[i] = (char) tolower(str[i]);
        }
    }
    printf("%s\n", str);
}
