// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Sound.h
//
// Simple class used for playing short sound files.  Uses FMod: www.fmod.org

#pragma once

#include <string>
#include "fmod/fmod.hpp"
#include "SoundManager.h"

namespace T3D{

	class Sound
	{
	friend class SoundManager;
	public:
		Sound(SoundManager* sm);
		~Sound(void);

		void play();	
		void setVolume(float v);

	private:
		SoundManager* soundManager;
		FMOD::Sound *theSound;
		FMOD::Channel *channel;

		float volume;
	};

}

