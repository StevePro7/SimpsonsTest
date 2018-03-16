#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

void screen_title_screen_load()
{
	SMS_displayOff();
	//engine_content_manager_load_font();
	engine_content_manager_load_sprites();
	engine_content_manager_title();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	
	SMS_displayOn();
}

void screen_title_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	engine_sprite_manager_draw(0 + 4, 0 + 60, 64);
	*screen_type = SCREEN_TYPE_TITLE;
}

#endif//_TITLE_SCREEN_H_