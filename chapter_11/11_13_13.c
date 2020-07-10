//
// Created by klause on 2020/6/29.
//

#include <stdio.h>

//倒序打印命令行参数
int main(int argc, char *argv[]) {
    printf("The command line has %d arguments: \n", argc - 1);
    if (argc > 1)
        for (int j = argc - 1; j >= 1; --j) {
            printf("%s ", argv[j]);
        }
    return 0;
}
