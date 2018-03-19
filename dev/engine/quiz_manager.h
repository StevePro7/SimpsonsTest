#ifndef _QUIZ_MANAGER_H_
#define _QUIZ_MANAGER_H_

#define QUIZ_X	2
#define QUIZ_Y	5

#define TITLE_X	22
#define TITLE_Y	3

#define OPTN_X	4
#define OPTA_Y	9
#define OPTB_Y	13
#define OPTC_Y	17
#define OPTD_Y	21

extern unsigned char quiz_number;

void engine_quiz_manager_init()
{
	quiz_number = 0;
}

void engine_quiz_manager_base()
{
	engine_font_manager_draw_text(LOCALE_QUESTION, QUIZ_X, TITLE_Y);
	engine_font_manager_draw_text(LOCALE_SCORE, TITLE_X, TITLE_Y);

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
	// Number.
	engine_font_manager_draw_data_ZERO(q + 51, QUIZ_X + 12, TITLE_Y);		// TODO - logic here is wrong!

	// Question.
	engine_font_manager_draw_text(bank3_quiz_line1[q], QUIZ_X, QUIZ_Y + 0);
	engine_font_manager_draw_text(bank3_quiz_line2[q], QUIZ_X, QUIZ_Y + 1);
	engine_font_manager_draw_text(bank3_quiz_line3[q], QUIZ_X, QUIZ_Y + 2);

	// Option A.
	engine_font_manager_draw_text(bank3_opt1_line1[q], OPTN_X, OPTA_Y + 0);
	engine_font_manager_draw_text(bank3_opt1_line2[q], OPTN_X, OPTA_Y + 1);
	engine_font_manager_draw_text(bank3_opt1_line3[q], OPTN_X, OPTA_Y + 2);

	// Option B.
	engine_font_manager_draw_text(bank3_opt2_line1[q], OPTN_X, OPTB_Y + 0);
	engine_font_manager_draw_text(bank3_opt2_line2[q], OPTN_X, OPTB_Y + 1);
	engine_font_manager_draw_text(bank3_opt2_line3[q], OPTN_X, OPTB_Y + 2);

	// Option C.
	engine_font_manager_draw_text(bank3_opt3_line1[q], OPTN_X, OPTC_Y + 0);
	engine_font_manager_draw_text(bank3_opt3_line2[q], OPTN_X, OPTC_Y + 1);
	engine_font_manager_draw_text(bank3_opt3_line3[q], OPTN_X, OPTC_Y + 2);

	// Option D.
	engine_font_manager_draw_text(bank3_opt4_line1[q], OPTN_X, OPTD_Y + 0);
	engine_font_manager_draw_text(bank3_opt4_line2[q], OPTN_X, OPTD_Y + 1);
	engine_font_manager_draw_text(bank3_opt4_line3[q], OPTN_X, OPTD_Y + 2);
}

//void engine_quiz_manager_load()
//{
//	engine_quiz_manager_load_all(quiz_number);
//}

#endif//_QUIZ_MANAGER_H_