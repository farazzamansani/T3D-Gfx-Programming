#pragma once
#include "Task.h"
#include "Animation.h"
#include "Sound.h"
#include "Music.h"
#include "Camera.h"

namespace T3D {
	class AnimationTest :
		public Task
	{
	public:
		AnimationTest(T3DApplication *app);
		~AnimationTest();
		void AnimationTest::update(float dt);
		static float smoothedLerp(float firstPos, float endPos, float time, float accelerationTime);

		Transform *task2;
		Transform *task5;
		Animation *blah;
		Transform *camera;
		bool pause = false;
		bool played = false;
		Sound *sound;
		Sound *horseneigh;
		Sound *horse02;
		
		Music *minigun;
		Music *music;
		Music *dirtwalk;
		int direction;
	};

}
