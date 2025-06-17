#ifndef _MYLED_H
#define _MYLED_H

#include <8052.h>

// 静态点亮数码管函数声明，position: 数码管位置（0-2），number: 数字（0-9）
void static_led_on(int position, int number);

// 关闭数码管函数声明，position: 数码管位置（0-2）
void led_off(int position);

// 动态点亮数码管函数声明，position: 数码管位置（0-2），number: 数字（0-9）
void dynamic_led_on(int number_one, int number_two, int number_three);

#endif
