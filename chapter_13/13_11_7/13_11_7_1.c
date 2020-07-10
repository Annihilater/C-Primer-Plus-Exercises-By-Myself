//
// Created by klause on 2020/7/3.
//

//Program arguments: chapter_13/13_11_7/test1.txt chapter_13/13_11_7/test2.txt chapter_13/13_11_7/test3.txt
#include <stdio.h>
#include <stdlib.h>

#define SIZE 40//每一行做大字符数
#define MAX_ROW 20//最大行数

int main(int argc, char *argv[]) {
    char *filename;
    char words[100];
    FILE *fp;
    int k;
    int m;
    long int pos[argc];//用来存放文件指针指向的位置

    //pos 数组初始化
    for (int l = 0; l < argc; ++l) {
        pos[l] = 0;
    }

    //命令行参数校验
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename was wrong.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //遍历行
    for (int i = 0; i < MAX_ROW; ++i) {
        m = 0;
        printf("\n%d Row:\n", i);

        //遍历文件
        for (int j = 1; j < argc; ++j) {

            //获取文件名
            filename = argv[j];

            //打开文件
            if ((fp = fopen(filename, "r")) == NULL) {
                fprintf(stderr, "I couldn't open %s.\n", filename);
                exit(EXIT_FAILURE);
            }

            /*
             * 读取一行内容并打印
             * 每次都遍历整个文件，记录遍历的当前行号，当当前行号与要打印的行号相同时，才打印当前行
             * 也就是说每次遍历整个文件，只打印一行
             * 如果可以获取一行的偏移量，就可以直接使用 一行偏移量*行数 得到改行的偏移量直接打印
             */
            /*k = 0;
            while (fgets(words, SIZE, fp) != NULL) {
                if (++k == i)
                    printf("%s", words);
            }*/

            fseek(fp, pos[j], SEEK_SET);//将文件指针调节到上次读取的位置
            if (fgets(words, SIZE, fp) == NULL) {//读取文件
                m++;
                continue;
            }
            pos[j] = ftell(fp);//将距离文件开始位置的长度保存下来，以便下次循环使用
            printf("%s", words);//打印行内容
            printf("%ld\n", pos[j]);//打印文件指针位置

            //关闭文件
            fclose(fp);
        }

        if (m == argc - 1) {
            break;
        }
    }

    return 0;
}
