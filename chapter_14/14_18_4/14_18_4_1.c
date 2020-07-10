//
// Created by klause on 2020/7/7.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20
#define ARRSIZE 5

struct name {
    char first[SIZE];
    char middle[SIZE];
    char last[SIZE];
};

struct people {
    struct name na;
    int ssn;
};

void show(const struct people ar[ARRSIZE]);

int main(void) {
    struct people ar[ARRSIZE] = {
            {"Claude",  "",     "Johnny",     302039823},
            {"Bblythe", "",     "Harry",      302039824},
            {"Eudora",  "Good", "Daniel",     302039825},
            {"Carter",  "",     "Springhall", 302039826},
            {"Primo",   "",     "Lamb",       302039827},
    };

    show(ar);
    return 0;
}

void show(const struct people ar[ARRSIZE]) {
    for (int i = 0; i < ARRSIZE; ++i) {
        if (strcmp(ar[i].na.middle, "") == 0)
            printf("%s, %s -- %d\n", ar[i].na.first, ar[i].na.last, ar[i].ssn);
        else
            printf("%s, %s %c.-- %d\n", ar[i].na.first, ar[i].na.last, toupper(ar[i].na.middle[0]), ar[i].ssn);
    }
}
