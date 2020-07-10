//
// Created by klause on 2020/7/7.
//

/*
 * 思路:
 *
 * 选择航班
 *      显示航班菜单: 102、311、444、519
 *      校验输入的航班是否正确，不正确时重新输入
 *
 *
 * 预定座位
 *      显示预定座位菜单: a、b、c、d、e、f(退出菜单是返回选择航班)、g(确认座位分配)
 *      指明当前操作的航班
 *      显示座位分配状态
 *          每次预定或者取消座位之后，需要确认座位状态
 *          (使用标签标记状态，预定或取消后立即修改状态为未确认，确认状态后立即修改状态为确认)
 */

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

void show(struct seat ar[ARRSIZE], int fly_number, int status);

void show_scheduled_flight(void);

void show_menu(int fly_number, int status);

void show_one_empty_seats(struct seat ar[ARRSIZE], int fly_number, int status);

void show_empty_seats_list(struct seat ar[ARRSIZE], int fly_number, int status);

void show_not_empty_seats_list(struct seat ar[ARRSIZE], int fly_number, int status);

void show_empty_seats_list_by_alphabetical(struct seat ar[ARRSIZE], int fly_number, int status);

void order_seat(struct seat ar[ARRSIZE], int fly_number, int *p_status);

void cancel_seat(struct seat ar[ARRSIZE], int fly_number, int *p_status);

void confirm_seat(int *p_status);

int main(void) {
    int is_quit = 0, status = 1;
    int *p_status = &status;
    char t, fly;
    int fly_number = 0;
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

    show(ar, fly_number, status);

    printf("Please select a fly number:\n");
    show_scheduled_flight();

    while (1) {
        while (scanf("%c", &fly) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Please select a fly number:\n");
            show_scheduled_flight();
        }
        if (fly == '\n')
            continue;

        switch (fly) {
            case 'a': {
                fly_number = 102;
                break;
            }
            case 'b': {
                fly_number = 311;
                break;
            }
            case 'c': {
                fly_number = 444;
                break;
            }
            case 'd': {
                fly_number = 519;
                break;
            }
            case 'e': {
                exit(EXIT_SUCCESS);
            }
            default: {
                printf("Please select a fly number:\n");
                show_scheduled_flight();
                continue;
            }
        }

        show_menu(fly_number, status);

        while (1) {
            while (scanf("%c", &t) != 1) {
                while (getchar() != '\n')
                    continue;
            }
            if (t == '\n')
                continue;

            switch (t) {
                case 'a': {
                    show_one_empty_seats(ar, fly_number, status);
                    break;
                }
                case 'b': {
                    show_empty_seats_list(ar, fly_number, status);
                    break;
                }
                case 'c': {
                    show_empty_seats_list_by_alphabetical(ar, fly_number, status);
                    break;
                }
                case 'd': {
                    order_seat(ar, fly_number, p_status);
                    break;
                }
                case 'e': {
                    cancel_seat(ar, fly_number, p_status);
                    break;
                }
                case 'f': {
                    is_quit = 1;
                    break;
                }
                case 'g': {
                    confirm_seat(p_status);
                    break;
                }
                default:
                    break;
            }

            if (is_quit)
                break;

            show_menu(fly_number, status);
        }

        show_scheduled_flight();
    }
    return 0;
}

void show(struct seat ar[ARRSIZE], int fly_number, int status) {
    if (status == 1)
        printf("Fly Number: %d      Seats status: Confirmed\n", fly_number);
    else
        printf("Fly Number: %d      Seats status: Not Confirmed\n", fly_number);
    printf("%3s %2s %13s %14s\n", "No", "status", "first_name", "last_name");
    for (int i = 0; i < ARRSIZE; ++i) {
        printf("%3d %2d %15s %15s\n", ar[i].number, ar[i].status, ar[i].fn, ar[i].ln);
    }
    printf("\n");
}

void show_scheduled_flight(void) {
    printf("Please input a~d to select a scheduled flight:\n");
    printf("a.102       b.311\n");
    printf("c.444       d.519\n");
    printf("e.quit\n");
}

