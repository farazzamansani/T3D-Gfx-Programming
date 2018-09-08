#define _USE_MATH_DEFINES

#include <math.h>
#include "barrel.h"

using namespace T3D;

barrel::barrel(float radius, float height, int density)
{
	density = 8;
	// Init vertex and index arrays
	initArrays((density * 2) + ((density + 5) * 2),	// num vertices
		28,								// num tris
		density + 1);									// num quads

	

	for (int i = 0; i <= density + 1; i++) {
		float theta = i * ((M_PI * 2) / density);
		setVertex(i, radius * cos(theta), height, radius * sin(theta));//0-8
		setUV(i, 1 - float(i) / (density + 1), 0.55);
		setVertex(density + 1 + i, radius * cos(theta), -height, radius * sin(theta));//9-17
		setUV(density + 1 + i, 1 - float(i) / (density + 1), 1);
	}

	setVertex(density * 4 + 4, 0, -height, 0);//36

	setVertex(density * 4 + 5, 0, height, 0);//37


	//top and bottoms faces vertices
	for (int i = 1; i <= density + 1; i++) {
		float theta = (float(i) / density) * (M_PI * 2);
		setVertex(density * 2 + 2 + i, radius * cos(theta), height, radius * sin(theta));//19-27

		setVertex(density * 3 + 2 + i, radius * cos(theta), -height, radius * sin(theta));//27-35


	}
	

	//texture the top of the barrel
	setUV(37, 0.26, 0.2); //centre
	setUV(19, 0.145, 0.06);
	setUV(20, 0.27, 0.02);
	setUV(21, 0.39, 0.06);
	setUV(22, 0.46, 0.2);
	setUV(23, 0.41, 0.33);
	setUV(24, 0.27, 0.40); 
	setUV(25, 0.135, 0.34);
	setUV(26, 0.077, 0.2);
	setUV(27, 0.15, 0.06);

	setUV(36, 0.26, 0.2); //centre
	setUV(28, 0.145, 0.06);
	setUV(29, 0.27, 0.02);
	setUV(30, 0.39, 0.06);
	setUV(31, 0.46, 0.2);
	setUV(32, 0.41, 0.33);
	setUV(33, 0.27, 0.40);
	setUV(34, 0.135, 0.34);
	setUV(35, 0.077, 0.2);
	setUV(36, 0.15, 0.06);





	// Build side quads
	for (int i = 1; i < density + 1; i++) {
		setFace(i,
			i,							 // current top vertex
			(i + 1),			 // next top vertex (with wrapping)
			density + (i + 1 + 1), // next bottom vertex (with wrapping) 
			density + i + 1				 // current bottom vertex
		);

	}

	//set top faces
	setFace(10,
		19,
		37,
		20
	);
	setFace(11,
		20,
		37,
		21
	);
	setFace(12,
		21,
		37,
		22
	);
	setFace(13,
		22,
		37,
		23
	);
	setFace(14,
		23,
		37,
		24
	);
	setFace(15,
		24,
		37,
		25
	);
	setFace(16,
		25,
		37,
		26
	);
	setFace(17,
		26,
		37,
		27
	);

	//set bottom faces

	setFace(18,
		29,
		36,
		28
	);
	setFace(19,
		30,
		36,
		29
	);
	setFace(20,
		31,
		36,
		30
	);
	setFace(21,
		32,
		36,
		31
	);
	setFace(22,
		33,
		36,
		32
	);
	setFace(23,
		34,
		36,
		33
	);
	setFace(24,
		35,
		36,
		34
	);
	setFace(25,
		28,
		36,
		35
	);










	// Check vertex and index arrays
	checkArrays();

	// Calculate normals
	calcNormals();
}


barrel::~barrel()
{
}
