//
// Created by klause on 2020/7/6.
//

#include <stdio.h>

struct month {
    char month_name[20];    //月份名
    char acronym[4];        //月份 3 个字母的缩写
    int days;               //月份天数
    int month_number;       //月份号
};
struct month ar[12] = {//非闰年
        {"January",   "Jan", 31, 1},
        {"February",  "Feb", 29, 2},
        {"March",     "Mar", 31, 3},
        {"April",     "Apr", 30, 4},
        {"May",       "May", 31, 5},
        {"June",      "Jun", 30, 6},
        {"July",      "Jul", 31, 7},
        {"August",    "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October",   "Oct", 31, 10},
        {"November",  "Nov", 30, 11},
        {"December",  "Dec", 31, 12},
};

int main(void) {
    int n, sum;
    printf("Please input an integer(1~12)(0 to quit): ");

    while (1) {
        sum = 0;
        while (scanf("%d", &n) != 1 || n < 0 || n > 12) {
            while (getchar() != '\n')
                continue;

            printf("Please input an integer(1~12)(0 to quit): ");

        }
        if (n == 0)
            break;

        for (int i = 0; i < n; ++i) {
            sum += ar[i].days;
        }

        printf("Sum days is %d.\n", sum);

        printf("Please input an integer(1~12)(0 to quit): ");
    }

    return 0;
}
