#ifndef _READY_SCREEN_H_
#define _READY_SCREEN_H_

extern unsigned char question_index, question_value, question_count;

void screen_ready_screen_load()
{
	unsigned char bank;

	// Clear space.
	engine_select_manager_clear();

	// TODO format this better!!
	engine_font_manager_draw_text("DIFFICULTY", 2, 5);
	engine_font_manager_draw_text( select_diff_option[diff_select], 2, 6);

	engine_font_manager_draw_text("QUESTIONS", 2, 8);
	engine_font_manager_draw_data( question_count, 3, 9);

	engine_font_manager_draw_text(LOCALE_GET, 5, 12);
	engine_font_manager_draw_text(LOCALE_READY, 5, 13);
	// TODO format this better!!


	// Initialize all relevant variables before quiz starts...
	question_index = 0;
	question_value = 0;

	engine_random_manager_init();

	bank = diff_select + QUIZ_BANK;
	engine_quiz_manager_bank( bank );

	engine_random_manager_load();
	engine_select_manager_load_quiz();

}

void screen_ready_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;

	rand();
	input = engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1);
	if( input )
	{
		engine_select_manager_clear();
		engine_audio_manager_stop_music();
		*screen_type = SCREEN_TYPE_PLAY;
		return;
	}

	*screen_type = SCREEN_TYPE_READY;
}

#endif//_READY_SCREEN_H_