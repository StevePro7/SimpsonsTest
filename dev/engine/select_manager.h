#ifndef _SELECT_MANAGER_H_
#define _SELECT_MANAGER_H_

#define ANSWER_X		0
#define SELECT_X		4
#define SELECT_Y		60
#define SELECT_DELTA	32

extern unsigned char diff_select, long_select, quiz_select;
extern unsigned char select_choice, select_height;
extern unsigned char select_option[MAX_OPTIONS];

void engine_select_manager_init()
{
	unsigned char idx = 0;
	for(idx = 0; idx < MAX_OPTIONS; idx++)
	{
		select_option[idx] = SELECT_Y + idx * SELECT_DELTA;
	}

	diff_select = 1;
	long_select = 0;
	quiz_select = 2;
	select_choice = 0;
	select_height = select_option[select_choice];
}

void engine_select_manager_load_diff()
{
	select_choice = diff_select;
	select_height = select_option[select_choice];
}
void engine_select_manager_load_long()
{
	select_choice = long_select;
	select_height = select_option[select_choice];
}
void engine_select_manager_load_quiz()
{
	select_choice = quiz_select;
	select_height = select_option[select_choice];
}

unsigned char engine_select_manager_move_up( unsigned char select_choice )
{
	if( 0 == select_choice )
	{
		select_choice = (MAX_OPTIONS - 1);
	}
	else
	{
		select_choice--;
	}

	select_height = select_option[select_choice];
	return select_choice;
}

unsigned char engine_select_manager_move_down( unsigned char select_choice )
{
	if( ( MAX_OPTIONS - 1 ) == select_choice )
	{
		select_choice = 0;
	}
	else
	{
		select_choice++;
	}

	select_height = select_option[select_choice];
	return select_choice;
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