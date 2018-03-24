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

	question_count++;
	screen_bases_screen_init();
	if( quiz_select == answer_index )
	{
		screen_quiz_screen_state = ANSWER_TYPE_RIGHT;
		
	}
	else
	{
		screen_quiz_screen_state = ANSWER_TYPE_WRONG;
	}

	if( ANSWER_TYPE_RIGHT == screen_quiz_screen_state )
	{
		engine_audio_manager_sound_right();
		engine_score_manager_update();
	}
	else
	{
		engine_audio_manager_sound_wrong();
	}
}

void screen_quiz_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	if( ANSWER_TYPE_RIGHT == screen_quiz_screen_state )
	{
		engine_select_manager_draw_right();
	}
	else
	{
		engine_select_manager_draw_wrong();
	}

	*screen_type = SCREEN_TYPE_QUIZ;
}

#endif//_QUIZ_SCREEN_H_