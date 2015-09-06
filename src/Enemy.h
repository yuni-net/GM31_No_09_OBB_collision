#pragma once

#include "Character.h"

class Enemy :public Character
{
public:
	// @Override
	void init(si3::ModelData & modeld);

	// @Override
	void update();
};