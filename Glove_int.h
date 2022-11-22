/*
 * Glove_int.h
 *
 *  Created on: Aug 25, 2019
 *      Author: Ahmed
 */

#ifndef GLOVE_INT_H_
#define GLOVE_INT_H_

	void send_bufferini(void);
	// Send Buffer to UART TX Pin
	void send_buffer(void);
	// Set Volume And Send it's Serial Command
	void set_volume( int volume );
	// Set a Track (1-3000) to Play
	void play_track(int track_id);


#endif /* GLOVE_INT_H_ */