void show_menu(int fly_number, int status) {
    if (status == 1)
        printf("Fly Number: %d      Seats status: Confirmed\n", fly_number);
    else
        printf("Fly Number: %d      Seats status: Not Confirmed\n", fly_number);
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
    printf("g) Confirm seat\n");
}

void show_one_empty_seats(struct seat ar[ARRSIZE], int fly_number, int status) {
    if (status == 1)
        printf("Fly Number: %d      Seats status: Confirmed\n", fly_number);
    else
        printf("Fly Number: %d      Seats status: Not Confirmed\n", fly_number);
    for (int i = 0; i < ARRSIZE; ++i) {
        if (ar[i].status == 0) {
            printf("NO. %d is empty.\n", ar[i].number);
            break;
        }
    }
}

void show_empty_seats_list(struct seat ar[ARRSIZE], int fly_number, int status) {
    if (status == 1)
        printf("Fly Number: %d      Seats status: Confirmed\n", fly_number);
    else
        printf("Fly Number: %d      Seats status: Not Confirmed\n", fly_number);
    printf("Empty seats number:\n");
    for (int i = 0; i < ARRSIZE; ++i) {
        if (ar[i].status == 0)
            printf("%d ", ar[i].number);
    }
    printf("\n");
}

void show_not_empty_seats_list(struct seat ar[ARRSIZE], int fly_number, int status) {
    if (status == 1)
        printf("Fly Number: %d      Seats status: Confirmed\n", fly_number);
    else
        printf("Fly Number: %d      Seats status: Not Confirmed\n", fly_number);
    printf("Empty seats number:\n");
    for (int i = 0; i < ARRSIZE; ++i) {
        if (ar[i].status == 1)
            printf("%d ", ar[i].number);
    }
    printf("\n");
}

void show_empty_seats_list_by_alphabetical(struct seat ar[ARRSIZE], int fly_number, int status) {
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

    show(ar1, fly_number, status);
}

void order_seat(struct seat ar[ARRSIZE], int fly_number, int *p_status) {
    int n, is_ok = 0;

    printf("Please input a number of seat from next line:\n");
    show_empty_seats_list(ar, fly_number, *p_status);

    while (1) {
        while (scanf("%d", &n) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Please input a number from next line:\n");
            show_empty_seats_list(ar, fly_number, *p_status);
        }

        for (int i = 0; i < ARRSIZE; ++i) {
            if (is_ok == 0 && ar[i].status == 0 && ar[i].number == n) {
                is_ok = 1;
            }
        }

        if (is_ok)
            break;

        printf("Please input a number from next line:\n");
        show_empty_seats_list(ar, fly_number, *p_status);
    }

    ar[n - 1].status = 1;
    printf("Please input your first name:\n");
    scanf("%s", ar[n - 1].fn);
    printf("Please input your last name:\n");
    scanf("%s", ar[n - 1].ln);

    printf("Order seat successful!.\n");
    show(ar, fly_number, *p_status);
    *p_status = 0;
}

void cancel_seat(struct seat ar[ARRSIZE], int fly_number, int *p_status) {
    int n, is_ok = 0;
    char first_name[20], last_name[20];

    printf("Please input a number of seat from next line:\n");
    show_not_empty_seats_list(ar, fly_number, *p_status);

    while (1) {
        while (scanf("%d", &n) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Please input a number of seat from next line:\n");
            show_not_empty_seats_list(ar, fly_number, *p_status);
        }

        for (int i = 0; i < ARRSIZE; ++i) {
            if (is_ok == 0 && ar[i].status == 1 && ar[i].number == n) {
                is_ok = 1;
            }
        }

        if (is_ok)
            break;

        printf("Please input a number of seat from next line:\n");
        show_not_empty_seats_list(ar, fly_number, *p_status);
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
    show(ar, fly_number, *p_status);
    *p_status = 0;
}

void confirm_seat(int *p_status) {
    if (*p_status == 1)
        printf("Have nothing to confirm. Please order or cancel seat first.\n");
    else {
        printf("Seats status has been confirmed.\n");
        *p_status = 1;
    }
}
