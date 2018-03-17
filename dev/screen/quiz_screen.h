#ifndef _QUIZ_SCREEN_H_
#define _QUIZ_SCREEN_H_

void screen_quiz_screen_load()
{
}

void screen_quiz_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int bob = curr_joypad1 * 2;
	unsigned int sgb = prev_joypad1 * 2;

	*screen_type = SCREEN_TYPE_TITLE;
}

#endif//_QUIZ_SCREEN_H_