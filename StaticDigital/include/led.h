#ifndef _MYLED_H
#define _MYLED_H

#include <8052.h>
#include "my_types.h"

// 点亮数码管函数声明，position: 数码管位置（0-2），number: 数字（0-9）
void led_on(uchar position, uchar number);

// 关闭数码管函数声明，position: 数码管位置（0-2）
void led_off(uchar position);

// 静态点亮数码管函数声明，number_one: 数码管1显示的数字（0-9），number_two: 数码管2显示的数字（0-9），number_three: 数码管3显示的数字（0-9）
void static_led_display(uchar number_one, uchar number_two, uchar number_three);

// 动态点亮数码管函数声明，number_one: 数码管1显示的数字（0-9），number_two: 数码管2显示的数字（0-9），number_three: 数码管3显示的数字（0-9）
void dynamic_led_display(uchar number_one, uchar number_two, uchar number_three);

#endif
// 数码管控制函数声明