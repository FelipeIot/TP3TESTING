
/*
 * Asegurarase que un led no afecta los demas
 * Prender todos los leds simultaneamente
 * Apagar todos los leds simultaneamente
 * Consultar el estado de un led prendido
 * Consultar el estado de un led apagado
 * 
*/



#include "unity.h"
#include "leds.h"

uint16_t virtuales;

void setUp(void)
{
    LedsCreate(&virtuales);
}


void test_todos_los_leds_inician_apagados(void)
{
    uint16_t virtuales=0xFFFF;
    LedsCreate(&virtuales);
    TEST_ASSERT_EQUAL(0x0000,virtuales);
}

void test_enceder_un_led(void)
{

    LedsTurnOn(1);
    TEST_ASSERT_EQUAL(0x0001,virtuales);
}

void test_encender_y_apagar_un_led(void)
{

        LedsTurnOn(1);
        LedsTurnOff(1);
        TEST_ASSERT_EQUAL(0x0000,virtuales);
}

void test_prender_y_apagar_varios_leds(void)
{
        LedsTurnOn(3);
        LedsTurnOn(5);
        LedsTurnOff(3);
        TEST_ASSERT_EQUAL(0x0010,virtuales);
}