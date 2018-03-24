#ifndef _NUMBER_SCREEN_H_
#define _NUMBER_SCREEN_H_

// This will be the "Select difficulty" screen!

void screen_number_screen_load()
{
	engine_select_manager_base();
	engine_select_manager_load_diff();
}

void screen_number_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
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

	*screen_type = SCREEN_TYPE_NUMBER;
}

#endif//_NUMBER_SCREEN_H_