//
// Created by klause on 2020/7/7.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20
#define ARRSIZE 12

struct seat {
    int number;
    int status;
    char fn[SIZE];
    char ln[SIZE];
};

void show(struct seat ar[ARRSIZE]);

void show_menu(void);

void show_one_empty_seats(struct seat ar[ARRSIZE]);

void show_empty_seats_list(struct seat ar[ARRSIZE]);

void show_not_empty_seats_list(struct seat ar[ARRSIZE]);

void show_empty_seats_list_by_alphabetical(struct seat ar[ARRSIZE]);

void order_seat(struct seat ar[ARRSIZE]);

void cancel_seat(struct seat ar[ARRSIZE]);

int main(void) {
    char t;
    struct seat ar[ARRSIZE] = {
            {1,  0, "",        ""},
            {2,  0, "",        ""},
            {3,  0, "",        ""},
            {4,  0, "",        ""},
            {5,  0, "",        ""},
            {6,  1, "Claude",  "Johnny"},
            {7,  1, "Bblythe", "Harry"},
            {8,  1, "Eudora",  "Daniel"},
            {9,  1, "Carter",  "Springhall"},
            {10, 1, "Primo",   "Lamb"},
            {11, 1, "Bella",   "Alfred"},
            {12, 1, "Solomon", "Bill"},
    };

    show(ar);
    show_menu();

    while (1) {
        while (scanf("%c", &t) != 1) {
            while (getchar() != '\n')
                continue;
        }
        if (t == '\n')
            continue;

        switch (t) {
            case 'a': {
                show_one_empty_seats(ar);
                break;
            }
            case 'b': {
                show_empty_seats_list(ar);
                break;
            }
            case 'c': {
                show_empty_seats_list_by_alphabetical(ar);
                break;
            }
            case 'd': {
                order_seat(ar);
                break;
            }
            case 'e': {
                cancel_seat(ar);
                break;
            }
            case 'f': {
                exit(EXIT_SUCCESS);
            }
            default:
                break;
        }
        show_menu();
    }
    return 0;
}

void show(struct seat ar[ARRSIZE]) {
    printf("%3s %2s %13s %14s\n", "No", "status", "first_name", "last_name");
    for (int i = 0; i < ARRSIZE; ++i) {
        printf("%3d %2d %15s %15s\n", ar[i].number, ar[i].status, ar[i].fn, ar[i].ln);
    }
    printf("\n");
}

void show_menu(void) {
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
}

void show_one_empty_seats(struct seat ar[ARRSIZE]) {
    for (int i = 0; i < ARRSIZE; ++i) {
        if (ar[i].status == 0) {
            printf("NO. %d is empty.\n", ar[i].number);
            break;
        }
    }
}

void show_empty_seats_list(struct seat ar[ARRSIZE]) {
    printf("Empty seats number:\n");
    for (int i = 0; i < ARRSIZE; ++i) {
        if (ar[i].status == 0)
            printf("%d ", ar[i].number);
    }
    printf("\n");
}

void show_not_empty_seats_list(struct seat ar[ARRSIZE]) {
    printf("Empty seats number:\n");
    for (int i = 0; i < ARRSIZE; ++i) {
        if (ar[i].status == 1)
            printf("%d ", ar[i].number);
    }
    printf("\n");
}

void show_empty_seats_list_by_alphabetical(struct seat ar[ARRSIZE]) {
    struct seat ar1[ARRSIZE];
    struct seat tmp;

    for (int k = 0; k < ARRSIZE; ++k) {
        ar1[k] = ar[k];
    }

    for (int i = 0; i < ARRSIZE - 1; ++i) {
        for (int j = i + 1; j < ARRSIZE; ++j) {
            if (strcmp(ar1[i].fn, ar1[j].fn) > 0) {
                tmp = ar1[j];
                ar1[j] = ar1[i];
                ar1[i] = tmp;
            }
        }
    }

    show(ar1);
}

void order_seat(struct seat ar[ARRSIZE]) {
    int n, is_ok = 0;

    printf("Please input a number of seat from next line:\n");
    show_empty_seats_list(ar);

    while (1) {
        while (scanf("%d", &n) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Please input a number from next line:\n");
            show_empty_seats_list(ar);
        }

        for (int i = 0; i < ARRSIZE; ++i) {
            if (is_ok == 0 && ar[i].status == 0 && ar[i].number == n) {
                is_ok = 1;
            }
        }

        if (is_ok)
            break;

        printf("Please input a number from next line:\n");
        show_empty_seats_list(ar);
    }

    ar[n - 1].status = 1;
    printf("Please input your first name:\n");
    scanf("%s", ar[n - 1].fn);
    printf("Please input your last name:\n");
    scanf("%s", ar[n - 1].ln);

    printf("Order seat successful!.\n");
    show(ar);
}

void cancel_seat(struct seat ar[ARRSIZE]) {
    int n, is_ok = 0;
    char first_name[20], last_name[20];

    printf("Please input a number of seat from next line:\n");
    show_not_empty_seats_list(ar);

    while (1) {
        while (scanf("%d", &n) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Please input a number of seat from next line:\n");
            show_not_empty_seats_list(ar);
        }

        for (int i = 0; i < ARRSIZE; ++i) {
            if (is_ok == 0 && ar[i].status == 1 && ar[i].number == n) {
                is_ok = 1;
            }
        }

        if (is_ok)
            break;

        printf("Please input a number of seat from next line:\n");
        show_not_empty_seats_list(ar);
    }

    while (1) {
        printf("Please input your first name:\n");
        scanf("%s", first_name);
        printf("Please input your last name:\n");
        scanf("%s", last_name);

        if (strcmp(ar[n - 1].fn, first_name) == 0 && strcmp(ar[n - 1].ln, last_name) == 0) {
            ar[n - 1].status = 0;
            strcpy(ar[n - 1].fn, "");
            strcpy(ar[n - 1].ln, "");
            break;
        } else {
            printf("Your name was wrong. Please try again.\n");
        }
    }

    printf("Cancel seat successful!.\n");
    show(ar);
}
