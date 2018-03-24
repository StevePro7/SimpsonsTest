#ifndef _HACK_MANAGER_H_
#define _HACK_MANAGER_H_

#define PEEK(addr)			(*(unsigned char *)(addr))
#define POKE(addr, data)	(*(unsigned char *)(addr) = (data))

extern unsigned char hacker_debug, hacker_splash;
extern unsigned char hacker_start, hacker_delay, hacker_music, hacker_sound;
extern unsigned char hacker_cheat, hacker_random;

#define HACKER_START		0x0050

void engine_hack_manager_init()
{
	hacker_debug = PEEK(HACKER_START - 1);		// 0x004F		// 0=debug on otherwise off.
	hacker_splash= PEEK(HACKER_START - 2);		// 0x004E		// 0=splash off for testing.

	hacker_start = PEEK(HACKER_START + 0);		// 0x0050		// 0=steps to move: 1,2,4,8.
	hacker_delay = PEEK(HACKER_START + 1);		// 0x0051		// 0=enemy to alternate arm.
	hacker_music = PEEK(HACKER_START + 3);		// 0x0053		// 0=music on otherwise off.
	hacker_sound = PEEK(HACKER_START + 4);		// 0x0054		// 0=sound on otherwise off.

	// TODO update correctly
	hacker_random= PEEK(HACKER_START + 7);		//
	hacker_cheat = PEEK(HACKER_START + 8);		//
}

void engine_hack_manager_invert()
{
	//hacker_debug = !hacker_debug;				// TODO REMOVE

	hacker_splash = !hacker_splash;
	hacker_music = !hacker_music;				// TODO uncomment - just for testing
	hacker_sound = !hacker_sound;
	//hacker_random= !hacker_random;
	hacker_random= RAND_TYPE_NORMAL;
	hacker_cheat = 1;							// TODO REMOVE
}

void engine_hack_manager_resetX()
{
	hacker_debug = 0;
	hacker_splash= 0;

	hacker_start = 0;
	hacker_delay = 0;
	hacker_music = 0;
	hacker_sound = 0;
	hacker_random= 0;
	hacker_cheat = 0;
}

#endif//_HACK_MANAGER_H_