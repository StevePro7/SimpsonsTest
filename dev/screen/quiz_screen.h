#ifndef _QUIZ_SCREEN_H_
#define _QUIZ_SCREEN_H_

#define MAX_QUIZ	100

void screen_quiz_screen_load()
{
	SMS_displayOff();

	// Load full screen image here!
	engine_content_manager_load_maggie();
	engine_content_manager_load_sprites();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	engine_quiz_manager_base();
	//engine_quiz_manager_bank(5);
	engine_quiz_manager_load(0);
	engine_score_manager_draw();

	//play_answer_state = ANSWER_TYPE_SELECT;
	SMS_displayOn();
}

void screen_quiz_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int bob = curr_joypad1 * 2;
	unsigned int sgb = prev_joypad1 * 2;

	if (curr_joypad1 & PORT_A_KEY_UP && !(prev_joypad1 & PORT_A_KEY_UP))
	{
		engine_select_manager_moveup();
	}
	if (curr_joypad1 & PORT_A_KEY_DOWN && !(prev_joypad1 & PORT_A_KEY_DOWN))
	{
		engine_select_manager_movedown();
	}

	if (curr_joypad1 & PORT_A_KEY_LEFT)// && !(prev_joypad1 & PORT_A_KEY_LEFT))
	{
		if(0 == quiz_number)
		{
			return;
		}

		quiz_number--;
		engine_quiz_manager_load(quiz_number);
	}
	if (curr_joypad1 & PORT_A_KEY_RIGHT)// && !(prev_joypad1 & PORT_A_KEY_RIGHT))
	{
		if(MAX_QUIZ-1 == quiz_number)
		{
			return;
		}

		quiz_number++;
		engine_quiz_manager_load(quiz_number);
	}

	engine_select_manager_draw_select();

	*screen_type = SCREEN_TYPE_QUIZ;
}

#endif//_QUIZ_SCREEN_H_