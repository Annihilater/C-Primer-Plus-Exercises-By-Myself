//
// Created by klause on 2020/7/2.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

int main(void) {
    char filename[SIZE];
    FILE *fp;
    int ch;
    unsigned long count = 0;

    printf("Please input the file name: ");
    //输入文件名 chapter_13/13_11_1/test.txt
    while (scanf("%s", filename) != 1)
        printf("File name was wrong. Please input again:\n");

    //打开文件
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    //读取文件内容
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }

    //关闭文件
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);

    return 0;
}
