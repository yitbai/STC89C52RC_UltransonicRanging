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
    if(Key_1 == 0) { // 按键1按下
      led_on(0, 1); // 点亮数码管1显示数字1
      delay_ms(500); // 延时500毫秒
      led_off(0); // 关闭数码管1
    }
    if(Key_2 == 0) { // 按键2按下
      led_on(1, 2); // 点亮数码管2显示数字2
      delay_ms(500); // 延时500毫秒
      led_off(1); // 关闭数码管2
    }
    if(Key_3 == 0) { // 按键3按下
      led_on(2, 3); // 点亮数码管3显示数字3
      delay_ms(500); // 延时500毫秒
      led_off(2); // 关闭数码管3
    }
  }
}