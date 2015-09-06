#pragma once

#include <simplect3D.h>

class Character
{
public:
	virtual void init(si3::ModelData & modeld);
	virtual void update();
	void draw();

	void collided();


protected:
	si3::Model model;
	si3::Coor3 center_pos;
	si3::BoxData boxd;
	si3::Box box;
};