## What I did:
  
  - I did followed the instruction on assignment08. I did use the code from the Tutorial and modified with my system clock(4 MHz)
  
  - One problem I had was an infinite loop happened when I try to reload PWM value by calling HAL_TIM_PWM_ConfigChannel(). **Andrew Law's** posting on DIscussion link solved the problem. But I still don't understand what exactly happening in detail. But, I'll keep looking for the answer.

## a-b. executed as instructed:![STM32CubeMX](https://github.com/khkim607/embsys310/blob/main/assignment08/PWM%20configuration_STM32CubeMX.png)

## c. attached file: [main.c](https://github.com/khkim607/embsys310/blob/main/assignment08/Core/Src/main.c)

- For LED1(PA5): System clock(4 MHz), Prescaler(20), clock to counter(200KHz), CounterPeriod(2000: 200ms), PWM duty cycle (0.75)

- For LED2(PB14): System clock(4 MHz), Prescaler(200), clock to counter(20KHz), CounterPeriod(10000: 0.5s), PWM duty cycle (0.1)

- LED1 is set to show PWM value change. Up-down cycle of 2 sec(20x100 msec), 10 steps increase for 1 sec (1x100 msec), and 10 steps decrease for 1 sec (1x100 msec)

- LED2 is set to show just short duty cycle w/o PWM value change.

## d. attached video: [PWM_LED_AS08_Kihong.mp4](https://github.com/khkim607/embsys310/blob/main/assignment08/PWM_LED_AS08_Kihong.mp4)

- LED1 intensity changes in 2 sec cycle; increases for 1 sec and decreases for 1 sec. Intensity level changes at every 100 msec. 

- LED2 intensity does not change. It is blinking twice per second for 0.05 sec with the duty cycle of 0.1   

## e. files uploaded: [Core](https://github.com/khkim607/embsys310/tree/main/assignment08/Core)
  
- I tried to upload whole project files, but failed due to its large number and size(maybe I am missing some information on Github system).  So I uploaded main.c and other src files only.

## FYI

- Thank you for all the encouragement during the course! It helped me a lot to finish the course and keep moving forward. 
 
