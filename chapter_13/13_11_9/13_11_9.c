//
// Created by klause on 2020/7/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void) {
    FILE *fp;
    char words[MAX];
    int number = 0;
    char *end;

    if ((fp = fopen("chapter_13/13_11_9/wordy", "a+")) == NULL) {
        fprintf(stderr, "Con't open \"wordy.txt\" file.\n");
        exit(EXIT_FAILURE);
    }

    //从文件读取计数
    fseek(fp, 0L, SEEK_SET);
    while (fscanf(fp, "%40s", words) != EOF) {
        fprintf(stdout, "%s\n", words);
        number = (int) strtol(words, &end, 10);
    }

    puts("Enter words to add to the file; pass the #");
    puts("key at the beginning of a line to terminate");

    fseek(fp, 0L, SEEK_END);
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
        number++;//计数自增
        fprintf(fp, "%3d-%s\n", number, words);//记录计数
    }

    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1) {
        puts(words);
    }
    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    return 0;
}
