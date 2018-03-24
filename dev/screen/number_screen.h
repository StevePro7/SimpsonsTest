#ifndef _NUMBER_SCREEN_H_
#define _NUMBER_SCREEN_H_

// This will be the "Select difficulty" screen!

void screen_number_screen_load()
{
	//unsigned char bob[MAX_OPTIONS][6] = { "EASY", "NORM", "HARD", "ARGH" };
	//unsigned char sgb[MAX_OPTIONS][6] = { LOCALE_DIFF_OPT1, LOCALE_DIFF_OPT2, LOCALE_DIFF_OPT3, LOCALE_DIFF_OPT4 };

	engine_font_manager_draw_text( "      ", 2, 1 );
	engine_font_manager_draw_text( "NUMBER", 2, 1 );

	//engine_quiz_manager_base();
	//engine_score_manager_base();
	engine_select_manager_base();
	engine_select_manager_load_diff();
	//engine_font_manager_draw_text(sgb[2], QUIZ_X+2, OPTA_Y);
}

void screen_number_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	engine_select_manager_draw_select();

	input = engine_input_manager_hold_up(curr_joypad1, prev_joypad1);
	if( input )
	{
		diff_select = engine_select_manager_move_up( diff_select );
		engine_font_manager_draw_data(select_choice, 20, 0);
	}
	input = engine_input_manager_hold_down(curr_joypad1, prev_joypad1);
	if (input)
	{
		diff_select = engine_select_manager_move_down( diff_select );
		engine_font_manager_draw_data(select_choice, 20, 0);
	}

	//if ((curr_joypad1 & PORT_A_KEY_1 && !(prev_joypad1 & PORT_A_KEY_1)) ||
	//	(curr_joypad1 & PORT_A_KEY_2 && !(prev_joypad1 & PORT_A_KEY_2)))
	//{
	//	level = 1;
	//}

	//if (level)
	//{
	//	engine_audio_manager_stop_music();
	//	//*screen_type = SCREEN_TYPE_INTRO;
	//	//*screen_type = SCREEN_TYPE_READY;
	//	*screen_type = SCREEN_TYPE_PLAY;
	//}
}

#endif//_NUMBER_SCREEN_H_