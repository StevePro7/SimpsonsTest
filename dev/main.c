#include "main.h"

// Global variables.
bool global_pause;

unsigned char hacker_debug, hacker_splash;
unsigned char hacker_start, hacker_delay, hacker_music, hacker_sound;
unsigned char enum_curr_screen_type, enum_next_screen_type;


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

	engine_content_manager_load_font();
	engine_content_manager_load_sprites();
	//engine_content_manager_splash();
	//engine_content_manager_title();

	// Ensure white border
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	enum_curr_screen_type = screen_type_none;//SCREEN_TYPE_NONE;
	enum_next_screen_type = screen_type_title;

	
	SMS_displayOn();
	for (;;)
	{
		if (enum_curr_screen_type != enum_next_screen_type)
		{
			engine_font_manager_draw_text("BOBO", 5, 5);
			engine_font_manager_draw_data(enum_curr_screen_type, 5, 7);
			engine_font_manager_draw_data(enum_next_screen_type, 5, 9);
		}

		SMS_waitForVBlank();
	}
}

SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
SMS_EMBED_SDSC_HEADER(1, 0, 2018, 3, 1, "StevePro Studios", "The Simpsons", "Simple Sega Master System demo to run on real hardware!");