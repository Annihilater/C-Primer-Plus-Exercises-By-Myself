//
// Created by klause on 2020/7/11.
//

//效率太低了,不建议使用

#include <stdio.h>
#include <time.h>

static unsigned long int next = 1;

void lottery(int ar[], unsigned int n, unsigned int m);

unsigned int rand1(void);

int main(void) {
    unsigned int n = 100, m = 10;
    int ar[n];

    for (int i = 0; i < n; ++i) {
        ar[i] = i + 1;
    }

    lottery(ar, n, m);

    return 0;
}

void lottery(int ar[], unsigned int n, unsigned int m) {
    unsigned int r, times = 0;
    for (int i = 0; i < m; ++i) {
        while (1) {
            times++;
            r = rand1();
            if (r % n >= 0 && r % n <= 99 && ar[(r % n)] != 0) {
                printf("%d\n", ar[(r % n)]);
                ar[(r % n)] = 0;
                break;
            }
        }
    }
    printf("times = %d\n", times);
}


unsigned int rand1(void) {
    next = (unsigned int) time(0);
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}
