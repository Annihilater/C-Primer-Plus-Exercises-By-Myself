//
// Created by klause on 2020/7/2.
//

//Program arguments: chapter_13/13_11_5/dest.txt chapter_13/13_11_5/source.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

void append(FILE *source, FILE *dest);


int main(int argc, char *argv[]) {
    FILE *fa, *fs;
    int files = 0;
    char *file_app;
    char *file_src;
    int ch;

    //校验命令行参数
    if (argc < 3) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        file_app = argv[1];
    }

    if ((fa = fopen(file_app, "a+")) == NULL) {
        fprintf(stderr, "Con't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file (empty line to quit):");
    for (int i = 2; i < argc; ++i) {
        file_src = argv[i];
        printf("%d\n", i);

        if (strcmp(file_src, file_app) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL) {
            fprintf(stderr, "Con't open %s\n", file_src);
        } else {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_app);
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit): ");
        }


    }

    printf("Done appending. %d files appended.\n", files);
    rewind(fa);//将文件的指针指向文件开始
    printf("%s contents:\n", file_app);

    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");

    fclose(fa);
    return 0;
}

void append(FILE *source, FILE *dest) {
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}
