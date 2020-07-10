//
// Created by klause on 2020/7/6.
//

#include <stdio.h>

struct name {
    char first[20];
    char last[20];
};

struct bem {
    int limbs;
    struct name title;
    char type[30];
};

struct bem *pb;

struct bem deb = {
        6,
        {"Berbnazel", "Gwolkapwolk"},
        "Arcturan",
};

void helper(const struct bem *tmp);

int main(void) {
    pb = &deb;
    helper(pb);
    return 0;
}

void helper(const struct bem *tmp) {
    printf("%s %s is a %d-limbed %s.", tmp->title.first, tmp->title.last, tmp->limbs, tmp->type);
}
