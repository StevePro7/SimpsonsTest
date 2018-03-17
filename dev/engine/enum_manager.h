#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

// Screen type.
#define SCREEN_TYPE_NONE	0
#define SCREEN_TYPE_SPLASH	1
#define SCREEN_TYPE_TITLE	2
#define SCREEN_TYPE_INTRO	3
#define SCREEN_TYPE_READY	4
#define SCREEN_TYPE_PLAY	5

enum
{
	screen_type_none,	// 0
	screen_type_splash,	// 1
	screen_type_title,	// 2
	screen_type_intro,	// 3
	screen_type_ready,	// 4
	screen_type_play,	// 5
} enum_curr_screen_type, enum_next_screen_type;


// Select type.
#define ANSWER_TYPE_SELECT	0
#define ANSWER_TYPE_RIGHT	1
#define ANSWER_TYPE_WRONG	2

enum
{
	answer_type_select,	// 0
	answer_type_right,	// 1
	answer_type_wrong,	// 2
} enum_select_answer_type;

#endif//_ENUM_MANAGER_H_