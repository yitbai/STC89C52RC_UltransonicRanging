#include <8052.h>
#include "gpio.h"
#include "led.h"
#include "time.h"

void main(void)
{
  // 初始化GPIO
  myGPIO_Init();
  while(1) {
    dynamic_led_on(1, 2, 3); // 动态点亮数码管，显示数字1, 2, 3
  }

}