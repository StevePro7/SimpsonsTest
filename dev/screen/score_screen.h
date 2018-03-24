#ifndef _SCORE_SCREEN_H_
#define _SCORE_SCREEN_H_

void screen_score_screen_load()
{
	float percent = 0.0f;

	// TODO REMOVE
	engine_debug_manager_clear();
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("SCORE", 2, 2);
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

	// Allow for potential division by zero error.
	engine_font_manager_draw_text("PERCENTAGE", 2, 15);
	if( question_count == 0 )
	{
		engine_font_manager_draw_data(percent, 4, 16);
		return;
	}

	percent = (float)score_player / (float)question_count * 100;
	engine_font_manager_draw_data(percent, 4, 16);
}

void screen_score_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	input = engine_input_manager_hold_fire2( curr_joypad1, prev_joypad1 );
	if( input )
	{
		// TODO REMOVE
		engine_debug_manager_clear();
		// TODO REMOVE

		*screen_type = SCREEN_TYPE_PLAY;
		return;
	}

	*screen_type = SCREEN_TYPE_SCORE;
}

#endif//_SCORE_SCREEN_H_