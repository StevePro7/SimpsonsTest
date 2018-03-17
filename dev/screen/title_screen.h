#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

void screen_title_screen_load()
{
	SMS_displayOff();
	//engine_content_manager_load_font();
	engine_content_manager_load_sprites();
	//engine_content_manager_title();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	//engine_font_manager_draw_text("A.SIMPLE", 2, 9);
	//engine_font_manager_draw_text("> EASY", 2, 13);
	//engine_font_manager_draw_text("> HARD", 2, 17);
	//engine_font_manager_draw_text("D.INSANE", 2, 21);
	
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("TITLE", 2, 2);

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
		*screen_type = SCREEN_TYPE_INTRO;
	}
}

#endif//_TITLE_SCREEN_H_