#ifndef _QUIZ_SCREEN_H_
#define _QUIZ_SCREEN_H_

void screen_quiz_screen_load()
{
}

void screen_quiz_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_QUIZ;
}

#endif//_QUIZ_SCREEN_H_