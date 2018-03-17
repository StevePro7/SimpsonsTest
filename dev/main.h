#ifndef __MAIN__
#define __MAIN__

#include <stdbool.h>
#include <stdlib.h>
#include "..\lib\SMSlib.h"
#include "..\lib\PSGlib.h"
#include "gfx.h"
#include "psg.h"

#include "banks\bank2.h"

#include "engine\global_manager.h"
#include "engine\locale_manager.h"
#include "engine\hack_manager.h"
#include "engine\enum_manager.h"
#include "engine\content_manager.h"
#include "engine\font_manager.h"
#include "engine\quiz_manager.h"
#include "engine\sprite_manager.h"
#include "engine\select_manager.h"
#include "engine\asm_manager.h"

#include "screen\splash_screen.h"
#include "screen\title_screen.h"
#include "screen\intro_screen.h"
#include "screen\ready_screen.h"
#include "screen\play_screen.h"
//#include "screen\quiz_screen.h"

//_SELECT_MANAGER_H_
unsigned char select_choice, select_height;
unsigned char select_option[4];

//_BASES_SCREEN_H_
unsigned int screen_bases_screen_count, screen_bases_screen_timer;

//_SPLASH_SCREEN_H_
unsigned char screen_splash_screen_delay;

//_PLAY_SCREEN_H_
unsigned char play_answer_state;

#endif//__MAIN__