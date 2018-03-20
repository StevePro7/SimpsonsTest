#ifndef _SPLASH_SCREEN_H_
#define _SPLASH_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_splash_screen_delay;

void screen_splash_screen_init()
{
	screen_splash_screen_delay = SPLASH_DELAY;
}

void screen_splash_screen_load()
{
	SMS_displayOff();
	engine_content_manager_splash();
	SMS_displayOn();
}

void screen_splash_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char mover = 0;
	unsigned char input = 0;

	input = engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1);
	if( input )
	{
		*screen_type = SCREEN_TYPE_TITLE;
	}

	screen_bases_screen_timer++;
	if (screen_bases_screen_timer >= screen_splash_screen_delay)
	{
		*screen_type = SCREEN_TYPE_TITLE;
	}

}

#endif//_SPLASH_SCREEN_H_