#include "Character.h"
#include "util.h"

void Character::init(si3::ModelData & modeld)
{
	model.model_data(modeld);
	si3::Coor3 box_size;
	compute_bounding(model, box_size, center_pos);
	boxd.create(box_size.x, box_size.y, box_size.z);
	box.set_box_data(boxd);
	box.alpha(0.4f);
}

void Character::update()
{
	box.x(center_pos.x + model.x());
	box.y(center_pos.y + model.y());
	box.z(center_pos.z + model.z());

	box.rot_x(model.radian_x());
	box.rot_y(model.radian_y());
	box.rot_z(model.radian_z());

	box.red(0.4f);
	box.green(1.0f);
	box.blue(0.4f);
}

void Character::draw()
{
	si3::Manager::register_display_object(model);
	si3::Manager::register_display_object(box);
}


void Character::collided()
{
	box.red(1.0f);
	box.green(0.4f);
	box.blue(0.4f);
}