#ifndef _LEVEL_SCREEN_H_
#define _LEVEL_SCREEN_H_

// Dump previous contents of the play screen here
void screen_level_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("LEVEL", 2, 2);

	/*
	SMS_displayOff();

	// Load full screen image here!
	engine_content_manager_load_maggie();
	engine_content_manager_load_sprites();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	engine_quiz_manager_base();
	engine_quiz_manager_bank(2);
	//engine_quiz_manager_load();
	engine_score_manager_draw();

	play_answer_state = ANSWER_TYPE_SELECT;
	SMS_displayOn();
	*/
}

void screen_level_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_LEVEL;

	/*
	if(ANSWER_TYPE_SELECT == play_answer_state)
	{
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


	// REMOVE - used for testing
	input = engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1);
	if( input )
	{
	play_answer_state = ANSWER_TYPE_RIGHT;
	engine_sprite_manager_hide_select();
	engine_audio_manager_sound_right();
	}
	input = engine_input_manager_hold_fire2(curr_joypad1, prev_joypad1);
	if( input )
	{
	play_answer_state = ANSWER_TYPE_WRONG;
	engine_sprite_manager_hide_select();
	engine_audio_manager_sound_wrong();
	}
	// REMOVE - used for testing


	}

	if(ANSWER_TYPE_RIGHT == play_answer_state)
	{
	engine_select_manager_draw_right();
	}
	if(ANSWER_TYPE_WRONG == play_answer_state)
	{
	engine_select_manager_draw_wrong();
	}

	*screen_type = SCREEN_TYPE_PLAY;
	*/
}

#endif//_LEVEL_SCREEN_H_