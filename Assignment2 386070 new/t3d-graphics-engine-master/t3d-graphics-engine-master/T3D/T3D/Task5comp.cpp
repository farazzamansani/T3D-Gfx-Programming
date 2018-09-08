#include "Task5comp.h"
#include "Transform.h"
#include "Sweep.h"
#include "SweepPath.h"
#include "Cylinder.h"
#include "Pyramid.h"
//This is task 5 composition
// It is a horse , his name is henry the horse
using namespace T3D;
Task5comp::Task5comp(T3DApplication *app) :GameObject(app){
	setMesh(new Cylinder(0, 0, 16));
	getTransform()->name = "task2";

	base = new GameObject(app);
	base->setMesh(new Cylinder(0, 0.2, 16));
	base->getTransform()->setParent(getTransform());
	base->getTransform()->setLocalPosition(Vector3(0, 0.02, 0));
	base->getTransform()->name = "henry";

	//sweep profile
	std::vector<Vector3> shadeProfile;
	shadeProfile.push_back(Vector3(0.0f, -0.65f, 0.0f));
	shadeProfile.push_back(Vector3(0.17f, -0.63f, 0.0f));
	shadeProfile.push_back(Vector3(0.32f, -0.57f, 0.0f));
	shadeProfile.push_back(Vector3(0.49f, -0.39f, 0.0f));
	shadeProfile.push_back(Vector3(0.64, -0.09f, 0.0f));
	shadeProfile.push_back(Vector3(0.56f, 0.08f, 0.0f));
	shadeProfile.push_back(Vector3(0.49f, 0.21f, 0.0f));
	shadeProfile.push_back(Vector3(0.43f, 0.31f, 0.0f));
	shadeProfile.push_back(Vector3(0.15f, 0.39f, 0.0f));
	shadeProfile.push_back(Vector3(-0.15f, 0.39f, 0.0f));
	shadeProfile.push_back(Vector3(-0.43f, 0.31f, 0.0f));
	shadeProfile.push_back(Vector3(-0.49f, 0.21f, 0.0f));
	shadeProfile.push_back(Vector3(-0.56f, 0.08f, 0.0f));
	shadeProfile.push_back(Vector3(-0.64, -0.09f, 0.0f));
	shadeProfile.push_back(Vector3(-0.49f, -0.39f, 0.0f));
	shadeProfile.push_back(Vector3(-0.32f, -0.57f, 0.0f));
	shadeProfile.push_back(Vector3(-0.17f, -0.63f, 0.0f));
	shadeProfile.push_back(Vector3(0.0f, -0.65f, 0.0f));

	SweepPath shadepath;
	Transform t;
	
	t.setLocalPosition(Vector3(-0.01, -0.5, 0));
	t.setLocalScale(Vector3(0, 0, 0));
	t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(0.9, 0.9, 1));
	t.setLocalPosition(Vector3(0.1, -0.5, 0));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(0.2, 0.2, 1));
	t.setLocalPosition(Vector3(0.5, -0.2, 0));
	t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(0.2, 0.2, 1));
	t.setLocalPosition(Vector3(1, 0, 0));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(0.8, 0.8, 1));
	t.setLocalPosition(Vector3(1.1, -0.2, 0));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(0.9, 0.9, 1));
	t.setLocalPosition(Vector3(1.5, -0.2, 0));
	shadepath.addTransform(t);
	t.setLocalScale(Vector3(0.8, 0.8, 1));
	t.setLocalPosition(Vector3(2, -0.2, 0));
	shadepath.addTransform(t);
	t.setLocalScale(Vector3(0.6, 0.6, 1));
	t.setLocalPosition(Vector3(2.5, -0.22, 0));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(1, 1, 1));
	t.setLocalPosition(Vector3(3, -0.2, 0));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(1.4, 1.4, 1));
	t.setLocalPosition(Vector3(3.5, 0.1, 0));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(1.4, 1.4, 1));
	t.setLocalPosition(Vector3(4, 0.3, 0));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(1, 1, 1));
	t.setLocalPosition(Vector3(4.2, 0.4, 0));
	shadepath.addTransform(t);

	t.setLocalScale(Vector3(0, 0, 0));
	t.setLocalPosition(Vector3(4.4, 0.4, 0));
	shadepath.addTransform(t);

	pathobj = new GameObject(app);
	pathobj->setMesh(new Sweep(shadeProfile, shadepath, false));
	pathobj->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
	pathobj->getTransform()->setParent(base->getTransform()); 
	pathobj->getTransform()->name = "taskfive";

	SweepPath legpathbl1;
	Transform l;

	l.setLocalPosition(Vector3(-0.01, 0, 0.5));
	l.setLocalScale(Vector3(0, 0, 0));
	l.setLocalRotation(Quaternion(Vector3(Math::PI / 3, Math::PI / 3, 0)));
	legpathbl1.addTransform(l);

	l.setLocalScale(Vector3(0.3, 0.4, 1));
	l.setLocalPosition(Vector3(0, -0.2, 0.5));
	legpathbl1.addTransform(l);


	l.setLocalScale(Vector3(0.4, 1, 1));
	l.setLocalPosition(Vector3(0.3, -0.8, 0.5));
	legpathbl1.addTransform(l);

	l.setLocalScale(Vector3(0.4, 1.1, 1));
	l.setLocalPosition(Vector3(0.3, -1, 0.5));
	legpathbl1.addTransform(l);

	l.setLocalScale(Vector3(0.3, 0.3, 1));
	l.setLocalPosition(Vector3(0.2, -1.3, 0.5));
	legpathbl1.addTransform(l);

	l.setLocalScale(Vector3(0, 0, 0));
	l.setLocalPosition(Vector3(0.1, -1.4, 0.5));
	legpathbl1.addTransform(l);

	blhipjoint = new GameObject(app);
	blhipjoint->getTransform()->setLocalPosition(Vector3(1.1, 0.1, 0));
	blhipjoint->getTransform()->setParent(base->getTransform());
	blhipjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, Math::PI / 4)));
	blhipjoint->getTransform()->name = "blhipjoint";

	brhipjoint = new GameObject(app);
	brhipjoint->getTransform()->setLocalPosition(Vector3(1.1, 0.1, -0.7));
	brhipjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 4, 0)));
	brhipjoint->getTransform()->setParent(base->getTransform());
	brhipjoint->getTransform()->name = "brhipjoint";

	frhipjoint = new GameObject(app);
	frhipjoint->getTransform()->setLocalPosition(Vector3(3.1, 0.6, -1.2));
	frhipjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, Math::PI / 4)));
	frhipjoint->getTransform()->setParent(base->getTransform());
	frhipjoint->getTransform()->name = "frhipjoint";

	flhipjoint = new GameObject(app);
	flhipjoint->getTransform()->setLocalPosition(Vector3(3.1, 0.6, 0.3));
	flhipjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, Math::PI / 4)));
	flhipjoint->getTransform()->setParent(base->getTransform());
	flhipjoint->getTransform()->name = "flhipjoint";

	backleftleg1 = new GameObject(app);
	backleftleg1->setMesh(new Sweep(shadeProfile, legpathbl1, false));
	backleftleg1->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	backleftleg1->getTransform()->setParent(blhipjoint->getTransform());
	backleftleg1->getTransform()->name = "leg1";

	backrightleg1 = new GameObject(app);
	backrightleg1->setMesh(new Sweep(shadeProfile, legpathbl1, false));
	backrightleg1->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	backrightleg1->getTransform()->setParent(brhipjoint->getTransform());
	backrightleg1->getTransform()->name = "leg2";

	frontrightleg1 = new GameObject(app);
	frontrightleg1->setMesh(new Sweep(shadeProfile, legpathbl1, false));
	frontrightleg1->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	frontrightleg1->getTransform()->setParent(frhipjoint->getTransform());
	frontrightleg1->getTransform()->name = "leg3";

	frontleftleg1 = new GameObject(app);
	frontleftleg1->setMesh(new Sweep(shadeProfile, legpathbl1, false));
	frontleftleg1->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	frontleftleg1->getTransform()->setParent(flhipjoint->getTransform());
	frontleftleg1->getTransform()->name = "leg4";

	SweepPath legpathbl2;
	Transform l2;

	l2.setLocalPosition(Vector3(-0.01, 0, 0.5));
	l2.setLocalScale(Vector3(0, 0, 0));
	l2.setLocalRotation(Quaternion(Vector3(Math::PI / 3, Math::PI / 3, 0)));
	legpathbl2.addTransform(l2);

	l2.setLocalScale(Vector3(0.2, 0.3, 1));
	l2.setLocalPosition(Vector3(-0.1, -0.1, 0.5));
	legpathbl2.addTransform(l2);

	l2.setLocalScale(Vector3(0.2, 0.3, 1));
	l2.setLocalPosition(Vector3(-0.1, -0.3, 0.5));
	legpathbl2.addTransform(l2);

	l2.setLocalScale(Vector3(0.2, 0.3, 1));
	l2.setLocalPosition(Vector3(-0.3, -0.7, 0.5));
	legpathbl2.addTransform(l2);

	l2.setLocalScale(Vector3(0.1, 0.2, 1));
	l2.setLocalPosition(Vector3(-0.3, -0.8, 0.5));
	legpathbl2.addTransform(l2);

	l2.setLocalScale(Vector3(0, 0, 1));
	l2.setLocalPosition(Vector3(-0.3, -0.9, 0.5));
	legpathbl2.addTransform(l2);

	blkneejoint = new GameObject(app);
	blkneejoint->getTransform()->setLocalPosition(Vector3(0, -1.25, -0.1));
	blkneejoint->getTransform()->setParent(backleftleg1->getTransform());
	blkneejoint->getTransform()->name = "blkneejoint";

	brkneejoint = new GameObject(app);
	brkneejoint->getTransform()->setLocalPosition(Vector3(0, -1.25, -0.1));
	brkneejoint->getTransform()->setParent(backrightleg1->getTransform());
	brkneejoint->getTransform()->name = "brkneejoint";

	flkneejoint = new GameObject(app);
	flkneejoint->getTransform()->setLocalPosition(Vector3(0, -1.25, -0.1));
	flkneejoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, Math::PI / 4)));
	flkneejoint->getTransform()->setParent(frontleftleg1->getTransform());
	flkneejoint->getTransform()->name = "flkneejoint";

	frkneejoint = new GameObject(app);
	frkneejoint->getTransform()->setLocalPosition(Vector3(0, -1.25, -0.1));

	frkneejoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, -Math::PI / 4)));
	frkneejoint->getTransform()->setParent(frontrightleg1->getTransform());
	frkneejoint->getTransform()->name = "frkneejoint";

	backleftleg2 = new GameObject(app);
	backleftleg2->setMesh(new Sweep(shadeProfile, legpathbl2, false));
	backleftleg2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	backleftleg2->getTransform()->setParent(blkneejoint->getTransform());
	backleftleg2->getTransform()->name = "blleg2";

	backrightleg2 = new GameObject(app);
	backrightleg2->setMesh(new Sweep(shadeProfile, legpathbl2, false));
	backrightleg2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	backrightleg2->getTransform()->setParent(brkneejoint->getTransform());
	backrightleg2->getTransform()->name = "brleg2";

	frontleftleg2 = new GameObject(app);
	frontleftleg2->setMesh(new Sweep(shadeProfile, legpathbl2, false));
	frontleftleg2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	frontleftleg2->getTransform()->setParent(flkneejoint->getTransform());
	frontleftleg2->getTransform()->name = "flleg2";

	frontrightleg2 = new GameObject(app);
	frontrightleg2->setMesh(new Sweep(shadeProfile, legpathbl2, false));
	frontrightleg2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	frontrightleg2->getTransform()->setParent(frkneejoint->getTransform());
	frontrightleg2->getTransform()->name = "frleg2";

	SweepPath legpathbl3;
	Transform l3;

	l3.setLocalPosition(Vector3(-0.01, 0, 0));
	l3.setLocalScale(Vector3(0, 0, 0));
	l3.setLocalRotation(Quaternion(Vector3(Math::PI / 3, Math::PI / 3, 0)));
	legpathbl3.addTransform(l3);

	l3.setLocalScale(Vector3(0.2, 0.3, 1));
	l3.setLocalPosition(Vector3(-0.1, -0.1, 0));
	legpathbl3.addTransform(l3);

	l3.setLocalScale(Vector3(0.2, 0.3, 1));
	l3.setLocalPosition(Vector3(-0.2, -0.6, 0));
	legpathbl3.addTransform(l3);

	l3.setLocalScale(Vector3(0.3, 0.4, 1));
	l3.setLocalPosition(Vector3(-0.18, -0.6, 0));
	legpathbl3.addTransform(l3);

	l3.setLocalScale(Vector3(0.4, 0.5, 1));
	l3.setLocalPosition(Vector3(-0.18, -0.8, 0));
	l3.setLocalRotation(Quaternion(Vector3(Math::PI / 3, 0, 0)));
	legpathbl3.addTransform(l3);


	l3.setLocalScale(Vector3(0, 0, 1));
	l3.setLocalPosition(Vector3(-0.18, -0.8, 0));
	legpathbl3.addTransform(l3);

	blfootjoint = new GameObject(app);
	blfootjoint->getTransform()->setLocalPosition(Vector3(-0.2, -0.7, 0.5));
	blfootjoint->getTransform()->setParent(backleftleg2->getTransform());
	blfootjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, -Math::PI / 4)));
	blfootjoint->getTransform()->name = "blfootjoint";

	brfootjoint = new GameObject(app);
	brfootjoint->getTransform()->setLocalPosition(Vector3(-0.3, -0.7, 0.5));
	brfootjoint->getTransform()->setParent(backrightleg2->getTransform());
	brfootjoint->getTransform()->name = "brfootjoint";

	frfootjoint = new GameObject(app);
	frfootjoint->getTransform()->setLocalPosition(Vector3(-0.2, -0.8, 0.5));
	frfootjoint->getTransform()->setParent(frontrightleg2->getTransform());
	frfootjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, -Math::PI / 4)));
	frfootjoint->getTransform()->name = "frfootjoint";


	flfootjoint = new GameObject(app);
	flfootjoint->getTransform()->setLocalPosition(Vector3(-0.2, -0.8, 0.5));
	flfootjoint->getTransform()->setParent(frontleftleg2->getTransform());
	flfootjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, -Math::PI / 2)));
	flfootjoint->getTransform()->name = "flfootjoint";


	backleftleg3 = new GameObject(app);
	backleftleg3->setMesh(new Sweep(shadeProfile, legpathbl3, false));
	backleftleg3->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	backleftleg3->getTransform()->setParent(blfootjoint->getTransform());
	backleftleg3->getTransform()->name = "blleg3";

	backrightleg3 = new GameObject(app);
	backrightleg3->setMesh(new Sweep(shadeProfile, legpathbl3, false));
	backrightleg3->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	backrightleg3->getTransform()->setParent(brfootjoint->getTransform());
	backrightleg3->getTransform()->name = "brleg3";

	frontleftleg3 = new GameObject(app);
	frontleftleg3->setMesh(new Sweep(shadeProfile, legpathbl3, false));
	frontleftleg3->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	frontleftleg3->getTransform()->setParent(flfootjoint->getTransform());
	frontleftleg3->getTransform()->name = "flleg3";

	frontrightleg3 = new GameObject(app);
	frontrightleg3->setMesh(new Sweep(shadeProfile, legpathbl3, false));
	frontrightleg3->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	frontrightleg3->getTransform()->setParent(frfootjoint->getTransform());
	frontrightleg3->getTransform()->name = "frleg3";

	SweepPath neckpath;
	Transform n;

	n.setLocalPosition(Vector3(-0.01, 0, 0));
	n.setLocalScale(Vector3(0, 0, 0));
	n.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	neckpath.addTransform(n);

	n.setLocalScale(Vector3(0.8, 1, 1));
	n.setLocalPosition(Vector3(0.1, 0.1, 0));
	neckpath.addTransform(n);

	n.setLocalScale(Vector3(0.8, 1, 1));
	n.setLocalPosition(Vector3(1, 1, 0));
	neckpath.addTransform(n);


	n.setLocalScale(Vector3(0, 0, 1));
	n.setLocalPosition(Vector3(1.3, 1.1, 0));
	neckpath.addTransform(n);

	neckjoint = new GameObject(app);
	neckjoint->getTransform()->setLocalPosition(Vector3(4, 0.3 , 0));
	neckjoint->getTransform()->setParent(base->getTransform());
	neckjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));
	neckjoint->getTransform()->name = "neckjoint";

	neck = new GameObject(app);
	neck->setMesh(new Sweep(shadeProfile, neckpath, false));
	neck->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	neck->getTransform()->setParent(neckjoint->getTransform());
	neck->getTransform()->name = "neck";

	SweepPath headpath;
	Transform h;

	h.setLocalPosition(Vector3(-0.01, 0, 0));
	h.setLocalScale(Vector3(0, 0, 0));
	h.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	headpath.addTransform(h);

	h.setLocalScale(Vector3(0.7, 0.8, 1));
	h.setLocalPosition(Vector3(0.1, 0.1, 0));
	headpath.addTransform(h);

	h.setLocalScale(Vector3(0.7, 0.8, 1));
	h.setLocalPosition(Vector3(0.6, 0.1, 0));
	headpath.addTransform(h);

	h.setLocalScale(Vector3(0.4, 0.5, 1));
	h.setLocalPosition(Vector3(1.5, -0.1, 0));
	headpath.addTransform(h);

	h.setLocalScale(Vector3(0.4, 0.5, 1));
	h.setLocalPosition(Vector3(1.7, -0.1, 0));
	headpath.addTransform(h);

	h.setLocalScale(Vector3(0.3, 0.4, 1));
	h.setLocalPosition(Vector3(1.8, -0.1, 0));
	headpath.addTransform(h);

	h.setLocalScale(Vector3(0, 0, 1));
	h.setLocalPosition(Vector3(1.85, -0.1, 0));
	headpath.addTransform(h);


	headjoint = new GameObject(app);
	headjoint->getTransform()->setLocalPosition(Vector3(1, 1, 0));
	headjoint->getTransform()->setParent(neck->getTransform());
	headjoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));
	headjoint->getTransform()->name = "headjoint";

	head = new GameObject(app);
	head->setMesh(new Sweep(shadeProfile, headpath, false));
	head->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	head->getTransform()->setParent(headjoint->getTransform());
	head->getTransform()->name = "head";


	earl = new GameObject(app); 
	earl->setMesh(new Pyramid(0.2));
	earl->getTransform()->setParent(head->getTransform()); 
	earl->getTransform()->setLocalPosition(Vector3(0.2, 0.4, 0.4));
	earl->getTransform()->setLocalScale(Vector3(0.4, 1.2, 1.2));
	earl->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	earl->getTransform()->name = "left ear";

	earr = new GameObject(app); 
	earr->setMesh(new Pyramid(0.2));
	earr->getTransform()->setParent(head->getTransform()); 
	earr->getTransform()->setLocalPosition(Vector3(0.2, 0.4, -0.4));
	earr->getTransform()->setLocalScale(Vector3(0.4, 1.2, 1.2));
	earr->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 4, 0, 0)));
	earr->getTransform()->name = "right ear";




}


Task5comp::~Task5comp()
{
}
