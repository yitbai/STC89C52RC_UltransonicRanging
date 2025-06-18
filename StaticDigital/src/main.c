#include <8052.h>
#include "my_types.h"
#include "gpio.h"
#include "led.h"
#include "time.h"
#include "beep.h"

static uint count = 0; // 全局计数变量(0-999)

void main(void)
{
  // 初始化GPIO
  gpio_Init();

  while(1) {
    // 处理KEY_1(减1)
    if(Key_1 == 0) {
      delay_ms(20); // 消抖
      if(Key_1 == 0) {
        if(count == 0) count = 999;
        else count--;
        while(!Key_1); // 等待按键释放
      }
    }

    // 处理KEY_2(加1)
    if(Key_2 == 0) {
      delay_ms(20); // 消抖
      if(Key_2 == 0) {
        count++;
        if(count > 999) count = 0;
        while(!Key_2); // 等待按键释放
      }
    }

    // 处理KEY_3(复位)
    if(Key_3 == 0) {
      delay_ms(20); // 消抖
      if(Key_3 == 0) {
        count = 0;
        while(!Key_3); // 等待按键释放
      }
    }

    //检查是否为10的倍数并触发蜂鸣器
    if(count % 10 == 0 && count != 0) {
      beep_on();
      delay_ms(100);
      beep_off();
    }

    // 更新数码管显示
    uchar hundred = count / 100;
    uchar ten = (count % 100) / 10;
    uchar one = count % 10;
    dynamic_led_display(hundred, ten, one); // 注意参数顺序是个、十、百位
  }
}
