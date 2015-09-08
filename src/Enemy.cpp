#include "Enemy.h"

// @Override
void Enemy::init(si3::ModelData & modeld)
{
	Character::init(modeld);
	model.x(-3.0f);
	model.y(0.0f);
	model.z(0.0f);
}

// @Override
void Enemy::update()
{
	// todo

	Character::update();
}
