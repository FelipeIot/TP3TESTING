#include "leds.h"
#define LEDS_ALL_OFF    0x0000
#define LEDS_ALL_ON     0xFFFF
#define LED_STATE_ON    1
#define LED_STATE_OFF   0 

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

void LedsAllOn(uint16_t * direccion)
{
    puerto=direccion;
    *puerto=LEDS_ALL_ON;
}


void LedsAllOff(uint16_t * direccion)
{
    puerto=direccion;
    *puerto=LEDS_ALL_OFF;
}

uint8_t LedState(uint8_t nled)
{
    static uint8_t vretorno;

    if(*puerto & BitMask(ledTOBit(nled)))
    {
        vretorno=LED_STATE_ON;
    }
    else
    {
        vretorno=LED_STATE_OFF;
    }
    
    return vretorno;
}