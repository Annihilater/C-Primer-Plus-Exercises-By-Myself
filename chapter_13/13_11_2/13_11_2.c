//
// Created by klause on 2020/7/2.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

int main(int argc, char *argv[]) {
    char *file1, *file2;
    FILE *fp1, *fp2;
    char words[SIZE];

    //校验命令行参数
    if (argc != 3) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file1 = argv[1];
    file2 = argv[2];

    //打开源文件
    if ((fp1 = fopen(file1, "rb")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", file1);
        exit(EXIT_FAILURE);
    }

    //打开目标文件
    if ((fp2 = fopen(file2, "wb")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", file2);
        exit(EXIT_FAILURE);
    }

    //读取源文件并写入目标文件
    while (fscanf(fp1, "%40s", words) == 1) {
        fprintf(stdout, "%s\n", words);
        fprintf(fp2, "%s ", words);
    }

    //关闭文件
    if (fclose(fp1) != 0 || fclose(fp2) != 0)
        fprintf(stderr, "Error in closing files.\n");
    else
        fprintf(stdout, "File was closed.\n");
    return 0;
}
