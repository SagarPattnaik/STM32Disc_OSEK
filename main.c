/**
 * @file OsekIntro_Example1.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  Simple example to show the support of periodic task using Alarm OS
 * object
 * @version 0.1
 * @date 2020-05-1
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */
#include <stdbool.h>
#include <stdint.h>
#include "led.h"
#include "os.h"

#define USE_REAL_HW   1 /* 0 for simulation, 1 for real hardware */

DeclareTask(AppTaskBlinker);
DeclareTask(AppTaskInit);

int main(void) {
  StartOS();
  while (1)
    ; /* Should not be executed */
  return 0;
}

TASK(AppTaskBlinker) {

  static uint8_t Blinker_Counter = 0u;
  Blinker_Counter ^= 0x2;
#if USE_REAL_HW
	led_toggle(LED_BLUE);
#endif
  TerminateTask();
}
TASK(AppTaskInit) {

#if USE_REAL_HW
   led_init_all();
#endif
  TerminateTask();
}
