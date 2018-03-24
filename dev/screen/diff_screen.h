#ifndef _DIFF_SCREEN_H_
#define _DIFF_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_diff_screen_delay, screen_diff_screen_state;

void screen_diff_screen_init()
{
	screen_bases_screen_init();
	screen_intro_screen_delay = NORMAL_DELAY;
}

void screen_diff_screen_load()
{
	engine_select_manager_base();
	engine_select_manager_load_diff();
}

void screen_diff_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	engine_select_manager_draw_select();

	input = engine_input_manager_hold_up(curr_joypad1, prev_joypad1);
	if( input )
	{
		diff_select = engine_select_manager_move_up( diff_select );
	}
	input = engine_input_manager_hold_down(curr_joypad1, prev_joypad1);
	if (input)
	{
		diff_select = engine_select_manager_move_down( diff_select );
	}

	*screen_type = SCREEN_TYPE_DIFF;
}

#endif//_DIFF_SCREEN_H_