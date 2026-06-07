#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>

void encoder_init(void);
void encoder_update(void);
int16_t encoder_get_delta(void);

#endif