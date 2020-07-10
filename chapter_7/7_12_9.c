//
// Created by klause on 2020/6/24.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

int main(void) {
    bool isPrime;
    unsigned int input;
    printf("Please input a int number: ");
    if (scanf("%d", &input) == 1) {
        for (int i = 2; i <= input; ++i) {

            isPrime = TRUE;
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    isPrime = FALSE;
                }
            }
            if (isPrime) {
                printf("%d ", i);
            }
        }
    }
    return 0;
}
