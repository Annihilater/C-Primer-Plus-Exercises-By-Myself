//
// Created by klause on 2020/6/19.
//

#include <stdio.h>

int main(void) {
    char first_name[40];
    char last_name[40];
    int first_name_len, last_name_len;
    printf("Please enter your first name:\n");
    scanf("%s", first_name);
    printf("Please enter your last name:\n");
    scanf("%s", last_name);
    first_name_len = strlen(first_name);
    last_name_len = strlen(last_name);
    printf("%s %s\n", first_name, last_name);
    printf("%*d %*d\n", first_name_len, first_name_len, last_name_len, last_name_len);
    printf("%s %s\n", first_name, last_name);
    printf("%-*d %-*d\n", first_name_len, first_name_len, last_name_len, last_name_len);

    return 0;
}
