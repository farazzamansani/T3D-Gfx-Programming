#include "Pyramid.h"

using namespace T3D;

Pyramid::Pyramid(float size)
{
	// Init vertex and index arrays
	initArrays(4 + (3 * 4),	// num vertices
		4,					// num tris
		1);					// num quads

							// Set vertices
	int pos = 0;
	//front
	setVertex(pos++, -size, -size, size);
	setVertex(pos++, 0, size, 0);
	setVertex(pos++, size, -size, size);
	//back
	setVertex(pos++, size, -size, -size);
	setVertex(pos++, 0, size, 0);
	setVertex(pos++, -size, -size, -size);
	//left
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, 0, size, 0);
	setVertex(pos++, -size, -size, size);
	//right
	setVertex(pos++, size, -size, size);
	setVertex(pos++, 0, size, 0);
	setVertex(pos++, size, -size, -size);
	//bottom
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, -size, -size, size);
	setVertex(pos++, size, -size, size);
	setVertex(pos++, size, -size, -size);


	// Build tris
	pos = 0;
	//front
	setFace(pos++, 2, 1, 0);
	//back
	setFace(pos++, 5, 4, 3);
	//left
	setFace(pos++, 8, 7, 6);
	//right
	setFace(pos++, 11, 10, 9);

	// Build quads
	pos = 0;
	//bottom
	setFace(pos++, 15, 14, 13, 12);

	// Check vertex and index arrays
	checkArrays();

	// Calculate normals
	calcNormals();
}


Pyramid::~Pyramid()
{
}
