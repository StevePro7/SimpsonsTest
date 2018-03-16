#include "main.h"

// Global variables.
bool global_pause;

unsigned char hacker_debug, hacker_splash;
unsigned char hacker_start, hacker_delay, hacker_music, hacker_sound;
unsigned char enum_curr_screen_type, enum_next_screen_type;
/*
void custom_initialize();
void custom_load_content();
*/
void custom_screen_manager_load(unsigned char screen_type);
void custom_screen_manager_update(unsigned char *screen_type, const unsigned int curr_joypad1, const unsigned int prev_joypad1);

void main (void)
{
	// Must be static to persist values!
	static unsigned int curr_joypad1 = 0;
	static unsigned int prev_joypad1 = 0;

	SMS_init();
	SMS_displayOff();

	engine_asm_manager_clear_VRAM();
	
	SMS_setSpriteMode(SPRITEMODE_NORMAL);
	SMS_useFirstHalfTilesforSprites(true);

	//engine_content_manager_load_font();
	//engine_content_manager_load_sprites();
	//engine_content_manager_splash();
	//engine_content_manager_title();

	// Ensure white border
	//SMS_setSpritePaletteColor(0, RGB(3,3,3));

	enum_curr_screen_type = SCREEN_TYPE_NONE;
	enum_next_screen_type = SCREEN_TYPE_TITLE;

	SMS_displayOn();
	for (;;)
	{
		if (SMS_queryPauseRequested())
		{
			SMS_resetPauseRequest();
			global_pause = !global_pause;
			if (global_pause)
			{
				engine_font_manager_draw_text(LOCALE_PAUSED, 13, 12);
				PSGSilenceChannels();
			}
			else
			{
				engine_font_manager_draw_text(LOCALE_RESUME, 13, 12);
				PSGRestoreVolumes();
			}
		}

		if (global_pause)
		{
			continue;
		}

		if (enum_curr_screen_type != enum_next_screen_type)
		{
			enum_curr_screen_type = enum_next_screen_type;
			custom_screen_manager_load(enum_curr_screen_type);
		}

		SMS_initSprites();

		curr_joypad1 = SMS_getKeysStatus();
		custom_screen_manager_update(&enum_next_screen_type, curr_joypad1, prev_joypad1);

		SMS_finalizeSprites();
		SMS_waitForVBlank();
		SMS_copySpritestoSAT();

		PSGFrame();
		PSGSFXFrame();

		prev_joypad1 = curr_joypad1;
	}
}
/*
void custom_initialize()
{
}

void custom_load_content()
{
}
*/
void custom_screen_manager_load(unsigned char screen_type)
{
	switch (screen_type)
	{
	case screen_type_splash:
		screen_splash_screen_load();
		break;
	case screen_type_title:
		screen_title_screen_load();
		break;
	}
}

void custom_screen_manager_update(unsigned char *screen_type, const unsigned int curr_joypad1, const unsigned int prev_joypad1)
{
	switch (*screen_type)
	{
	case SCREEN_TYPE_SPLASH:
		screen_splash_screen_update(screen_type, curr_joypad1, prev_joypad1);
		break;
	case SCREEN_TYPE_TITLE:
		screen_title_screen_update(screen_type, curr_joypad1, prev_joypad1);
		break;
	}
}

SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
SMS_EMBED_SDSC_HEADER(1, 0, 2018, 3, 1, "StevePro Studios", "The Simpsons", "Simple Sega Master System demo to run on real hardware!");