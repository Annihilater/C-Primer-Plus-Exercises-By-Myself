//
// Created by klause on 2020/6/24.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch = 0;
    int n_space = 0;
    int n_break = 0;
    int n_other = 0;

    printf("Please enter text to be analyzed(# to terminate):");
    while ((ch = getchar()) != '#') {
        if (isspace(ch))
            n_space++;
        else if (ch == '\n')
            n_break++;
        else
            n_other++;
    }
    printf("break = %d, space = %d, other = %d\n", n_break, n_space, n_other);
    return 0;
}
