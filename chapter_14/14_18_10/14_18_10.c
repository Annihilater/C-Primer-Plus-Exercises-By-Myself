//
// Created by klause on 2020/7/7.
//

#include <stdio.h>
#include <string.h>

void func1(void);

void func2(void);

void func3(void);

void func4(void);

int main(void) {
    void (*ar[4])(void) ={func1, func2, func3, func4};
    char t;

    printf("Select function(a~d):\n");
    printf("a.func1     b.func2\n");
    printf("c.func3     d.func4\n");

    while (1) {
        while (scanf("%c", &t) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Select function(a~d):\n");
            printf("a.func1     b.func2\n");
            printf("c.func3     d.func4\n");
        }
        if (t == '\n')
            continue;

        if (strchr("abcd", t) != NULL)
            break;

        printf("Select function(a~d):\n");
        printf("a.func1     b.func2\n");
        printf("c.func3     d.func4\n");
    }

    switch (t) {
        case 'a': {
            ar[0]();
            break;
        }
        case 'b': {
            ar[1]();
            break;
        }
        case 'c': {
            ar[2]();
            break;
        }
        case 'd': {
            ar[3]();
            break;
        }
        default:
            break;
    }
    return 0;
}

void func1(void) {
    printf("This is Function 1.\n");
}

void func2(void) {
    printf("This is Function 2.\n");
}

void func3(void) {
    printf("This is Function 3.\n");
}

void func4(void) {
    printf("This is Function 4.\n");
}
