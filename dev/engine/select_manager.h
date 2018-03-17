#ifndef _SELECT_MANAGER_H_
#define _SELECT_MANAGER_H_

#define ANSWER_X		0
#define SELECT_X		4
#define SELECT_Y		60
#define SELECT_DELTA	32

extern unsigned char select_choice, select_height;
extern unsigned char select_option[MAX_OPTIONS];

void engine_select_manager_init()
{
	unsigned char idx = 0;
	for(idx = 0; idx < MAX_OPTIONS; idx++)
	{
		select_option[idx] = SELECT_Y + idx * SELECT_DELTA;
	}

	select_choice = 0;
	select_height = select_option[select_choice];
}

void engine_select_manager_moveup()
{
	if(0 == select_choice)
	{
		select_choice = (MAX_OPTIONS - 1);
	}
	else
	{
		select_choice--;
	}

	select_height = select_option[select_choice];
}

void engine_select_manager_movedown()
{
	if((MAX_OPTIONS - 1) == select_choice)
	{
		select_choice = 0;
	}
	else
	{
		select_choice++;
	}

	select_height = select_option[select_choice];
}

void engine_select_manager_draw_select()
{
	engine_sprite_manager_draw_select(SELECT_X, select_height);
}
void engine_select_manager_draw_right()
{
	engine_sprite_manager_draw_right(ANSWER_X, select_height);
}
void engine_select_manager_draw_wrong()
{
	engine_sprite_manager_draw_wrong(ANSWER_X, select_height);
}
#endif//_SELECT_MANAGER_H_