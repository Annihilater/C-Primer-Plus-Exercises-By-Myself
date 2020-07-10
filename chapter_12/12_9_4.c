//
// Created by klause on 2020/7/1.
//

#include <stdio.h>

int call_count = 0;

int func(void);

int main(void) {
    int n, m = 0;

    printf("Please input an integer for loop number:");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        m = func();
    }
    printf("func() has been called %d times!", m);
    return 0;
}

int func(void) {
    call_count++;
    return call_count;
}
