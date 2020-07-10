//
// Created by klause on 2020/6/24.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int input;
    int n_even = 0;
    int n_odd = 0;
    int sum_even = 0;
    int sum_odd = 0;
    float average_even = 0;
    float average_odd = 0;

    while (scanf("%d", &input) == 1) {//input "1 2 3 4 5 6 7 8 9 0"
        if (input == 0)
            break;

        if (input % 2 == 0) {
            sum_even += input;
            n_even++;
            printf("偶数%d\n", input);
        } else {
            sum_odd += input;
            n_odd++;
            printf("奇数%d\n", input);
        }
    }

    if (n_even != 0)
        average_even = (float) sum_even / (float) n_even;

    if (n_odd != 0)
        average_odd = (float) sum_odd / (float) n_odd;

    printf("even: %d %.2f\n", n_even, average_even);
    printf("odd: %d %.2f\n", n_odd, average_odd);
    return 0;
}
