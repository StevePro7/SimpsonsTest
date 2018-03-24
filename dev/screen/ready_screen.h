#ifndef _READY_SCREEN_H_
#define _READY_SCREEN_H_

extern unsigned int screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned int screen_ready_screen_delay;
extern unsigned char question_index, question_value, question_long, question_count;

void screen_ready_screen_init()
{
	screen_ready_screen_delay = NORMAL_DELAY * 4;
}

void screen_ready_screen_load()
{
	// TODO REMOVE
	//SMS_displayOff();
	//engine_content_manager_title();
	//SMS_setSpritePaletteColor(0, RGB(3,3,3));
	//SMS_displayOn();
	diff_select = 0;
	question_long = 3;
	// TODO REMOVE

	screen_bases_screen_init();

	// Clear space.
	engine_select_manager_clear();

	engine_font_manager_draw_text( LOCALE_DIFFICULTY, 2, 6);
	engine_font_manager_draw_text( LOCALE_ARROW_LEFT, 1, 7);
	engine_font_manager_draw_text( select_diff_option[diff_select], 2, 7);

	engine_font_manager_draw_text( LOCALE_QUESTIONS, 2, 9);
	engine_font_manager_draw_text( LOCALE_ARROW_LEFT, 1, 10);
	engine_font_manager_draw_data_ZERO( question_long, 4, 10);

	engine_font_manager_draw_text(LOCALE_GET, 2, 16);
	engine_font_manager_draw_text(LOCALE_READY, 2, 17);

	// Initialize all relevant variables before quiz starts...
	question_index = 0;
	question_value = 0;
	question_count = 0;
	engine_score_manager_init();
}

void screen_ready_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	unsigned char level = 0;

	rand();
	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1 );
	if( input )
	{
		level = 1;
	}

	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_ready_screen_delay )
	{
		level = 1;
	}

	if ( level )
	{
		engine_select_manager_clear();
		engine_audio_manager_stop_music();

		*screen_type = SCREEN_TYPE_LEVEL;
		return;
	}

	*screen_type = SCREEN_TYPE_READY;
}

#endif//_READY_SCREEN_H_