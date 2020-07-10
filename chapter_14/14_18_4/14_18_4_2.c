//
// Created by klause on 2020/7/7.
//


#include <stdio.h>
#include <string.h>
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
    int ssn;//Social security number 社会保险号
};

void show(struct people p);

int main(void) {
    struct people ar[ARRSIZE] = {
            {"Claude",  "",     "Johnny",     302039823},
            {"Bblythe", "",     "Harry",      302039824},
            {"Eudora",  "Good", "Daniel",     302039825},
            {"Carter",  "",     "Springhall", 302039826},
            {"Primo",   "",     "Lamb",       302039827},
    };

    for (int i = 0; i < ARRSIZE; ++i) {
        show(ar[i]);
    }
    return 0;
}

void show(struct people p) {
    if (strcmp(p.na.middle, "") == 0)
        printf("%s, %s -- %d\n", p.na.first, p.na.last, p.ssn);
    else
        printf("%s, %s %c.-- %d\n", p.na.first, p.na.last, toupper(p.na.middle[0]), p.ssn);
}

