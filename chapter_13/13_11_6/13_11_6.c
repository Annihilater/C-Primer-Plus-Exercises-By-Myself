//
// Created by klause on 2020/7/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void) {
    FILE *in, *out;
    int ch;
    char name[LEN];
    char filename[LEN];
    int count = 0;

    //输入文件名: chapter_13/13_11_6/test.txt
    if (fscanf(stdin, "%s", filename) != 1) {
        printf("Name was wrong. Please input again.\n");
    }

    //打开文件
    if ((in = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"", filename);
        exit(EXIT_FAILURE);
    }

    //生成输出文件名
    strncpy(name, filename, LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");

    //打开输出文件
    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Can't create output file.");
        exit(3);
    }

    //拷贝数据
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);


    //关闭文件
    if (fclose(in) != 0 || fclose(out) != 0) {
        fprintf(stderr, "Error in closing files\n");
    }

    return 0;
}
