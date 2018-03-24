#ifndef _SCORE_SCREEN_H_
#define _SCORE_SCREEN_H_

#define TEXT_X		2
#define DATA_X		19

void screen_score_screen_load()
{
	float percent = 0.0f;
	engine_select_manager_clear2();

	//SMS_displayOff();
	//engine_content_manager_load_maggie();
	//engine_content_manager_load_sprites();
	//SMS_setSpritePaletteColor(0, RGB(3,3,3));
	//SMS_displayOn();


	// TODO REMOVE format better
	//engine_font_manager_draw_text("PRESS FIRE2 TO RESUME QUIZ", 2, 20);
	//engine_font_manager_draw_text("PRESS FIRE1 TO FINISH QUZE", 2, 21);

	//engine_font_manager_draw_text("1234567890123456789", 2, 4);


	engine_font_manager_draw_text( "=THE STATISTICS=", 8, TITLE_Y);

	engine_font_manager_draw_text("QUESTIONS TOTAL", TEXT_X, 5);
	engine_font_manager_draw_data_ZERO(question_long, DATA_X, 6);

	engine_font_manager_draw_text("QUESTIONS SOLVED", TEXT_X, 9);
	//engine_font_manager_draw_text("ANSWERED", 2, 9);
	engine_font_manager_draw_data_ZERO(question_count, DATA_X, 10);

	engine_font_manager_draw_text("QUESTIONS RIGHT", TEXT_X, 13);
	//engine_font_manager_draw_text("CORRECT", 2, 13);
	engine_font_manager_draw_data_ZERO(score_player, DATA_X, 14);

	// Allow for potential division by zero error.
	engine_font_manager_draw_text("CURRENT PERCENT", TEXT_X, 17);
	if( question_count == 0 )
	{
		engine_font_manager_draw_data_ZERO(percent, DATA_X, 18);
		engine_font_manager_draw_text("%", DATA_X + 1, 18);
		return;
	}

	percent = (float)score_player / (float)question_count * 100;
	engine_font_manager_draw_data_ZERO(percent, DATA_X, 18);
	engine_font_manager_draw_text("%", DATA_X + 1, 18);

}

void screen_score_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;

	input = engine_input_manager_hold_fire2( curr_joypad1, prev_joypad1 );
	if( input )
	{
		engine_select_manager_clear2();
		*screen_type = SCREEN_TYPE_PLAY;
		return;
	}

	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1 );
	if( input )
	{
		engine_select_manager_clear2();
		*screen_type = SCREEN_TYPE_OVER;
		return;
	}

	*screen_type = SCREEN_TYPE_SCORE;
}

#endif//_SCORE_SCREEN_H_