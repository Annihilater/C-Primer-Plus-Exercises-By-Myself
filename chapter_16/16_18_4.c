//
// Created by klause on 2020/7/11.
//

#include <stdio.h>
#include <time.h>

void func(double n);

int main(void) {
    double start = clock();
    double m = 1000000;
    func(m);
    double end = clock();
    printf("Spending time : %f seconds.\n", (end - start) / CLOCKS_PER_SEC);
    return 0;
}

void func(double n) {
    for (int i = 0; i < n; ++i) {
        printf("%d\n", i);
    }
}
