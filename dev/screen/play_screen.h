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
	
	engine_quiz_manager_base();
	engine_quiz_manager_bank(2);
	engine_quiz_manager_load(1);

	
	SMS_displayOn();
}

void screen_play_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int bob = curr_joypad1 * 2;
	unsigned int sgb = prev_joypad1 * 2;

	//engine_sprite_manager_draw_select(4, 60);
	//engine_sprite_manager_draw_select(4, 92);
	//engine_sprite_manager_draw_select(4, 124);
	//engine_sprite_manager_draw_select(4, 156);


	/*
	engine_sprite_manager_draw_tick(80, 100);
	engine_sprite_manager_draw_cross(80, 150);
	*/

	if (curr_joypad1 & PORT_A_KEY_UP && !(prev_joypad1 & PORT_A_KEY_UP))
	{
		engine_select_manager_moveup();
	}
	if (curr_joypad1 & PORT_A_KEY_DOWN && !(prev_joypad1 & PORT_A_KEY_DOWN))
	{
		engine_select_manager_movedown();
	}

	engine_select_manager_draw();
	*screen_type = SCREEN_TYPE_PLAY;
}

#endif//_PLAY_SCREEN_H_