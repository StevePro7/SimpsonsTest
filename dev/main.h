#ifndef __MAIN__
#define __MAIN__

#include <stdbool.h>
#include <stdlib.h>
#include "..\lib\SMSlib.h"
#include "..\lib\PSGlib.h"
#include "gfx.h"
#include "psg.h"

#include "banks\bank2.h"
//#include "banks\bank3.h"
//#include "banks\bank4.h"
//#include "banks\bank5.h"

#include "engine\global_manager.h"
#include "engine\locale_manager.h"
#include "engine\hack_manager.h"
#include "engine\enum_manager.h"
#include "engine\content_manager.h"
#include "engine\image_manager.h"
#include "engine\font_manager.h"
#include "engine\quiz_manager.h"
#include "engine\sprite_manager.h"
#include "engine\select_manager.h"
#include "engine\score_manager.h"
#include "engine\audio_manager.h"
#include "engine\input_manager.h"
#include "engine\asm_manager.h"

#include "screen\bases_screen.h"
#include "screen\splash_screen.h"
#include "screen\title_screen.h"
#include "screen\intro_screen.h"
#include "screen\level_screen.h"
#include "screen\number_screen.h"
#include "screen\ready_screen.h"
#include "screen\play_screen.h"
#include "screen\quiz_screen.h"
#include "screen\score_screen.h"
#include "screen\over_screen.h"
#include "screen\credit_screen.h"

//_QUIZ_MANAGER_H_
unsigned char quiz_number;

//_SCORE_MANAGER_H_
unsigned char score_player;

//_SELECT_MANAGER_H_
unsigned char diff_select, long_select, quiz_select;
unsigned char select_choice, select_height;
unsigned char select_option[4];

//_BASES_SCREEN_H_
unsigned int screen_bases_screen_count, screen_bases_screen_timer;

//_SPLASH_SCREEN_H_
unsigned char screen_splash_screen_delay;

//_INTRO_SCREEN_H_
unsigned char screen_intro_screen_delay;

//_INTRO_SCREEN_H_
unsigned char screen_intro_screen_delay;

//_PLAY_SCREEN_H_
unsigned char play_answer_state;

#endif//__MAIN__