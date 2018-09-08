// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Sound.cpp
//
// Simple class used for playing short sound files.  Uses FMod: www.fmod.org

#include "Sound.h"

namespace T3D{

	Sound::Sound(SoundManager* sm) : soundManager(sm)
	{
		channel = NULL;
		volume = 0.01f; 
	}


	Sound::~Sound(void)
	{
	}

	void Sound::play(){
		soundManager->system->playSound(FMOD_CHANNEL_FREE, theSound, true, &channel);
		channel->setVolume(volume); 
		channel->setPaused(false);
	}

	void Sound::setVolume(float v){
		volume = v;
	}
}
