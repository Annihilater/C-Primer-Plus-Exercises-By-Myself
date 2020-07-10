//
// Created by klause on 2020/7/7.
//

/*
 * 思路:
 * 获取输入年
 *      验证输入的是数字
 * 获取输入月
 *      提供输入选项:
 *      a、输入月份名或者缩写
 *          验证字符串输入
 *          转换成月份号
 *      b、输入月份号
 *          验证数字输入
 *          验证数字输入的大小 1-12
 * 获取输入日
 *      根据年月区分提示信息
 *      闰年
 *          1、3、5、7、8、10、12 体术输入 1-31 天
 *          4、6、9、11 提示输入 1-30 天
 *          2 提示输入 29 天
 *      平年
 *          1、3、5、7、8、10、12 提示输入 1-31 天
 *          4、6、9、11 提示输入 1-30 天
 *          2 提示输入 1-28 天
 * 依据月份遍历数组，遍历到 月份-1
 *      当年份是闰年，月份是 2 月时，+29 天
 *
 * 打印总天数
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct month {
    char month_name[20];    //月份名
    char acronym[4];        //月份 3 个字母的缩写
    int days;               //月份天数
    int month_number;       //月份号
    int status;
};
struct month ar[12] = {//非闰年
        {"January",   "Jan", 31, 1},
        {"February",  "Feb", 28, 2},
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

int input_year(void);

int input_month(void);

int input_day(int year, int month);

int main(void) {
    int day, month, year, total = 0;

    year = input_year();
    month = input_month();
    day = input_day(year, month);

    for (int i = 0; i < month - 1; ++i) {
        if (year % 4 == 0 && i == 1) {//闰年 2 月是 29 天
            total += 29;
            continue;
        }
        total += ar[i].days;
    }
    total += day;

    printf("%d 年初到 %d 月 %d 日共计 %d 天.\n", year, month, day, total);
    return 0;
}

int input_year(void) {
    int year;

    while (1) {
        printf("Please input a year number(1~2020)(0 to quit): ");
        while (scanf("%d", &year) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Please input a year number(1~2020): ");
        }

        if (year > 1 && year < 2021)
            break;
        else if (year == 0) {
            printf("Program quit!");
            exit(EXIT_FAILURE);
        } else
            continue;
    }

    return year;
}

int input_month(void) {
    char str_month[20] = {[0]='\0'};
    int n, t;

    while (1) {
        printf("Select your input type(a~b)1:\n");
        printf("a.month name or month acronym   b.month number\n");
        while ((t = getc(stdin)) != 1) {
            if (t == '\n')
                continue;
            while (getchar() != '\n')
                continue;
            if (t == 'a' || t == 'b')
                break;
            printf("Select your input type(a~b)2:\n");
            printf("a.month name or month acronym   b.month number\n");
        }

        switch (t) {
            case 'a': {
                while (1) {
                    printf("Please input month name or month acronym(q to quit)1: ");
                    while (scanf("%s", str_month) != 1) {
                        while (getchar() != '\n')
                            continue;
                        printf("Please input month name or month acronym(q to quit)2: ");
                    }

                    for (int i = 0; i < strlen(str_month); ++i) {
                        if (isupper(str_month[i]))
                            str_month[i] = (char) tolower(str_month[i]);
                    }

                    if (strcmp(str_month, "quit") == 0) {
                        printf("Program quit!");
                        exit(EXIT_FAILURE);
                    } else if (strcmp(str_month, "january") == 0 || strcmp(str_month, "jan") == 0) {
                        n = 1;
                    } else if (strcmp(str_month, "february") == 0 || strcmp(str_month, "feb") == 0) {
                        n = 2;
                    } else if (strcmp(str_month, "march") == 0 || strcmp(str_month, "mar") == 0) {
                        n = 3;
                    } else if (strcmp(str_month, "april") == 0 || strcmp(str_month, "apr") == 0) {
                        n = 4;
                    } else if (strcmp(str_month, "may") == 0) {
                        n = 5;
                    } else if (strcmp(str_month, "june") == 0 || strcmp(str_month, "jun") == 0) {
                        n = 6;
                    } else if (strcmp(str_month, "july") == 0 || strcmp(str_month, "jul") == 0) {
                        n = 7;
                    } else if (strcmp(str_month, "august") == 0 || strcmp(str_month, "aug") == 0) {
                        n = 8;
                    } else if (strcmp(str_month, "september") == 0 || strcmp(str_month, "sep") == 0) {
                        n = 9;
                    } else if (strcmp(str_month, "october") == 0 || strcmp(str_month, "oct") == 0) {
                        n = 10;
                    } else if (strcmp(str_month, "november") == 0 || strcmp(str_month, "nov") == 0) {
                        n = 11;
                    } else if (strcmp(str_month, "december") == 0 || strcmp(str_month, "dec") == 0) {
                        n = 12;
                    } else
                        continue;
                    break;
                }
                break;
            }
            case 'b': {
                while (1) {
                    printf("Please input month number(1~12)(q to quit)1: ");
                    while (scanf("%d", &n) != 1) {
                        while (getchar() != '\n')
                            continue;
                        printf("Please input month number(1~12)(q to quit)2: ");
                    }
                    if (n >= 1 && n <= 12)
                        break;
                }
                break;
            }
            default:
                continue;
        }
        break;
    }
    return n;
}

int input_day(int year, int month) {
    int day;

    while (1) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            printf("Please input a day number(1~31)(0 to quit): ");
            while (scanf("%d", &day) != 1) {
                while (getchar() != '\n')
                    continue;
                printf("Please input a day number(1~31)(0 to quit): ");
            }

            if (day >= 1 && day <= 31)
                break;
            else if (day == 0) {
                printf("Program quit!");
                exit(EXIT_FAILURE);
            } else
                continue;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            printf("Please input a day number(1~30)(0 to quit): ");
            while (scanf("%d", &day) != 1) {
                while (getchar() != '\n')
                    continue;
                printf("Please input a day number(1~30): ");
            }

            if (day >= 1 && day <= 30)
                break;
            else if (day == 0) {
                printf("Program quit!");
                exit(EXIT_FAILURE);
            } else
                continue;
        } else if (year % 4 == 0) {
            printf("Please input a day number(1~29)(0 to quit): ");
            while (scanf("%d", &day) != 1) {
                while (getchar() != '\n')
                    continue;
                printf("Please input a day number(1~29)(0 to quit): ");
            }

            if (day >= 1 && day <= 29)
                break;
            else if (day == 0) {
                printf("Program quit!");
                exit(EXIT_FAILURE);
            } else
                continue;
        } else {
            printf("Please input a day number(1~28)(0 to quit): ");
            while (scanf("%d", &day) != 1) {
                while (getchar() != '\n')
                    continue;
                printf("Please input a day number(1~28)(0 to quit): ");
            }

            if (day >= 1 && day <= 28)
                break;
            else if (day == 0) {
                printf("Program quit!");
                exit(EXIT_FAILURE);
            } else
                continue;
        }
    }

    return day;
}
