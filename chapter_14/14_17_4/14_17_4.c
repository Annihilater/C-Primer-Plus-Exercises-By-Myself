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

int main(void) {
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
    for (int i = 0; i < 12; ++i) {
        printf("month_name:%10s acronym:%3s days:%2d month_number:%2d\n",
               ar[i].month_name, ar[i].acronym, ar[i].days, ar[i].month_number);
    }

    return 0;
}
