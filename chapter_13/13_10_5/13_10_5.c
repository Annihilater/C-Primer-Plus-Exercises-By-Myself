//
// Created by klause on 2020/7/2.
//

//Program Arguments: o chapter_13/13_10_5/test.txt
// o 表示单个字符，是打印 test.txt 文件中含有 o 字符的行
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 40

int main(int argc, char *argv[]) {
    FILE *fp;
    char ptr[SIZE];
    char *char_ar;
    char ch;

    //校验命令行参数
    if (argc != 3) {
        fprintf(stderr, "Usage: %s filename\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    //打开文件
    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    //打印文件中含有指定字符的行
    while ((fscanf(fp, "%40s", ptr) == 1)) {
        char_ar = argv[1];
        ch = char_ar[0];
        if (strchr(ptr, ch)) {
            fprintf(stdout, "%s\n", ptr);
        }
    }

    //关闭文件
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    return 0;
}
