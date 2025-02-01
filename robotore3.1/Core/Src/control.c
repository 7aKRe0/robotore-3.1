#include "main.h"


void ControlMotor(double duty_L, double duty_R){
    if (duty_L >= 0) {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET); // PH-HIGH(+)
        __HAL_TIM_SET_COMPARE( &htim8,TIM_CHANNEL_4, duty_L);
    } else {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET); // PH-LOW(-)
        __HAL_TIM_SET_COMPARE( &htim8,TIM_CHANNEL_4, -duty_L);
    }
    if (duty_R >= 0) {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET); // PH-HIGH(+)
        __HAL_TIM_SET_COMPARE( &htim1,TIM_CHANNEL_2, duty_R);
    } else {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET); // PH-LOW(-)
        __HAL_TIM_SET_COMPARE( &htim1,TIM_CHANNEL_2, -duty_R);
        }
}



