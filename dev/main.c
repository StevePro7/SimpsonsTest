#include "main.h"

#define SPLASH_TILES	0
#define SIMPSONS_TILES	64

void engine_content_manager_splash()
{
	SMS_loadPSGaidencompressedTiles(splash__tiles__psgcompr, SPLASH_TILES);
	SMS_loadSTMcompressedTileMap(0, 0, splash__tilemap__stmcompr);
	SMS_loadBGPalette(splash__palette__bin);
}

void engine_content_manager_title()
{
	SMS_loadPSGaidencompressedTiles(simpsons__tiles__psgcompr, SIMPSONS_TILES);
	SMS_loadSTMcompressedTileMap(0, 0, simpsons__tilemap__stmcompr);
	SMS_loadBGPalette(simpsons__palette__bin);
}

//void engine_content_manager_splash()
//{
//	SMS_loadPSGaidencompressedTiles(introstage1tiles_psgcompr, 0);
//	SMS_loadTileMap(0, 0, introstage1tilemap_bin, introstage1tilemap_bin_size);
//	SMS_loadBGPalette(introstage1palette_bin);
//}

void main (void)
{
	SMS_init();
	SMS_displayOff();

	//SMS_setSpritePaletteColor(0, RGB(3,3,3));
	engine_asm_manager_clear_VRAM();
	engine_content_manager_splash();
	//engine_content_manager_title();
	SMS_displayOn();
	for (;;)
	{
		SMS_waitForVBlank();
	}
}

SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
SMS_EMBED_SDSC_HEADER(1, 0, 2018, 3, 1, "StevePro Studios", "The Simpsons", "Simple Sega Master System demo to run on real hardware!");