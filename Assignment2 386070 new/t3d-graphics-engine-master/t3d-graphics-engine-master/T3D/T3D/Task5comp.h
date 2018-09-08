#pragma once
#include "GameObject.h"
namespace T3D {
	class Task5comp : public GameObject
	{
	public:
		Task5comp(T3DApplication *app);
		~Task5comp(void);

		GameObject *base;
		GameObject *heady;
		GameObject *pathobj;
		GameObject *backleftleg1;
		GameObject *backrightleg1;
		GameObject *backleftleg2;
		GameObject *backrightleg2;
		GameObject *backleftleg3;
		GameObject *backrightleg3;
		GameObject *blhipjoint;
		GameObject *brhipjoint;
		GameObject *blkneejoint;
		GameObject *brkneejoint;
		GameObject *blfootjoint;
		GameObject *brfootjoint;

		GameObject *frontleftleg1;
		GameObject *frontrightleg1;
		GameObject *frontleftleg2;
		GameObject *frontrightleg2;
		GameObject *frontleftleg3;
		GameObject *frontrightleg3;
		GameObject *flhipjoint;
		GameObject *frhipjoint;
		GameObject *flkneejoint;
		GameObject *frkneejoint;
		GameObject *flfootjoint;
		GameObject *frfootjoint;
		GameObject *neckjoint;
		GameObject *neck;
		GameObject *headjoint;
		GameObject *head;
		GameObject *earl;
		GameObject *earr;

	};
}

