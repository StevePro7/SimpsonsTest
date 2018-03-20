#ifndef _INTRO_SCREEN_H_
#define _INTRO_SCREEN_H_

void screen_intro_screen_load()
{
	SMS_displayOff();
	engine_content_manager_load_font();
	//engine_content_manager_load_sprites();
	engine_content_manager_title();
	//SMS_setSpritePaletteColor(0, RGB(3,3,3));

	/*engine_font_manager_draw_text("PRESS", 2, 16);
	engine_font_manager_draw_text("START", 2, 17);

	if( hacker_debug )
	{
		engine_font_manager_draw_text( "      ", 2, 21 );
		
	}*/

	engine_font_manager_draw_text( "INTRO", 2, 21 );

	SMS_displayOn();
}

void screen_intro_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;

	rand();

	if( engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1 ) )
	{
		*screen_type = SCREEN_TYPE_READY;
	}

	/*if ((curr_joypad1 & PORT_A_KEY_1 && !(prev_joypad1 & PORT_A_KEY_1)) ||
		(curr_joypad1 & PORT_A_KEY_2 && !(prev_joypad1 & PORT_A_KEY_2)))
	{
		level = 1;
	}

	if (level)
	{
		engine_font_manager_draw_text("     ", 2, 16);
		engine_font_manager_draw_text("     ", 2, 17);

		*screen_type = SCREEN_TYPE_LEVEL;
	}*/

	*screen_type = SCREEN_TYPE_INTRO;
}

#endif//_INTRO_SCREEN_H_