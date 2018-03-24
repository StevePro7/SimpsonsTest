#ifndef _READY_SCREEN_H_
#define _READY_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned int screen_ready_screen_delay;
extern unsigned char question_index, question_value, question_long, question_count;

void screen_ready_screen_init()
{
	screen_ready_screen_delay = NORMAL_DELAY * 4;
}

void screen_ready_screen_load()
{
//	unsigned char bank;


	// TODO REMOVE
	diff_select = 1;
	question_long = 3;
	// TODO REMOVE

	screen_bases_screen_init();

	// Clear space.
	engine_select_manager_clear();

	// TODO format this better!!
	engine_font_manager_draw_text("DIFFICULTY", 2, 5);
	engine_font_manager_draw_text( select_diff_option[diff_select], 2, 6);

	engine_font_manager_draw_text("QUESTIONS", 2, 8);
	engine_font_manager_draw_data( question_long, 3, 9);

	engine_font_manager_draw_text(LOCALE_GET, 5, 12);
	engine_font_manager_draw_text(LOCALE_READY, 5, 13);
	// TODO format this better!!


	// Initialize all relevant variables before quiz starts...
	question_index = 0;
	question_value = 0;
	question_count = 0;
	engine_score_manager_init();


	/*engine_random_manager_init();
	bank = diff_select + QUIZ_BANK;
	engine_quiz_manager_bank( bank );
	engine_random_manager_load();
	engine_select_manager_load_quiz();*/
}

void screen_ready_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	unsigned char level = 0;

	rand();
	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1 );
	if( input )
	{
		level = 1;
	}

	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_ready_screen_delay )
	{
		level = 1;
	}

	if ( level )
	{
		engine_select_manager_clear();
		engine_audio_manager_stop_music();

		// TODO REMOVE
		//engine_debug_manager_clear();
		// TODO REMOVE


		*screen_type = SCREEN_TYPE_LEVEL;
		return;
	}

	*screen_type = SCREEN_TYPE_READY;
}

#endif//_READY_SCREEN_H_