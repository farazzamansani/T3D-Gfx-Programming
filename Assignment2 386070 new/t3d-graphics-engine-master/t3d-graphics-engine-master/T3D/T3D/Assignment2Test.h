#pragma once
#include "WINGLAPPLICATION.H"

namespace T3D {
	class Assignment2Test :
		public WinGLApplication
	{
	public:
		Assignment2Test();
		~Assignment2Test();
		bool init();

		class Animation *anim;

	};
}

