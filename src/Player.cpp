#include "Player.h"

// @Override
void Player::init(si3::ModelData & modeld)
{
	Character::init(modeld);
	model.x(3.0f);
	model.y(0.0f);
	model.z(0.0f);
}

// @Override
void Player::update()
{
	Character::update();

	box.x(center_pos.x + model.x());
	box.y(center_pos.y + model.y());
	box.z(center_pos.z + model.z());
}
