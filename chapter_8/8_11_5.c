//
// Created by klause on 2020/6/25.
//
#include <stdio.h>

char get_choice(void);

char get_first(void);

int main(void) {
    int low = 1, high = 100, guess = 50;
    char ch;

    printf("Pick an integer from 1 to 100. I will try to guess it\n");
    printf("Unis your number %d?\n", guess);

    while ((ch = get_choice()) != 'q') {

        if (ch == 'a') {
            printf("I knew I could do it!\n");
            break;
        } else if (ch == 'b') {
            printf("It is too small!\n");
            low = guess + 1;
        } else if (ch == 'c') {
            printf("It is too big!\n");
            high = guess - 1;
        }
        guess = (low + high) / 2;
        printf("Unis your number %d?\n", guess);
    }
    printf("Done!\n");
    return 0;
}

char get_choice(void) {
    int ch;

    printf("Enter the letter of your choice: \n");
    printf("a. right       b. too small\n");
    printf("c. too big     q. quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'c') && ch != 'q') {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();
    }
    return (char) ch;
}

char get_first(void) {
    int ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;
    return (char) ch;
}
