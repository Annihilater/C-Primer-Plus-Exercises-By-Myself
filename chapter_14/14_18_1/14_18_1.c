//
// Created by klause on 2020/7/7.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
    char name[20];
    printf("Please input month name(q to quit): ");

    while (1) {
        sum = 0;
        while (scanf("%s", name) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Please input month name(q to quit): ");
        }

        for (int j = 0; j < strlen(name); ++j) {
            if (isupper(name[j]))
                name[j] = (char) tolower(name[j]);
        }

        if (strcmp(name, "quit") == 0) {
            printf("Program quit!");
            break;
        } else if (strcmp(name, "january") == 0)
            n = 1;
        else if (strcmp(name, "february") == 0)
            n = 2;
        else if (strcmp(name, "march") == 0)
            n = 3;
        else if (strcmp(name, "april") == 0)
            n = 4;
        else if (strcmp(name, "may") == 0)
            n = 5;
        else if (strcmp(name, "june") == 0)
            n = 6;
        else if (strcmp(name, "july") == 0)
            n = 7;
        else if (strcmp(name, "august") == 0)
            n = 8;
        else if (strcmp(name, "september") == 0)
            n = 9;
        else if (strcmp(name, "october") == 0)
            n = 10;
        else if (strcmp(name, "november") == 0)
            n = 11;
        else if (strcmp(name, "december") == 0)
            n = 12;
        else {
            printf("Please input month name(q to quit): ");
            continue;
        }


        for (int i = 0; i < n; ++i) {
            sum += ar[i].days;
        }

        printf("Sum days is %d.\n", sum);

        printf("Please input month name(q to quit): ");
    }

    return 0;
}
