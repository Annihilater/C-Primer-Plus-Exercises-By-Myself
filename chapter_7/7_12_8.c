//
// Created by klause on 2020/6/24.
//

#include <stdio.h>

#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

void helper(double pay_rate);

int main(void) {
    int pay_rate_num;

    while (1) {
        printf("Enter the number corresponding to the desired pay rate or action: \n");
        printf("1) $%05.2f/hr            2) $%05.2f/hr\n", PAY_RATE1, PAY_RATE2);
        printf("3) $%05.2f/hr            4) $%05.2f/hr\n", PAY_RATE3, PAY_RATE4);
        printf("5) quit\n");
        scanf("%d", &pay_rate_num);

        switch (pay_rate_num) {
            case 1: {
                helper(PAY_RATE1);
                break;
            }
            case 2: {
                helper(PAY_RATE2);
                break;
            }
            case 3: {
                helper(PAY_RATE3);
                break;
            }
            case 4: {
                helper(PAY_RATE4);
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                printf("Please input 1~5: ");
                continue;
            }
        }
        return 0;
    }
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

