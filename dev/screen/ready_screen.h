#ifndef _READY_SCREEN_H_
#define _READY_SCREEN_H_

void screen_ready_screen_load()
{
	SMS_displayOff();
	//engine_content_manager_load_font();
	//engine_content_manager_load_sprites();
	//engine_content_manager_title();
	//SMS_setSpritePaletteColor(0, RGB(3,3,3));

	////engine_font_manager_draw_text("A.SIMPLE", 2, 9);
	//engine_font_manager_draw_text("> EASY", 2, 13);
	//engine_font_manager_draw_text("> HARD", 2, 17);
	////engine_font_manager_draw_text("D.INSANE", 2, 21);
	engine_audio_manager_stop_music();
	engine_font_manager_draw_text( "READY", 2, 2 );
	SMS_displayOn();
}

void screen_ready_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int bob = curr_joypad1 * 2;
	unsigned int sgb = prev_joypad1 * 2;

	//engine_sprite_manager_draw(0 + 4, 0 + 92, 64);
	engine_sprite_manager_draw(0 + 4, 0 + 124, 64);
	*screen_type = SCREEN_TYPE_READY;
}

#endif//_READY_SCREEN_H_