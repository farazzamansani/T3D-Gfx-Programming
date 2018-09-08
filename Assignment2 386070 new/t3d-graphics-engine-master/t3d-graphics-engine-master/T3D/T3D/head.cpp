#include "head.h"

using namespace T3D;


head::head()
{
	// Init vertex and index arrays
	initArrays(4 ,	// num vertices
		1,					// num tris
		0);					// num quads

	int pos = 0;

	setVertex(pos++, 0, 0, 0);
	setVertex(pos++, -0.1, 0, 0);
	setVertex(pos++, 0, 0, 1);
	setVertex(pos++, -0.2, 1, 0);
	setVertex(pos++, -0.3, 0, 0);
	

	setFace(0, 3, 2,1);
}


head::~head()
{
}
