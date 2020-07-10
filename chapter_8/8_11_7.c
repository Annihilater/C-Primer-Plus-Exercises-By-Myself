//
// Created by klause on 2020/6/25.
//

#include <stdio.h>
#include <string.h>

#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

void helper(double pay_rate);

char get_first_char(void);

int main(void) {
    int pay_rate_num;
    char input3;

    while (1) {
        printf("Enter the number corresponding to the desired pay rate or action: \n");
        printf("a) $%05.2f/hr            b) $%05.2f/hr\n", PAY_RATE1, PAY_RATE2);
        printf("c) $%05.2f/hr            d) $%05.2f/hr\n", PAY_RATE3, PAY_RATE4);
        printf("q) quit\n");

        /*
         * 因为将提示的从 1、2、3、4、5 数字改成了 a、b、c、d、q，scanf 读取输入的时候会将换行符留在输入队列
         * 造成下一次 scanf 读取输入的时候会一直读取换行符，读取失败一直读取，所以需要清除输入缓存队列中的换行符
         * 使用 get_first_char 函数来只读取首字符的方式来清除换行符
         */
//        scanf("%d", &pay_rate_num); // 来用使用 1、2、3、4、5 时使用的读取方式
        pay_rate_num = get_first_char();

        switch (pay_rate_num) {
            case 'a': {
                printf("Select a type:\n");
                helper(PAY_RATE1);
                break;
            }
            case 'b': {
                printf("Select b type:\n");
                helper(PAY_RATE2);
                break;
            }
            case 'c': {
                printf("Select c type:\n");
                helper(PAY_RATE3);
                break;
            }
            case 'd': {
                printf("Select d type:\n");
                helper(PAY_RATE4);
                break;
            }
            case 'q': {
                return 0;
            }
            default: {
                printf("Please input a、b、c、d、q: \n");
                continue;
            }
        }
        return 0;
    }
}

char get_first_char(void) {     // 正确读取一个字符，多了的报错提示重新输入
    char input, input2;
    int ch = 0;

    /*
     * 此处输入数字，scanf 一样返回 1
     * 此处输入换行符，scanf 一样返回 1
     * 因为输入单个字符或者单个数字都是换行符结尾
     */
    while (scanf("%c", &input) != 1) {

        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not correct choice.");
        printf("Please input a correct choice: ");
    }

    /*
     * 因为之前的scanf 会遗留换行符，这里对换行符做一个处理
     * 这样处理不会造成数据丢失：
     * 因为可能的情况有：
     * a[enter] 处理换行符正确
     * ac[enter] 只读取了 a 并没有遗留换行符
     * [enter] 直接处理换行符
     * a 100[enter] 没有换行符遗留，遗留的是数字 100
     */
    scanf("%c", &input2);
    if (input2 == '\n') {
        printf("已经去除了换行符!\n");
    }

    return (char) input;
}

void helper(double pay_rate) {
    double earning;
    int work_time = 0;

    printf("Please input your working time: ");
    scanf("%d", &work_time);

    if (work_time <= 40) {
        earning = pay_rate * work_time;
    } else {
        earning = pay_rate * 40 + (work_time - 40) * 1.5;
    }

    if (earning <= 300) {//300 美元以内
        earning = earning * (1 - RATE1);
    } else if (earning <= 450) {// 300 - 450 美元
        earning = 300 * (1 - RATE1) + (earning - 300) * (1 - RATE2);
    } else {//450 美元以上
        earning = 300 * (1 - RATE1) + (450 - 300) * (1 - RATE2) + (earning - 450) * (1 - RATE3);
    }
    printf("$%.2lf", earning);
}
