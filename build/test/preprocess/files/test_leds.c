#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


uint16_t virtuales;



void setUp(void)

{

    LedsCreate(&virtuales);

}





void test_todos_los_leds_inician_apagados(void)

{

    uint16_t virtuales=0xFFFF;

    LedsCreate(&virtuales);

    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}



void test_enceder_un_led(void)

{



    LedsTurnOn(1);

    UnityAssertEqualNumber((UNITY_INT)((0x0001)), (UNITY_INT)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}



void test_encender_y_apagar_un_led(void)

{



        LedsTurnOn(1);

        LedsTurnOff(1);

        UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((virtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);

}



void test_prender_y_apagar_varios_leds(void)

{

        LedsTurnOn(3);

        LedsTurnOn(5);

        LedsTurnOff(3);

        UnityAssertEqualNumber((UNITY_INT)((0x0010)), (UNITY_INT)((virtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

}



void test_dos_leds_independientes(void)

{

        LedsTurnOn(4);

        LedsTurnOn(7);

        UnityAssertEqualNumber((UNITY_INT)((0x0048)), (UNITY_INT)((virtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}



void test_encender_todos(void)

{

        LedsAllOn(&virtuales);

        UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((virtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

}



void test_apagar_todos(void)

{

        uint16_t virtuales=0xFFFF;

        LedsAllOff(&virtuales);

        UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((virtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

}



void test_obtener_estado_led_encendido(void)

{

    uint8_t estado;

    LedsTurnOn(12);

    estado=LedState(12);

    UnityAssertEqualNumber((UNITY_INT)((0x01)), (UNITY_INT)((estado)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

}







void test_obtener_estado_leds_apagado(void)

{

    uint8_t estado;

    LedsTurnOff(8);

    estado=LedState(8);

    UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((estado)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

}



void test_obtener_estado_led_encendido_con_dos_encendidos(void)

{

    uint8_t estado;

    LedsTurnOn(2);

    LedsTurnOn(13);

    estado=LedState(2);

    UnityAssertEqualNumber((UNITY_INT)((0x01)), (UNITY_INT)((estado)), (

   ((void *)0)

   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);

}
