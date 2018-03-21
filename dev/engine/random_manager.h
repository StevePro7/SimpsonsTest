#ifndef _RANDOM_MANAGER_H_
#define _RANDOM_MANAGER_H_

extern unsigned char quiz_questions[MAX_QUESTIONS];
extern unsigned char quiz_options[MAX_QUESTIONS][MAX_OPTIONS];

void engine_random_manager_init()
{
	unsigned char idx, opt;

	for( idx = 0; idx < MAX_QUESTIONS; idx++)
	{
		quiz_questions[idx] = 0;
	}

	for( idx = 0; idx < MAX_QUESTIONS; idx++)
	{
		for( opt = 0; opt < MAX_OPTIONS; opt++)
		{
			quiz_options[idx][opt] = 0;
		}
	}
}

void engine_random_manager_load()
{
	unsigned char bob;

	unsigned char idx, opt;
	for( idx = 0; idx < MAX_QUESTIONS; idx++)
	{
		while( 1 )
		{
			unsigned char rnd = rand() % MAX_QUESTIONS;
			if( 0 == quiz_questions[rnd] )
			{
				quiz_questions[rnd] = idx;
				break;
			}
		}
	}

	for( idx = 0; idx < MAX_QUESTIONS; idx++)
	{
		for( opt = 0; opt < MAX_OPTIONS; opt++)
		{
			while( 1 )
			{
				unsigned char rnd = rand() % MAX_OPTIONS;
				if( 0 == quiz_options[idx][rnd] )
				{
					quiz_options[idx][rnd] = opt;
					break;
				}
			}
		}
	}

	bob = 17; 

}

#endif//_RANDOM_MANAGER_H_