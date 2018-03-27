#ifndef _HACK_MANAGER_H_
#define _HACK_MANAGER_H_

#define PEEK(addr)			(*(unsigned char *)(addr))
#define POKE(addr, data)	(*(unsigned char *)(addr) = (data))

extern unsigned char hacker_debug;
extern unsigned char hacker_cheat, hacker_random;
extern unsigned char hacker_music, hacker_sound;

#define HACKER_START		0x0050

void engine_hack_manager_init()
{
	hacker_debug = PEEK(HACKER_START - 1);		// 0x004F		// 0=debug on otherwise off.

	hacker_cheat = PEEK(HACKER_START + 0);		// 0x0050		// 0=there's no help at all.
	hacker_random= PEEK(HACKER_START + 1);		// 0x0051		// 0=randomly ask questions.
	hacker_music = PEEK(HACKER_START + 2);		// 0x0053		// 0=music on otherwise off.
	hacker_sound = PEEK(HACKER_START + 3);		// 0x0054		// 0=sound on otherwise off.


	// TODO remove
	hacker_cheat = 1;
	hacker_random= RAND_TYPE_NORMAL;
	// TODO remove
}

void engine_hack_manager_invert()
{
	hacker_music = !hacker_music;
	hacker_sound = !hacker_sound;
	//hacker_random= !hacker_random;
	hacker_random= RAND_TYPE_NORMAL;
	hacker_cheat = 1;							// TODO REMOVE
}

void engine_hack_manager_resetX()
{
	hacker_debug = 0;

	hacker_cheat = 0;
	hacker_random= 0;
	hacker_music = 0;
	hacker_sound = 0;
}

#endif//_HACK_MANAGER_H_