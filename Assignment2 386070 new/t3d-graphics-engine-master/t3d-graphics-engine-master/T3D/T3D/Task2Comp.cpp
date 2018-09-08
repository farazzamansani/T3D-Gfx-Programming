#include "Task2Comp.h"
#include "Cylinder.h"
#include "Transform.h"
#include "Sweep.h"
#include "SweepPath.h"
#include "Cube.h"
//this is task 2 composition, it is a minigun
//noteworthy features are 6 sweeped barrels attached to a parent rotar for animation
//trigger could also be animated
//ammo also could be animated

using namespace T3D;
Task2Comp::Task2Comp(T3DApplication *app) :GameObject(app) {
	setMesh(new Cylinder(0, 0, 16));
	getTransform()->name = "task2";


	base = new GameObject(app); 
	base->setMesh(new Cylinder(1, 0.2, 16));
	base->getTransform()->setParent(getTransform()); 
	base->getTransform()->setLocalPosition(Vector3(0, 0.02, 0));
	base->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, Math::PI, Math::PI / 2)));
	base->getTransform()->name = "base";

	//the rotar is the parent of all the barrels and supports so used for shooting animation
	rotar = new GameObject(app);
	rotar->setMesh(new Cylinder(0.9, 0.05, 16));
	rotar->getTransform()->setParent(getTransform());
	rotar->getTransform()->setLocalPosition(Vector3(0, 0.02, 0));
	rotar->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));//rotate here for firing animation :D
	rotar->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, Math::PI, Math::PI / 2)));
	rotar->getTransform()->name = "rotar";

	support = new GameObject(app); 
	support->setMesh(new Cylinder(1, 0.15, 16));
	support->getTransform()->setParent(rotar->getTransform());
	support->getTransform()->setLocalPosition(Vector3(0, 4.5, 0));
	support->getTransform()->name = "support";//supports are just the bits supporting the barrels

	supportm1 = new GameObject(app);
	supportm1->setMesh(new Cylinder(1, 0.05, 16));
	supportm1->getTransform()->setParent(rotar->getTransform());
	supportm1->getTransform()->setLocalPosition(Vector3(0, 4, 0));
	supportm1->getTransform()->name = "supportm1";
	supportm2 = new GameObject(app);
	supportm2->setMesh(new Cylinder(1, 0.05, 16));
	supportm2->getTransform()->setParent(rotar->getTransform());
	supportm2->getTransform()->setLocalPosition(Vector3(0, 3.8, 0));
	supportm2->getTransform()->name = "supportm2";

	bulk = new GameObject(app);
	bulk->setMesh(new Cylinder(1.4, 0.8, 16));
	bulk->getTransform()->setParent(base->getTransform());
	bulk->getTransform()->setLocalPosition(Vector3(0, -1, 0));
	bulk->getTransform()->name = "bulk";

	bulk2 = new GameObject(app);
	bulk2->setMesh(new Cylinder(1, 1, 16));
	bulk2->getTransform()->setParent(base->getTransform());
	bulk2->getTransform()->setLocalPosition(Vector3(0, -2, 0));
	bulk2->getTransform()->name = "bulk2";

	bulk3 = new GameObject(app);
	bulk3->setMesh(new Cube(0.5));
	bulk3->getTransform()->setParent(base->getTransform());
	bulk3->getTransform()->setLocalPosition(Vector3(0, -4, 0));
	bulk3->getTransform()->setLocalScale(Vector3(1, 2, 1));
	bulk3->getTransform()->name = "bulk3";

	triggerhandle = new GameObject(app);
	triggerhandle->setMesh(new Cylinder(0.2, 0.7, 16));
	triggerhandle->getTransform()->setParent(base->getTransform());
	triggerhandle->getTransform()->setLocalPosition(Vector3(0, -4, 1));
	triggerhandle->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	triggerhandle->getTransform()->name = "triggerhandle";

	trigger = new GameObject(app);
	trigger->setMesh(new Cube(0.1));
	trigger->getTransform()->setParent(base->getTransform());
	trigger->getTransform()->setLocalPosition(Vector3(0, -3.9, 0.5));//adjust position or rotate for press animation
	trigger->getTransform()->setLocalScale(Vector3(1, 2, 3));
	trigger->getTransform()->name = "trigger";

	handlel = new GameObject(app);
	handlel->setMesh(new Cylinder(0.2, 0.8, 16));
	handlel->getTransform()->setParent(base->getTransform());
	handlel->getTransform()->setLocalPosition(Vector3(-1, -1, 1.5));
	handlel->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	handlel->getTransform()->name = "handlel";
	handler = new GameObject(app);
	handler->setMesh(new Cylinder(0.2, 0.8, 16));
	handler->getTransform()->setParent(base->getTransform());
	handler->getTransform()->setLocalPosition(Vector3(1, -1, 1.5));
	handler->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	handler->getTransform()->name = "handler";

	handlebridge = new GameObject(app);
	handlebridge->setMesh(new Cylinder(0.2, 1, 16));
	handlebridge->getTransform()->setParent(base->getTransform());
	handlebridge->getTransform()->setLocalPosition(Vector3(0, -1, 2));
	handlebridge->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, Math::PI / 2, 0)));
	handlebridge->getTransform()->name = "handlebridge";

	ammo = new GameObject(app);
	ammo->setMesh(new Cube(0.2));
	ammo->getTransform()->setParent(base->getTransform());
	ammo->getTransform()->setLocalPosition(Vector3(1.5, -1, -0.5));
	ammo->getTransform()->setLocalScale(Vector3(7, 2, 0.4));//shrink for running out of bullets animation
	ammo->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 3, 0)));
	ammo->getTransform()->name = "ammo";


	//sweep profile for barrels
	std::vector<Vector3> shadeProfile;
	shadeProfile.push_back(Vector3(0.0f, 0.0f, 0.0f));
	shadeProfile.push_back(Vector3(0.2f, 0.0f, 0.0f));
	shadeProfile.push_back(Vector3(0.2f, 5.0f, 0.0f));
	shadeProfile.push_back(Vector3(0.1f, 5.0f, 0.0f));
	shadeProfile.push_back(Vector3(0.1f, 0.3f, 0.0f));
	shadeProfile.push_back(Vector3(0.0f, 0.3f, 0.0f));
	SweepPath shadepath;
	Transform t;
	shadepath.makeCirclePath(0, 12);
	barrel1 = new GameObject(app);
	barrel1->setMesh(new Sweep(shadeProfile, shadepath, true));
	barrel1->getTransform()->setLocalPosition(Vector3(-0.5, 0.1, 0));
	barrel1->getTransform()->setParent(rotar->getTransform()); 
	barrel1->getTransform()->name = "barrel1";
	barrel2 = new GameObject(app);
	barrel2->setMesh(new Sweep(shadeProfile, shadepath, true));
	barrel2->getTransform()->setLocalPosition(Vector3(0.5, 0.1, 0)); 
	barrel2->getTransform()->setParent(rotar->getTransform()); 
	barrel2->getTransform()->name = "barrel2";
	barrel3 = new GameObject(app);
	barrel3->setMesh(new Sweep(shadeProfile, shadepath, true));
	barrel3->getTransform()->setLocalPosition(Vector3(0.05, 0.1, 0.5)); 
	barrel3->getTransform()->setParent(rotar->getTransform());
	barrel3->getTransform()->name = "barrel3";
	barrel4 = new GameObject(app);
	barrel4->setMesh(new Sweep(shadeProfile, shadepath, true));
	barrel4->getTransform()->setLocalPosition(Vector3(-0.5, 0.1, 0.5)); 
	barrel4->getTransform()->setParent(rotar->getTransform()); 
	barrel4->getTransform()->name = "barrel4";
	barrel5 = new GameObject(app);
	barrel5->setMesh(new Sweep(shadeProfile, shadepath, true));
	barrel5->getTransform()->setLocalPosition(Vector3(0.5, 0.1, -0.5)); 
	barrel5->getTransform()->setParent(rotar->getTransform()); 
	barrel5->getTransform()->name = "barrel5";
	barrel6 = new GameObject(app);
	barrel6->setMesh(new Sweep(shadeProfile, shadepath, true));
	barrel6->getTransform()->setLocalPosition(Vector3(-0.05, 0.1, -0.5));
	barrel6->getTransform()->setParent(rotar->getTransform()); 
	barrel6->getTransform()->name = "barrel6";
}


Task2Comp::~Task2Comp()
{
}
