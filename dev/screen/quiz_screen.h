#ifndef _QUIZ_SCREEN_H_
#define _QUIZ_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_quiz_screen_delay, screen_quiz_screen_state;

void screen_quiz_screen_load()
{
	// TODO REMOVE
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("QUIZ", 2, 2);
	// TODO REMOVE


	screen_bases_screen_init();
	if( select_choice == answer_index )
	{
		engine_score_manager_update();
	}


}

void screen_quiz_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_QUIZ;
}

#endif//_QUIZ_SCREEN_H_