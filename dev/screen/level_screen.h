#ifndef _LEVEL_SCREEN_H_
#define _LEVEL_SCREEN_H_

// Dump previous contents of the play screen here
void screen_level_screen_load()
{
	unsigned char bank;

	engine_content_manager_load_sprites();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	// Process this here just before quiz starts
	// Why?  Otherwise may cause music to "drag"
	engine_random_manager_init();

	bank = diff_select + QUIZ_BANK;
	engine_quiz_manager_bank( bank );

	engine_random_manager_load();
	engine_select_manager_load_quiz();
}

void screen_level_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_PLAY;
}

#endif//_LEVEL_SCREEN_H_