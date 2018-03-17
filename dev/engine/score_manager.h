#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_

#define SCORE_X 30
#define SCORE_Y 3

extern unsigned char score_player;

void engine_score_manager_init()
{
	score_player = 2;
}

void engine_score_manager_draw()
{
	engine_font_manager_draw_data_ZERO(score_player, SCORE_X, SCORE_Y);
}

#endif//_SCORE_MANAGER_H_