#ifndef _MYTIME_H
#define _MYTIME_H
#include <8052.h>
#include "my_types.h"

void delay_ms(uint ms); // 通用延时

void delay_timer1(void); // 定时器1延时控制beep蜂鸣

void timer1_isr(void) __interrupt 3; // 定时器1中断服务程序

#endif
// 时间相关函数声明