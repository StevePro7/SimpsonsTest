#ifndef _LONG_SCREEN_H_
#define _LONG_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_long_screen_delay, screen_long_screen_state;

void screen_long_screen_init()
{
	screen_bases_screen_init();
	screen_long_screen_delay = NORMAL_DELAY;
	screen_long_screen_state = SELECT_TYPE_BEFORE;
}

void screen_long_screen_load()
{
	engine_select_manager_clear();
	engine_select_manager_load_long();
	engine_select_manager_base();
}

void screen_long_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;

	if( SELECT_TYPE_BEFORE == screen_long_screen_state )
	{
		engine_select_manager_draw_select();
		input = engine_input_manager_hold_up(curr_joypad1, prev_joypad1);
		if( input )
		{
			long_select = engine_select_manager_move_up( long_select );
		}
		input = engine_input_manager_hold_down(curr_joypad1, prev_joypad1);
		if (input)
		{
			long_select = engine_select_manager_move_down( long_select );
		}
		input = engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1);
		if (input)
		{
			engine_audio_manager_sound_right();
			screen_long_screen_state = SELECT_TYPE_AFTER;
		}
	}

	if( SELECT_TYPE_AFTER == screen_long_screen_state )
	{
		engine_select_manager_draw_right();

		screen_bases_screen_timer++;
		if (screen_bases_screen_timer >= screen_long_screen_delay)
		{
			*screen_type = SCREEN_TYPE_READY;
			return;
		}
	}

	*screen_type = SCREEN_TYPE_LONG;
}

#endif//_LONG_SCREEN_H_