#include "leds.h"
#define LEDS_ALL_OFF 0x0000

static uint16_t * puerto;

uint8_t ledTOBit(uint8_t led)
{
    return (led-1);
}

uint16_t BitMask(uint8_t bit)
{
    return(1<<bit);
}


void LedsCreate(uint16_t * direccion)
{   
    puerto=direccion;
    *puerto=LEDS_ALL_OFF;
}

void LedsTurnOn(uint8_t led)
{
    *puerto |=BitMask(ledTOBit(led));
}

void LedsTurnOff(uint8_t led)
{
    *puerto &=~BitMask(ledTOBit(led));
}
