#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

void engine_audio_manager_music()
{
	if (hacker_music)
	{
		PSGPlayNoRepeat(MUSIC_PSG);
	}
}

void engine_audio_manager_sound_right()
{
	if(hacker_sound)
	{
		PSGSFXPlay(SOUND1_PSG, SFX_CHANNEL2);
	}
}

void engine_audio_manager_sound_wrong()
{
	if(hacker_sound)
	{
		PSGSFXPlay(SOUND2_PSG, SFX_CHANNEL2);
	}
}

#endif//_AUDIO_MANAGER_H_