//
// Created by klause on 2020/7/3.
//

//Program argument: chapter_13/13_11_14/test.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 20//数组的行数
#define COL_SIZE 31//数组的列数
#define ORIGIN_COL_SIZE 60//文件内行中有空格，一行有 60 个字符，读取一行需要 60 个字符的空间

int cmp(int a, int b);

int main(int argc, char *argv[]) {
    int row, col, row_size = ROW_SIZE, col_size = COL_SIZE;
    FILE *fp;
    int ar[row_size][col_size];
    char words[ORIGIN_COL_SIZE];
    char *filename;
    char ch;
    int ch1;
    int up, down, left, right, sum, cur;


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
                ch1 = (int) ch;
                ch1 = ch1 - 48;
                ar[row][col] = ch1;//字符转化为数字: '1' -> 1
                col++;
            }
        }
        row++;
    }

    printf("\n失真处理前打印图片:\n");
    printf("\n第  x 行: ");
    for (int m = 0; m < COL_SIZE; ++m) {
        printf("%3d ", m);
    }
    printf("\n");
    for (int i = 0; i < ROW_SIZE; ++i) {
        printf("第 %2d 行: ", i);
        for (int j = 0; j < COL_SIZE; ++j) {
            printf("%2c", ar[i][j] + 48);
        }
        printf("\n");
    }

    //失真处理
    for (int i = 0; i < ROW_SIZE; ++i) {
        for (int j = 0; j < COL_SIZE; ++j) {
            cur = ar[i][j];

            //上下左右都有
            if (i > 0 && i < ROW_SIZE - 1 && j > 0 && j < COL_SIZE - 1) {
                up = ar[i - 1][j];
                down = ar[i + 1][j];
                left = ar[i][j - 1];
                right = ar[i][j + 1];

                if (cmp(cur, up) && cmp(cur, down) && cmp(cur, left) && cmp(cur, right)) {
                    sum = up + down + left + right;
                    ar[i][j] = (sum % 4) >= 2 ? sum / 4 + 1 : sum / 4;
                }
            }

            //上没有
            if (i == 0 && j > 0 && j < COL_SIZE - 1) {
                down = ar[i + 1][j];
                left = ar[i][j - 1];
                right = ar[i][j + 1];

                if (cmp(cur, down) && cmp(cur, left) && cmp(cur, right)) {
                    sum = down + left + right;
                    ar[i][j] = (sum % 3) > 1 ? sum / 3 + 1 : sum / 3;
                }
            }

            //下没有
            if (i == ROW_SIZE - 1 && j > 0 && j < COL_SIZE - 1) {
                up = ar[i - 1][j];
                left = ar[i][j - 1];
                right = ar[i][j + 1];

                if (cmp(cur, up) && cmp(cur, left) && cmp(cur, right)) {
                    sum = up + left + right;
                    ar[i][j] = (sum % 3) > 1 ? sum / 3 + 1 : sum / 3;
                }
            }

            //左没有
            if (i > 0 && i < ROW_SIZE - 1 && j == 0) {
                up = ar[i - 1][j];
                down = ar[i + 1][j];
                right = ar[i][j + 1];

                if (cmp(cur, up) && cmp(cur, down) && cmp(cur, right)) {
                    sum = up + down + right;
                    ar[i][j] = (sum % 3) > 1 ? sum / 3 + 1 : sum / 3;
                }
            }

            //右没有
            if (i > 0 && i < ROW_SIZE - 1 && j == COL_SIZE - 1) {
                up = ar[i - 1][j];
                down = ar[i + 1][j];
                left = ar[i][j - 1];

                if (cmp(cur, up) && cmp(cur, down) && cmp(cur, left)) {
                    sum = up + down + left;
                    ar[i][j] = (sum % 3) > 1 ? sum / 3 + 1 : sum / 3;
                }
            }

            //左上没有
            if (i == 0 && j == 0) {
                down = ar[i + 1][j];
                right = ar[i][j + 1];

                if (cmp(cur, down) && cmp(cur, right)) {
                    sum = down + right;
                    ar[i][j] = (sum % 2) > 1 ? sum / 2 + 1 : sum / 2;
                }
            }

            //右上没有
            if (i == 0 && j == COL_SIZE - 1) {
                down = ar[i + 1][j];
                left = ar[i][j - 1];

                if (cmp(cur, down) && cmp(cur, left)) {
                    sum = down + left;
                    ar[i][j] = (sum % 2) > 1 ? sum / 2 + 1 : sum / 2;
                }
            }

            //左下没有
            if (i == ROW_SIZE - 1 && j == 0) {
                up = ar[i - 1][j];
                right = ar[i][j + 1];

                if (cmp(cur, up) && cmp(cur, right)) {
                    sum = up + right;
                    ar[i][j] = (sum % 2) > 1 ? sum / 2 + 1 : sum / 2;
                }
            }

            //右下没有
            if (i == ROW_SIZE - 1 && j == COL_SIZE - 1) {
                up = ar[i - 1][j];
                left = ar[i][j - 1];

                if (cmp(cur, up) && cmp(cur, left)) {
                    sum = up + left;
                    ar[i][j] = (sum % 2) > 1 ? sum / 2 + 1 : sum / 2;
                }
            }
        }
    }

    printf("\n失真处理后打印图片:\n");
    printf("\n第  x 行: ");
    for (int m = 0; m < COL_SIZE; ++m) {
        printf("%3d ", m);
    }
    printf("\n");
    for (int i = 0; i < ROW_SIZE; ++i) {
        printf("第 %2d 行: ", i);
        for (int j = 0; j < COL_SIZE; ++j) {
            printf("%2c", ar[i][j] + 48);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}

int cmp(int a, int b) {
    int n = 0;

    if (a > b && a - b > 1)
        n = 1;
    if (a < b && b - a > 1)
        n = 1;

    return n;
}
