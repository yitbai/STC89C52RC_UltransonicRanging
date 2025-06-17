#include "beep.h"
#include "my_types.h"

void beep_on(void)
{
    beep = 0; // 打开蜂鸣器
}
void beep_off(void)
{
    beep = 1; // 关闭蜂鸣器
}