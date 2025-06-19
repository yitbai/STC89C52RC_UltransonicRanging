#include <8052.h>
#include "my_types.h"
#include "gpio.h"
#include "led.h"
#include "time.h"
#include "beep.h"

static uint count = 0; // 全局计数变量(0-999)
static uint8_t beep_flag = 0; // 蜂鸣器状态标志
static uint8_t key1_pressed = 0;
static uint8_t key2_pressed = 0; 
static uint8_t key3_pressed = 0;


void main(void)
{
  // 初始化GPIO
  gpio_Init();

  while(1) {  
    // 处理KEY_1(减1)
    if(Key_1 == 0) {
      delay_ms(2); // 消抖
      if(Key_1 == 0 && !key1_pressed) {
        key1_pressed = 1;
        if(count == 0) count = 999;
        else count--;
      }
    } else {
      key1_pressed = 0;
    }

    // 处理KEY_2(加1)
    if(Key_2 == 0) {
      delay_ms(2); // 消抖
      if(Key_2 == 0 && !key2_pressed) {
        key2_pressed = 1;
        count++;
        if(count > 999) count = 0;
      }
    } else {
      key2_pressed = 0;
    }

    // 处理KEY_3(复位)
    if(Key_3 == 0) {
      delay_ms(2); // 消抖
      if(Key_3 == 0 && !key3_pressed) {
        key3_pressed = 1;
        count = 0;
      }
    } else {
      key3_pressed = 0;
    }

  if(count != 0 && count % 10 == 0) {
    if(!beep_flag) { // 如果蜂鸣器未处于工作状态
      //beep_on();
      beep = 0; // 打开蜂鸣器
      delay_ms(300);
      beep_flag = 1; // 设置蜂鸣器状态标志
      //beep_off();
      beep = 1; // 关闭蜂鸣器
    }
  }else {
    beep_flag = 0; // 重置蜂鸣器状态标志
    //beep_off(); // 确保蜂鸣器关闭
    beep = 1; // 关闭蜂鸣器
  }
  
  dynamic_led_display(count); // 注意参数顺序是个、十、百位
  }
}