#define _USE_MATH_DEFINES

#include <math.h>
#include "Cylinder.h"

using namespace T3D;

Cylinder::Cylinder(float radius, float height, int density)
{
	// Init vertex and index arrays
	initArrays((density * 2) + ((density + 1) * 2),	// num vertices
		density * 2,								// num tris
		density);									// num quads

													// Set side vertices
	for (int i = 0; i < density; i++) {
		float theta = i * ((M_PI * 2) / density);
		setVertex(i, radius * cos(theta), height, radius * sin(theta));
		setVertex(density + i, radius * cos(theta), -height, radius * sin(theta));
	}

	for (int i = 0; i < density; i++) {
		float theta = (float(i) / density) * (M_PI * 2);
		setVertex(density * 2 + i, radius * cos(theta), height, radius * sin(theta));
		setVertex(density * 3 + i, radius * cos(theta), -height, radius * sin(theta));
	}

	setVertex(density * 4, 0, -height, 0);
	setVertex(density * 4 + 1, 0, height, 0);

	// Build side quads
	for (int i = 0; i < density; i++) {
		setFace(i,
			i,							 // current top vertex
			(i + 1) % density,			 // next top vertex (with wrapping)
			density + (i + 1) % density, // next bottom vertex (with wrapping) 
			density + i					 // current bottom vertex
		);


		setFace(i,
			density * 3 + i,
			density * 3 + (i + 1) % density,
			density * 4
		);

		setFace(density + i,
			density * 2 + (i + 1) % density,
			density * 2 + i,
			density * 4 + 1
		);
	}

	// Check vertex and index arrays
	checkArrays();

	// Calculate normals
	calcNormals();
}


Cylinder::~Cylinder()
{
}
