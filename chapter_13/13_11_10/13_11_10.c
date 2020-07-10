//
// Created by klause on 2020/7/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char filename[100], str_pos[100];
    FILE *fp;
    int ch;
    char *end;
    long int pos = 0;
    int is_digit;

    fprintf(stdout, "Please input file name: ");

    //input: chapter_13/13_11_10/test.txt
    if (fscanf(stdin, "%s", filename) != 1) {
        printf("Name was wrong. Please input again.\n");
    }

    if ((fp = fopen(filename, "r")) == NULL) {//检查文件是否能打开
        fprintf(stdout, "I couldn't open %s file.\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Please input a position to print:\n");
    while (fscanf(stdin, "%s", str_pos) == 1) {//example: 200

        //先假设输入的是数值，在遍历每个字符，发现一个不是数字，就将 is_digit 设置为 0
        is_digit = 1;
        for (int i = 0; i < strlen(str_pos); ++i) {
            if (!isdigit((int) str_pos[i])) {
                is_digit = 0;
            }
        }

        if (is_digit == 0) {//检查 is_digit 是否为 0 判断输入是否为数值
            printf("Your input position is not a digit.\n");
            break;
        }

        pos = strtol(str_pos, &end, 10);//将字符转换为长整型数值

        if (pos < 0) {//如果数值小于 0，则退出循环终止程序
            printf("Your input position is not a positive integer.\n");
            break;
        }

        fseek(fp, pos, SEEK_SET);//根据输入的 pos 位置，设置文件指针

        while ((ch = getc(fp)) != '\n')//从文件指针位置开始读取内容，直到下一个换行符
            fprintf(stdout, "%c", ch);

        fprintf(stdout, "\nPlease input next position to print:\n");
    }

    fclose(fp);
    return 0;
}
