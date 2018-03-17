#ifndef _QUIZ_MANAGER_H_
#define _QUIZ_MANAGER_H_


#define QUIZ_X	2
#define QUIZ_Y	5

#define SCORE_X	22
#define TITLE_Y	3

#define OPTN_X	4
#define OPTA_Y	9
#define OPTB_Y	13
#define OPTC_Y	17
#define OPTD_Y	21

void engine_quiz_manager_base()
{
	engine_font_manager_draw_text(LOCALE_QUESTION, QUIZ_X, TITLE_Y);
	engine_font_manager_draw_text(LOCALE_SCORE, SCORE_X, TITLE_Y);

	engine_font_manager_draw_text(LOCALE_OPTA, QUIZ_X, OPTA_Y);
	engine_font_manager_draw_text(LOCALE_OPTB, QUIZ_X, OPTB_Y);
	engine_font_manager_draw_text(LOCALE_OPTC, QUIZ_X, OPTC_Y);
	engine_font_manager_draw_text(LOCALE_OPTD, QUIZ_X, OPTD_Y);
}

void engine_quiz_manager_bank(unsigned char b)
{
	SMS_mapROMBank(b);
}

void engine_quiz_manager_load(unsigned char q)
{
	engine_font_manager_draw_text(bank2_quiz_line1[q], QUIZ_X, QUIZ_Y + 0);
	engine_font_manager_draw_text(bank2_quiz_line2[q], QUIZ_X, QUIZ_Y + 1);
	engine_font_manager_draw_text(bank2_quiz_line3[q], QUIZ_X, QUIZ_Y + 2);

	engine_font_manager_draw_text(bank2_optA_line1[q], OPTN_X, OPTA_Y + 0);
}

#endif//_QUIZ_MANAGER_H_