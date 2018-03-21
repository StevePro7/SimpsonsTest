#ifndef _TEST3_SCREEN_H_
#define _TEST3_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_test3_screen_delay;

void screen_test3_screen_init()
{
	screen_test3_screen_delay = 100;
}

void screen_splash_screen_load()
{
	SMS_displayOff();
	screen_bases_screen_init();
	SMS_displayOn();
}

void screen_test3_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_TEST3;
}

#endif//_TEST3_SCREEN_H_