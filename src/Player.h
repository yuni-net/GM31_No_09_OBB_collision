#pragma once

#include "Character.h"

class Player :public Character
{
public:
	// @Override
	void init(si3::ModelData & modeld);
		 
	// @Override
	void update();



private:
	void move();
	void rotate();
};