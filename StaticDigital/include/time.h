#ifndef _MYTIME_H
#define _MYTIME_H
#include <8052.h>
#include "my_types.h"

void delay_ms(uint ms);

uchar set_timer_value(uchar timer,uint value);

#endif
// 时间相关函数声明