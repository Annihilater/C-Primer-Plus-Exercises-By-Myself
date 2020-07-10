//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>

char *string_in(char *, char *);

int main(void) {
    char s1[100] = "hats";
    char s2[100] = "at";
    char *p;
    p = string_in(s1, s2);
    if (p == NULL)
        printf("%s not in %s!", s2, s1);
    else
        printf("找到了: %c", *p);
    return 0;
}

char *string_in(char *s1, char *s2) {
    char *p = NULL;
    int n, m, in_or_not = 0;// in_or_not 表示 s2 在不在 s1 中，1 表示在，0 表示不在

    n = (int) strlen(s1);//n 表示 s1 的长度
    m = (int) strlen(s2);//m 表示 s2 的长度

    /*
     *  先在 s1 中查找 s2 的首字符，如果在 i 位置找得到
     *  再根据 s1 中找到的位置 i 向后 m 位，与 s2 进行对比
     *  使用 for 循环 m 遍进行遍历，如果遇到不相等的字符，就立即跳出循环，继续进行第一步在 s1 中继续从 i+1 位找 s2 的首字母
     *  另外循环中根据 j 与 m-1 的大小来确定循环是否完整的遍历了 s2，如果完整的遍历了 s2，还没有跳出循环的话，
     *  就表明 s2 与 s1 中 i 位置之后的字符串是相等的，说明 s2 在 s1 中，将 in_or_not 标记为 1
     *  等内部循环结束之后，查看 in_or_not 的值，判断 s2 在不在 s1 中
     */
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[0]) {

            for (int j = 0; j < m; ++j) {
                if (*(s1 + i + j) != *(s2 + j))
                    break;
                if (j == (m - 1))
                    in_or_not = 1;
            }

            if (in_or_not) {
                p = s1 + i;
                break;
            }
        }
    }

    if (in_or_not)
        return p;
    else
        return NULL;
}
