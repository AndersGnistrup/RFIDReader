/*
 * RfidReader.cpp
 *
 * Created: 04-05-2020 21:16:33
 * Author : agn
 */

extern "C" {
	#include "uart/uart.h"
}
#include <avr/io.h>
#include <util/delay.h>

// Select baud rate on the uart
#define UART_SPEED_115200 UART_BAUD_SELECT_DOUBLE_SPEED(115200, 16000000)

int main(void)
{
	uart0_init(UART_SPEED_115200);
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(1000);
		uart_puts("Hello world\r\n");
    }
}

