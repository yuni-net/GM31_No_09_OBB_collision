#include <simplect3D.h>
#include "God.h"
#include "util.h"

void God::load()
{
	get_instance().load_dynamic();
}

void God::init()
{
	get_instance().init_dynamic();
}

void God::update()
{
	get_instance().update_dynamic();
}

void God::draw()
{
	get_instance().draw_dynamic();
}

JudgeMan & God::get_judge_man()
{
	return get_instance().judge_man;
}

God::God()
{
	// Nothing
}

God & God::get_instance()
{
	static God god;
	return god;
}

void God::load_dynamic()
{
	modeld.load("data/sidewinder/sidewinder.pmd");
}

void God::init_dynamic()
{
	camera_work.init();

	si3::Manager::display_manager().get_skydome().load("data/sky.png");

	player.init(modeld);
	enemy.init(modeld);
}

void God::update_dynamic()
{
	judge_man.clear();

	camera_work.update();
	player.update();
	enemy.update();

	judge_man.judge();
}

void God::draw_dynamic()
{
	player.draw();
	enemy.draw();
}

