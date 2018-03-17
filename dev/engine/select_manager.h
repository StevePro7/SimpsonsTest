#ifndef _SELECT_MANAGER_H_
#define _SELECT_MANAGER_H_

#define SELECT_X		4
#define SELECT_Y		60
#define SELECT_DELTA	32

extern unsigned char select_choice;
extern unsigned char select_option[MAX_OPTIONS];

void engine_select_manager_init()
{
	unsigned char idx = 0;
	for(idx = 0; idx < MAX_OPTIONS; idx++)
	{
		select_option[idx] = SELECT_Y + idx * SELECT_DELTA;
	}

	select_choice = 0;
}

#endif//_SELECT_MANAGER_H_