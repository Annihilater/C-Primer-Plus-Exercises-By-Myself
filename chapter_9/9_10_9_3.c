//
// Created by klause on 2020/6/26.
//

#include <stdio.h>

int helper(int, int);

void menu(void);

int main(void) {
    int a = 1, b = 10, result;
    menu();
    printf("Please enter an integer between %d and %d: ", a, b);
    result = helper(a, b);
    printf("%d", result);
    return 0;
}

void menu(void) {
    printf("Please choose one of the following:\n");
    printf("1) copy files           2) move files\n");
    printf("3) remove files         4) quit\n");
    printf("Enter the number of your choice:\n");
}

int helper(int low, int up) {
    int n;
    while (1) {
        if (scanf("%d", &n) == 1) {
            if (n >= low && n <= up)
                return n;
            else
                printf("Please enter an integer between %d and %d: ", low, up);
            continue;
        } else
            return 4;
    }
}
