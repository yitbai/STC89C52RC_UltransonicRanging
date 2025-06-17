#include "myled.h"

// 数码管段选值数组
const unsigned char digit_segments[10] = {
  0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90
};

void static_led_on(int position, int number)
{
    // 位置范围检查
    if (position < 0 || position > 2)
        return; // 无效位置

    // 数字范围检查
    if (number < 0 || number > 9)
        return; // 无效数字

  switch (position) {
    case 0:
        P1 = digit_segments[number]; // 设置段选
        P3_4 = 0; // 选择第一个数码管
        break;
    case 1:
        P1 = digit_segments[number]; // 设置段选
        P3_5 = 0; // 选择第二个数码管
        break;
    case 2:
        P1 = digit_segments[number]; // 设置段选
        P3_6 = 0; // 选择第三个数码管
        break;
    default:
        break; // 不应到达这里
    }
}

void led_off(int position)
{
    // 位置范围检查
    if (position < 0 || position > 2)
        return; // 无效位置

    switch (position) {
        case 0:
            P3_4 = 1; // 关闭第一个数码管
            break;
        case 1:
            P3_5 = 1; // 关闭第二个数码管
            break;
        case 2:
            P3_6 = 1; // 关闭第三个数码管
            break;
        default:
            break; // 不应到达这里
    }
}