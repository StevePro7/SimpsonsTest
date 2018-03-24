#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

extern unsigned char play_answer_state;

void screen_play_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("LEVEL", 2, 2);
}

void screen_play_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_PLAY;
}

#endif//_PLAY_SCREEN_H_