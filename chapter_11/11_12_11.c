//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);

int main(void) {
    char tmp[100];
    s_gets(tmp, 100);
    printf("%s", tmp);
    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *end;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        end = strchr(ret_val, '\n');//strchr 查找字符串中是否存在换行符，如果存在则返回首次出现换行符的指针
        if (end)                        //如果出现换行符则将换行符替换为空字符
            *end = '\0';
        else
            while (getchar() != '\n')   //如果没有出现换行符，则将 n 位之后、留在缓存中的字符清楚
                continue;
    }
    return ret_val;
}
