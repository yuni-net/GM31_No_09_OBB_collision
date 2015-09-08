#include "OBB.h"


void OBB::init(const si3::Coor3 & box_size, const si3::Coor3 & center_pos)
{
	half_length3.x = box_size.x * 0.5f;
	half_length3.y = box_size.y * 0.5f;
	half_length3.z = box_size.z * 0.5f;

	center = center_pos;
}

void OBB::set_world_mat(const si3::Matrix & world_mat)
{
	this->world_mat = world_mat;
}


const si3::Coor3 & OBB::get_half_length3() const
{
	return half_length3;
}
const si3::Coor3 & OBB::get_center() const
{
	return center;
}
const si3::Matrix & OBB::get_world_mat() const
{
	return world_mat;
}




bool is_colliding_OBB(const OBB & one, const OBB & ano)
{
	// todo
	return false;
}