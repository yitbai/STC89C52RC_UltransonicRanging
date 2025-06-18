#ifndef MY_TYPES_H
#define MY_TYPES_H

#include <stdint.h>

typedef unsigned int uint;
typedef unsigned char uchar;
typedef uint8_t byte;


#define LED_1 P3_4 // 数码管1位选连接到P3.4
#define LED_2 P3_5 // 数码管2位选连接到P3.5
#define LED_3 P3_6 // 数码管3位选连接到P3.6
#define beep P2_3 // 蜂鸣器连接到P2.3
#define Key_1 P2_0 // 按键1连接到P2.0
#define Key_2 P2_1 // 按键2连接到P2.1
#define Key_3 P2_2 // 按键3连接到P2.2

// KEY == 0 是按下

#endif
