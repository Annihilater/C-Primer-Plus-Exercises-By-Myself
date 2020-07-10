//
// Created by klause on 2020/7/6.
//
#include <stdio.h>
#include <string.h>

typedef struct lens {
    float foclen;
    float fstop;
    char brand[30];
} LENS;

int main(void) {
    LENS ar[10];

    ar[2].foclen = 500;
    ar[2].fstop = (float) 2.0;
    strcpy(ar[2].brand, "Remarkata");

    printf("foclen=%.2f fstop=%.2f brand=%s", ar[2].foclen, ar[2].fstop, ar[2].brand);
    return 0;
}
