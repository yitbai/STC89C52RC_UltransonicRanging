#include "led.h"
#include "time.h"
#include "my_types.h"

// 数码管段选值数组
const uchar digit_segments[10] = {
  0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90
};

void led_on(uchar position, uchar number)
{
    // 位置范围检查
    if (position > 2)
        return; // 无效位置

    // 数字范围检查
    if (number > 9)
        return; // 无效数字
    P1 = digit_segments[number]; // 设置段选

    switch (position) {
    case 0:
        LED_1 = 0; // 选择第一个数码管
        break;
    case 1:
        LED_2 = 0; // 选择第二个数码管
        break;
    case 2:
        LED_3 = 0; // 选择第三个数码管
        break;
    default:
        break; // 不应到达这里
    }
}

void led_off(uchar position)
{
    // 位置范围检查
    if (position > 2)
        return; // 无效位置

    switch (position) {
        case 0:
            LED_1 = 1; // 关闭第一个数码管
            break;
        case 1:
            LED_2 = 1; // 关闭第二个数码管
            break;
        case 2:
            LED_3 = 1; // 关闭第三个数码管
            break;
        default:
            break; // 不应到达这里
    }
}

void dynamic_led_display(uint number_display)
{
    // 数字范围检查
    if (number_display > 999)
        return; // 无效数字

    uchar hundred = number_display / 100;
    uchar ten = (number_display % 100) / 10;
    uchar one = number_display % 10;

    // 点亮第一个数码管
    led_on(0, hundred);
    delay_ms(5); // 延时5毫秒
    led_off(0);

    // 点亮第二个数码管
    led_on(1, ten);
    delay_ms(5); // 延时5毫秒
    led_off(1);

    // 点亮第三个数码管
    led_on(2, one);
    delay_ms(5); // 延时5毫秒
    led_off(2);
}