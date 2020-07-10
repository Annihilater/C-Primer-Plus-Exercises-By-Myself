//
// Created by klause on 2020/6/24.
//
#include <stdio.h>

#define HOURLY_SALARY 10
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void) {
    double earning;
    int work_time = 0;
    printf("Please input your working time: ");
    scanf("%d", &work_time);

    if (work_time <= 40) {
        earning = HOURLY_SALARY * work_time;
    } else {
        earning = HOURLY_SALARY * 40 + (work_time - 40) * 1.5;
    }

    if (earning <= 300) {
        earning = earning * (1 - RATE1);
    } else if (earning <= 450) {
        earning = 300 * (1 - RATE1) + (earning - 300) * (1 - RATE2);
    } else {
        earning = 300 * (1 - RATE1) + (450 - 300) * (1 - RATE2) + (earning - 450) * (1 - RATE3);
    }
    printf("%.2lf$", earning);
    return 0;
}
