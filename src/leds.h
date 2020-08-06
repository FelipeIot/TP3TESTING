#include "stdint.h"
#include <stdbool.h>

#define LEDS_ALL_OFF    0x0000
#define LEDS_ALL_ON     0xFFFF
#define LED_STATE_ON    1
#define LED_STATE_OFF   0 


void LedsCreate(uint16_t * direccion);
void LedsTurnOn(uint8_t led);
void LedsTurnOff(uint8_t led);
void LedsAllOn(uint16_t * direccion);
void LedsAllOff(uint16_t * direccion);
bool LedState(uint8_t nled);