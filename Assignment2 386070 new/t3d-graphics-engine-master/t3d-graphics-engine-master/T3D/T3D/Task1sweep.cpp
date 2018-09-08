#include "Task1sweep.h"
#include "Cylinder.h"
#include "Transform.h"
#include "Sweep.h"
#include "SweepPath.h"
#include <math.h>
using namespace T3D;
//This is task 1, a sweep creating a sword.

Task1sweep::Task1sweep(T3DApplication *app) :GameObject(app) 
{
	//the following code block is taken from the lamp tutorial code provided
		setMesh(new Cylinder(0, 0, 16));
		getTransform()->name = "Task1";
		base = new GameObject(app); 
		base->setMesh(new Cylinder(0, 0, 16));
		base->getTransform()->setParent(getTransform()); 
		base->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		base->getTransform()->name = "Base";
	//


	//sweep profile
		std::vector<Vector3> shadeProfile;
		shadeProfile.push_back(Vector3(0.0f, -0.5f, 0.0f));
		shadeProfile.push_back(Vector3(0.17f, -0.45f, 0.0f));
		shadeProfile.push_back(Vector3(0.35f, -0.31f, 0.0f));
		shadeProfile.push_back(Vector3(0.45f, -0.16f, 0.0f));
		shadeProfile.push_back(Vector3(0.50f, 0.0f, 0.0f));

		shadeProfile.push_back(Vector3(0.48f, 0.22f, 0.0f));
		shadeProfile.push_back(Vector3(0.40f, 0.33f, 0.0f));
		shadeProfile.push_back(Vector3(0.26f, 0.42f, 0.0f));
		shadeProfile.push_back(Vector3(0.08f, 0.5f, 0.0f));

		shadeProfile.push_back(Vector3(-0.08f, 0.5f, 0.0f));
		shadeProfile.push_back(Vector3(-0.26f, 0.42f, 0.0f));
		shadeProfile.push_back(Vector3(-0.40f, 0.33f, 0.0f));
		shadeProfile.push_back(Vector3(-0.48f, 0.22f, 0.0f));

		shadeProfile.push_back(Vector3(-0.5f, 0.0f, 0.0f));
		shadeProfile.push_back(Vector3(-0.45f, -0.16f, 0.0f));
		shadeProfile.push_back(Vector3(-0.35f, -0.31f, 0.0f));
		shadeProfile.push_back(Vector3(-0.17f, -0.45f, 0.0f));
		shadeProfile.push_back(Vector3(0.0f, -0.5f, 0.0f));


		SweepPath shadepath;
		Transform t;
		//sweep path starting at the pommel
		t.setLocalPosition(Vector3(-0.01, 0, 0));
		t.setLocalScale(Vector3(0, 0, 0));
		t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
		shadepath.addTransform(t);

		t.setLocalScale(Vector3(0.06, 0.06, 1));
		t.setLocalPosition(Vector3(0.01, 0, 0));
		shadepath.addTransform(t);

		t.setLocalScale(Vector3(0.15, 0.15, 1));
		t.setLocalPosition(Vector3(0.08, 0, 0));
		shadepath.addTransform(t);

		//grip
		t.setLocalScale(Vector3(0.1, 0.1, 1));
		t.setLocalPosition(Vector3(0.15, 0, 0));
		shadepath.addTransform(t);

		t.setLocalPosition(Vector3(0.5, 0, 0));
		t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 3, 0)));
		shadepath.addTransform(t);

		//gaurd
		t.setLocalPosition(Vector3(0.6, 0, 0));
		t.setLocalScale(Vector3(0.15, 0.6, 1));
		shadepath.addTransform(t);

		t.setLocalPosition(Vector3(0.6, 0, 0));
		t.setLocalScale(Vector3(0.1, 0.1, 1));
		shadepath.addTransform(t);
		//blade
		t.setLocalPosition(Vector3(0.8, 0, 0));
		t.setLocalScale(Vector3(0.01, 0.1, 1));
		shadepath.addTransform(t);


	
		t.setLocalPosition(Vector3(2.4, 0, 0));
		t.setLocalScale(Vector3(0.01, 0.2, 1));
		shadepath.addTransform(t);

		
		t.setLocalPosition(Vector3(3, 0, 0));
		t.setLocalScale(Vector3(0.01, 0, 1));
		shadepath.addTransform(t);

		

		pathobj = new GameObject(app);
		pathobj->setMesh(new Sweep(shadeProfile, shadepath, false));
		pathobj->getTransform()->setLocalPosition(Vector3(0, 0.1, 0)); 
		pathobj->getTransform()->setParent(base->getTransform()); 
		pathobj->getTransform()->name = "taskone";


}


Task1sweep::~Task1sweep()
{
}
