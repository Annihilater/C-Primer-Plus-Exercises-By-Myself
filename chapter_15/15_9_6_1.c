//
// Created by klause on 2020/7/9.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LEFT 1
#define RIGHT 2
#define CENTER 0

struct font {
    unsigned int id: 8;
    unsigned int size: 7;
    unsigned int alignment: 2;
    bool bold: 1;
    bool italic: 1;
    bool underline: 1;
};

void change_font(struct font *ps);

void change_size(struct font *ps);

void change_alignment(struct font *ps);

void change_bold(struct font *ps);

void change_italic(struct font *ps);

void change_underline(struct font *ps);

void show_settings(struct font my_font);

char *show_alignment(unsigned int n);

char *show_bold(bool);

char *show_italic(bool);

char *show_underline(bool);

int main(void) {
    bool is_quit = false;
    char ch;
    struct font my_font = {1, 12, LEFT, false, false, false};
    struct font *ps;

    ps = &my_font;

    show_settings(*ps);
    while (1) {
        while (1) {
            while (scanf("%c", &ch) != 1) {
                while (getchar() != '\n') continue;
                show_settings(*ps);
            }
            if (ch == '\n') continue;

            if (strchr("fsabiuq", ch) != NULL) break;//各个选项开头首字母
            show_settings(*ps);
        }

        switch (ch) {
            case 'f': {
                change_font(ps);
                break;
            }
            case 's': {
                change_size(ps);
                break;
            }
            case 'a': {
                change_alignment(ps);
                break;
            }
            case 'b': {
                change_bold(ps);
                break;
            }
            case 'i': {
                change_italic(ps);
                break;
            }
            case 'u': {
                change_underline(ps);
                break;
            }
            default: {//'q'
                is_quit = true;
                break;
            }
        }

        if (is_quit) break;
    }
    printf("Bye!");
    return 0;
}

void show_menu(void) {
    printf("f)change font   s)change size   a)change alignment\n");
    printf("b)change bold   i)toggle italic u)toggle underline\n");
    printf("q)quit\n");
}

void change_font(struct font *ps) {
    int n;
    printf("Enter font number(0~255):\n");

    while (1) {
        while (scanf("%d", &n) != 1) {
            while (getchar() != '\n') continue;
            printf("Enter font number(0~255):\n");
        }

        if (n >= 0 && n <= 255) break;
        printf("Enter font number(0~255):\n");
    }

    ps->id = n;
    show_settings(*ps);
}

void change_size(struct font *ps) {
    int n;
    printf("Enter font size(0~127):\n");

    while (1) {
        while (scanf("%d", &n) != 1) {
            while (getchar() != '\n') continue;
            printf("Enter font size(0~127):\n");
        }

        if (n >= 0 && n <= 127) break;
        printf("Enter font size(0~127):\n");
    }

    ps->size = n;
    show_settings(*ps);
}

void change_alignment(struct font *ps) {
    char ch;
    printf("Select alignment:\n");
    printf("1)left  2)center    3)right\n");

    while (1) {
        while (scanf("%c", &ch) != 1) {
            while (getchar() != '\n') continue;
            printf("Select alignment:\n");
            printf("1)left  2)center    3)right\n");
        }
        if (ch == '\n') continue;

        if (strchr("lcr", ch) != NULL) break;
        printf("Select alignment:\n");
        printf("1)left  2)center    3)right\n");
    }

    switch (ch) {
        case 'l': {
            ps->alignment = LEFT;
            break;
        }
        case 'r': {
            ps->alignment = RIGHT;
            break;
        }
        default: {//'c'
            ps->alignment = CENTER;
            break;
        }
    }
    show_settings(*ps);
}

void change_bold(struct font *ps) {
    ps->bold = ps->bold ? false : true;
    show_settings(*ps);
}

void change_italic(struct font *ps) {
    ps->italic = ps->italic ? false : true;
    show_settings(*ps);
}

void change_underline(struct font *ps) {
    ps->underline = ps->underline ? false : true;
    show_settings(*ps);
}

void show_settings(const struct font my_font) {
    printf("Font settings:\n");
    printf("%5s %5s %10s %5s %5s %5s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%4u %5u %8s %9s %5s %5s\n\n", (int) my_font.id, (int) my_font.size, show_alignment(my_font.alignment),
           show_bold(my_font.bold), show_italic(my_font.italic), show_underline(my_font.underline));
    show_menu();
}

char *show_alignment(const unsigned int n) {
    char *result;
    if (n == 1)
        result = "left";
    else if (n == 2)
        result = "right";
    else//n=0
        result = "center";
    return result;
}

char *show_bold(const bool n) {
    char *result;
    if (n == false)
        result = "off";
    else
        result = "on";
    return result;
}

char *show_italic(const bool n) {
    char *result;
    if (n == false)
        result = "off";
    else
        result = "on";
    return result;
}

char *show_underline(const bool n) {
    char *result;
    if (n == false)
        result = "off";
    else
        result = "on";
    return result;
}
