//
// Created by klause on 2020/6/25.
//

#include <stdio.h>

int main(void) {
    char ch, input;
    int a, b;

//    while (scanf("%c", &ch) == 1) {
//        printf("%c-%d\n", ch, ch);
//    }
    a = scanf("%c", &input);
    printf("%d\n", a);
    b = scanf("%c", &input);
    printf("%d\n", b);
    return 0;
}
