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

#define QUIZ_BANK	2

extern unsigned char quiz_number;
extern unsigned char diff_select;
extern unsigned char quiz_questions[MAX_QUESTIONS];
extern unsigned char quiz_options[MAX_QUESTIONS][MAX_OPTIONS];
extern unsigned char option_height[MAX_OPTIONS];
extern unsigned char question_value, answer_index, answer_value;

void engine_quiz_manager_init()
{
	quiz_number = 0;		// TODO remove!

	option_height[0] = OPTA_Y;
	option_height[1] = OPTB_Y;
	option_height[2] = OPTC_Y;
	option_height[3] = OPTD_Y;
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

void engine_quiz_manager_answer(unsigned char q)
{
	//unsigned char idx;

	answer_value = MAX_OPTIONS;
	if( DIFF_TYPE_EASY == diff_select )
	{
		answer_value = bank2_soln[q];
	}
	
engine_font_manager_draw_data(answer_value, 22, 1);

	answer_value -= 1;
engine_font_manager_draw_data(answer_value, 26, 1);

answer_index = quiz_options[q][answer_value];

engine_font_manager_draw_data(answer_index, 30, 1);

	/*for( idx = 0; idx < MAX_OPTIONS; idx++ )
	{
		if( answer_value == quiz_options[q][idx] )
		{
			answer_index = idx;
			break;
		}
	}*/

engine_font_manager_draw_data(answer_index, 30, 1);
}

void engine_quiz_manager_cheat(unsigned char ans)
{
	unsigned char idx, cheat_Y;

	for( idx = 0; idx < MAX_OPTIONS; idx++)
	{
		cheat_Y = option_height[idx];
		engine_font_manager_draw_text(LOCALE_ARROW_SPACE, QUIZ_X-1, cheat_Y);
	}

	if( hacker_cheat )
	{
		cheat_Y = option_height[ans];
		engine_font_manager_draw_text(LOCALE_ARROW_LEFT, QUIZ_X-1, cheat_Y);
	}
}

void engine_quiz_manager_load(unsigned char qi, unsigned char qv, unsigned char opt1, unsigned char opt2, unsigned char opt3, unsigned char opt4)
{
	unsigned char opt1_Y, opt2_Y, opt3_Y, opt4_Y;

	opt1_Y = option_height[opt1];
	opt2_Y = option_height[opt2];
	opt3_Y = option_height[opt3];
	opt4_Y = option_height[opt4];

	// Number.
	engine_font_manager_draw_data_ZERO(qi + 1, QUIZ_X + 12, TITLE_Y);


//	engine_font_manager_draw_data(hacker_cheat, 30, 0);

	// Cheat!
	/*for( idx = 0; idx < MAX_OPTIONS; idx++)
	{
		cheat_Y = option_height[idx];
		engine_font_manager_draw_text(LOCALE_ARROW_SPACE, QUIZ_X-1, cheat_Y);
	}

	cheat_Y = option_height[answer_index];
	engine_font_manager_draw_text(LOCALE_ARROW_LEFT, QUIZ_X-1, cheat_Y);*/
	// TODO remove
	//engine_font_manager_draw_data_ZERO(opt1+1, 10, 10);
	//engine_font_manager_draw_data_ZERO(opt2+1, 10, 11);
	//engine_font_manager_draw_data_ZERO(opt3+1, 10, 12);
	//engine_font_manager_draw_data_ZERO(opt4+1, 10, 13);
	// TODO remove


	if( DIFF_TYPE_EASY == diff_select )
	{
		// Question.
		engine_font_manager_draw_text(bank2_quiz_line1[qv], QUIZ_X, QUIZ_Y + 0);
		engine_font_manager_draw_text(bank2_quiz_line2[qv], QUIZ_X, QUIZ_Y + 1);
		engine_font_manager_draw_text(bank2_quiz_line3[qv], QUIZ_X, QUIZ_Y + 2);

		// Option A.
		engine_font_manager_draw_text(bank2_opt1_line1[qv], OPTN_X, opt1_Y + 0);
		engine_font_manager_draw_text(bank2_opt1_line2[qv], OPTN_X, opt1_Y + 1);
		engine_font_manager_draw_text(bank2_opt1_line3[qv], OPTN_X, opt1_Y + 2);

		// Option B.
		engine_font_manager_draw_text(bank2_opt2_line1[qv], OPTN_X, opt2_Y + 0);
		engine_font_manager_draw_text(bank2_opt2_line2[qv], OPTN_X, opt2_Y + 1);
		engine_font_manager_draw_text(bank2_opt2_line3[qv], OPTN_X, opt2_Y + 2);

		// Option C.
		engine_font_manager_draw_text(bank2_opt3_line1[qv], OPTN_X, opt3_Y + 0);
		engine_font_manager_draw_text(bank2_opt3_line2[qv], OPTN_X, opt3_Y + 1);
		engine_font_manager_draw_text(bank2_opt3_line3[qv], OPTN_X, opt3_Y + 2);

		// Option D.
		engine_font_manager_draw_text(bank2_opt4_line1[qv], OPTN_X, opt4_Y + 0);
		engine_font_manager_draw_text(bank2_opt4_line2[qv], OPTN_X, opt4_Y + 1);
		engine_font_manager_draw_text(bank2_opt4_line3[qv], OPTN_X, opt4_Y + 2);
	}

	// Cheat!
	//if( hacker_cheat )
	//{
	//	//answer_value = engine_quiz_manager_answer(question_value);
	//	//answer_index = answer_value - 1;		// Zero based index

	//	//for( idx = 0; idx < MAX_OPTIONS; idx++)
	//	//{
	//	//	cheat_Y = option_height[idx];
	//	//	engine_font_manager_draw_text(LOCALE_ARROW_SPACE, QUIZ_X-1, cheat_Y);
	//	//}

	//	cheat_Y = option_height[answer_index];
	//	engine_font_manager_draw_text(LOCALE_ARROW_LEFT, QUIZ_X-1, cheat_Y);
	//}
}

void engine_quiz_manager_loadX(unsigned char q)
{
	if( DIFF_TYPE_EASY == diff_select )
	{
		// Question.
		engine_font_manager_draw_text(bank2_quiz_line1[q], QUIZ_X, QUIZ_Y + 0);
		engine_font_manager_draw_text(bank2_quiz_line2[q], QUIZ_X, QUIZ_Y + 1);
		engine_font_manager_draw_text(bank2_quiz_line3[q], QUIZ_X, QUIZ_Y + 2);

		// Option A.
		engine_font_manager_draw_text(bank2_opt1_line1[q], OPTN_X, OPTA_Y + 0);
		engine_font_manager_draw_text(bank2_opt1_line2[q], OPTN_X, OPTA_Y + 1);
		engine_font_manager_draw_text(bank2_opt1_line3[q], OPTN_X, OPTA_Y + 2);

		// Option B.
		engine_font_manager_draw_text(bank2_opt2_line1[q], OPTN_X, OPTB_Y + 0);
		engine_font_manager_draw_text(bank2_opt2_line2[q], OPTN_X, OPTB_Y + 1);
		engine_font_manager_draw_text(bank2_opt2_line3[q], OPTN_X, OPTB_Y + 2);

		// Option C.
		engine_font_manager_draw_text(bank2_opt3_line1[q], OPTN_X, OPTC_Y + 0);
		engine_font_manager_draw_text(bank2_opt3_line2[q], OPTN_X, OPTC_Y + 1);
		engine_font_manager_draw_text(bank2_opt3_line3[q], OPTN_X, OPTC_Y + 2);

		// Option D.
		engine_font_manager_draw_text(bank2_opt4_line1[q], OPTN_X, OPTD_Y + 0);
		engine_font_manager_draw_text(bank2_opt4_line2[q], OPTN_X, OPTD_Y + 1);
		engine_font_manager_draw_text(bank2_opt4_line3[q], OPTN_X, OPTD_Y + 2);
	}
	//else if( DIFF_TYPE_NORM == diff_select )
	//{
	//	// Question.
	//	engine_font_manager_draw_text(bank3_quiz_line1[q], QUIZ_X, QUIZ_Y + 0);
	//	engine_font_manager_draw_text(bank3_quiz_line2[q], QUIZ_X, QUIZ_Y + 1);
	//	engine_font_manager_draw_text(bank3_quiz_line3[q], QUIZ_X, QUIZ_Y + 2);

	//	// Option A.
	//	engine_font_manager_draw_text(bank3_opt1_line1[q], OPTN_X, OPTA_Y + 0);
	//	engine_font_manager_draw_text(bank3_opt1_line2[q], OPTN_X, OPTA_Y + 1);
	//	engine_font_manager_draw_text(bank3_opt1_line3[q], OPTN_X, OPTA_Y + 2);

	//	// Option B.
	//	engine_font_manager_draw_text(bank3_opt2_line1[q], OPTN_X, OPTB_Y + 0);
	//	engine_font_manager_draw_text(bank3_opt2_line2[q], OPTN_X, OPTB_Y + 1);
	//	engine_font_manager_draw_text(bank3_opt2_line3[q], OPTN_X, OPTB_Y + 2);

	//	// Option C.
	//	engine_font_manager_draw_text(bank3_opt3_line1[q], OPTN_X, OPTC_Y + 0);
	//	engine_font_manager_draw_text(bank3_opt3_line2[q], OPTN_X, OPTC_Y + 1);
	//	engine_font_manager_draw_text(bank3_opt3_line3[q], OPTN_X, OPTC_Y + 2);

	//	// Option D.
	//	engine_font_manager_draw_text(bank3_opt4_line1[q], OPTN_X, OPTD_Y + 0);
	//	engine_font_manager_draw_text(bank3_opt4_line2[q], OPTN_X, OPTD_Y + 1);
	//	engine_font_manager_draw_text(bank3_opt4_line3[q], OPTN_X, OPTD_Y + 2);
	//}
	//else if( DIFF_TYPE_HARD == diff_select )
	//{
	//	// Question.
	//	engine_font_manager_draw_text(bank4_quiz_line1[q], QUIZ_X, QUIZ_Y + 0);
	//	engine_font_manager_draw_text(bank4_quiz_line2[q], QUIZ_X, QUIZ_Y + 1);
	//	engine_font_manager_draw_text(bank4_quiz_line3[q], QUIZ_X, QUIZ_Y + 2);

	//	// Option A.
	//	engine_font_manager_draw_text(bank4_opt1_line1[q], OPTN_X, OPTA_Y + 0);
	//	engine_font_manager_draw_text(bank4_opt1_line2[q], OPTN_X, OPTA_Y + 1);
	//	engine_font_manager_draw_text(bank4_opt1_line3[q], OPTN_X, OPTA_Y + 2);

	//	// Option B.
	//	engine_font_manager_draw_text(bank4_opt2_line1[q], OPTN_X, OPTB_Y + 0);
	//	engine_font_manager_draw_text(bank4_opt2_line2[q], OPTN_X, OPTB_Y + 1);
	//	engine_font_manager_draw_text(bank4_opt2_line3[q], OPTN_X, OPTB_Y + 2);

	//	// Option C.
	//	engine_font_manager_draw_text(bank4_opt3_line1[q], OPTN_X, OPTC_Y + 0);
	//	engine_font_manager_draw_text(bank4_opt3_line2[q], OPTN_X, OPTC_Y + 1);
	//	engine_font_manager_draw_text(bank4_opt3_line3[q], OPTN_X, OPTC_Y + 2);

	//	// Option D.
	//	engine_font_manager_draw_text(bank4_opt4_line1[q], OPTN_X, OPTD_Y + 0);
	//	engine_font_manager_draw_text(bank4_opt4_line2[q], OPTN_X, OPTD_Y + 1);
	//	engine_font_manager_draw_text(bank4_opt4_line3[q], OPTN_X, OPTD_Y + 2);
	//}
	//else if( DIFF_TYPE_ARGH == diff_select )
	//{
	//	// Question.
	//	engine_font_manager_draw_text(bank5_quiz_line1[q], QUIZ_X, QUIZ_Y + 0);
	//	engine_font_manager_draw_text(bank5_quiz_line2[q], QUIZ_X, QUIZ_Y + 1);
	//	engine_font_manager_draw_text(bank5_quiz_line3[q], QUIZ_X, QUIZ_Y + 2);

	//	// Option A.
	//	engine_font_manager_draw_text(bank5_opt1_line1[q], OPTN_X, OPTA_Y + 0);
	//	engine_font_manager_draw_text(bank5_opt1_line2[q], OPTN_X, OPTA_Y + 1);
	//	engine_font_manager_draw_text(bank5_opt1_line3[q], OPTN_X, OPTA_Y + 2);

	//	// Option B.
	//	engine_font_manager_draw_text(bank5_opt2_line1[q], OPTN_X, OPTB_Y + 0);
	//	engine_font_manager_draw_text(bank5_opt2_line2[q], OPTN_X, OPTB_Y + 1);
	//	engine_font_manager_draw_text(bank5_opt2_line3[q], OPTN_X, OPTB_Y + 2);

	//	// Option C.
	//	engine_font_manager_draw_text(bank5_opt3_line1[q], OPTN_X, OPTC_Y + 0);
	//	engine_font_manager_draw_text(bank5_opt3_line2[q], OPTN_X, OPTC_Y + 1);
	//	engine_font_manager_draw_text(bank5_opt3_line3[q], OPTN_X, OPTC_Y + 2);

	//	// Option D.
	//	engine_font_manager_draw_text(bank5_opt4_line1[q], OPTN_X, OPTD_Y + 0);
	//	engine_font_manager_draw_text(bank5_opt4_line2[q], OPTN_X, OPTD_Y + 1);
	//	engine_font_manager_draw_text(bank5_opt4_line3[q], OPTN_X, OPTD_Y + 2);
	//}

	// Number.
	engine_font_manager_draw_data_ZERO(q + 1, QUIZ_X + 12, TITLE_Y);		// TODO - logic here is wrong!
}



#endif//_QUIZ_MANAGER_H_