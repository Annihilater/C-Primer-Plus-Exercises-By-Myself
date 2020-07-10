//
// Created by klause on 2020/7/6.
//

#include <stdio.h>

typedef struct lens {
    float foclen;
    float fstop;
    char brand[30];
} LENS;

int main(void) {
/*    LENS ar[10] = {
            {},
            {},
            {500, (float) 2.0, "Remarkata"},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
    };*/

    LENS ar[10] = {[2] = {500, (float) 2.0, "Remarkatar"}};

    printf("foclen=%.2f fstop=%.2f brand=%s", ar[2].foclen, ar[2].fstop, ar[2].brand);
    return 0;
}
