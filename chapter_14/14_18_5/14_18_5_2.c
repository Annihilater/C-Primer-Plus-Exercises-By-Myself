//
// Created by klause on 2020/7/8.
//

#include <stdio.h>

#define CSIZE 4
#define NAMELEN 20
#define GRADELEN 3

struct Name {
    char first[NAMELEN];
    char last[NAMELEN];
};

struct Student {
    struct Name name;
    float grades[GRADELEN];
    float average;
};

void getgrades(struct Student *);

void getaverage(struct Student *);

void showstudentinfo(struct Student *);

int main(void) {
    struct Student students[CSIZE] = {
            {.name = {"Zack", "Morris"}},
            {.name = {"Kelly", "Kapowski"}},
            {.name = {"AC", "Slater"}},
            {.name = {"Screech", "Powers"}}
    };

    // get student grades
    for (int i = 0; i < CSIZE; i++)
        getgrades(&students[i]);

    // get grade averages
    for (int i = 0; i < CSIZE; i++)
        getaverage(&students[i]);

    // print student info
    for (int i = 0; i < CSIZE; i++)
        showstudentinfo(&students[i]);

    return 0;
}

void getgrades(struct Student *student) {
    // interactively acquire and set grades for student

    for (int i = 0; i < GRADELEN; i++) {
        printf("Enter grade %d for student %s %s: ", i + 1, student->name.first,
               student->name.last);
        while (scanf("%f", student->grades + i) != 1)
            while (getchar() != '\n') continue;
        while (getchar() != '\n') continue;
    }
    puts("");
}

void getaverage(struct Student *student) {
    // calculate and set the average grade for a student

    float total = 0;
    for (int i = 0; i < GRADELEN; i++)
        total += student->grades[i];
    student->average = total / GRADELEN;
}

void showstudentinfo(struct Student *student) {
    printf("Name: %s %s\n", student->name.first, student->name.last);
    printf("Grade 1: %.1f\n", student->grades[0]);
    printf("Grade 2: %.1f\n", student->grades[1]);
    printf("Grade 3: %.1f\n", student->grades[2]);
    printf("Average Grade: %.1f\n", student->average);
    puts("");
}
