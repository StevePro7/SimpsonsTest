#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

void screen_title_screen_load()
{
	SMS_displayOff();
	engine_content_manager_title();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	engine_audio_manager_start_music();
	if( hacker_debug )
	{
		engine_font_manager_draw_text("      ", 2, 21);
		engine_font_manager_draw_text("TITLE", 2, 21);
	}

	SMS_displayOn();
}

void screen_title_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char level = 0;
	if ((curr_joypad1 & PORT_A_KEY_1 && !(prev_joypad1 & PORT_A_KEY_1)) ||
		(curr_joypad1 & PORT_A_KEY_2 && !(prev_joypad1 & PORT_A_KEY_2)))
	{
		level = 1;
	}

	//engine_sprite_manager_draw(0 + 4, 0 + 92, 64);
	//engine_sprite_manager_draw(0 + 4, 0 + 124, 64);
	//*screen_type = SCREEN_TYPE_TITLE;

	if (level)
	{
		//*screen_type = SCREEN_TYPE_INTRO;
		*screen_type = SCREEN_TYPE_PLAY;			// TODO remove - just for testing
	}
}

#endif//_TITLE_SCREEN_H_