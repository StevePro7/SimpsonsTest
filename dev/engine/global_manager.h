#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

// General.
#define MAX_STATES			17

// Content.
#define MUSIC_PSG			music_psg
#define SOUND1_PSG			sfx_right_psg
#define SOUND2_PSG			sfx_wrong_psg
#define SOUND3_PSG			sfx_pause_psg

// Sprites.
#define SPRITE_TILES		64

// Delay.
#define SPLASH_DELAY		150
#define TITLE_DELAY			100
#define INTRO_DELAY			50

#define ENEMY_STD_DELAY		75
#define ENEMY_MIN_DELAY		25

// Quiz.
#define MAX_QUESTIONS		10		// TODO changed for testing - correct to 50

// Options.
#define MAX_OPTIONS			4

// Long.
#define LONG_DELTA			4		// Change this to 4 if max no. questions >= 100!

#endif//_GLOBAL_MANAGER_H_