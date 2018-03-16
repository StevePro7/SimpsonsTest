#ifndef _INTRO_SCREEN_H_
#define _INTRO_SCREEN_H_

void screen_intro_screen_load()
{
	SMS_displayOff();
	//engine_content_manager_load_font();
	engine_content_manager_load_sprites();
	engine_content_manager_title();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	engine_font_manager_draw_text("PRESS", 2, 14);
	engine_font_manager_draw_text("START", 2, 16);
	
	SMS_displayOn();
}

void screen_intro_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	*screen_type = SCREEN_TYPE_INTRO;
}

#endif//_INTRO_SCREEN_H_