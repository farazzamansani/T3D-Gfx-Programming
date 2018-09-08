#pragma once
#include "Mesh.h"

namespace T3D {

	class TCylinder :
		public Mesh
	{
	public:
		TCylinder(float radius, float height, int density);
		~TCylinder();
	};

}

