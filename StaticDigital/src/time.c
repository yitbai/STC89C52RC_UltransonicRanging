#include "time.h"
#include "my_types.h"
#include "led.h"
#include "beep.h"

void delay_ms(uint ms)
{
  // 最大单次延时65ms(防止计算溢出)
  #define MAX_DELAY 65
  uint cycles = ms;
  
  // 使用定时器0进行延时
  while(cycles > 0) {
    uint current = (cycles > MAX_DELAY) ? MAX_DELAY : cycles;
    cycles -= current;
    
    // 清除所有标志和控制位
    TR0 = 0;
    TF0 = 0;
    
    // 配置定时器0为模式1(16位定时器)
    TMOD = (TMOD & 0xF0) | 0x01;
    
    // 计算并设置定时器初值(12MHz晶振,12分频)
    uint timer_val = 65536 - (current * 1000);
    TH0 = timer_val >> 8;
    TL0 = timer_val & 0xFF;
    
    // 启动定时器
    TR0 = 1;
    
    // 等待溢出
    while(!TF0);
    
    // 停止定时器
    TR0 = 0;
    TF0 = 0;
  }
}


void timer1_isr(void) __interrupt 3
{
  // 定时器1中断服务程序
  static uint timerCounter = 0;  // 定时器计数器
  static uint ms = 2000;  // LED闪烁周期，单位为毫秒
  static uint8_t beepState = 0;  // 蜂鸣器状态，0为关闭，1为打开
    
  // 定时器1中断每1毫秒触发一次
  TH1 = 0xFC;  // 定时器初值高8位
  TL1 = 0x18;  // 定时器初值低8位
    
  // 增加定时器计数器
  timerCounter++;

  // 当计数器达到ms时，切换蜂鸣器状态
  if (timerCounter >= ms) {
        timerCounter = 0;  // 重置计数器
        beep = beepState;
        beepState = !beepState;  // 切换蜂鸣器状态
  }
}

void delay_timer1(void)
{
  // 使用中断的方式进行延时
  EA = 1; // 允许总中断
  ET1 = 1; // 允许定时器1中断
  PT1 = 1; // 设置定时器1中断为高优先级
  TMOD = 0x10; // 设置定时器1为模式1(16位定时器)

  // 定时器1中断每1毫秒触发一次
  TH1 = 0xFC;  // 定时器初值高8位
  TL1 = 0x18;  // 定时器初值低8位
  TR1 = 1; // 启动定时器1
}
