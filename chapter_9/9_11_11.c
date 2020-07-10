//
// Created by klause on 2020/6/26.
//

#include <stdio.h>

int Fibonacci(int);

int main(void) {
    int result, n;
    printf("Please enter an integer number: ");
    scanf("%d", &n);
    result = Fibonacci(n);
    printf("The result = %d", result);
    return 0;
}

int Fibonacci(int n) {
    int result, tmp1 = 1, tmp2 = 1;

    for (int i = 3; i <= n; ++i) {
        result = tmp1 + tmp2;
        tmp1 = tmp2;
        tmp2 = result;
    }
    return result;
}
