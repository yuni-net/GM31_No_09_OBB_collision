#pragma once

#include <simplect3D.h>
#include "Player.h"
#include "Enemy.h"
#include "CameraWork.h"
#include "JudgeMan.h"

class God
{
public:
	static void load();
	static void init();
	static void update();
	static void draw();

	static JudgeMan & get_judge_man();

private:
	si3::ModelData modeld;
	Player player;
	Enemy enemy;
	CameraWork camera_work;
	JudgeMan judge_man;

	God();
	static God & get_instance();

	void load_dynamic();
	void init_dynamic();
	void update_dynamic();
	void draw_dynamic();
};