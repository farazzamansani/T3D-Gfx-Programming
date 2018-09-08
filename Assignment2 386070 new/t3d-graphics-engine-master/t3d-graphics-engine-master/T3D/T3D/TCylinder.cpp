#define _USE_MATH_DEFINES

#include <math.h>
#include "TCylinder.h"

using namespace T3D;

TCylinder::TCylinder(float radius, float height, int density)
{
	// Init vertex and index arrays
	initArrays((density * 2) + ((density + 5) * 2),	// num vertices
		density * 2+1,								// num tris
		density+1);									// num quads

													// Set side vertices
	//for (int i = 0; i <= density; i++) {
	//	float theta = float(i) / density * (M_PI*2);
	//	setVertex(i, radius*cos(theta), height, radius*sin(theta));
	//	setUV(i, float(i) / density, 0);
	//	setVertex(density+1 + i, radius*cos(theta), -height, radius*sin(theta));
	//	setUV(density + 1 + i, float(i) / density, 0.6);
	//}

	for (int i = 0; i <= density+1; i++) {
		float theta = i * ((M_PI * 2) / density);
		setVertex(i, radius * cos(theta), height, radius * sin(theta));
		setUV(i, 1-float(i) / (density+1), 0);
		setVertex(density + 1 + i, radius * cos(theta), -height, radius * sin(theta));
		setUV(density + 1 + i, 1-float(i) / (density+1), 0.6);
	}

	setVertex(density * 4 + 3, 0, -height, 0);

	setVertex(density * 4 + 4, 0, height, 0);


	//top and bottoms faces vertices
	for (int i = 1; i <= density+1; i++) {
		float theta = (float(i) / density) * (M_PI * 2);
		setVertex(density * 2 +2+ i, radius * cos(theta), height, radius * sin(theta));
		setUV(density * 3 + 2 + i, 1, 0);
		
		setUV(density*2+2+i, 1 , 0);
		
		setUV(density * 4 + 3, 1, 0);
	
		setVertex(density * 3+2 + i, radius * cos(theta), -height, radius * sin(theta));

		
	}


	
	

	// Build side quads
	for (int i = 1; i < density+1; i++) {
		setFace(i,
			i,							 // current top vertex
			(i + 1),			 // next top vertex (with wrapping)
			density + (i + 1+1) , // next bottom vertex (with wrapping) 
			density + i	+1				 // current bottom vertex
		);


		setFace(i,
			density * 3 + i+1,
			density * 3 + (i + 1)+1,
			density * 4+1
		);

		setFace(density + i,
			density * 2 + (i + 1)+1,
			density * 2 + i+1,
			density * 4 + 1+1
		);
	}
	

	// Check vertex and index arrays
	checkArrays();

	// Calculate normals
	calcNormals();
}


TCylinder::~TCylinder()
{
}
