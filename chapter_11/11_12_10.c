//
// Created by klause on 2020/6/28.
//

#include <stdio.h>

int helper(char *);

int main(void) {
    char name[100] = "hellogood";
    int length;
    length = helper(name);
    printf("Length of the word is: %d.", length);
    return 0;
}

int helper(char *ptr) {
    int n = 0;
    while (*ptr++)
        n++;
    return n;
}
