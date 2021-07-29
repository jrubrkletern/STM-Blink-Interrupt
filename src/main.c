#include "stm32f429xx.h"


void SysTick_Handler() {
        GPIOG->ODR ^= (1<<14);
}

int main() {

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;

    GPIOG->MODER |= GPIO_MODER_MODE13_0 | GPIO_MODER_MODE14_0;
        
    SysTick_Config(SystemCoreClock);

    volatile int countdown = 1000000;

    for(;;) {
        while(countdown > 0) {
            countdown--;
        } 
        GPIOG->ODR ^= (1<<13);
        countdown = 1000000;
    }
   


}
