//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>

#define S1SIZE 100
#define S2SIZE 50

char *mystrcopy(char *, char *, int);

int main(void) {
    char s1[S1SIZE] = "hello";
    char s2[S2SIZE] = "wellgoodname";
    int n = 10;

    mystrcopy(s1, s2, n);
    printf("%s", s1);
    return 0;
}

// 区分 s2 的长度大于 n 和小于 n 两种情况
char *mystrcopy(char *s1, char *s2, int n) {
    int limit = n;
    if (strlen(s2) < n)
        limit = (int) strlen(s2);

    for (int i = 0; i < limit; ++i)
        *(s1 + i) = *(s2 + i);
    *(s1 + n) = '\0';

    return s1;
}
