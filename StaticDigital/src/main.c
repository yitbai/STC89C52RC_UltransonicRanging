#include <8052.h>
#include "mygpio.h"
#include "myled.h"

int main(void)
{
  myGPIO_Init();

  static_led_on(2, 9);

  return 0;
}