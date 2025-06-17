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
  while(1) {
//    dynamic_led_on(1, 2, 3); // 动态点亮数码管，显示数字1, 2, 3
    beep_on(); // 打开蜂鸣器
    delay_ms(500); // 延时500毫秒
    beep_off(); // 关闭蜂鸣器
    delay_ms(500); // 延时500毫秒
  }

}