#include "Player.h"

// @Override
void Player::init(si3::ModelData & modeld)
{
	Character::init(modeld);
	model.x(0.0f);
	model.y(0.0f);
	model.z(0.0f);
}

// @Override
void Player::update()
{
	move();
	rotate();

	Character::update();
}


void Player::move()
{
	const float speed = 0.3f;

	if (si3::Manager::key().pushing(DIK_Q))
	{
		model.x(model.x() - speed);
	}
	if (si3::Manager::key().pushing(DIK_W))
	{
		model.x(model.x() + speed);
	}

	if (si3::Manager::key().pushing(DIK_A))
	{
		model.y(model.y() - speed);
	}
	if (si3::Manager::key().pushing(DIK_S))
	{
		model.y(model.y() + speed);
	}

	if (si3::Manager::key().pushing(DIK_Z))
	{
		model.z(model.z() - speed);
	}
	if (si3::Manager::key().pushing(DIK_X))
	{
		model.z(model.z() + speed);
	}
}

void Player::rotate()
{
	const float speed = 0.1f;

	if (si3::Manager::key().pushing(DIK_1))
	{
		model.radian_x(model.radian_x() + speed);
	}

	if (si3::Manager::key().pushing(DIK_2))
	{
		model.radian_y(model.radian_y() + speed);
	}

	if (si3::Manager::key().pushing(DIK_3))
	{
		model.radian_z(model.radian_z() + speed);
	}
}