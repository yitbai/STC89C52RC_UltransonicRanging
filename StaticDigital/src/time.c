#include "time.h"

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

// value: 0-65535
// timer: 0-2 (0: TH0/TL0, 1: TH1/TL1, 2: TH2/TL2)
uchar set_timer_value(uchar timer,uint value)
{
  if (timer > 2) // 检查定时器编号是否有效
        return 0; // 返回0表示设置失败
  if (timer == 0) {
    TH0 = (value >> 8) & 0xFF; // 设置定时器高字节
    TL0 = value & 0xFF;        // 设置定时器低字节
    return 1; // 返回1表示设置成功
  } else if (timer == 1) {
    TH1 = (value >> 8) & 0xFF; // 设置定时器1高字节
    TL1 = value & 0xFF;        // 设置定时器1低字节
    return 1; // 返回1表示设置成功
  }
  return 0; // 返回0表示设置失败
}
