
/*
 * Asegurarase que un led no afecta los demas
 * Prender todos los leds simultaneamente
 * Apagar todos los leds simultaneamente
 * Consultar el estado de un led prendido
 * Consultar el estado de un led apagado
 * Consultar el estado de un led encendido con 2 leds encedidos
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

void test_dos_leds_independientes(void)
{
        LedsTurnOn(4);
        LedsTurnOn(7);
        TEST_ASSERT_EQUAL(0x0048,virtuales);
}

void test_encender_todos(void)
{
        LedsAllOn(&virtuales);
        TEST_ASSERT_EQUAL(0xFFFF,virtuales);
}

void test_apagar_todos(void)
{
        uint16_t virtuales=0xFFFF;
        LedsAllOff(&virtuales);
        TEST_ASSERT_EQUAL(0x0000,virtuales);
}

void test_obtener_estado_led_encendido(void)
{
    uint8_t estado;
    LedsTurnOn(12);
    estado=LedState(12);
    TEST_ASSERT_EQUAL(0x01,estado);
}



void test_obtener_estado_leds_apagado(void)
{
    uint8_t estado;
    LedsTurnOff(8);
    estado=LedState(8);
    TEST_ASSERT_EQUAL(0x00,estado);
}

void test_obtener_estado_led_encendido_con_dos_encendidos(void)
{
    uint8_t estado;
    LedsTurnOn(2);
    LedsTurnOn(13);
    estado=LedState(2);
    TEST_ASSERT_EQUAL(0x01,estado);
}







