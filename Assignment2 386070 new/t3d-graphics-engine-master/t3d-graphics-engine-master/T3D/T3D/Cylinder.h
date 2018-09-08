#pragma once
#include "Mesh.h"

namespace T3D {

	class Cylinder :
		public Mesh
	{
	public:
		Cylinder(float radius, float height, int density);
		~Cylinder();
	};

}

