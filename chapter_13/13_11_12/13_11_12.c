//
// Created by klause on 2020/7/3.
//

//Program argument: chapter_13/13_11_12/test.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 20//数组的行数
#define COL_SIZE 31//数组的列数
#define ORIGIN_COL_SIZE 60//文件内行中有空格，一行有 60 个字符，读取一行需要 60 个字符的空间

int main(int argc, char *argv[]) {
    FILE *fp;
    char ar[ROW_SIZE][COL_SIZE];
    char words[ORIGIN_COL_SIZE];
    char *filename;
    char ch;
    int row, col;

    //初始化 words 全部为 ' '
    for (int k = 0; k < COL_SIZE; ++k) {
        words[k] = ' ';
    }

    printf("初始化数组(全部为空格):\n");
    for (int j = 0; j < ROW_SIZE; ++j) {
        for (int i = 0; i < COL_SIZE; ++i) {
            ar[j][i] = ' ';
        }
    }

    printf("打印数组:\n");
    for (int j = 0; j < ROW_SIZE; ++j) {
        printf("第 %2d 行: ", j);
        for (int i = 0; i < COL_SIZE; ++i) {
            printf("%c", ar[j][i]);
        }
        printf("\n");
    }

    if (argc != 2) {
        fprintf(stderr, "Usage: %s file wrong.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "I couldn't open %s file.", filename);
        exit(EXIT_FAILURE);
    }

    row = 0;
    /*
     * fgets 表示逐行读取文件
     * 但是读取一行结束，会留下换行符和结尾的空字符
     * 换行符和空字符下次会被读取
     * 第一次读取："0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0 \0"
     * 下一次读取："\n \0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0 \0"
     * 可以看到以 '\n' 开头的行其实是上一行的重复，所以需要过滤掉，这是本题的关键
     */
    while ((fgets(words, ORIGIN_COL_SIZE, fp) != NULL) && row < ROW_SIZE) {
        if (words[0] == '\n')
            continue;

        col = 0;
        for (int i = 0; i < ORIGIN_COL_SIZE; ++i) {
            ch = words[i];
            if (ch != '\0') {//字符转换
                if (ch == ' ')
                    continue;
                else if (ch == '0') {
                    ar[row][col] = ' ';
                } else if (ch == '1') {
                    ar[row][col] = '.';
                } else if (ch == '2') {
                    ar[row][col] = '\'';
                } else if (ch == '3') {
                    ar[row][col] = ':';
                } else if (ch == '4') {
                    ar[row][col] = '~';
                } else if (ch == '5') {
                    ar[row][col] = '*';
                } else if (ch == '6') {
                    ar[row][col] = '=';
                } else if (ch == '8') {
                    ar[row][col] = '%';
                } else if (ch == '9') {
                    ar[row][col] = '#';
                }
                col++;
            }
        }
        row++;
    }

    printf("\n打印图片:\n");
    for (int j = 0; j < ROW_SIZE; ++j) {
        for (int i = 0; i < COL_SIZE; ++i) {
            printf("%c", ar[j][i]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}
