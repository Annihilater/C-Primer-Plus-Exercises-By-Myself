//
// Created by klause on 2020/6/23.
//

#include <stdio.h>

int main(void) {
    char ch[26];
    for (int i = 0; i < 26; ++i) {
        ch[i] = (char) ('a' + i);
        printf("%c", ch[i]);
    }

    return 0;
}
