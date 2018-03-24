#ifndef _NUMBER_SCREEN_H_
#define _NUMBER_SCREEN_H_

// Dump previous contents of the quiz screen here

void screen_number_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 0, 1);
	engine_font_manager_draw_text("NUMBER", 0, 1);

	/*
	SMS_displayOff();

	// Load full screen image here!
	engine_content_manager_load_maggie();
	engine_content_manager_load_sprites();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	engine_quiz_manager_base();
	engine_quiz_manager_bank(diff_select + QUIZ_BANK);
	engine_quiz_manager_loadX(0);
	engine_score_manager_draw();

	//engine_font_manager_draw_data(diff_select, 10, 10);
	//play_answer_state = ANSWER_TYPE_SELECT;
	SMS_displayOn();
	*/
}

void screen_number_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	/*
	unsigned char input = 0;

	engine_select_manager_draw_select();

	input = engine_input_manager_hold_up(curr_joypad1, prev_joypad1);
	if( input )
	{
	//engine_select_manager_move_up();
	}
	input = engine_input_manager_hold_down(curr_joypad1, prev_joypad1);
	if (input)
	{
	//engine_select_manager_move_down();
	}

	input = engine_input_manager_move_left(curr_joypad1);
	if( input )
	{
	if( 0 == quiz_number )
	{
	return;
	}

	quiz_number--;
	engine_quiz_manager_loadX(quiz_number);
	}
	input = engine_input_manager_move_right(curr_joypad1);
	if( input )
	{
	if(MAX_QUESTIONS-1 == quiz_number)
	{
	return;
	}

	quiz_number++;
	engine_quiz_manager_loadX(quiz_number);
	}
	*/

	*screen_type = SCREEN_TYPE_NUMBER;
}

#endif//_NUMBER_SCREEN_H_