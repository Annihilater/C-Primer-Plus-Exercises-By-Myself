//
// Created by klause on 2020/7/14.
//

/*
 * 本题要求使用两个队列来模拟两个摊位，分析点在于当顾客来的时候，如果做出选择：
 * 情况 1: 队列 1 和队列 2 都未满，队列 1 <= 队列 2 时：顾客排在队列 1
 * 情况 2: 队列 1 和队列 2 都未满，队列 1 > 队列 2 时：顾客排在队列 2
 * 情况 3: 队列 1 未满、队列 2 满：顾客排在队列 1
 * 情况 4: 队列 1 满、队列 2 未满：顾客排在队列 2
 * 情况 5: 队列 1 和队列 2 都满：顾客离开
 *
 * 总共 5 种情况，可以按照顾客的选择分类：
 * 排队列 1: 情况 1、情况 3
 * 排队列 2: 情况 2、情况 4
 * 离开: 情况 5
 *
 * 另外当顾客没来时:
 *      判断 Sigmund 是否在处理顾客
 *          如果在处理: wait_time--
 *          如果不在处理: 从队列取出一个顾客给 Sigmund 处理
 */

#include <stdio.h>
#include <stdlib.h>             //提供 rand()和 srand() 的原型
#include <time.h>               //提供 time() 的原型
#include "queue.h"              //更改 Item 的 typedef

#define MIN_PER_HR 60.0

bool newcustomer(double x);//是否有新顾客到来

Item customertime(long when);//设置顾客参数

int main(void) {
    Queue line1, line2;
    Item temp;                  //新的顾客
    int hours;                  //模拟的小时数量
    int perhour;                //每小时平均多少位顾客
    long cycle, cyclelimit;     //循环计数器、计数器的上限
    long turnaways = 0;         //因队列已满被拒的顾客数量
    long customers = 0;         //加入队列的顾客数量
    long served = 0;            //在模拟期间咨询过 Sigmund 的顾客数量
    long sum_line = 0;          //累计队列总长
    int wait_time1 = 0;         //从当前到 Sigmund1 空闲所需的时间
    int wait_time2 = 0;         //从当前到 Sigmund2 空闲所需的时间
    double min_per_cust;        //顾客到来的平均时间
    long line_wait = 0;         //队列累计等待时间

    InitializeQueue(&line1);
    InitializeQueue(&line2);

    srand((unsigned int) time(0));     //rand() 随机初始化
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;

    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);                  //输入小时平均客流量
    min_per_cust = MIN_PER_HR / perhour;    //求得分钟平均客流量

    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if ((!QueueIsFull(&line1) && !QueueIsFull(&line2) && line1.items <= line2.items) ||         //1、2都没满，1<=2
                (!QueueIsFull(&line1) && QueueIsFull(&line2))) {                                        //1没满 2满
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line1);                                                                  //排 1 队列
            } else if ((!QueueIsFull(&line1) && !QueueIsFull(&line2) && line1.items > line2.items) ||   //1、2都没满 1>2
                       (!QueueIsFull(&line1) && QueueIsFull(&line2))) {                                 //1满 2没满
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line2);                                                                  //排 2 队列
            } else {                                                                                    //1、2都满了, 离开
                turnaways++;
            }
        }

        if (wait_time1 <= 0 && !QueueIsEmpty(&line1)) {//Sigmund 没在处理顾客时, 取一个顾客给它处理
            DeQueue(&temp, &line1);
            wait_time1 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }

        if (wait_time1 > 0) wait_time1--;//Sigmund 在处理顾客时, 等待时间减 1 秒
        sum_line += QueueItemCount(&line1);

        if (wait_time2 <= 0 && !QueueIsEmpty(&line2)) {
            DeQueue(&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }

        if (wait_time2 > 0) wait_time2--;
        sum_line += QueueItemCount(&line2);
    }

    if (customers > 0) {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
               (double) sum_line / (double) cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double) line_wait / (double) served);

    } else
        puts("No customers!");

    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");
    return 0;
}

/*
 * x 是顾客到来的平均时间(单位: 分钟)
 * 如果 1 分钟内有顾客到来，则返回 true
 */
bool newcustomer(double x) {
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

/*
 * when 是顾客到来的时间
 * 该函数返回一个 Item 结构，该顾客到达的时间设置为 when
 * 咨询时间设置为 1~3 的随机值
 */
Item customertime(long when) {
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
