//
// Created by klause on 2020/7/7.
//

/*
 test case:
 My Life as a Budgie
 Mack Zackles
 12.95

 Thought and Unthought Rethought
 Kindra Schlagmeyer
 43.50

 Concerto for Financial Instruments
 Filmore Walletz
 49.99

 The CEO Power Diet
 Buster Downsize
 19.25

 C++ Prime Plus
 Stephen Prata
 59.99

 Fact Avoidance: Perception as Reality
 Polly Bull
 19.97

 Coping with Coping
 Dr. Rubin Thonkwacker
 0.02

 Diaphanous Frivolity
 Neda McFey
 29.99

 Murder Wore a Bikini
 Mickey Splats
 18.95

 A History of Buvania, Volume 8
 Prince Nikoli Buvan
 50.04

 Mastering Your Digital Watch, 5th Edition
 Miklos Mysz
 28.95

 A Foregone Confusion
 Phalty Reasoner
 5.99

 Outsourcing Government: Selection vs. Election
 Ima Pundit
 33.33
 */

#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char *s_gets(char *st, int n);

void sort_by_title(struct book pb[], int n);

void sort_by_price(struct book pb[], int n);

int main(void) {
    struct book library[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {

        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);

        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);

        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");

    }

    if (count > 0) {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; ++index) {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
    } else
        printf("No books? Too bad.\n");

    sort_by_title(library, count);

    sort_by_price(library, count);

    return 0;
}

void sort_by_title(struct book pb[], int n) {
    char tmp[MAXTITL];

    printf("\nSort book by title:\n");
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(pb[i].title, pb[j].title) > 0) {
                strcpy(tmp, pb[i].title);
                strcpy(pb[i].title, pb[j].title);
                strcpy(pb[j].title, tmp);
            }
        }
    }
    for (int index = 0; index < n; ++index) {
        printf("%s by %s: $%.2f\n", pb[index].title, pb[index].author, pb[index].value);
    }
}

void sort_by_price(struct book pb[], int n) {
    float tmp;

    printf("\nSort book by value:\n");
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pb[i].value > pb[j].value) {
                tmp = pb[i].value;
                pb[i].value = pb[j].value;
                pb[j].value = tmp;
            }
        }
    }
    for (int index = 0; index < n; ++index) {
        printf("%s by %s: $%.2f\n", pb[index].title, pb[index].author, pb[index].value);
    }
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
