#pragma once
#include "Mesh.h"

namespace T3D {

	class barrel :
		public Mesh
	{
	public:
		barrel(float radius, float height, int density);
		~barrel();
	};

}

