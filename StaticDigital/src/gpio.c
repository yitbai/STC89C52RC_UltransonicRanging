#include "gpio.h"
#include "my_types.h"

// gpio 初始化
void gpio_Init(void)
{
  // 数码管初始化
  LED_1 = 1; // 数码管1位选
  LED_2 = 1; // 数码管2位选
  LED_3 = 1; // 数码管3位选
  P1 = 0x00; // 数码管段选
  // 蜂鸣器初始化
  beep = 1; // 蜂鸣器关闭
}