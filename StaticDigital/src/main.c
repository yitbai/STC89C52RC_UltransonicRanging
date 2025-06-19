#include <8052.h>
#include "my_types.h"
#include "gpio.h"
#include "led.h"
#include "time.h"
#include "beep.h"

static uint count = 0; // 全局计数变量(0-999)
static uint8_t beep_flag = 0; // 蜂鸣器状态标志

/*
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
    if(count != 0 && count % 10 == 0) {
        if(beep_flag == 0) { // 如果蜂鸣器未处于工作状态
          beep_on();
          delay_ms(500);
          beep_flag = 1; // 设置蜂鸣器状态标志
          beep_off();
        }
    }else {
      beep_flag = 0; // 重置蜂鸣器状态标志
      beep_off(); // 确保蜂鸣器关闭
    }

    // 更新数码管显示
    dynamic_led_display(count); // 注意参数顺序是个、十、百位
  }
}
*/

void main(void)
{
  // 初始化GPIO
  gpio_Init();
  

  while(1) {
    uchar hundred = count / 100;
    uchar ten = (count % 100) / 10;
    uchar one = count % 10;

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

    // 检查是否为10的倍数并触发蜂鸣器
    if(count != 0 && count % 10 == 0) {
        if(beep_flag == 0) { // 如果蜂鸣器未处于工作状态
          beep_on();
          delay_ms(500);
          beep_flag = 1; // 设置蜂鸣器状态标志
          beep_off();
        }
    } else {
      beep_flag = 0; // 重置蜂鸣器状态标志
      beep_off(); // 确保蜂鸣器关闭
    }
  }
}