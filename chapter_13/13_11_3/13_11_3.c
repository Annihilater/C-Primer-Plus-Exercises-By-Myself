//
// Created by klause on 2020/7/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 40

int main(void) {
    FILE *fp;
    int ch, index = 0;
    char filename[SIZE];

    printf("Please input a file name: ");
    while (scanf("%s", filename) != 1) {//input: chapter_13/13_11_3/test.txt
        printf("File name was wrong. Please input again:");
    }

    if ((fp = fopen(filename, "r+")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", filename);
        exit(EXIT_FAILURE);
    }

    //读取源文件内容，转换成大写并写入源文件
    while ((ch = fgetc(fp)) != EOF) {
        if (islower(ch)) {
            fprintf(stdout, "%c ->", ch);
            ch = toupper(ch);

            fseek(fp, (long) index, SEEK_SET);//将指针指向当前字符所在的位置，因为要将大写字母写在对应位置
            fprintf(stdout, "%c\n", ch);
            putc(ch, fp);
        }
        index++;
    }

    fclose(fp);
    return 0;
}
