#pragma once

#include <simplect3D.h>
#include "Player.h"
#include "Enemy.h"
#include "CameraWork.h"

class God
{
public:
	void load();
	void init();
	void update();
	void draw();



private:
	si3::ModelData modeld;
	Player player;
	Enemy enemy;
	CameraWork camera_work;
};