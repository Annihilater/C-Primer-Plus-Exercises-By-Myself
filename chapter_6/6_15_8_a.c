//
// Created by klause on 2020/6/23.
//

#include <stdio.h>

int main(void) {
    char ch;
    scanf("%c", &ch);
    while (ch != 'g') {
        printf("%c", ch);
        scanf("%c", &ch);
//        printf("test: %c\n", ch);
    }
    return 0;
}
