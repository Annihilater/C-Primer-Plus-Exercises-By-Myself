//
// Created by klause on 2020/7/8.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

int bstrtoi(char *pbin);

int main(void) {
    char *pbin = "01001001";
    int result;
    result = bstrtoi(pbin);
    printf("%d", result);
    return 0;
}

int bstrtoi(char *pbin) {
    int len = 0, total = 0;
    while (*pbin != '\0') {//结束时 pbin 指到空字符 '\0'
        len++;
        pbin++;
    }
    pbin--;
    for (int i = 0; i < len; ++i) {
        if (*pbin == '1')
            total += (int) pow((double) 2, (double) i);
        pbin--;
    }
    return total;
}
