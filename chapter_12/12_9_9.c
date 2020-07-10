//
// Created by klause on 2020/7/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 400

char **get_words(int n);

static void find_word(char **start, char **end);

int main(void) {
    int n;
    char **words;

    printf("How many words do you wish to enter?\n");
    if (scanf("%d", &n) == 1 && n > 0) {
        while (getchar() != '\n')
            continue;
        words = get_words(n);

        printf("Here are your words:\n");
        for (int i = 0; i < n; i++)
            printf("%s\n", words[i]);
    }

    return 0;
}

char **get_words(int n) {
    char tmp[LIMIT];
    int i;
    char *word_start;
    char *word_end;
    int word_length;

    /*
     * 申请 n 个指针的空间，每个指针都指向 char
     * 就是二位数组
     */
    char **word_array = (char **) malloc(n * sizeof(char *));

    /*
     * 将所有字符串一起读入，字符串首字符地址赋给 word_start(临时存放)
     * input: I enjoyed doing this exercise
     */
    printf("Enter %d words now:\n", n);
    word_start = fgets(tmp, LIMIT, stdin);

    for (i = 0; i < n; i++) {
        // find the start and end of next word
        find_word(&word_start, &word_end);//找出单个字符串的长度，字符串的首地址为 word_start，末地址赋值给 word_end

        // if word_start points to null char, there are no more
        // words to find; exit loop
        if (*word_start == '\0')//如果字符串的首地址为空字符，则表明字符串已经读取完毕
            break;

        // allocate memory for new word and copy from tmp
        word_length = (int) (word_end - word_start);//计算字符串的长度
        word_array[i] = (char *) malloc((word_length + 1) * sizeof(char));//依据长度+1(空字符)给每个字符串申请空间
        if (word_array[i] != NULL) {//如果内存申请成功，就赋值
            strncpy(word_array[i], word_start, word_length);//将字符串拷贝到新申请的内存地址
            word_array[i][word_length] = '\0';//并在末尾添加上空字符表示 C 字符串
        }

        word_start = word_end;//将末尾标记为开头，继续下一轮循环
    }

    // if less than n words found, set remaining elements of
    // word_array to null string
    if (i < n)//如果找到的单词数少于 n，则将剩下的空间设置为空字符
        for (; i < n; i++) {
            word_array[i] = (char *) malloc(sizeof(char));
            *word_array[i] = '\0';
        }

    return word_array;
}

static void find_word(char **start, char **end) {
    // takes two pointers to pointers to char
    // sets *start to point to first character of first
    // word occuring after **start and sets *end to point
    // to the character immediately after the word

    while (isspace(**start))//跳过前面的空字符
        (*start)++;

    *end = *start;//将首位标记为末位，方便后面使用末位查找空格

    while (!isspace(**end) && **end != '\0')//使用末位查找空格，找到空格或者空字符为止，算一个单词
        (*end)++;
}
