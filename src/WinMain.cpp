#include <simplect3D.h>
#include "God.h"

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	if (si3::Manager::init() == false)
	{
		fw::popup("failed");
		return -1;
	}

	const si3::Key & key = si3::Manager::key();
	si3::Camera & camera = si3::Manager::camera();
	const si3::Mouse & mouse = si3::Manager::mouse();

	camera.x(0.0f);
	camera.y(16.0f);
	camera.z(-16.0f);

	God god;
	god.load();
	god.init();


	while (si3::Manager::begin_frame())
	{
		god.update();
		god.draw();


		si3::Manager::show();


	}

	return 0;
}

