#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

void screen_play_screen_load()
{
	SMS_displayOff();
	engine_content_manager_load_maggie();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	////engine_font_manager_draw_text("A.SIMPLE", 2, 9);
	//engine_font_manager_draw_text("> EASY", 2, 13);
	//engine_font_manager_draw_text("> HARD", 2, 17);
	////engine_font_manager_draw_text("D.INSANE", 2, 21);
	
	SMS_displayOn();
}

void screen_play_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int bob = curr_joypad1 * 2;
	unsigned int sgb = prev_joypad1 * 2;

	engine_sprite_manager_draw_select(80, 50);
	engine_sprite_manager_draw_tick(80, 100);
	engine_sprite_manager_draw_cross(80, 150);
	*screen_type = SCREEN_TYPE_PLAY;
}

#endif//_PLAY_SCREEN_H_