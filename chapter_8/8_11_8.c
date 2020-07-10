//
// Created by klause on 2020/6/25.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    float first, second;
    int t;
    char ch;

    while (1) {
        printf("Please enter 1~5 to select function:\n");
        printf("1.加法      2.减法\n");
        printf("3.乘法      4.除法\n");
        printf("5.quit\n");

        while (scanf("%d", &t) != 1) {
            while ((ch = getchar()) != '\n') {
                putchar(ch);
                printf(" is not an integer.\n");
            }
            printf("Please enter 1~5 to select function:\n");
            printf("1.加法      2.减法\n");
            printf("3.乘法      4.除法\n");
            printf("5.quit\n");
        }

        if (!isdigit(t))
            continue;

        if (t == 5)// 选择 5 就退出
            return 0;

        if (t == 1 || t == 2 || t == 3 || t == 4) {// 选择其他非法字符就提示重新输入
            printf("Please input first number: ");
            while (scanf("%f", &first) != 1) {
                printf("Please input correct first number:");
            }

            // 选择除法时，第二个数不能为 0
            if (t == 2) {
                printf("Please input second number: ");
                while (scanf("%f", &second) != 1 || second == 0) {
                    printf("Please input correct second number, if you select divide, second number can not be 0.\n");
                }
            } else {
                printf("Please input second number: ");
                while (scanf("%f", &second) != 1) {
                    printf("Please input correct second number");
                }
            }

            switch (t) {
                case 1: {
                    printf("select 加法\n");
                    printf("%.2f + %.2f = %.2f", first, second, first + second);
                    break;
                }
                case 2: {
                    printf("select 减法\n");
                    printf("%.2f - %.2f = %.2f", first, second, first - second);
                    break;
                }
                case 3: {
                    printf("select 乘法\n");
                    printf("%.2f * %.2f = %.2f", first, second, first * second);
                    break;
                }
                case 4: {
                    printf("select 除法\n");
                    printf("%.2f / %.2f = %.2f", first, second, first / second);
                    break;
                }
                default:
                    printf("Please input 1~5 to select function:");
                    break;
            }
            break;
        }
        printf("Please input 1~5 to select function:");
    }
    return 0;
}
