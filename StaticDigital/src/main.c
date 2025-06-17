#include <8052.h>
#include "my_types.h"
#include "gpio.h"
#include "led.h"
#include "time.h"
#include "beep.h"

void main(void)
{
  // 初始化GPIO
  gpio_Init();
  // while(1) {
  // //  dynamic_led_on(1, 2, 3); // 动态点亮数码管，显示数字1, 2, 3
  // //  beep_on(); // 打开蜂鸣器
  //   static_led_on(0, 1); // 静态点亮第一个数码管，显示数字1
  //   delay_ms(1000); // 延时1000毫秒
  // //  beep_off(); // 关闭蜂鸣器
  //   led_off(0); // 关闭第一个数码管
  //   delay_ms(1000); // 延时1000毫秒
  // }
  delay_timer1(); // 启动定时器1
  while(1) {

  }
}