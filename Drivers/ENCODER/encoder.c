#include "encoder.h"
#include "tim.h"

static int16_t encoder_delta = 0;
static uint16_t prev_cnt = 0;

void encoder_init(void)
{
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);

    prev_cnt = __HAL_TIM_GET_COUNTER(&htim4);
}

void encoder_update(void)
{
    uint16_t cnt = __HAL_TIM_GET_COUNTER(&htim4);

    int16_t delta = (int16_t)(cnt - prev_cnt);

    prev_cnt = cnt;

    encoder_delta += delta;
}

int16_t encoder_get_delta(void)
{
    int16_t delta = encoder_delta;

    encoder_delta = 0;

    return delta;
}