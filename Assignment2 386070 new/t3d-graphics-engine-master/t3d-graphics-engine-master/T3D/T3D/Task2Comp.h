#pragma once
#include "GameObject.h"
namespace T3D {

	class Task2Comp : public GameObject
		
	{
	public:
		Task2Comp(T3DApplication *app);
		~Task2Comp(void);

		GameObject *base;
		GameObject *support;
		GameObject *supportm1;
		GameObject *supportm2;
		GameObject *rotar;
		GameObject *bulk;
		GameObject *bulk2;
		GameObject *bulk3;
		GameObject *triggerhandle;
		GameObject *trigger;
		GameObject *handlel;
		GameObject *handler;
		GameObject *handlebridge;
		GameObject *ammo;
		GameObject *barrel1;
		GameObject *barrel2;
		GameObject *barrel3;
		GameObject *barrel4;
		GameObject *barrel5;
		GameObject *barrel6;
	};

}

