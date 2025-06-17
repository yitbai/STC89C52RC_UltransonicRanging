#include "beep.h"

void beep_on(void)
{
    P2_3 = 0; // 打开蜂鸣器
}
void beep_off(void)
{
    P2_3 = 1; // 关闭蜂鸣器
}