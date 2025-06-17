#include "time.h"

void delay_ms(int ms)
{
  int j;
  while (ms--)
  {
    j = 70;
    while(j--);
  }
}
