#include "stdint.h"
void LedsCreate(uint16_t * direccion);
void LedsTurnOn(uint8_t led);
void LedsTurnOff(uint8_t led);
void LedsAllOn(uint16_t * direccion);
void LedsAllOff(uint16_t * direccion);
uint8_t LedState(uint8_t nled);