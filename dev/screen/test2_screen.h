#ifndef _TEST2_SCREEN_H_
#define _TEST2_SCREEN_H_

//extern unsigned char select_choice;
extern unsigned char question_index, question_value, question_count;
extern unsigned char question_value, option1_value, option2_value, option3_value, option4_value;
extern unsigned char answer_index, answer_value;

void screen_test2_screen_init()
{
	/*screen_test2_screen_delay = 100;*/
}

// Play
void screen_test2_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 0, 1);
	engine_font_manager_draw_text("TEST2", 0, 1);


	engine_quiz_manager_base();

	question_value = quiz_questions[question_index];
	option1_value = quiz_options[question_value][0];
	option2_value = quiz_options[question_value][1];
	option3_value = quiz_options[question_value][2];
	option4_value = quiz_options[question_value][3];

	engine_font_manager_draw_data(question_index, 15, 0);
	engine_font_manager_draw_data(question_value, 20, 0);

	engine_font_manager_draw_data(option1_value, 20, 10);
	engine_font_manager_draw_data(option2_value, 20, 11);
	engine_font_manager_draw_data(option3_value, 20, 12);
	engine_font_manager_draw_data(option4_value, 20, 13);

	//engine_quiz_manager_load(question_index, question_value, option1_value, option2_value, option3_value, option4_value);
}

void screen_test2_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	input = engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1);
	if( input )
	{
		*screen_type = SCREEN_TYPE_TEST3;
		return;
	}

	*screen_type = SCREEN_TYPE_TEST2;
}

#endif//_TEST2_SCREEN_H_