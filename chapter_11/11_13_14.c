//
// Created by klause on 2020/6/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    double n;
    int m;

    if (argc != 3)
        printf("Argc was wrong;");

    n = atof(argv[1]);
    m = atoi(argv[2]);
    printf("%.2f ^ %d = %.2f!\n", n, m, pow(n, m));
    return 0;
}

