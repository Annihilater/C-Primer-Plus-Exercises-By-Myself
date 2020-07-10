//
// Created by klause on 2020/6/25.
//
#include <stdio.h>

int main(void) {
    int ch, n = 0;
    while ((ch = getchar()) != '#') {
        if (ch >= 32) {                     //处理可打印字符
            printf("%c/%d ", ch, ch);
            n++;
        } else if (ch == '\n') {            //处理换行符
            printf("\\n %d ", ch);
        } else if (ch == '\t') {            //处理制表符
            printf("\\t %d ", ch);
        } else {                            //处理非打印字符
            printf("^%c %d ", ch + 64, ch);
        }
        if ((n % 10) == 0) {
            printf("\n");
        }
    }
    return 0;
}
