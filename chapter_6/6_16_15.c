//
// Created by klause on 2020/6/23.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char ch[40];
    for (int i = 0; i < 20; ++i) {
        scanf("%c", &ch[i]);
    }
    for (int j = 0; j < 20; ++j) {
        printf("%c", ch[j]);
//        printf("%d%c", j, ch[j]);
    }
    return 0;
}
