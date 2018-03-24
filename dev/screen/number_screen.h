#ifndef _NUMBER_SCREEN_H_
#define _NUMBER_SCREEN_H_

// Back up the Intro screen

void screen_number_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 0, 1);
	engine_font_manager_draw_text("NUMBER", 0, 1);

}

void screen_number_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_NUMBER;
}

#endif//_NUMBER_SCREEN_H_