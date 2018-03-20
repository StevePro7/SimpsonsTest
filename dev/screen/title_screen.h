#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

void screen_title_screen_load()
{
	SMS_displayOff();
	engine_content_manager_title();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	engine_audio_manager_start_music();
	SMS_displayOn();
}

void screen_title_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char test_curr_joypad1 = curr_joypad1;
	unsigned char test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_INTRO;
}

#endif//_TITLE_SCREEN_H_