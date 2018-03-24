#ifndef _READY_SCREEN_H_
#define _READY_SCREEN_H_

void screen_ready_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("READY", 2, 2);
}

void screen_ready_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;

	input = engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1);
	if( input )
	{
		engine_audio_manager_stop_music();
		*screen_type = SCREEN_TYPE_PLAY;
		return;
	}

	*screen_type = SCREEN_TYPE_READY;
}

#endif//_READY_SCREEN_H_