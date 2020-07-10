//
// Created by klause on 2020/6/28.
//

#include <stdio.h>

char *s_gets(char *st, int n);

int main(void) {
    char tmp[3];
    s_gets(tmp, 4);
    printf("%s", tmp);
    return 0;
}

/*
 * 读取整行输入并用空字符替代换行符，或者读取一部分输入，并丢弃其余部分
 */
char *s_gets(char *st, int n) {
    char *ret_val;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (*st != '\n' && *st != '\0') // 寻找空字符或者换行符
            st++;
        if (*st == '\n')                   // 如果找到换行符，则将换行符替换为 空字符
            *st = '\0';
        else
            while (getchar() != '\n')      // 如果没有找到换行符（找到了空字符），那么就清空空字符后面的缓存
                continue;
    }
    return ret_val;
}
