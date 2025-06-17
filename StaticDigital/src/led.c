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

  switch (position) {
    case 0:
        P1 = digit_segments[number]; // 设置段选
        LED_1 = 0; // 选择第一个数码管
        break;
    case 1:
        P1 = digit_segments[number]; // 设置段选
        LED_2 = 0; // 选择第二个数码管
        break;
    case 2:
        P1 = digit_segments[number]; // 设置段选
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

void static_led_display(uchar number_one, uchar number_two, uchar number_three)
{
    // 数字范围检查
    if (number_one > 9 ||
        number_two > 9 ||
        number_three > 9)
        return; // 无效数字

    led_on(0, number_one); // 点亮第一个数码管
    led_on(1, number_two); // 点亮第二个数码管
    led_on(2, number_three); // 点亮第三个数码管
}

void dynamic_led_display(uchar number_one, uchar number_two, uchar number_three)
{
    // 数字范围检查
    if (number_one > 9 ||
        number_two > 9 ||
        number_three > 9)
        return; // 无效数字

    // 点亮第一个数码管
    led_on(0, number_one);
    delay_ms(5); // 延时5毫秒
    led_off(0);

    // 点亮第二个数码管
    led_on(1, number_two);
    delay_ms(5); // 延时5毫秒
    led_off(1);

    // 点亮第三个数码管
    led_on(2, number_three);
    delay_ms(5); // 延时5毫秒
    led_off(2);
}