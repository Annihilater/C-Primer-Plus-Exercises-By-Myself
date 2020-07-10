//
// Created by klause on 2020/6/30.
//

#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int my_atoi(char *str);

int main(void) {
    char str[SIZE];
    int n;

    printf("Please input a string number:\n");
    scanf("%s", str);

    n = my_atoi(str);
    printf("string: %s\nnumber: %d\n", str, n);
    return 0;
}

//将字符串转为数字
int my_atoi(char *str) {
    int sign = 1, num = 0;

    // 字符串不能为空
    if (str == NULL)
        return 0;

    // 去掉字符串前面的空格
    while (isspace(*str))
        str++;

    // 判断首位是否有符号，若为负号，sign等于-1；若为正号，sign不变
    if (*str == '-')
        sign = -1;

    // 如果有符号位，就跳过符号位
    if (*str == '-' || *str == '+')
        str++;

    // 转换直到遇到非数字结束
    while (isdigit(*str)) {
        num = num * 10 + (*str - '0');//内部是 ASCII 码，字符的 ASCII 码减去'0'的 ASCII 码表示数字是多少
        str++;
    }

    // 增加符号位
    num *= sign;
    return num;
}
