#pragma once
#include "gameobject.h"

namespace T3D {

	class Task1sweep : public GameObject
	{
	public:
		Task1sweep(T3DApplication *app);
		~Task1sweep(void);


		GameObject *base;
		GameObject *pathobj;
	};
}
