#pragma once

#include <simplect3D.h>

class OBB
{
public:
	void init(const si3::Coor3 & box_size, const si3::Coor3 & center_pos);
	void set_world_mat(const si3::Matrix & world_mat);





	const si3::Coor3 & get_half_length3() const;
	const si3::Coor3 & get_center() const;
	const si3::Matrix & get_world_mat() const;

private:
	
	si3::Coor3 half_length3;
	si3::Coor3 center;
	si3::Matrix world_mat;
};


bool is_colliding_OBB(const OBB & one, const OBB & ano);