#ifndef _NUMBER_SCREEN_H_
#define _NUMBER_SCREEN_H_

void screen_number_screen_load()
{
	if( hacker_debug )
	{
		engine_font_manager_draw_text( "      ", 2, 21 );
		engine_font_manager_draw_text( "NUMBER", 2, 21 );
	}
}

void screen_number_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char level = 0;
	if ((curr_joypad1 & PORT_A_KEY_1 && !(prev_joypad1 & PORT_A_KEY_1)) ||
		(curr_joypad1 & PORT_A_KEY_2 && !(prev_joypad1 & PORT_A_KEY_2)))
	{
		level = 1;
	}

	if (level)
	{
		engine_audio_manager_stop_music();
		//*screen_type = SCREEN_TYPE_INTRO;
		//*screen_type = SCREEN_TYPE_READY;
		*screen_type = SCREEN_TYPE_PLAY;
	}
}

#endif//_NUMBER_SCREEN_H_