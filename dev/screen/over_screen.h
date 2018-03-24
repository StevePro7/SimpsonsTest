#ifndef _OVER_SCREEN_H_
#define _OVER_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_over_screen_delay;

void screen_over_screen_init()
{
	//screen_over_screen_delay = NORMAL_DELAY * 8;
	screen_over_screen_delay = NORMAL_DELAY;
}

void screen_over_screen_load()
{
	float percent = 0.0f;
	screen_bases_screen_init();

	// TODO REMOVE
	engine_debug_manager_clear();
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("GAME OVER", 2, 2);
	// TODO REMOVE


	// TODO REMOVE format better
	engine_font_manager_draw_text("QUESTIONS", 2, 4);
	engine_font_manager_draw_text("TOTAL", 2, 5);
	engine_font_manager_draw_data(question_long, 4, 6);

	engine_font_manager_draw_text("QUESTIONS", 2, 8);
	engine_font_manager_draw_text("ANSWERED", 2, 9);
	engine_font_manager_draw_data(question_count, 4, 10);

	engine_font_manager_draw_text("NUMBER", 2, 12);
	engine_font_manager_draw_text("CORRECT", 2, 13);
	engine_font_manager_draw_data(score_player, 4, 14);

	engine_font_manager_draw_text("PERCENTAGE", 2, 16);
	percent = (float)score_player / (float)question_long * 100;
	engine_font_manager_draw_data(percent, 4, 17);
}

void screen_over_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	unsigned char level = 0;

	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1 );
	if( input )
	{
		level = 1;
	}

	screen_bases_screen_timer++;
	if (screen_bases_screen_timer >= screen_over_screen_delay)
	{
		level = 1;
	}

	if ( level )
	{
		// TODO REMOVE
		engine_debug_manager_clear();
		// TODO REMOVE

		*screen_type = SCREEN_TYPE_INTRO;
		return;
	}

	*screen_type = SCREEN_TYPE_OVER;
}

#endif//_OVER_SCREEN_H_