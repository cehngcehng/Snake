/*
 * JR_timer.c (1.0)
 * 单线程中的定时器
 *
 * By Jason song
 * learning from By Eric-JR Chen
 * diamont 1001@163.com
 */

#include"JR_timer.h"

// do something here
// define in main.c

extern void mainTimer();

static unsigned long JR_next_time=0xFFFFFFFF;
static unsigned long JR_Interval=1000; // 计时器间隔，单位ms, 默认秒钟


// 获取cpu时间ms
unsigned long JR_GetTicks(void)
{
    return clock();
}

// 启动计时器
void startTimer(void)
{
    JR_next_time=JR_GetTicks() + JR_Interval;
}

// 停止计时器
void stopTimer(void)
{
    JR_next_time = 0xFFFFFFFF;
}

//设定计时器间隔
void setTimer(int ms)
{
    JR_Interval=ms;
}

// 每个Interval触发一次
void ontimer(void)
{
    if (JR_next_time > JR_GetTicks()) return;

    JR_next_time += JR_Interval;
    mainTimer();
}


