#ifndef __MAIN__
#define __MAIN__

#include <stdbool.h>
#include <stdlib.h>
#include "..\lib\SMSlib.h"
#include "..\lib\PSGlib.h"
#include "gfx.h"
#include "psg.h"

#include "engine\global_manager.h"
#include "engine\locale_manager.h"
#include "engine\hack_manager.h"
#include "engine\enum_manager.h"
#include "engine\content_manager.h"
#include "engine\font_manager.h"
#include "engine\sprite_manager.h"
#include "engine\asm_manager.h"

#include "screen\splash_screen.h"
#include "screen\title_screen.h"
#include "screen\intro_screen.h"
#include "screen\ready_screen.h"

//_BASES_SCREEN_H_
unsigned int screen_bases_screen_count, screen_bases_screen_timer;

//_SPLASH_SCREEN_H_
unsigned char screen_splash_screen_delay;

#endif//__MAIN__