//
// Created by klause on 2020/7/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pettree.h"

char menu(void);

void add_pet(Tree *pt);

void print_pet(Pet pet);

void drop_pet(Tree *pt);

void show_pets(const Tree *pt);

void find_pet(const Tree *pt);

void uppercase(char *str);

char *get(char *st, int n);

int main(void) {
    Tree pets;
    char choice;
    InitializeTree(&pets);

    while ((choice = menu()) != 'q') {
        puts("");
        if (choice == 'a') {
            add_pet(&pets);
        } else if (choice == 'l') {
            show_pets(&pets);
        } else if (choice == 'f') {
            find_pet(&pets);
        } else if (choice == 'n') {
            printf("%d pets in club\n", TreeItemCount(pets));
        } else if (choice == 'd') {
            drop_pet(&pets);
        } else {
            printf("Not a valid option.\n");
        }
        puts("");
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

char menu(void) {
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet 			l) show list of pets");
    puts("n) number of pets		f) find pets");
    puts("d) delete a pet 		q) quit");
    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("alfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d or q:");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';

    return (char) ch;
}

void add_pet(Tree *pt) {
    Pet *ppet = (Pet *) malloc(sizeof(Pet));
    if (ppet == NULL) {
        fprintf(stderr, "Could not allocate memory.\n");
        return;
    }

    if (TreeIsFull(pt)) {
        puts("No room in the club!");
    } else {
        puts("Please enter name of pet:");
        get(ppet->name, STRLEN);
        puts("Please enter pet kind:");
        get(ppet->type, STRLEN);
        uppercase(ppet->name);
        uppercase(ppet->type);
        ppet->next = NULL;
        AddPet(ppet, pt);
    }
}

void drop_pet(Tree *pt) {
    Pet temp;

    if (TreeIsEmpty(pt)) {
        printf("No entries!\n");
        return;
    }

    puts("Please enter name of pet you wish to delete:");
    get(temp.name, STRLEN);
    puts("Please enter type of pet:");
    get(temp.type, STRLEN);
    uppercase(temp.name);
    uppercase(temp.type);
    printf("%s the %s ", temp.name, temp.type);
    if (DeletePet(&temp, pt))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void show_pets(const Tree *pt) {
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        TraverseTree(pt, print_pet);
}

void print_pet(Pet pet) {
    printf("Pet: %-19s Kind: %-19s\n", pet.name, pet.type);
}

void find_pet(const Tree *pt) {
    Pet temp;

    if (TreeIsEmpty(pt)) {
        puts("No entries.");
        return;
    }

    puts("Please enter name of pet you wish to find:");
    get(temp.name, STRLEN);
    uppercase(temp.name);
    printf("Here are all pets named %s:\n", temp.name);
    ApplyToNode(&temp, pt, print_pet);
}

void uppercase(char *str) {
    for (; *str != '\0'; str++)
        *str = (char) toupper(*str);
}

char *get(char *string, int n) {
    // wrapper for fgets - read from stdin and replace
    // first newline with null character

    char *ret_val = fgets(string, n, stdin);

    for (; *string != '\0'; string++) {
        if (*string == '\n') {
            *string = '\0';
            break;
        }
    }
    return ret_val;
}
