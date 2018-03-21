#ifndef _DEBUG_MANAGER_H_
#define _DEBUG_MANAGER_H_

extern unsigned char quiz_questions[MAX_QUESTIONS];
extern unsigned char quiz_options[MAX_QUESTIONS][MAX_OPTIONS];

void engine_debug_manager_init()
{
	unsigned char idx;

	engine_font_manager_draw_text("QUESTIONS", 0, 0);
	engine_font_manager_draw_text("OPTION A.", 0, 5);
	engine_font_manager_draw_text("OPTION B.", 0, 10);
	engine_font_manager_draw_text("OPTION C.", 0, 15);
	engine_font_manager_draw_text("OPTION D.", 0, 20);

	for(idx = 0; idx < MAX_QUESTIONS; idx++)
	{
		engine_font_manager_draw_data(idx+1, 5* idx, 1);
		engine_font_manager_draw_data(idx+1, 5* idx, 6);
		engine_font_manager_draw_data(idx+1, 5* idx, 11);
		engine_font_manager_draw_data(idx+1, 5* idx, 16);
		engine_font_manager_draw_data(idx+1, 5* idx, 21);

		engine_font_manager_draw_data(quiz_questions[idx]+1, 5 * idx, 2);
		engine_font_manager_draw_data(quiz_options[idx][0]+1, 5 * idx, 7);
		engine_font_manager_draw_data(quiz_options[idx][1]+1, 5 * idx, 12);
		engine_font_manager_draw_data(quiz_options[idx][2]+1, 5 * idx, 17);
		engine_font_manager_draw_data(quiz_options[idx][3]+1, 5 * idx, 22);
	}
}

void engine_debug_manager_load()
{
	unsigned char idx;

	for(idx = 0; idx < MAX_QUESTIONS; idx++)
	{
		engine_font_manager_draw_data(quiz_questions[idx]+1, 5 * idx, 2);
		engine_font_manager_draw_data(quiz_options[idx][0]+1, 5 * idx, 7);
		engine_font_manager_draw_data(quiz_options[idx][1]+1, 5 * idx, 12);
		engine_font_manager_draw_data(quiz_options[idx][2]+1, 5 * idx, 17);
		engine_font_manager_draw_data(quiz_options[idx][3]+1, 5 * idx, 22);
	}
}

#endif//_DEBUG_MANAGER_H_