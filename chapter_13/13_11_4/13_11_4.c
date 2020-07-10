//
// Created by klause on 2020/7/2.
//

// Program arguments: chapter_13/13_11_4/test1.txt chapter_13/13_11_4/test2.txt chapter_13/13_11_4/test3.txt
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    int ch;

    //验证命令行参数
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    //遍历命令行参数指定的文件
    for (int i = 1; i < argc; ++i) {
        //获取文件名
        filename = argv[i];

        printf("%s 's content:\n", filename);

        //打开文件
        if ((fp = fopen(filename, "r")) == NULL) {
            fprintf(stderr, "I couldn't open the file \"%s\"\n", filename);
            exit(EXIT_FAILURE);
        }

        //读取文件内容并打印
        while ((ch = getc(fp)) != EOF) {
            putchar(ch);
        }

        //关闭文件
        fclose(fp);
    }


    return 0;
}
