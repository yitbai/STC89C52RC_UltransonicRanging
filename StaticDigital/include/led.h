#ifndef _MYLED_H
#define _MYLED_H

#include <8052.h>
#include "my_types.h"

// 静态点亮数码管函数声明，position: 数码管位置（0-2），number: 数字（0-9）
void static_led_on(uchar position, uchar number);

// 关闭数码管函数声明，position: 数码管位置（0-2）
void led_off(uchar position);

// 动态点亮数码管函数声明，position: 数码管位置（0-2），number: 数字（0-9）
void dynamic_led_on(uchar number_one, uchar number_two, uchar number_three);

#endif
// 数码管控制函数声明