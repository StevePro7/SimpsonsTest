#ifndef _TEST1_SCREEN_H_
#define _TEST1_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_test1_screen_delay;

void screen_test1_screen_init()
{
	screen_test1_screen_delay = 100;
}

void screen_test1_screen_load()
{
	screen_bases_screen_init();
	engine_font_manager_draw_text("HELLO", 3, 3);
}

void screen_test1_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_TEST1;
}

#endif//_TEST1_SCREEN_H_