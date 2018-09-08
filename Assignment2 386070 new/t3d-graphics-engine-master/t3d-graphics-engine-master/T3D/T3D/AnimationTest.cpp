#include "AnimationTest.h"
#include "Assignment2Test.h"
#include "Animation.h"


using namespace T3D;

float elapsedTime;
Transform task2;
Transform task5;
bool on = false;
bool played = false;
bool dead = false;
Transform camera;
int direction = 0;//front 0, left 1, back 2, right 3
AnimationTest::AnimationTest(T3DApplication *app) : Task(app)
{
	
	elapsedTime = 0;
	pause = false;
	dead = false;
	direction = 0;

	music = app->soundManager->createMusic("Resources/DoomOST.mp3"); //retrieved from https://www.youtube.com/watch?v=j05hzwQf8pA
	sound = app->soundManager->createSound("Resources/pacdeath.mp3"); //https://www.youtube.com/watch?v=wT-8Dm1VThc
	horseneigh= app->soundManager->createSound("Resources/horse01neigh.mp3");
	horse02= app->soundManager->createSound("Resources/horse02.mp3");
	dirtwalk= app->soundManager->createMusic("Resources/dirtwalk.mp3"); //https://www.youtube.com/watch?v=sQr42tGL8is
	minigun=app->soundManager->createMusic("Resources/minigun.mp3");//recorded this off soulknight game on phone
	sound->setVolume(1);
	music->setVolume(0.2);
	horseneigh->setVolume(1);
	horse02->setVolume(1);
	dirtwalk->setVolume(1.5);
	music->play();
	minigun->play();
	dirtwalk->play();
	
	
	direction = 0;
	
}


AnimationTest::~AnimationTest()
{
}

void AnimationTest::update(float dt)
{
	elapsedTime += dt;
	
	if (elapsedTime > 54.5 && elapsedTime < 56.3) {
		blah->pause();
	}
	if (elapsedTime >= 56.3 && played==false) {
		played = true;
		blah->play();
	}

	if (elapsedTime > 2.1 && elapsedTime < 2.3)
	{
		direction = 3;
		horseneigh->play();
	}

	if (int(elapsedTime) == 7)
		direction = 1;


	if (elapsedTime > 9.4 && elapsedTime < 9.5)
	{
		direction = 0;
		horse02->play();
	}

	if (elapsedTime >9.6 && elapsedTime<9.8)
		direction = 3;


	if (int(elapsedTime) == 12)
		direction = 3;

	if (int(elapsedTime) == 14)
		direction = 1;

	if (int(elapsedTime) == 17)
		direction = 2;

	if (elapsedTime >18 && elapsedTime<18.2)
	{
		direction = 2;
		horse02->play();
	}

	if (int(elapsedTime) == 21)
		direction = 1;

	if (int(elapsedTime) == 25)
		direction = 0;

	if (int(elapsedTime) == 26)
		direction = 3;

	if (elapsedTime > 29.4 && elapsedTime < 29.6)
	{
		direction = 2;
		horseneigh->play();
	}

	if (elapsedTime >32.8 && elapsedTime<33)
		direction = 3;

	if (elapsedTime > 40.5 && elapsedTime < 40.6)
	{
		direction = 0;
		horse02->play();
	}

	if (elapsedTime >44.3 && elapsedTime<44.5)
		direction = 1;

	if (elapsedTime >46.5 && elapsedTime<46.7)
		direction = 2;

	if (elapsedTime >49.7 && elapsedTime<49.9)
		direction = 3;

	if (elapsedTime > 52.2 && elapsedTime < 53)
	{
		direction = 0;
		dirtwalk->pause();
	}


	if (direction == 0)
	{
		Vector3 cameraPosition = camera->getLocalPosition();
		Quaternion camangle = camera->getQuaternion();
		Quaternion change = Quaternion(Vector3(Math::PI / 2, Math::PI, Math::PI / 2));
		cameraPosition = cameraPosition - Vector3(1.2, 1.5, 3.1);
		task2->setLocalPosition(cameraPosition);
		task2->setLocalRotation(camangle);
	}
	else
	if (direction == 1)
		{
			Vector3 cameraPosition = camera->getLocalPosition();
			Quaternion camangle = camera->getQuaternion();
			Quaternion change = Quaternion(Vector3(Math::PI / 2, Math::PI, Math::PI / 2));
			cameraPosition = cameraPosition - Vector3(3.2, 1.5, 3.1);
			task2->setLocalPosition(cameraPosition);
			task2->setLocalRotation(camangle);
		}
	else
	if (direction == 2)
	{
		Vector3 cameraPosition = camera->getLocalPosition();
		Quaternion camangle = camera->getQuaternion();
		Quaternion change = Quaternion(Vector3(Math::PI / 2, Math::PI, Math::PI / 2));
		cameraPosition = cameraPosition - Vector3(1.2, 1.5, -3.1);
		task2->setLocalPosition(cameraPosition);
		task2->setLocalRotation(camangle);
	}
	else
		if (direction == 3)
		{
			Vector3 cameraPosition = camera->getLocalPosition();
			Quaternion camangle = camera->getQuaternion();
			Quaternion change = Quaternion(Vector3(Math::PI / 2, Math::PI, Math::PI / 2));
			cameraPosition = cameraPosition - Vector3(-2, 1.5, 3.1);
			task2->setLocalPosition(cameraPosition);
			task2->setLocalRotation(camangle);
		}

	//camera->lookAt(task5->getChildByName("henry")->getLocalPosition()); //this would look at the horse all the time however doesnt work on keyframes :)

	if (elapsedTime > 59 && dead==false)
	{
		sound->play();
		dead = true;
	}



}

