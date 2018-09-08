#include "Assignment2Test.H"
#include "Camera.h"
#include "KeyboardController.h"
#include "TerrainFollower.h"
#include "RotateBehaviour.h"
#include "LookAtBehaviour.h"
#include "Terrain.h"
#include "ParticleEmitter.h"
#include "ParticleBehaviour.h"
#include "Cube.h"
#include "TCube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "TCylinder.h"
#include "Lamp.h"
#include "Task1sweep.h"
#include "Task2Comp.h"
#include "propeller.h"
#include "Task5comp.h"
#include "AnimationTest.h"
#include "Animation.h"
#include "Billboard.h"
#include "barrel.h"

using namespace T3D;
Assignment2Test::Assignment2Test()
{
}


Assignment2Test::~Assignment2Test()
{
}

bool Assignment2Test::init() {
	WinGLApplication::init();

	AnimationTest *cat = new AnimationTest(this);
	addTask(cat);
	
	//Create a skybox and add some fog
	renderer->loadSkybox("Resources/Sunny1");
	renderer->setFog(0.009f, 0.8f, 0.8f, 0.8f, 1.0f);
	renderer->toggleFog();

	//add light
	GameObject *lightObj = new GameObject(this);
	Light *light = new Light(Light::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	lightObj->getTransform()->
		setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
	lightObj->getTransform()->setParent(root);

	//Next add a camera and camera controller:
	GameObject *camObj = new GameObject(this);
	renderer->camera =
		new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());
	camObj->getTransform()->name = "camy";

	//And a Material:
	Material *green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);
	Material *red = renderer->createMaterial(Renderer::PR_OPAQUE);
	red->setDiffuse(1, 0, 0, 1);
	Material *black = renderer->createMaterial(Renderer::PR_OPAQUE);
	black->setDiffuse(0.1, 0.1, 0.1, 1);
	Material *grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0.8, 0.8, 0.9, 1);
	grey->setShininess(88);

	//Create a textured material by adding text
	Texture *texttex = new Texture(128, 32);
	texttex->clear(Colour(255, 255, 255, 255));
	font *f = getFont("resources/FreeSans.ttf", 24);
	if (f != NULL) {
		texttex->writeText(8, 0, "By Faraz", Colour(0, 255, 0, 255), f->getFont());
	}
	renderer->loadTexture(texttex, true);
	Material *textmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	textmat->setTexture(texttex, 1);
	textmat->setEmissive(1, 1, 1, 1);

	//Add a welcome message
	GameObject *billboard = new GameObject(this);
	Billboard *billboardComponent = new Billboard(renderer->camera->gameObject->getTransform(), true);
	billboard->addComponent(billboardComponent);
	billboard->setMaterial(textmat);			
	billboard->getTransform()->setLocalPosition(Vector3(0, 3, 0));
	billboard->getTransform()->setLocalScale(Vector3(6, 1.5, 1));
	billboard->getTransform()->setLocalRotation(Vector3(Math::PI / 2, 0, 0));
	billboard->getTransform()->setParent(root);
	billboard->getTransform()->name = "Billboard";
	
	//a custom sword sweep
	Task1sweep *task1 = new Task1sweep(this);
	task1->setMaterial(grey);
	task1->getTransform()->setLocalPosition(Vector3(5, 0, 0));
	task1->getTransform()->setParent(root);
	task1->base->setMaterial(grey);
	task1->pathobj->setMaterial(grey);

	//minigun composite object
	Task2Comp *task2 = new Task2Comp(this);
	task2->setMaterial(grey);
	task2->getTransform()->setLocalPosition(Vector3(-5, 0, 0));
	task2->getTransform()->setParent(root);
	task2->base->setMaterial(grey);
	task2->support->setMaterial(grey);
	task2->supportm1->setMaterial(grey);
	task2->supportm2->setMaterial(grey);
	task2->rotar->setMaterial(grey);
	task2->bulk->setMaterial(grey);
	task2->bulk2->setMaterial(grey);
	task2->bulk3->setMaterial(grey);
	task2->triggerhandle->setMaterial(black);
	task2->handlel->setMaterial(grey);
	task2->handler->setMaterial(grey);
	task2->handlebridge->setMaterial(black);
	task2->trigger->setMaterial(red);
	task2->barrel1->setMaterial(grey);
	task2->barrel2->setMaterial(grey);
	task2->barrel3->setMaterial(grey);
	task2->barrel4->setMaterial(grey);
	task2->barrel5->setMaterial(grey);
	task2->barrel6->setMaterial(grey);
	task2->ammo->setMaterial(grey);
	task2->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, Math::PI / 3, Math::PI / 1)));
	
	Task5comp *task5 = new Task5comp(this);
	task5->setMaterial(black);
	task5->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	task5->getTransform()->setParent(root);
	task5->pathobj->setMaterial(black);
	task5->backleftleg1->setMaterial(black);
	task5->backrightleg1->setMaterial(black);
	task5->backleftleg2->setMaterial(black);
	task5->backrightleg2->setMaterial(black);
	task5->backleftleg3->setMaterial(black);
	task5->backrightleg3->setMaterial(black);
	task5->frontrightleg1->setMaterial(black);
	task5->frontleftleg1->setMaterial(black);
	task5->frontleftleg2->setMaterial(black);
	task5->frontrightleg2->setMaterial(black);
	task5->frontleftleg3->setMaterial(black);
	task5->frontrightleg3->setMaterial(black);
	task5->neck->setMaterial(black);
	task5->head->setMaterial(black);
	task5->earl->setMaterial(black);
	task5->earr->setMaterial(black);

	Task5comp *horse2 = new Task5comp(this);
	horse2->setMaterial(black);
	horse2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	horse2->getTransform()->setParent(root);
	horse2->pathobj->setMaterial(black);
	horse2->backleftleg1->setMaterial(black);
	horse2->backrightleg1->setMaterial(black);
	horse2->backleftleg2->setMaterial(black);
	horse2->backrightleg2->setMaterial(black);
	horse2->backleftleg3->setMaterial(black);
	horse2->backrightleg3->setMaterial(black);
	horse2->frontrightleg1->setMaterial(black);
	horse2->frontleftleg1->setMaterial(black);
	horse2->frontleftleg2->setMaterial(black);
	horse2->frontrightleg2->setMaterial(black);
	horse2->frontleftleg3->setMaterial(black);
	horse2->frontrightleg3->setMaterial(black);
	horse2->neck->setMaterial(black);
	horse2->head->setMaterial(black);
	horse2->earl->setMaterial(black);
	horse2->earr->setMaterial(black);


	Task5comp *horse3 = new Task5comp(this);
	horse3->setMaterial(black);
	horse3->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	horse3->getTransform()->setParent(root);
	horse3->pathobj->setMaterial(black);
	horse3->backleftleg1->setMaterial(black);
	horse3->backrightleg1->setMaterial(black);
	horse3->backleftleg2->setMaterial(black);
	horse3->backrightleg2->setMaterial(black);
	horse3->backleftleg3->setMaterial(black);
	horse3->backrightleg3->setMaterial(black);
	horse3->frontrightleg1->setMaterial(black);
	horse3->frontleftleg1->setMaterial(black);
	horse3->frontleftleg2->setMaterial(black);
	horse3->frontrightleg2->setMaterial(black);
	horse3->frontleftleg3->setMaterial(black);
	horse3->frontrightleg3->setMaterial(black);
	horse3->neck->setMaterial(black);
	horse3->head->setMaterial(black);
	horse3->earl->setMaterial(black);
	horse3->earr->setMaterial(black);

	Animation *anim = new Animation(1.0);
	cat->blah = anim;
	task5->addComponent(anim);
	anim->addKey("blhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, -0.7));
	anim->addKey("blhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, -0.7));
	anim->addKey("blhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI/3)), Vector3(1.2, 0.3, -0.7));
	anim->addKey("blhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI/3.3)), Vector3(1.2, 0, -0.7));
	anim->addKey("brhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, 0));
	anim->addKey("brhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, 0));
	anim->addKey("brhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI/2.8)), Vector3(1.2, 0.3, 0));
	anim->addKey("brhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI/3)), Vector3(1.2, 0, 0));
	anim->addKey("blkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim->addKey("blkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim->addKey("blkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim->addKey("blkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim->addKey("brkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim->addKey("brkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim->addKey("brkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim->addKey("brkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim->addKey("blfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("blfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("blfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("blfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("brfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("brfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("brfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("brfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI/2)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("flhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, -0.7));
	anim->addKey("flhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, -0.7));
	anim->addKey("flhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 10)), Vector3(3.1, 0.3, -0.7));
	anim->addKey("flhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 1)), Vector3(3.1, 0, -0.7));
	anim->addKey("frhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, 0));
	anim->addKey("frhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, 0));
	anim->addKey("frhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 10)), Vector3(3.1, 0.3, 0));
	anim->addKey("frhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 1.5)), Vector3(3.1, 0, 0));
	anim->addKey("flkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim->addKey("flkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim->addKey("flkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim->addKey("flkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim->addKey("frkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim->addKey("frkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim->addKey("frkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim->addKey("frkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim->addKey("flfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("flfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("flfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("flfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 1)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("frfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("frfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("frfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("frfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 1)), Vector3(-0.2, -0.7, 0.5));
	anim->addKey("neckjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(4, 0.3, 0));
	anim->addKey("neckjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(4, 0.3, 0));
	anim->addKey("neckjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(4, 0.3, 0));
	anim->addKey("headjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1, 1, 0));
	anim->addKey("headjoint", 0.6, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(1, 1, 0));
	anim->addKey("headjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1, 1, 0));
	anim->loop(true);
	anim->play();

	Animation *anim2 = new Animation(1.0);
	horse2->addComponent(anim2);
	anim2->addKey("blhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, -0.7));
	anim2->addKey("blhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, -0.7));
	anim2->addKey("blhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(1.2, 0.3, -0.7));
	anim2->addKey("blhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3.3)), Vector3(1.2, 0, -0.7));
	anim2->addKey("brhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, 0));
	anim2->addKey("brhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, 0));
	anim2->addKey("brhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2.8)), Vector3(1.2, 0.3, 0));
	anim2->addKey("brhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(1.2, 0, 0));
	anim2->addKey("blkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim2->addKey("blkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim2->addKey("blkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim2->addKey("blkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim2->addKey("brkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim2->addKey("brkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim2->addKey("brkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim2->addKey("brkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim2->addKey("blfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("blfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("blfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("blfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("brfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("brfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("brfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("brfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("flhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, -0.7));
	anim2->addKey("flhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, -0.7));
	anim2->addKey("flhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 10)), Vector3(3.1, 0.3, -0.7));
	anim2->addKey("flhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 1)), Vector3(3.1, 0, -0.7));
	anim2->addKey("frhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, 0));
	anim2->addKey("frhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, 0));
	anim2->addKey("frhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 10)), Vector3(3.1, 0.3, 0));
	anim2->addKey("frhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 1.5)), Vector3(3.1, 0, 0));
	anim2->addKey("flkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim2->addKey("flkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim2->addKey("flkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim2->addKey("flkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim2->addKey("frkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim2->addKey("frkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim2->addKey("frkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim2->addKey("frkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim2->addKey("flfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("flfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("flfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("flfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 1)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("frfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("frfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("frfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("frfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 1)), Vector3(-0.2, -0.7, 0.5));
	anim2->addKey("neckjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(4, 0.3, 0));
	anim2->addKey("neckjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(4, 0.3, 0));
	anim2->addKey("neckjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(4, 0.3, 0));
	anim2->addKey("headjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1, 1, 0));
	anim2->addKey("headjoint", 0.6, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(1, 1, 0));
	anim2->addKey("headjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1, 1, 0));
	anim2->loop(true);
	anim2->play();

	Animation *anim3 = new Animation(1.0);
	horse3->addComponent(anim3);
	anim3->addKey("blhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, -0.7));
	anim3->addKey("blhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, -0.7));
	anim3->addKey("blhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(1.2, 0.3, -0.7));
	anim3->addKey("blhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3.3)), Vector3(1.2, 0, -0.7));
	anim3->addKey("brhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, 0));
	anim3->addKey("brhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, 0));
	anim3->addKey("brhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2.8)), Vector3(1.2, 0.3, 0));
	anim3->addKey("brhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(1.2, 0, 0));
	anim3->addKey("blkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim3->addKey("blkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim3->addKey("blkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim3->addKey("blkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim3->addKey("brkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim3->addKey("brkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim3->addKey("brkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim3->addKey("brkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(0, -1.25, -0.1));
	anim3->addKey("blfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("blfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("blfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("blfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("brfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("brfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("brfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("brfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("flhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, -0.7));
	anim3->addKey("flhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, -0.7));
	anim3->addKey("flhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 10)), Vector3(3.1, 0.3, -0.7));
	anim3->addKey("flhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 1)), Vector3(3.1, 0, -0.7));
	anim3->addKey("frhipjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, 0));
	anim3->addKey("frhipjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(3.1, 0, 0));
	anim3->addKey("frhipjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 10)), Vector3(3.1, 0.3, 0));
	anim3->addKey("frhipjoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 1.5)), Vector3(3.1, 0, 0));
	anim3->addKey("flkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim3->addKey("flkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim3->addKey("flkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim3->addKey("flkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim3->addKey("frkneejoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim3->addKey("frkneejoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, -1.25, -0.1));
	anim3->addKey("frkneejoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim3->addKey("frkneejoint", 0.3, Quaternion(Vector3(0, 0, Math::HALF_PI / 2)), Vector3(0, -1.25, -0.1));
	anim3->addKey("flfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("flfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("flfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("flfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 1)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("frfootjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("frfootjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("frfootjoint", 0.6, Quaternion(Vector3(0, 0, 0)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("frfootjoint", 0.3, Quaternion(Vector3(0, 0, -Math::HALF_PI / 1)), Vector3(-0.2, -0.7, 0.5));
	anim3->addKey("neckjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(4, 0.3, 0));
	anim3->addKey("neckjoint", 0.6, Quaternion(Vector3(0, 0, -Math::HALF_PI / 3)), Vector3(4, 0.3, 0));
	anim3->addKey("neckjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(4, 0.3, 0));
	anim3->addKey("headjoint", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(1, 1, 0));
	anim3->addKey("headjoint", 0.6, Quaternion(Vector3(0, 0, Math::HALF_PI / 3)), Vector3(1, 1, 0));
	anim3->addKey("headjoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(1, 1, 0));
	anim3->loop(true);
	anim3->play();


	Animation *animgun = new Animation(0.3);
	task2->addComponent(animgun);
	animgun->addKey("rotar", 0.3, Quaternion(Vector3(Math::PI / 2, Math::PI, Math::PI / 2)), Vector3(0,0.02,0));
	animgun->addKey("rotar", 0.0, Quaternion(Vector3(Math::PI / 2, Math::PI , Math::PI )), Vector3(0, 0.02, 0));
	animgun->loop(true);
	animgun->play();


	Animation *horse1 = new Animation(60.0);
	task5->addComponent(horse1);
	horse1->addKey("henry", 0.0, Quaternion(Vector3(0, 0, 0)), Vector3(1.2, 0, -0.7));
	horse1->addKey("henry", 3.0, Quaternion(Vector3(0, 0, 0)), Vector3(14, 0, -0.7));
	horse1->addKey("henry", 3.4, Quaternion(Vector3(0, Math::PI, 0)), Vector3(14.3, 0, -0.7));
	horse1->addKey("henry", 6.0, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-1, 0, -0.7));
	horse1->addKey("henry", 6.3, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-2, 1, -0.7));
	horse1->addKey("henry", 6.6, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-4, 0, -0.7));
	horse1->addKey("henry", 7.6, Quaternion(Vector3(0, Math::PI / 2.2, 0)), Vector3(-4.3, 0, -8));
	horse1->addKey("henry", 7.8, Quaternion(Vector3(0, 0, 0)), Vector3(-4.3, 0, -8));
	horse1->addKey("henry", 9.0, Quaternion(Vector3(0, 0, 0)), Vector3(14, 0, -8));
	horse1->addKey("henry", 9.2, Quaternion(Vector3(0, Math::PI / 2.2, 0)), Vector3(14, 0, -8));
	horse1->addKey("henry", 12.2, Quaternion(Vector3(0, Math::PI / 2.2, 0)), Vector3(14, 0, -16));
	horse1->addKey("henry", 12.5, Quaternion(Vector3(0, Math::PI, 0)), Vector3(14, 0, -16));
	horse1->addKey("henry", 15, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-5, 0, -16.3));
	horse1->addKey("henry", 15.2, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(-5, 0, -16.3));
	horse1->addKey("henry", 19.2, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(-5, 0, 3));
	horse1->addKey("henry", 19.4, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-5, 0, 3));
	horse1->addKey("henry", 19.8, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-8, 3, 3));
	horse1->addKey("henry", 20.2, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-12, 0, 3));
	horse1->addKey("henry", 23.2, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-25, 0, 3));
	horse1->addKey("henry", 23.5, Quaternion(Vector3(0, Math::PI/1.5, 0)), Vector3(-25, 0, 3));
	horse1->addKey("henry", 24, Quaternion(Vector3(0, Math::PI / 1.5, 0)), Vector3(-29, 0, -6));
	horse1->addKey("henry", 24.3, Quaternion(Vector3(0, Math::PI / 3, 0)), Vector3(-29, 0, -6));
	horse1->addKey("henry", 27.3, Quaternion(Vector3(0, Math::PI / 3, 0)), Vector3(-15, 0, -15));
	horse1->addKey("henry", 27.5, Quaternion(Vector3(0, -Math::PI / 2, 0)), Vector3(-15, 0, -15));
	horse1->addKey("henry", 30.5, Quaternion(Vector3(0, -Math::PI / 2, 0)), Vector3(-15, 0, 15));
	horse1->addKey("henry", 30.8, Quaternion(Vector3(0, -Math::PI / 3, 0)), Vector3(-15, 0, 15.5));
	horse1->addKey("henry", 31.8, Quaternion(Vector3(0, -Math::PI / 3, 0)), Vector3(-10, 0, 20));
	horse1->addKey("henry", 32.1, Quaternion(Vector3(0, -Math::PI / 3, Math::PI / 6)), Vector3(-10, 0, 20));
	horse1->addKey("henry", 34.1, Quaternion(Vector3(0, -Math::PI / 3, Math::PI / 6)), Vector3(-6, 6, 24));
	horse1->addKey("henry", 34.3, Quaternion(Vector3(0, 0, 0)), Vector3(-6, 6, 24));
	horse1->addKey("henry", 36.5, Quaternion(Vector3(0, 0, 0)), Vector3(4, 0, 24));
	horse1->addKey("henry", 37.5, Quaternion(Vector3(0, 0, 0)), Vector3(14, 0, 24));
	horse1->addKey("henry", 37.7, Quaternion(Vector3(0, Math::PI / 2.2, 0)), Vector3(14, 0, 24));
	horse1->addKey("henry", 42, Quaternion(Vector3(0, Math::PI / 2.2, 0)), Vector3(14, 0, -30));
	horse1->addKey("henry", 42.3, Quaternion(Vector3(0, Math::PI, 0)), Vector3(14, 0, -30));
	horse1->addKey("henry", 44.3, Quaternion(Vector3(0, Math::PI, 0)), Vector3(-28, 0, -30));
	horse1->addKey("henry", 44.5, Quaternion(Vector3(0, -Math::PI/2, 0)), Vector3(-28, 0, -30));
	horse1->addKey("henry", 47.5, Quaternion(Vector3(0, -Math::PI / 2, 0)), Vector3(-28, 0, 32));
	horse1->addKey("henry", 47.7, Quaternion(Vector3(0, 0, 0)), Vector3(-28, 0, 33));
	horse1->addKey("henry", 50, Quaternion(Vector3(0, 0, 0)), Vector3(29, 0, 33));
	horse1->addKey("henry", 50.2, Quaternion(Vector3(0, Math::PI / 2.2, 0)), Vector3(29.5, 0, 33));
	horse1->addKey("henry", 54.2, Quaternion(Vector3(0, Math::PI / 2.2, 0)), Vector3(33, 0, -31));
	horse1->addKey("henry", 54.5, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(33, 0, -31));
	horse1->addKey("henry", 56.5, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(33, 0, -31));
	horse1->addKey("henry", 59.5, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(29.5, 0, 29));
	horse1->loop(false);
	horse1->play();


	Animation *cam1 = new Animation(60.0);
	camObj->addComponent(cam1);
	cam1->addKey("camy", 0.0, Quaternion(Vector3(0, 0,0 )), Vector3(0, 0, 5));//forwards
	cam1->addKey("camy", 3.0, Quaternion(Vector3(0, -1, 0)), Vector3(0, 0, 2));//right
	cam1->addKey("camy", 5.0, Quaternion(Vector3(0, -1, 0)), Vector3(7, 0, 2));//right
	cam1->addKey("camy", 5.4, Quaternion(Vector3(0, -1, 0)), Vector3(8, 0, 4));//right
	cam1->addKey("camy", 8.0, Quaternion(Vector3(0, 1, 0)), Vector3(-1, 0, 2));//left

	cam1->addKey("camy", 8.3, Quaternion(Vector3(0, 1, 0)), Vector3(-2, 1, 2)); //jump

	cam1->addKey("camy", 8.6, Quaternion(Vector3(0, 1, 0)), Vector3(-4, 0, 2));//left
	cam1->addKey("camy", 9.6, Quaternion(Vector3(0, -2, 0)), Vector3(-4.3, 0, -5));//forwards

	cam1->addKey("camy", 9.8, Quaternion(Vector3(0, -1, 0)), Vector3(-4.3, 0, -5));//forwards

	cam1->addKey("camy", 12.0, Quaternion(Vector3(0, -1, 0)), Vector3(14, 0, -5));//right
	cam1->addKey("camy", 12.2, Quaternion(Vector3(0, -1, 0)), Vector3(14, 0, -5));//right

	cam1->addKey("camy", 14.2, Quaternion(Vector3(0, 1.5, 0)), Vector3(14, 0, -16));//forwards

	cam1->addKey("camy", 14.5, Quaternion(Vector3(0, 1.5, 0)), Vector3(14, 0, -16));//left

	cam1->addKey("camy", 17, Quaternion(Vector3(0, 1.5, 0)), Vector3(-5, 0, -16.3));//left

	cam1->addKey("camy", 18.2, Quaternion(Vector3(0,-3.5, 0)), Vector3(-5, 0, -16.3));//backwards

	cam1->addKey("camy", 21.2, Quaternion(Vector3(0, -3.5, 0)), Vector3(-5, 0, 3));//backwards

	
	
	cam1->addKey("camy", 21.8, Quaternion(Vector3(0, 1.5, 0)), Vector3(-8, 3, 3)); //left


	cam1->addKey("camy", 22.2, Quaternion(Vector3(0, 1.5, 0)), Vector3(-12, 0, 3));//left

	cam1->addKey("camy", 25.2, Quaternion(Vector3(0, 1.5, 0)), Vector3(-25, 0, 3));//left


	cam1->addKey("camy", 25.5, Quaternion(Vector3(0, 0.5, 0)), Vector3(-25, 0, 3)); //lefty forward
	cam1->addKey("camy", 26, Quaternion(Vector3(0, 0.5, 0)), Vector3(-29, 0, -6)); //leftforward

	
	cam1->addKey("camy", 26.3, Quaternion(Vector3(0, -0.7, 0)), Vector3(-29, 0, -6)); //right forward
	cam1->addKey("camy", 29.3, Quaternion(Vector3(0, -1, 0)), Vector3(-15, 0, -15)); //right forward


	cam1->addKey("camy", 29.5, Quaternion(Vector3(0, -3, 0)), Vector3(-15, 0, -15)); //backwards
	cam1->addKey("camy", 32.5, Quaternion(Vector3(0, -3, 0)), Vector3(-15, 0, 15)); //backwards

	
	cam1->addKey("camy", 32.8, Quaternion(Vector3(0, -2, 0)), Vector3(-15, 0, 15.5));//right
	cam1->addKey("camy", 33.8, Quaternion(Vector3(0, -2, 0)), Vector3(-10, 0, 20));//right
	cam1->addKey("camy", 34.1, Quaternion(Vector3(0, -2, Math::PI / 6)), Vector3(-10, 0, 20));//right
	cam1->addKey("camy", 36.1, Quaternion(Vector3(0, -1.7, Math::PI / 6)), Vector3(-6, 6, 24));//right
	cam1->addKey("camy", 36.3, Quaternion(Vector3(0, -1.5, 0)), Vector3(-6, 6, 24));//right

	
	cam1->addKey("camy", 38.5, Quaternion(Vector3(0, -1.3, 0)), Vector3(4, 0, 24));//right
	cam1->addKey("camy", 39.5, Quaternion(Vector3(0, -1.3, 0)), Vector3(14, 0, 24));//right

	
	cam1->addKey("camy", 40.7, Quaternion(Vector3(0, 0, 0)), Vector3(14, 0, 24));//forward
	cam1->addKey("camy", 44, Quaternion(Vector3(0, 0, 0)), Vector3(14, 0, -30));//forward

	
	cam1->addKey("camy", 44.3, Quaternion(Vector3(0, 1.5, 0)), Vector3(14, 0, -30));//left
	cam1->addKey("camy", 46.3, Quaternion(Vector3(0, 1.5, 0)), Vector3(-28, 0, -30));//left

	
	cam1->addKey("camy", 46.5, Quaternion(Vector3(0, -3, 0)), Vector3(-28, 0, -30));//backwards
	cam1->addKey("camy", 49.5, Quaternion(Vector3(0, -3, 0)), Vector3(-28, 0, 32));//backwards


	cam1->addKey("camy", 49.7, Quaternion(Vector3(0, -1.7, 0)), Vector3(-28, 0, 33));//right
	
	cam1->addKey("camy", 52, Quaternion(Vector3(0, -1, 0)), Vector3(29, 0, 33));//right
	cam1->addKey("camy", 52.2, Quaternion(Vector3(0, 0, 0)), Vector3(29.5, 0, 33));//forwards

	cam1->addKey("camy", 58.8, Quaternion(Vector3(0, 0, 0)), Vector3(29.5, 0, 33));
	cam1->addKey("camy", 60.0, Quaternion(Vector3(0, 0, 3)), Vector3(29.5, 0, 29));
	cam1->loop(false);
	cam1->play();
	

	Animation *horseanim2 = new Animation(61.0);
	horse3->addComponent(horseanim2);
	horseanim2->addKey("henry", 0.0, Quaternion(Vector3(0, 0, 0)), Vector3(23, 0, -35));
	horseanim2->addKey("henry", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(23, 0, -35));
	horseanim2->addKey("henry", 53.2, Quaternion(Vector3(0, 0, 0)), Vector3(23, 0, -35));
	horseanim2->addKey("henry", 54.2, Quaternion(Vector3(0, 0, 0)), Vector3(35, 0, -31));
	horseanim2->addKey("henry", 56.3, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(35, 0, -31));
	horseanim2->addKey("henry", 56.5, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(35, 0, -31));
	horseanim2->addKey("henry", 59.5, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(33, 0, 29));
	horseanim2->addKey("henry", 61.0, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(33, 0, 29));
	horseanim2->loop(false);
	horseanim2->play();

	Animation *horseanim3 = new Animation(61.0);
	horse2->addComponent(horseanim3);
	horseanim3->addKey("henry", 0.0, Quaternion(Vector3(0, 0, 0)), Vector3(23, 0, -38));
	horseanim3->addKey("henry", 1.0, Quaternion(Vector3(0, 0, 0)), Vector3(23, 0, -38));
	horseanim3->addKey("henry", 53.2, Quaternion(Vector3(0, 0, 0)), Vector3(23, 0, -35));
	horseanim3->addKey("henry", 54.2, Quaternion(Vector3(0, 0, 0)), Vector3(38, 0, -31));
	horseanim3->addKey("henry", 56.3, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(38, 0, -31));
	horseanim3->addKey("henry", 56.5, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(38, 0, -31));
	horseanim3->addKey("henry", 59.5, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(38, 0, 29));
	horseanim3->addKey("henry", 61.0, Quaternion(Vector3(0, -Math::PI / 2.2, 0)), Vector3(38, 0, 29));
	horseanim3->loop(false);
	horseanim3->play();



	Texture *cratetex = new Texture("Resources/crate013jc.jpg", true, true);
	renderer->loadTexture(cratetex);
	Material *cratemat = renderer->createMaterial(Renderer::PR_OPAQUE);
	cratemat->setTexture(cratetex);


	GameObject *tcube = new GameObject(this);
	tcube->setMesh(new TCube(1,0));
	tcube->setMaterial(cratemat);
	tcube->getTransform()->setLocalPosition(Vector3(0, -1.5, -3));
	tcube->getTransform()->setParent(root);
	tcube->getTransform()->name = "TCube";
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////background boxes start
	GameObject *tcube2 = new GameObject(this);
	tcube2->setMesh(new TCube(5, 0));
	tcube2->setMaterial(cratemat);
	tcube2->getTransform()->setLocalPosition(Vector3(-50, 2.5, -50));
	tcube2->getTransform()->setLocalRotation(Vector3(0, 1, 0));
	tcube2->getTransform()->setParent(root);
	tcube2->getTransform()->name = "TCube2";
	GameObject *tcube3 = new GameObject(this);
	tcube3->setMesh(new TCube(5, 0));
	tcube3->setMaterial(cratemat);
	tcube3->getTransform()->setLocalPosition(Vector3(-37, 2.5, -50));
	tcube3->getTransform()->setParent(root);
	tcube3->getTransform()->name = "TCube3";
	GameObject *tcube4 = new GameObject(this);
	tcube4->setMesh(new TCube(6, 0));
	tcube4->setMaterial(cratemat);
	tcube4->getTransform()->setLocalPosition(Vector3(-27, 2.5, -50));
	tcube4->getTransform()->setParent(root);
	tcube4->getTransform()->name = "TCube4";
	GameObject *tcube5 = new GameObject(this);
	tcube5->setMesh(new TCube(3, 0));
	tcube5->setMaterial(cratemat);
	tcube5->getTransform()->setLocalPosition(Vector3(-18, 0, -49));
	tcube5->getTransform()->setParent(root);
	tcube5->getTransform()->name = "TCube5";
	GameObject *tcube6 = new GameObject(this);
	tcube6->setMesh(new TCube(6, 0));
	tcube6->setMaterial(cratemat);
	tcube6->getTransform()->setLocalPosition(Vector3(-3, 2.5, -50));
	tcube6->getTransform()->setLocalRotation(Vector3(0, 1, 0));
	tcube6->getTransform()->setParent(root);
	tcube6->getTransform()->name = "TCube6";
	GameObject *tcube7 = new GameObject(this);
	tcube7->setMesh(new TCube(6.4, 0));
	tcube7->setMaterial(cratemat);
	tcube7->getTransform()->setLocalPosition(Vector3(14, 2.5, -50));
	tcube7->getTransform()->setParent(root);
	tcube7->getTransform()->name = "TCube7";
	GameObject *tcube8 = new GameObject(this);
	tcube8->setMesh(new TCube(5.9, 0));
	tcube8->setMaterial(cratemat);
	tcube8->getTransform()->setLocalPosition(Vector3(27, 2.5, -50));
	tcube8->getTransform()->setParent(root);
	tcube8->getTransform()->name = "TCube8";
	GameObject *tcube9 = new GameObject(this);
	tcube9->setMesh(new TCube(6.3, 0));
	tcube9->setMaterial(cratemat);
	tcube9->getTransform()->setLocalPosition(Vector3(41, 2.5, -50));
	tcube9->getTransform()->setLocalRotation(Vector3(0, 1, 0));
	tcube9->getTransform()->setParent(root);
	tcube9->getTransform()->name = "TCube9";
	GameObject *tcube10= new GameObject(this);
	tcube10->setMesh(new TCube(6.3, 0));
	tcube10->setMaterial(cratemat);
	tcube10->getTransform()->setLocalPosition(Vector3(50, 2.5, -40));
	tcube10->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	tcube10->getTransform()->setParent(root);
	tcube10->getTransform()->name = "TCube10";
GameObject *tcube11 = new GameObject(this);
	tcube11->setMesh(new TCube(5.4, 0));
	tcube11->setMaterial(cratemat);
	tcube11->getTransform()->setLocalPosition(Vector3(50, 2.5, -30));
	tcube11->getTransform()->setLocalRotation(Vector3(0, 1, 0));
	tcube11->getTransform()->setParent(root);
	tcube11->getTransform()->name = "TCube11";
	GameObject *tcube12 = new GameObject(this);
tcube12->setMesh(new TCube(5.4, 0));
tcube12->setMaterial(cratemat);
tcube12->getTransform()->setLocalPosition(Vector3(50, 2.5, -15));
tcube12->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube12->getTransform()->setParent(root);
tcube12->getTransform()->name = "TCube12";
GameObject *tcube13 = new GameObject(this);
tcube13->setMesh(new TCube(6.3, 0));
tcube13->setMaterial(cratemat);
tcube13->getTransform()->setLocalPosition(Vector3(50, 2.5, 0));
tcube13->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube13->getTransform()->setParent(root);
tcube13->getTransform()->name = "TCube13";
GameObject *tcube14 = new GameObject(this);
tcube14->setMesh(new TCube(6.3, 0));
tcube14->setMaterial(cratemat);
tcube14->getTransform()->setLocalPosition(Vector3(50, 2.5, 15));
tcube14->getTransform()->setLocalRotation(Vector3(0, 1, 0));
tcube14->getTransform()->setParent(root);
tcube14->getTransform()->name = "TCube14";
GameObject *tcube15 = new GameObject(this);
tcube15->setMesh(new TCube(6.8, 0));
tcube15->setMaterial(cratemat);
tcube15->getTransform()->setLocalPosition(Vector3(50, 2.5, 30));
tcube15->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube15->getTransform()->setParent(root);
tcube15->getTransform()->name = "TCube15";
GameObject *tcube16 = new GameObject(this);
tcube16->setMesh(new TCube(5.8, 0));
tcube16->setMaterial(cratemat);
tcube16->getTransform()->setLocalPosition(Vector3(50, 2.5, 45));
tcube16->getTransform()->setLocalRotation(Vector3(0, 1, 0));
tcube16->getTransform()->setParent(root);
tcube16->getTransform()->name = "TCube16";
GameObject *tcube17 = new GameObject(this);
tcube17->setMesh(new TCube(6.4, 0));
tcube17->setMaterial(cratemat);
tcube17->getTransform()->setLocalPosition(Vector3(35, 2.5, 50));
tcube17->getTransform()->setLocalRotation(Vector3(0, 1, 0));
tcube17->getTransform()->setParent(root);
tcube17->getTransform()->name = "TCube17";
GameObject *tcube18 = new GameObject(this);
tcube18->setMesh(new TCube(7.2, 0));
tcube18->setMaterial(cratemat);
tcube18->getTransform()->setLocalPosition(Vector3(21, 2.5, 50));
tcube18->getTransform()->setLocalRotation(Vector3(0, 1, 0));
tcube18->getTransform()->setParent(root);
tcube18->getTransform()->name = "TCube18";
GameObject *tcube19 = new GameObject(this);
tcube19->setMesh(new TCube(6.5, 0));
tcube19->setMaterial(cratemat);
tcube19->getTransform()->setLocalPosition(Vector3(7, 2.5, 50));
tcube19->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube19->getTransform()->setParent(root);
tcube19->getTransform()->name = "TCube19";
GameObject *tcube20 = new GameObject(this);
tcube20->setMesh(new TCube(6.9, 0));
tcube20->setMaterial(cratemat);
tcube20->getTransform()->setLocalPosition(Vector3(-13, 2.5, 50));
tcube20->getTransform()->setLocalRotation(Vector3(0, 1, 0));
tcube20->getTransform()->setParent(root);
tcube20->getTransform()->name = "TCube20";
GameObject *tcube21 = new GameObject(this);
tcube21->setMesh(new TCube(5.9, 0));
tcube21->setMaterial(cratemat);
tcube21->getTransform()->setLocalPosition(Vector3(-30, 2.5, 50));
tcube21->getTransform()->setLocalRotation(Vector3(0, 1, 0));
tcube21->getTransform()->setParent(root);
tcube21->getTransform()->name = "TCube21";
GameObject *tcube22 = new GameObject(this);
tcube22->setMesh(new TCube(6.5, 0));
tcube22->setMaterial(cratemat);
tcube22->getTransform()->setLocalPosition(Vector3(-40, 2.5, 50));
tcube22->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube22->getTransform()->setParent(root);
tcube22->getTransform()->name = "TCube22";
GameObject *tcube23 = new GameObject(this);
tcube23->setMesh(new TCube(6, 0));
tcube23->setMaterial(cratemat);
tcube23->getTransform()->setLocalPosition(Vector3(-50, 2.5, 40));
tcube23->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube23->getTransform()->setParent(root);
tcube23->getTransform()->name = "TCube23";
GameObject *tcube24 = new GameObject(this);
tcube24->setMesh(new TCube(6.3, 0));
tcube24->setMaterial(cratemat);
tcube24->getTransform()->setLocalPosition(Vector3(-50, 2.5, 23));
tcube24->getTransform()->setLocalRotation(Vector3(0, 1, 0));
tcube24->getTransform()->setParent(root);
tcube24->getTransform()->name = "TCube24";
GameObject *tcube25 = new GameObject(this);
tcube25->setMesh(new TCube(6, 0));
tcube25->setMaterial(cratemat);
tcube25->getTransform()->setLocalPosition(Vector3(-50, 2.5, 8));
tcube25->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube25->getTransform()->setParent(root);
tcube25->getTransform()->name = "TCube25";
GameObject *tcube26 = new GameObject(this);
tcube26->setMesh(new TCube(6, 0));
tcube26->setMaterial(cratemat);
tcube26->getTransform()->setLocalPosition(Vector3(-50, 2.5, -8));
tcube26->getTransform()->setLocalRotation(Vector3(0, 1, 0));
tcube26->getTransform()->setParent(root);
tcube26->getTransform()->name = "TCube26";
GameObject *tcube27 = new GameObject(this);
tcube27->setMesh(new TCube(6, 0));
tcube27->setMaterial(cratemat);
tcube27->getTransform()->setLocalPosition(Vector3(-50, 2.5, -18));
tcube27->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube27->getTransform()->setParent(root);
tcube27->getTransform()->name = "TCube26";
GameObject *tcube28 = new GameObject(this);
tcube28->setMesh(new TCube(4, 0));
tcube28->setMaterial(cratemat);
tcube28->getTransform()->setLocalPosition(Vector3(-50, 2.5, -28));
tcube28->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube28->getTransform()->setParent(root);
tcube28->getTransform()->name = "TCube26";
GameObject *tcube29 = new GameObject(this);
tcube29->setMesh(new TCube(6.3, 0));
tcube29->setMaterial(cratemat);
tcube29->getTransform()->setLocalPosition(Vector3(-50, 2.5, -38));
tcube29->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube29->getTransform()->setParent(root);
tcube29->getTransform()->name = "TCube26";
GameObject *tcube30 = new GameObject(this);
tcube30->setMesh(new TCube(6, 0));
tcube30->setMaterial(cratemat);
tcube30->getTransform()->setLocalPosition(Vector3(-50, 2.5, -48));
tcube30->getTransform()->setLocalRotation(Vector3(0, 0, 0));
tcube30->getTransform()->setParent(root);
tcube30->getTransform()->name = "TCube26";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////background boxes end area boxes begin

GameObject *abox1 = new GameObject(this);
abox1->setMesh(new TCube(1.5, 0));
abox1->setMaterial(cratemat);
abox1->getTransform()->setLocalPosition(Vector3(4, -2, 5));
abox1->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox1->getTransform()->setParent(root);
abox1->getTransform()->name = "a";
GameObject *abox2 = new GameObject(this);
abox2->setMesh(new TCube(1, 0));
abox2->setMaterial(cratemat);
abox2->getTransform()->setLocalPosition(Vector3(-10, -2, 2));
abox2->getTransform()->setLocalRotation(Vector3(1, 0, 0));
abox2->getTransform()->setParent(root);
abox2->getTransform()->name = "a";
GameObject *abox3 = new GameObject(this);
abox3->setMesh(new TCube(6, 0));
abox3->setMaterial(cratemat);
abox3->getTransform()->setLocalPosition(Vector3(-2, -4, 25));
abox3->getTransform()->setLocalRotation(Vector3(0, 0, 1));
abox3->getTransform()->setParent(root);
abox3->getTransform()->name = "a";
GameObject *abox4 = new GameObject(this);
abox4->setMesh(new TCube(1.5, 0));
abox4->setMaterial(cratemat);
abox4->getTransform()->setLocalPosition(Vector3(36, -2, 30));
abox4->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox4->getTransform()->setParent(root);
abox4->getTransform()->name = "a";
GameObject *abox5 = new GameObject(this);
abox5->setMesh(new TCube(1.8, 0));
abox5->setMaterial(cratemat);
abox5->getTransform()->setLocalPosition(Vector3(7, -1, -12));
abox5->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox5->getTransform()->setParent(root);
abox5->getTransform()->name = "a";
GameObject *abox6 = new GameObject(this);
abox6->setMesh(new TCube(1.8, 0));
abox6->setMaterial(cratemat);
abox6->getTransform()->setLocalPosition(Vector3(3, -1, -12));
abox6->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox6->getTransform()->setParent(root);
abox6->getTransform()->name = "a";
GameObject *abox7 = new GameObject(this);
abox7->setMesh(new TCube(1.8, 0));
abox7->setMaterial(cratemat);
abox7->getTransform()->setLocalPosition(Vector3(5, 2.5, -12));
abox7->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox7->getTransform()->setParent(root);
abox7->getTransform()->name = "a";
GameObject *abox8 = new GameObject(this);
abox8->setMesh(new TCube(1.8, 0));
abox8->setMaterial(cratemat);
abox8->getTransform()->setLocalPosition(Vector3(7, -1, -23));
abox8->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox8->getTransform()->setParent(root);
abox8->getTransform()->name = "a";
GameObject *abox9 = new GameObject(this);
abox9->setMesh(new TCube(1.8, 0));
abox9->setMaterial(cratemat);
abox9->getTransform()->setLocalPosition(Vector3(3, -1, -23));
abox9->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox9->getTransform()->setParent(root);
abox9->getTransform()->name = "a";
GameObject *abox10 = new GameObject(this);
abox10->setMesh(new TCube(1.8, 0));
abox10->setMaterial(cratemat);
abox10->getTransform()->setLocalPosition(Vector3(5, 2.5, -23));
abox10->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox10->getTransform()->setParent(root);
abox10->getTransform()->name = "a";
GameObject *abox11 = new GameObject(this);
abox11->setMesh(new TCube(1.8, 0));
abox11->setMaterial(cratemat);
abox11->getTransform()->setLocalPosition(Vector3(2, -1, -26));
abox11->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox11->getTransform()->setParent(root);
abox11->getTransform()->name = "a";
GameObject *abox12 = new GameObject(this);
abox12->setMesh(new TCube(1.8, 0));
abox12->setMaterial(cratemat);
abox12->getTransform()->setLocalPosition(Vector3(-2, -1, -26));
abox12->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox12->getTransform()->setParent(root);
abox12->getTransform()->name = "a";
GameObject *abox13 = new GameObject(this);
abox13->setMesh(new TCube(1.7, 0));
abox13->setMaterial(cratemat);
abox13->getTransform()->setLocalPosition(Vector3(0, 2.5, -26));
abox13->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox13->getTransform()->setParent(root);
abox13->getTransform()->name = "a";
GameObject *abox14 = new GameObject(this);
abox14->setMesh(new TCube(3, 0));
abox14->setMaterial(cratemat);
abox14->getTransform()->setLocalPosition(Vector3(-6, -1, -24));
abox14->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox14->getTransform()->setParent(root);
abox14->getTransform()->name = "a";
GameObject *abox15 = new GameObject(this);
abox15->setMesh(new TCube(1.8, 0));
abox15->setMaterial(cratemat);
abox15->getTransform()->setLocalPosition(Vector3(-12, -1, -26));
abox15->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox15->getTransform()->setParent(root);
abox15->getTransform()->name = "a";
GameObject *abox16 = new GameObject(this);
abox16->setMesh(new TCube(1.8, 0));
abox16->setMaterial(cratemat);
abox16->getTransform()->setLocalPosition(Vector3(-16, -1, -26));
abox16->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox16->getTransform()->setParent(root);
abox16->getTransform()->name = "a";
GameObject *abox17 = new GameObject(this);
abox17->setMesh(new TCube(1.7, 0));
abox17->setMaterial(cratemat);
abox17->getTransform()->setLocalPosition(Vector3(-13, 2.5, -26));
abox17->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox17->getTransform()->setParent(root);
abox17->getTransform()->name = "a";
GameObject *abox18 = new GameObject(this);
abox18->setMesh(new TCube(2, 0));
abox18->setMaterial(cratemat);
abox18->getTransform()->setLocalPosition(Vector3(20, -0.5, 26));
abox18->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox18->getTransform()->setParent(root);
abox18->getTransform()->name = "a";

GameObject *abox19 = new GameObject(this);
abox19->setMesh(new TCube(2, 0));
abox19->setMaterial(cratemat);
abox19->getTransform()->setLocalPosition(Vector3(20, -0.5, 21));
abox19->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox19->getTransform()->setParent(root);
abox19->getTransform()->name = "a";

GameObject *abox20 = new GameObject(this);
abox20->setMesh(new TCube(2, 0));
abox20->setMaterial(cratemat);
abox20->getTransform()->setLocalPosition(Vector3(20, 3.3, 23));
abox20->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox20->getTransform()->setParent(root);
abox20->getTransform()->name = "a";


GameObject *abox21 = new GameObject(this);
abox21->setMesh(new TCube(2, 0));
abox21->setMaterial(cratemat);
abox21->getTransform()->setLocalPosition(Vector3(20, -0.5, 16));
abox21->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox21->getTransform()->setParent(root);
abox21->getTransform()->name = "a";

GameObject *abox22 = new GameObject(this);
abox22->setMesh(new TCube(2, 0));
abox22->setMaterial(cratemat);
abox22->getTransform()->setLocalPosition(Vector3(20, -0.5, 11));
abox22->getTransform()->setLocalRotation(Vector3(0, 1, 0));
abox22->getTransform()->setParent(root);
abox22->getTransform()->name = "a";

GameObject *abox23 = new GameObject(this);
abox23->setMesh(new TCube(2, 0));
abox23->setMaterial(cratemat);
abox23->getTransform()->setLocalPosition(Vector3(20, 3.3, 13));
abox23->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox23->getTransform()->setParent(root);
abox23->getTransform()->name = "a";

GameObject *abox24 = new GameObject(this);
abox24->setMesh(new TCube(2, 0));
abox24->setMaterial(cratemat);
abox24->getTransform()->setLocalPosition(Vector3(20, 3.3, 18));
abox24->getTransform()->setLocalRotation(Vector3(0, 1, 0));
abox24->getTransform()->setParent(root);
abox24->getTransform()->name = "a";


GameObject *abox25 = new GameObject(this);
abox25->setMesh(new TCube(2, 0));
abox25->setMaterial(cratemat);
abox25->getTransform()->setLocalPosition(Vector3(20, -0.5, 5));
abox25->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox25->getTransform()->setParent(root);
abox25->getTransform()->name = "a";

GameObject *abox26 = new GameObject(this);
abox26->setMesh(new TCube(2, 0));
abox26->setMaterial(cratemat);
abox26->getTransform()->setLocalPosition(Vector3(20, -0.5, 0));
abox26->getTransform()->setLocalRotation(Vector3(0, 1, 0));
abox26->getTransform()->setParent(root);
abox26->getTransform()->name = "a";

GameObject *abox27 = new GameObject(this);
abox27->setMesh(new TCube(2, 0));
abox27->setMaterial(cratemat);
abox27->getTransform()->setLocalPosition(Vector3(20, 3.3, 3));
abox27->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox27->getTransform()->setParent(root);
abox27->getTransform()->name = "a";

GameObject *abox28 = new GameObject(this);
abox28->setMesh(new TCube(2, 0));
abox28->setMaterial(cratemat);
abox28->getTransform()->setLocalPosition(Vector3(20, -0.5, -8));
abox28->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox28->getTransform()->setParent(root);
abox28->getTransform()->name = "a";

GameObject *abox29 = new GameObject(this);
abox29->setMesh(new TCube(2, 0));
abox29->setMaterial(cratemat);
abox29->getTransform()->setLocalPosition(Vector3(20, -0.5, -15));
abox29->getTransform()->setLocalRotation(Vector3(0, 1, 0));
abox29->getTransform()->setParent(root);
abox29->getTransform()->name = "a";

GameObject *abox30 = new GameObject(this);
abox30->setMesh(new TCube(2, 0));
abox30->setMaterial(cratemat);
abox30->getTransform()->setLocalPosition(Vector3(20, 3.3, -8));
abox30->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox30->getTransform()->setParent(root);
abox30->getTransform()->name = "a";




GameObject *abox31 = new GameObject(this);
abox31->setMesh(new TCube(2, 0));
abox31->setMaterial(cratemat);
abox31->getTransform()->setLocalPosition(Vector3(20, -0.5, -20));
abox31->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox31->getTransform()->setParent(root);
abox31->getTransform()->name = "a";

GameObject *abox32 = new GameObject(this);
abox32->setMesh(new TCube(2, 0));
abox32->setMaterial(cratemat);
abox32->getTransform()->setLocalPosition(Vector3(20, -0.5, -25));
abox32->getTransform()->setLocalRotation(Vector3(0, 1, 0));
abox32->getTransform()->setParent(root);
abox32->getTransform()->name = "a";

GameObject *abox33 = new GameObject(this);
abox33->setMesh(new TCube(2, 0));
abox33->setMaterial(cratemat);
abox33->getTransform()->setLocalPosition(Vector3(20, 3.3, -22));
abox33->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox33->getTransform()->setParent(root);
abox33->getTransform()->name = "a";


GameObject *abox34 = new GameObject(this);
abox34->setMesh(new TCube(2, 0));
abox34->setMaterial(cratemat);
abox34->getTransform()->setLocalPosition(Vector3(20, -0.5, -30));
abox34->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox34->getTransform()->setParent(root);
abox34->getTransform()->name = "a";

GameObject *abox35 = new GameObject(this);
abox35->setMesh(new TCube(2, 0));
abox35->setMaterial(cratemat);
abox35->getTransform()->setLocalPosition(Vector3(20, -0.5, -34));
abox35->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox35->getTransform()->setParent(root);
abox35->getTransform()->name = "a";

GameObject *abox36 = new GameObject(this);
abox36->setMesh(new TCube(2, 0));
abox36->setMaterial(cratemat);
abox36->getTransform()->setLocalPosition(Vector3(20, -0.5, -38));
abox36->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox36->getTransform()->setParent(root);
abox36->getTransform()->name = "a";

GameObject *abox37 = new GameObject(this);
abox37->setMesh(new TCube(2, 0));
abox37->setMaterial(cratemat);
abox37->getTransform()->setLocalPosition(Vector3(20, 3.3, -30));
abox37->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox37->getTransform()->setParent(root);
abox37->getTransform()->name = "a";

GameObject *abox38 = new GameObject(this);
abox38->setMesh(new TCube(2, 0));
abox38->setMaterial(cratemat);
abox38->getTransform()->setLocalPosition(Vector3(20, 3.3, -34));
abox38->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox38->getTransform()->setParent(root);
abox38->getTransform()->name = "a";

GameObject *abox39 = new GameObject(this);
abox39->setMesh(new TCube(2, 0));
abox39->setMaterial(cratemat);
abox39->getTransform()->setLocalPosition(Vector3(20, 3.3 ,-38));
abox39->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox39->getTransform()->setParent(root);
abox39->getTransform()->name = "a";


GameObject *abox40 = new GameObject(this);
abox40->setMesh(new TCube(2, 0));
abox40->setMaterial(cratemat);
abox40->getTransform()->setLocalPosition(Vector3(24, 3.3, -30));
abox40->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox40->getTransform()->setParent(root);
abox40->getTransform()->name = "a";


GameObject *abox41 = new GameObject(this);
abox41->setMesh(new TCube(2, 0));
abox41->setMaterial(cratemat);
abox41->getTransform()->setLocalPosition(Vector3(24, -0.5, -30));
abox41->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox41->getTransform()->setParent(root);
abox41->getTransform()->name = "a";

GameObject *abox42 = new GameObject(this);
abox42->setMesh(new TCube(2, 0));
abox42->setMaterial(cratemat);
abox42->getTransform()->setLocalPosition(Vector3(28, 3.3, -30));
abox42->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox42->getTransform()->setParent(root);
abox42->getTransform()->name = "a";


GameObject *abox43 = new GameObject(this);
abox43->setMesh(new TCube(2, 0));
abox43->setMaterial(cratemat);
abox43->getTransform()->setLocalPosition(Vector3(28, -0.5, -30));
abox43->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox43->getTransform()->setParent(root);
abox43->getTransform()->name = "a";



GameObject *abox44 = new GameObject(this);
abox44->setMesh(new TCube(2.2, 0));
abox44->setMaterial(cratemat);
abox44->getTransform()->setLocalPosition(Vector3(-23, -0.5, 25));
abox44->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox44->getTransform()->setParent(root);
abox44->getTransform()->name = "a";

GameObject *abox45 = new GameObject(this);
abox45->setMesh(new TCube(2.2, 0));
abox45->setMaterial(cratemat);
abox45->getTransform()->setLocalPosition(Vector3(-23, -0.5, 20));
abox45->getTransform()->setLocalRotation(Vector3(0, 0, 0));
abox45->getTransform()->setParent(root);
abox45->getTransform()->name = "a";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////scene boxes end
	
/*
	Texture *bartex = new Texture("Resources/ExplosiveBarrel.jpg", true, true);
	renderer->loadTexture(bartex);
	Material *barmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	barmat->setTexture(bartex);
	
	Texture *bartexwood = new Texture("Resources/Barrel.jpg", true, true);
	renderer->loadTexture(bartexwood);
	Material *barmatwood = renderer->createMaterial(Renderer::PR_OPAQUE);
	barmatwood->setTexture(bartexwood);


	GameObject *tcyl = new GameObject(this);
	tcyl->setMesh(new TCylinder(1,1,10));
	tcyl->setMaterial(barmat);
	tcyl->getTransform()->setLocalPosition(Vector3(2, -1.5, -3));
	tcyl->getTransform()->setLocalRotation(Vector3(0, 3, 0));
	tcyl->getTransform()->setParent(root);
	tcyl->getTransform()->name = "TCyl";
	
	GameObject *bar1 = new GameObject(this);
	bar1->setMesh(new barrel(1, 1, 8));
	bar1->setMaterial(barmatwood);
	bar1->getTransform()->setLocalPosition(Vector3(1, 0.5, -3));
	bar1->getTransform()->setParent(root);
	bar1->getTransform()->name = "bar1";

	GameObject *bar2 = new GameObject(this);
	bar2->setMesh(new barrel(1, 1, 8));
	bar2->setMaterial(barmatwood);
	bar2->getTransform()->setLocalPosition(Vector3(5, -1.5, -3));
	bar2->getTransform()->setParent(root);
	bar2->getTransform()->name = "bar1";

	GameObject *bar3 = new GameObject(this);
	bar3->setMesh(new barrel(1, 1, 8));
	bar3->setMaterial(barmatwood);
	bar3->getTransform()->setLocalPosition(Vector3(3.5, 0.5, 3));
	bar3->getTransform()->setParent(root);
	bar3->getTransform()->name = "bar1";



	GameObject *bar4 = new GameObject(this);
	bar4->setMesh(new barrel(1, 1, 8));
	bar4->setMaterial(barmatwood);
	bar4->getTransform()->setLocalPosition(Vector3(-23, -1.5, 6));
	bar4->getTransform()->setParent(root);
	bar4->getTransform()->name = "bar1";



	GameObject *bar5 = new GameObject(this);
	bar5->setMesh(new barrel(1, 1, 8));
	bar5->setMaterial(barmatwood);
	bar5->getTransform()->setLocalPosition(Vector3(-23, -1.5, -6));
	bar5->getTransform()->setParent(root);
	bar5->getTransform()->name = "bar1";

	GameObject *bar6 = new GameObject(this);
	bar6->setMesh(new barrel(1, 1, 8));
	bar6->setMaterial(barmatwood);
	bar6->getTransform()->setLocalPosition(Vector3(-21, -1.5, -6));
	bar6->getTransform()->setParent(root);
	bar6->getTransform()->name = "bar1";

	GameObject *bar7 = new GameObject(this);
	bar7->setMesh(new barrel(1, 1, 8));
	bar7->setMaterial(barmatwood);
	bar7->getTransform()->setLocalPosition(Vector3(-22, -1.5, -4.5));
	bar7->getTransform()->setParent(root);
	bar7->getTransform()->name = "bar1";

	GameObject *bar8 = new GameObject(this);
	bar8->setMesh(new barrel(1, 1, 8));
	bar8->setMaterial(barmatwood);
	bar8->getTransform()->setLocalPosition(Vector3(-22, 0.5, -5.25));
	bar8->getTransform()->setParent(root);
	bar8->getTransform()->name = "bar1";
	*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////scene barrels end

	Texture *dirtex = new Texture("Resources/dirt.jpg", true, true);
	renderer->loadTexture(dirtex);
	Material *dirtmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	dirtmat->setTexture(dirtex);

	//Add some terrain
	GameObject *terrain = new GameObject(this);
	Terrain *terrainComponent = new Terrain();
	terrain->addComponent(terrainComponent);
	terrainComponent->createFractalTerrain(1024, 100, 0, 0.); // procedurally generate terrain
	terrain->setMaterial(dirtmat);
	terrain->getTransform()->setLocalPosition(Vector3(0, -2.4, 0));
	terrain->getTransform()->setParent(root);
	terrain->getTransform()->name = "Terrain";

	Texture *sparkletex = new Texture("Resources/dustcloud.png", true, true);
	renderer->loadTexture(sparkletex);
	Material *sparklemat = renderer->createMaterial(Renderer::PR_TRANSPARENT);
	sparklemat->setEmissive(1, 1, 1, 1);
	sparklemat->setBlending(Material::BLEND_DEFAULT);
	sparklemat->setSortedDraw(true, false);
	sparklemat->setTexture(sparkletex);

	Texture *guntex = new Texture("Resources/gunfire.png", true, true);
	renderer->loadTexture(guntex);
	Material *gunmat = renderer->createMaterial(Renderer::PR_TRANSPARENT);
	gunmat->setEmissive(1, 1, 1, 1);
	gunmat->setBlending(Material::BLEND_DEFAULT);
	gunmat->setSortedDraw(true, false);
	gunmat->setTexture(guntex);

	ParticleEmitter *particlegun = new ParticleEmitter(0.0f, 20.0f, 2000.0f, 20.0f, 5.0f, 5.0f, 0.2f);
	task2->support->addComponent(particlegun);
	particlegun->createBillboardParticles(300, 0.1, 0.1, gunmat, 1.0, root);
	particlegun->setPositionRange(0.01f, 0.01f, 0.01f);
	particlegun->setDirection(0 * Math::DEG2RAD, 0.0*Math::DEG2RAD, 180 * Math::DEG2RAD);
	particlegun->setStartVelocity(20.0f, 20.0f);
	particlegun->setAcceleration(-30.0f, 1.0f);
	particlegun->setAlphaFade(1.0f, 0.0f);
	particlegun->emit(40);


	ParticleEmitter *particleSys = new ParticleEmitter(0.0f, 20.0f, 2000.0f, 20.0f, 5.0f, 5.0f, 0.2f);
	task5->frfootjoint->addComponent(particleSys);
	particleSys->createBillboardParticles(100, 0.1, 0.1, sparklemat, 1.0, root);
	particleSys->setPositionRange(0.01f, 0.01f, 0.01f);
	particleSys->setDirection(0 * Math::DEG2RAD, 0.0*Math::DEG2RAD, 180 * Math::DEG2RAD);
	particleSys->setStartVelocity(20.0f, 20.0f);
	particleSys->setAcceleration(-30.0f, 1.0f);
	particleSys->setAlphaFade(1.0f, 0.0f);
	particleSys->emit(40);

	ParticleEmitter *particleSys2 = new ParticleEmitter(0.0f, 20.0f, 2000.0f, 20.0f, 5.0f, 5.0f, 0.2f);
	task5->flfootjoint->addComponent(particleSys2);
	particleSys2->createBillboardParticles(100, 0.1, 0.1, sparklemat, 1.0, root);
	particleSys2->setPositionRange(0.01f, 0.01f, 0.01f);
	particleSys2->setDirection(0 * Math::DEG2RAD, 0.0*Math::DEG2RAD, 180 * Math::DEG2RAD);
	particleSys2->setStartVelocity(20.0f, 20.0f);
	particleSys2->setAcceleration(-30.0f, 1.0f);
	particleSys2->setAlphaFade(1.0f, 0.0f);
	particleSys2->emit(40);

	ParticleEmitter *particleSys3 = new ParticleEmitter(0.0f, 20.0f, 2000.0f, 20.0f, 5.0f, 5.0f, 0.2f);
	task5->blfootjoint->addComponent(particleSys3);
	particleSys3->createBillboardParticles(100, 0.1, 0.1, sparklemat, 1.0, root);
	particleSys3->setPositionRange(0.01f, 0.01f, 0.01f);
	particleSys3->setDirection(0 * Math::DEG2RAD, 0.0*Math::DEG2RAD, 180 * Math::DEG2RAD);
	particleSys3->setStartVelocity(20.0f, 20.0f);
	particleSys3->setAcceleration(-30.0f, 1.0f);
	particleSys3->setAlphaFade(1.0f, 0.0f);
	particleSys3->emit(40);

	ParticleEmitter *particleSys4 = new ParticleEmitter(0.0f, 20.0f, 2000.0f, 20.0f, 5.0f, 5.0f, 0.2f);
	task5->brfootjoint->addComponent(particleSys4);
	particleSys4->createBillboardParticles(100, 0.1, 0.1, sparklemat, 1.0, root);
	particleSys4->setPositionRange(0.01f, 0.01f, 0.01f);
	particleSys4->setDirection(0 * Math::DEG2RAD, 0.0*Math::DEG2RAD, 180 * Math::DEG2RAD);
	particleSys4->setStartVelocity(20.0f, 20.0f);
	particleSys4->setAcceleration(-30.0f, 1.0f);
	particleSys4->setAlphaFade(1.0f, 0.0f);
	particleSys4->emit(40);


	
	//sets gun to camera position
	Vector3 cameraPosition = camObj->getTransform()->getLocalPosition();
	cameraPosition = cameraPosition - Vector3(1.2,1.5,3.1);
	task2->getTransform()->setLocalScale(Vector3(0.5, 0.5, 0.5));
	task2->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI/2, Math::PI, Math::PI/2)));
	task2->getTransform()->setLocalPosition(cameraPosition);



	//Animation *cam = new Animation(60.0);
	//camObj->addComponent(cam);
	//cam->addKey("camy", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0, 0));
	//cam->addKey("camy", 5, Quaternion(Vector3(0, 0, 0)), Vector3(5, 5, 5));
	//cam->loop(false);
	//cam->play();

	task2->getTransform()->setLocalScale(Vector3(0.5, 0.5, 0.5));
	cat->task2 = task2->getTransform();
	cat->camera = camObj->getTransform();
	cat->task5 = task5->getTransform();

	return true;
}


