/*
 * Glove_prog.c
 *
 *  Created on: Aug 25, 2019
 *      Author: Ahmed
 */
#include "LIB/STD_Types.h"
#include "UART_int.h"
#include "UART_reg.h"
#include "LIB/Bit_Op.h"
#include "Glove_int.h"

	int default_buffer[10] = {0x7E , 0xFF , 0x06 , 0x09 , 0x00 , 0x00 , 0x02 , 0xFF , 0xF0 , 0xEF}; // Default Buffer
//	int buffer_data[10] = {0x7E , 0xFF , 0x06 , 0x00 , 0x00 , 0x00 , 0x00 , 0xEF}; // Sending Buffer
	int buffer_data[10] = {0x7E , 0xFF , 0x06 , 0x03 , 0x00 , 0x00 , 0x01 , 0xFF , 0xE6 , 0xEF }; // Sending Buffer


	// Send Buffer to UART TX Pin
/*	void send_buffer(void) {
	    int i;
	    for( i=0; i< 10; i++){
	        putchar(buffer_data[i]);
	        buffer_data[i] = default_buffer[i];
	    }
	}*/
	void send_bufferini(void)
	{
		int i;
		for(i=0 ; i<10 ; i++)
		{
		UART_vidSendChar(default_buffer[i]);
		//buffer_data[i] = default_buffer[i];
		}
	}
	void send_buffer(void)
	{
		int i;
		for(i=0 ; i<10 ; i++)
		{
		UART_vidSendChar(buffer_data[i]);
		//buffer_data[i] = default_buffer[i];
		}
	}

	// Set Volume And Send it's Serial Command
	void set_volume( int volume ) {
	    buffer_data[3] = 0x06;
	    buffer_data[6] = volume;
	    send_buffer();
	}

	// Set a Track (1-3000) to Play
	void play_track(int track_id) {
	  buffer_data[3] = 0x03;
	  if(track_id < 256) {
	    buffer_data[6] = track_id;
	  } else {
	    buffer_data[5] = track_id / 256;
	    buffer_data[6] = track_id - 256 * buffer_data[6];
	  }
	    send_buffer();
	}
