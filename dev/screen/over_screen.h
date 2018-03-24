#ifndef _OVER_SCREEN_H_
#define _OVER_SCREEN_H_

// This will be the "Number questions" screen!

void screen_over_screen_load()
{
	float percent = 0.0f;

	// TODO REMOVE
	engine_debug_manager_clear();
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("OVER", 2, 2);
	// TODO REMOVE


	// TODO REMOVE format better
	engine_font_manager_draw_text("QUESTIONS", 2, 2);
	engine_font_manager_draw_text("TOTAL", 2, 3);
	engine_font_manager_draw_data(question_long, 4, 4);

	engine_font_manager_draw_text("QUESTIONS", 2, 6);
	engine_font_manager_draw_text("ANSWERED", 2, 7);
	engine_font_manager_draw_data(question_count, 4, 8);

	engine_font_manager_draw_text("NUMBER", 2, 10);
	engine_font_manager_draw_text("CORRECT", 2, 11);
	engine_font_manager_draw_data(score_player, 4, 12);

	engine_font_manager_draw_text("PERCENTAGE", 2, 15);
	percent = (float)score_player / (float)question_long * 100;
	engine_font_manager_draw_data(percent, 4, 16);
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