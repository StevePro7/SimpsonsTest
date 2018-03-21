#ifndef _TEST1_SCREEN_H_
#define _TEST1_SCREEN_H_

//extern unsigned int screen_bases_screen_count;
//extern unsigned int screen_bases_screen_timer;
//extern unsigned char screen_test1_screen_delay;

extern unsigned char question_index, question_value, question_count;
extern unsigned char question_value, option1_value, option2_value, option3_value, option4_value;
extern unsigned char answer_index, answer_value;

void screen_test1_screen_init()
{
	//screen_test1_screen_delay = 100;
	question_value = 0;
}

void screen_test1_screen_load()
{
	question_count = 3;
	question_index = 0;

	rand();

	//engine_font_manager_draw_text("STOP!", 3, 3);
	engine_random_manager_init();
	engine_debug_manager_init();

	engine_random_manager_load();
	engine_debug_manager_load();
}

void screen_test1_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_TEST1;
}

#endif//_TEST1_SCREEN_H_