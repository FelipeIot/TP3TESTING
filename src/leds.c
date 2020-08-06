#include "leds.h"


static uint16_t * puerto;


/**
 * @brief Obtiene el número de bit 
 * @param led numero de led
 * @return número de bit
 */
uint8_t ledTOBit(uint8_t led)
{
    return (led-1);
}

/**
 * @brief mascara a partir de el número de bit 
 * @param bit numero de bit
 * @return mascara
 */
uint16_t BitMask(uint8_t bit)
{
    return(1<<bit);
}

/**
 * @brief Asigna de direccion del puerto 
 * @param direccion la dirección del puerto
 */
void LedsCreate(uint16_t * direccion)
{   
    puerto=direccion;
    *puerto=LEDS_ALL_OFF;
}


/**
 * @brief Enciende un led específico 
 * @param led número de led
 */
void LedsTurnOn(uint8_t led)
{
    *puerto |=BitMask(ledTOBit(led));
}

/**
 * @brief Apaga un led específico 
 * @param led número de led
 */
void LedsTurnOff(uint8_t led)
{
    *puerto &=~BitMask(ledTOBit(led));
}

/**
 * @brief Enciende todos los leds
 * @param direccion la dirección del puerto
 */

void LedsAllOn(uint16_t * direccion)
{
    puerto=direccion;
    *puerto=LEDS_ALL_ON;
}

/**
 * @brief Apaga todos los leds
 * @param direccion la dirección del puerto
 */
void LedsAllOff(uint16_t * direccion)
{
    puerto=direccion;
    *puerto=LEDS_ALL_OFF;
}


/**
 * @brief Obtine el estado de un led específico
 * @param nled número de led
 * @return estado del led 
 */
bool LedState(uint8_t nled)
{
    static uint8_t vretorno;

    if(*puerto & BitMask(ledTOBit(nled)))
    {
        vretorno=true;
    }
    else
    {
        vretorno=false;
    }
    
    return vretorno;
}