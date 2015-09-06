#include <simplect3D.h>
#include "CameraWork.h"

void CameraWork::init()
{
	first_mat.x(0.0f);
	first_mat.y(0.0f);
	first_mat.z(12.0f);

	radian.x = 0.1f;
	radian.y = 0.0f;
	radian.z = 0.0f;
}

void CameraWork::update()
{
	const float rot_speed = 0.1f;
	if (si3::Manager::key().pushing(DIK_W))
	{
		radian.x += rot_speed;
	}
	if (si3::Manager::key().pushing(DIK_D))
	{
		radian.y += rot_speed;
	}
	if (si3::Manager::key().pushing(DIK_S))
	{
		radian.x -= rot_speed;
	}
	if (si3::Manager::key().pushing(DIK_A))
	{
		radian.y -= rot_speed;
	}




	si3::Matrix converted_mat = first_mat;
	converted_mat *= si3::Matrix().rotate_y(radian.y);
	converted_mat *= si3::Matrix().rotate_x(radian.x);

	auto & camera = si3::Manager::camera();

	camera.x(converted_mat.x());
	camera.y(converted_mat.y());
	camera.z(converted_mat.z());
}
