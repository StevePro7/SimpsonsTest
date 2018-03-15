#ifndef _CONTENT_MANAGER_H_
#define _CONTENT_MANAGER_H_

#define SPLASH_TILES	0
#define FONT_TILES		0
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

void engine_content_manager_load_font()
{
	// Font tiles.
	SMS_loadPSGaidencompressedTiles(font__tiles__psgcompr, FONT_TILES);
	SMS_loadBGPalette(font__palette__bin);
}

void engine_content_manager_load_sprites()
{
	// Sprite tiles.
	SMS_loadPSGaidencompressedTiles(select__tiles__psgcompr, SPRITE_TILES);
	SMS_loadPSGaidencompressedTiles(tick__tiles__psgcompr, SPRITE_TILES + 16);
	SMS_loadPSGaidencompressedTiles(cross__tiles__psgcompr, SPRITE_TILES + 32);
	SMS_loadSpritePalette(cross__palette__bin);
}

#endif//_CONTENT_MANAGER_H_