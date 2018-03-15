#include "main.h"

void engine_content_manager_splash()
{
	SMS_loadPSGaidencompressedTiles(Simpsons__tiles__psgcompr, 0);
	SMS_loadSTMcompressedTileMap(0, 0, Simpsons__tilemap__stmcompr);
	SMS_loadBGPalette(Simpsons__palette__bin);
}

//void engine_content_manager_splash()
//{
//	SMS_loadPSGaidencompressedTiles(introstage1tiles_psgcompr, 0);
//	SMS_loadTileMap(0, 0, introstage1tilemap_bin, introstage1tilemap_bin_size);
//	SMS_loadBGPalette(introstage1palette_bin);
//}

void main (void)
{
	SMS_setSpritePaletteColor(0, RGB(3,3,3));
	//engine_content_manager_splash();
	SMS_displayOn();
	for (;;)
	{
		SMS_waitForVBlank();
	}
}

SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
SMS_EMBED_SDSC_HEADER(1, 0, 2018, 3, 1, "StevePro Studios", "The Simpsons", "Simple Sega Master System demo to run on real hardware!");