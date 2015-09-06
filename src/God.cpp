#include <simplect3D.h>
#include "God.h"
#include "util.h"

void God::load()
{
	modeld.load("data/sidewinder/sidewinder.pmd");
}

void God::init()
{
	camera_work.init();

	si3::Manager::display_manager().get_skydome().load("data/sky.png");

	player.init(modeld);
	enemy.init(modeld);
}

void God::update()
{
	camera_work.update();
	player.update();
	enemy.update();
}

void God::draw()
{
	player.draw();
	enemy.draw();
}

