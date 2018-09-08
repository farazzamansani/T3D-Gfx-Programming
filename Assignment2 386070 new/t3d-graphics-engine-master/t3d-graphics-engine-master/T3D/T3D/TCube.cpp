// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// cube.cpp
//
// Simple cube mesh with coloured sides
// Note that faces are triangles only and that normals are repeated for each vertex
// This allows use of gl array pointers

#include "TCube.h"

namespace T3D
{
	TCube::TCube(float size,int repeat)
	{
		// Init vertex and index arrays
		initArrays(4 * 6,	// num vertices
			0,		// num tris
			6);		// num quads

					// Set vertices

		int pos = 0;
		int vpos = 0;
		int uvpos = 0;
		//front
		setVertex(pos++, -size, -size, -size);
		setVertex(pos++, size, -size, -size);
		setVertex(pos++, size, size, -size);
		setVertex(pos++, -size, size, -size);

		if (repeat == 0)
		{
			setUV(uvpos++, 0, 0);
			setUV(uvpos++, 0.5, 0);
			setUV(uvpos++, 0.5, 0.5);
			setUV(uvpos++, 0, 0.5);
		}
		else
		{
			setUV(uvpos++, 0, 0);
			setUV(uvpos++, repeat, 0);
			setUV(uvpos++, repeat, repeat);
			setUV(uvpos++, 0, repeat);
		}
		//back
		setVertex(pos++, -size, -size, size);
		setVertex(pos++, size, -size, size);
		setVertex(pos++, size, size, size);
		setVertex(pos++, -size, size, size);

		if (repeat==0)
		{
		setUV(uvpos++, 0.5, 1.0);
		setUV(uvpos++, 1.0, 1.0);
		setUV(uvpos++, 1.0, 0.5);
		setUV(uvpos++, 0.5, 0.5);
		}
		else
		{
			setUV(uvpos++, 0, 0);
			setUV(uvpos++, repeat, 0);
			setUV(uvpos++, repeat, repeat);
			setUV(uvpos++, 0, repeat);
		}
		
		
	
		//left
		setVertex(pos++, -size, -size, -size);
		setVertex(pos++, -size, size, -size);
		setVertex(pos++, -size, size, size);
		setVertex(pos++, -size, -size, size);

		if (repeat==0){
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 0.5, 0.5);
		setUV(uvpos++, 0, 0.5);
		}
		else
		{
			setUV(uvpos++, 0, 0);
			setUV(uvpos++, repeat, 0);
			setUV(uvpos++, repeat, repeat);
			setUV(uvpos++, 0, repeat);
		}
		//right
		setVertex(pos++, size, -size, -size);
		setVertex(pos++, size, size, -size);
		setVertex(pos++, size, size, size);
		setVertex(pos++, size, -size, size);

		if (repeat==0)
		{
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 1.0, 0);
		setUV(uvpos++, 1.0, 0.5);
		setUV(uvpos++, 0.5, 0.5);
		}
	else
		{
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, repeat, 0);
		setUV(uvpos++, repeat, repeat);
		setUV(uvpos++, 0, repeat);
		}
		//bottom
		setVertex(pos++, -size, -size, -size);
		setVertex(pos++, -size, -size, size);
		setVertex(pos++, size, -size, size);
		setVertex(pos++, size, -size, -size);

		if (repeat==0)
		{
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 0.5, 0.5);
		setUV(uvpos++, 0, 0.5);
		}
		else
		{
			setUV(uvpos++, 0, 0);
			setUV(uvpos++, repeat, 0);
			setUV(uvpos++, repeat, repeat);
			setUV(uvpos++, 0, repeat);
		}
		//top
		setVertex(pos++, -size, size, -size);
		setVertex(pos++, -size, size, size);
		setVertex(pos++, size, size, size);
		setVertex(pos++, size, size, -size);

		if (repeat==0)
		{
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 0.5, 0.5);
		setUV(uvpos++, 0, 0.5);
		}
		else
		{
			setUV(uvpos++, 0, 0);
			setUV(uvpos++, repeat, 0);
			setUV(uvpos++, repeat, repeat);
			setUV(uvpos++, 0, repeat);
		}

		// Build quads
		pos = 0;
		//front
		setFace(pos++, 3, 2, 1, 0);
		//back
		setFace(pos++, 4, 5, 6, 7);
		//left
		setFace(pos++, 11, 10, 9, 8);
		//right
		setFace(pos++, 12, 13, 14, 15);
		//bottom
		setFace(pos++, 19, 18, 17, 16);
		//top
		setFace(pos++, 20, 21, 22, 23);

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();

		// Setup other arrays		
		pos = 0;
		//front
		for (int i = 0; i<4; i++) {
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}
		//back
		for (int i = 0; i<4; i++) {
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}
		//left
		for (int i = 0; i<4; i++) {
			colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
		}
		//right
		for (int i = 0; i<4; i++) {
			colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
		}
		//bottom
		for (int i = 0; i<4; i++) {
			colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
		}
		//top
		for (int i = 0; i<4; i++) {
			colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
		}

		//uvs
		pos = 0;
		/*for (int f = 0; f<6; f++) {
			uvs[pos++] = 0; uvs[pos++] = 0;
			uvs[pos++] = 0; uvs[pos++] = 1;
			uvs[pos++] = 1; uvs[pos++] = 1;
			uvs[pos++] = 1; uvs[pos++] = 0;
		}*/
	}


	TCube::~TCube(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
