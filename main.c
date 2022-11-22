/*
 * main.c
 *
 *  Created on: Aug 25, 2019
 *      Author: Ahmed
 */

#include "stdio.h"
#include "avr/io.h"
#include "LIB/STD_Types.h"
#include "UART_int.h"
#include "Dio.h"
#include "Glove_int.h"
#include "util/delay.h"

void main(void)
{
	uint8 i;
	uint8 state_of_switches;
	uint8 checksum;
	Dio_vidSetPortDirection(Dio_PORTC,Dio_Input);   //switches
	Dio_vidWritePort(Dio_PORTC,0xFF);

	UART_vidInit();
	set_volume( 30 );
	while(1)
	{	 send_bufferini();
	     _delay_ms(100);
		 send_buffer();
		 _delay_ms(10000);
		/*for(i=0;i<10;i++)
		{
			state_of_switches = Dio_u8ReadPort(Dio_PORTC,0);
			_delay_ms(100);
		}

	    if(state_of_switches == 0b00011110)
	    {
		    play_track(001);
	    }
	    else if(state_of_switches == 0b00011101)
	    {
		    play_track(002);
	    }
	    else if(state_of_switches == 0b00011011)
	    {
		    play_track(003);
	    }
	    else if(state_of_switches == 0b00010111)
	    {
		    play_track(004);
	    }
	    else if(state_of_switches == 0b00001111)
	    {
		    play_track(005);
	    }*/

	}
}


