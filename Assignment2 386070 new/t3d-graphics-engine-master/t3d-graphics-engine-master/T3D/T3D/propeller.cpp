#define _USE_MATH_DEFINES
#include "propeller.h"
#include "Transform.h"
#include "Sweep.h"
#include "SweepPath.h"
#include <math.h>

using namespace T3D;

propeller::propeller(float radius, float hubradius, float attackangle, float height, int density, int blades)  {
	// Init vertex and index arrays

	attackangle = attackangle*0.01;//0.45=45degrees, assuming input of 45.0 degrees so *0.01 becomes 0.45

	initArrays((density * 2) + ((density + 1) * 2)+blades*24,// num vertices
		(density*4)+10*blades,								// num tris
	0);									// num quads
	int bladepos = density / blades; //21/7=1 blade per 3
	int q = 0;//loop count
	for (int i = 0; i < density; i++) {
		float theta = i * ((M_PI * 2) / density);		
			float x = radius * cos(theta);
			float y = radius * sin(theta);
			float newX = x*cos(attackangle) - y*sin(attackangle);
			float newY = x*sin(attackangle) + y*cos(attackangle);
			setVertex(i, newX, height, newY);
			setVertex(density + i, radius * cos(theta), -height, radius * sin(theta));
		
		if(i%bladepos==0 && q<blades)
		{	
			//base for bottom/top returns
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 8, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 9, radius * cos(theta), -height, radius * sin(theta));
			//return for sides
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 16, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 17, radius * cos(theta), -height, radius * sin(theta));

			theta = (i + 0.5) * ((M_PI * 2) / density);
			 x = hubradius * cos(theta);
			 y = hubradius * sin(theta);
			 newX = x*cos(attackangle) - y*sin(attackangle);
			 newY = x * sin(attackangle) + y * cos(attackangle);
			setVertex(q+(density * 2) + ((density + 1) * 2), newX, height, newY);
			setVertex(q+ (density * 2) + ((density + 1) * 2)+blades, hubradius * cos(theta), -height, hubradius * sin(theta));
			
			setVertex(q + (density * 2) + ((density + 1) * 2)+blades*6, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades*7, hubradius * cos(theta), -height, hubradius * sin(theta));

			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 12, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 13, hubradius * cos(theta), -height, hubradius * sin(theta));
			//end for sides
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 22, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 23, hubradius * cos(theta), -height, hubradius * sin(theta));

			//
			theta = (i) * ((M_PI * 2) / density);
			
			x = hubradius * cos(theta);
			y = hubradius * sin(theta);
			newX = x*cos(attackangle) - y*sin(attackangle);
			newY = x * sin(attackangle) + y * cos(attackangle);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 2, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 3, hubradius * cos(theta), -height, hubradius * sin(theta));
			
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 4, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 5, hubradius * cos(theta), -height, hubradius * sin(theta));

			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 14, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 15, hubradius * cos(theta), -height, hubradius * sin(theta));
			//end for sides
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 20, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 21, hubradius * cos(theta), -height, hubradius * sin(theta));


			theta = (i+1) * ((M_PI * 2) / density);
			x = radius * cos(theta);
			y = radius * sin(theta);
			newX = x*cos(attackangle) - y*sin(attackangle);
			newY = x * sin(attackangle) + y * cos(attackangle);
			//base for bottom/top returns
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 10, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 11, radius * cos(theta), -height, radius * sin(theta));
			//returns for sides
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 18, newX, height, newY);
			setVertex(q + (density * 2) + ((density + 1) * 2) + blades * 19, radius * cos(theta), -height, radius * sin(theta));

			q++;
			
			
		}
	}

	for (int i = 0; i < density; i++) {
		float theta = (float(i) / density) * (M_PI * 2);
		float x = radius * cos(theta);
		float y = radius * sin(theta);
		float newX = x*cos(attackangle) - y*sin(attackangle);
		float newY = x * sin(attackangle) + y * cos(attackangle);
		setVertex(density * 2 + i, newX, height, newY);
		
		setVertex(density * 3 + i, radius * cos(theta), -height, radius * sin(theta));
	}//SET 42-62, 63-83

	setVertex(density * 4, 0, -height, 0);//SET 84
	setVertex(density * 4 + 1, 0, height, 0);//SET 85
	
	// Build side quads
	int p = 0;
	for (int i = 0; i < density; i++) {
	
		//setFace(i,
		//			i,							 // current top vertex
		//			(i + 1) % density,			 // next top vertex (with wrapping)
		//			density + (i + 1) % density, // next bottom vertex (with wrapping) 
		//			density + i				 // current bottom vertex
		//		);

			setFace(i,
				i,							 // current top vertex
				(i + 1) % density,			 // next top vertex (with wrapping)
				density + (i + 1) % density // next bottom vertex (with wrapping) 
			);
			setFace(i + density,
				i,			 
				density + (i + 1) % density, // next bottom vertex (with wrapping) 
				density + i				 // current bottom vertex
			);
		if (i%bladepos == 0)
		{
				int topleft = p + (density * 2) + ((density + 1) * 2);
				int bottomleft = p + (density * 2) + ((density + 1) * 2) + blades;
				int topright = p + (density * 2) + ((density + 1) * 2) + blades*2;
				int bottomright = p + (density * 2) + ((density + 1) * 2) + blades * 3;

				int topreturnright = p + (density * 2) + ((density + 1) * 2) + blades * 4;
				int bottomreturnright = p + (density * 2) + ((density + 1) * 2) + blades * 5;
				int topreturnleft = p + (density * 2) + ((density + 1) * 2) + blades * 6;
				int bottomreturnleft = p + (density * 2) + ((density + 1) * 2) + blades * 7;

				int toplefthub = p + (density * 2) + ((density + 1) * 2) + blades * 8;
				int bottomlefthub = p + (density * 2) + ((density + 1) * 2) + blades * 9;
				int toprighthub = p + (density * 2) + ((density + 1) * 2) + blades * 10;
				int bottomrighthub = p + (density * 2) + ((density + 1) * 2) + blades * 11;

				int topleftend= p + (density * 2) + ((density + 1) * 2) + blades * 12;
				int bottomleftend = p + (density * 2) + ((density + 1) * 2) + blades * 13;
				int toprightend = p + (density * 2) + ((density + 1) * 2) + blades * 14;
				int bottomrightend = p + (density * 2) + ((density + 1) * 2) + blades * 15;

				int toplefthub2 = p + (density * 2) + ((density + 1) * 2) + blades * 16;
				int bottomlefthub2 = p + (density * 2) + ((density + 1) * 2) + blades * 17;
				int toprighthub2 = p + (density * 2) + ((density + 1) * 2) + blades * 18;
				int bottomrighthub2 = p + (density * 2) + ((density + 1) * 2) + blades * 19;

				int toprightend2 = p + (density * 2) + ((density + 1) * 2) + blades * 20;
				int bottomrightend2 = p + (density * 2) + ((density + 1) * 2) + blades * 21;
				int topleftend2 = p + (density * 2) + ((density + 1) * 2) + blades * 22;
				int bottomleftend2 = p + (density * 2) + ((density + 1) * 2) + blades * 23;


			setFace(p+4*density,
				topleftend,							 // blade end 1
				bottomleftend,			 
				bottomrightend
			);
			setFace(p+4*density+blades,
				bottomrightend,								// blade end 2
				toprightend,			 
				topleftend
			);
			setFace(p + 4 * density + blades*2,
				topreturnleft,								// top blade to hub 1
				topreturnright,			 
				toplefthub//i
			);
			setFace(p + 4 * density + blades * 3,
				topreturnleft,								// top blade to hub 2 
				toplefthub,//i,			
				toprighthub//(i + 1) % density
			);
			setFace(p + 4 * density + blades * 4,//bottomblade to hub 1
				bottomrighthub,//density + (i + 1) % density, 
				bottomlefthub,//density + i,			 
				bottomreturnleft//bottomleft
			);

			setFace(p + 4 * density + blades * 5,//bottom blade to hub 2
				bottomlefthub,//density + i,
				bottomreturnright,//bottomright,			 
				bottomreturnleft//bottomleft
			);

			setFace(p + 4 * density + blades * 6,
			bottomlefthub2,//	density + (i + 0) % density, // return 1 
			toplefthub2,//(i + 0) % density,
			toprightend2//topright
			);
			setFace(p + 4 * density + blades * 7,
				toprightend2,//topright, // return 2
				bottomrightend2,//bottomright,			 
				bottomlefthub2//density + (i + 0) % density
			);
			//			i,							 // current top vertex
			//			(i + 1) % density,			 // next top vertex (with wrapping)
			//			density + (i + 1) % density, // next bottom vertex (with wrapping) 
			//			density + i				 // current bottom vertex
			int g = i-1;
			setFace(p + 4 * density + blades * 8,
				topleftend2,//topleft,
				bottomrighthub2,//density + (g + 2) % density,
				bottomleftend2//bottomleft
			);
			setFace(p + 4 * density + blades * 9,
				topleftend2,//topleft,
				toprighthub2,//(g + 2) % density,//	bottomleft,
				bottomrighthub2//density + (g + 2) % density
			);
			
			p++;
		}

		setFace(i+(density*2),
			density * 3 + i,
			density * 3 + (i + 1) % density,
			density * 4
		);

		setFace(i+(density*3),
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


propeller::~propeller()
{
}
