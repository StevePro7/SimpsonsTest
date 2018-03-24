#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

extern unsigned char question_index, question_value, question_long, question_count;
extern unsigned char question_value, option1_value, option2_value, option3_value, option4_value;
extern unsigned char answer_index, answer_value;

void screen_play_screen_load()
{
	// TODO REMOVE
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("PLAY", 2, 2);
	// TODO REMOVE


	engine_quiz_manager_base();
	engine_score_manager_base();

	question_value = quiz_questions[question_index];
	option1_value = quiz_options[question_value][0];
	option2_value = quiz_options[question_value][1];
	option3_value = quiz_options[question_value][2];
	option4_value = quiz_options[question_value][3];

	engine_select_manager_base();
	engine_quiz_manager_load(question_index, question_value, option1_value, option2_value, option3_value, option4_value);

	engine_quiz_manager_answer(question_value);
	engine_quiz_manager_cheat(answer_index);
}

void screen_play_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	engine_select_manager_draw_select();

	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1 );
	if( input )
	{
		*screen_type = SCREEN_TYPE_QUIZ;
		return;
	}

	input = engine_input_manager_hold_fire2( curr_joypad1, prev_joypad1 );
	if( input )
	{
		*screen_type = SCREEN_TYPE_SCORE;
		return;
	}

	input = engine_input_manager_hold_up(curr_joypad1, prev_joypad1);
	if( input )
	{
		quiz_select = engine_select_manager_move_up( quiz_select );
	}
	input = engine_input_manager_hold_down(curr_joypad1, prev_joypad1);
	if (input)
	{
		quiz_select = engine_select_manager_move_down( quiz_select );
	}

	*screen_type = SCREEN_TYPE_PLAY;
}

#endif//_PLAY_SCREEN_H_