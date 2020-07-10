//
// Created by klause on 2020/7/2.
//

#include <stdio.h>

#define SIZE 10

int main(int argc, char *argv[]) {
    FILE *fp;
    double ar[SIZE];
    int i = 0;
    double sum = 0, avg;

    if (argc == 1) {
        printf("Please input your double number(# to end):\n");
        while (fscanf(stdin, "%lf", &ar[i]) == 1 && (ar[i] != '#')) {
            sum += ar[i];
            i++;
        }
    } else if (argc == 2) {
        printf("%s is file name.\n", argv[1]);
        printf("Read number from %s file.\n", argv[1]);
        fp = fopen(argv[1], "r");

        while (fscanf(fp, "%lf", &ar[i]) == 1 && (ar[i] != '#')) {
            sum += ar[i];
            i++;
        }
    } else {
        printf("Wrong!\n");
    }

    avg = sum / i;
    for (int j = 0; j < i; ++j) {
        printf("%.2lf ", ar[j]);
    }
    printf("\n算数平均值: %.2lf\n", avg);
    return 0;
}
