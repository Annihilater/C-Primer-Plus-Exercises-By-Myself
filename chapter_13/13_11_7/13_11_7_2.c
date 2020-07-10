//
// Created by klause on 2020/7/3.
//

//Program arguments: chapter_13/13_11_7/test1.txt chapter_13/13_11_7/test2.txt chapter_13/13_11_7/test3.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 40//每一行做大字符数
#define MAX_ROW 20//最大行数

int main(int argc, char *argv[]) {
    char *filename;
    char words[100];
    FILE *fp;
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

            fseek(fp, pos[j], SEEK_SET);//将文件指针调节到上次读取的位置
            if (fgets(words, SIZE, fp) == NULL) {//读取文件
                m++;
                continue;
            }
            pos[j] = ftell(fp);//将距离文件开始位置的长度保存下来，以便下次循环使用

            for (int k = 0; k < strlen(words); ++k) {
                if (words[k] != '\n')
                    printf("%c", words[k]);
            }
            printf(" ");
//            printf("%ld\n", pos[j]);//打印文件指针位置

            //关闭文件
            fclose(fp);
        }

        if (m == argc - 1) {//用来去除多余的行数打印
            break;
        }
    }

    return 0;
}
