#ifndef _OVER_SCREEN_H_
#define _OVER_SCREEN_H_

// This will be the "Number questions" screen!

void screen_over_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("OVER", 2, 2);

	/*engine_select_manager_clear();
	engine_select_manager_load_long();
	engine_select_manager_base();*/
}

void screen_over_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	/*unsigned char input = 0;
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
	}*/

	*screen_type = SCREEN_TYPE_OVER;
}

#endif//_OVER_SCREEN_H_