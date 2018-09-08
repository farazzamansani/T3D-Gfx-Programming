#pragma once
#include "GameObject.h"
#include "Mesh.h"
namespace T3D {
	class propeller : public Mesh
	{
	public:
		propeller(float radius,float hubradius, float attackangle, float height, int density, int blades);
		//hubradius is actually blade radius, attack angle expects input of 45.0 for 45 degrees etc.
		~propeller(void);
	};
}

