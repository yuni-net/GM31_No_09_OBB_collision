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
	si3::Matrix center_mat = si3::Matrix(center) * world_mat;
	world_center = center_mat.coor3();
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

const si3::Coor3 & OBB::get_world_center() const
{
	return world_center;
}





void extract_coor_axes(si3::Coor3 normal_vecs[6], const si3::Matrix & one_world_mat, const si3::Matrix & ano_world_mat)
{
	normal_vecs[0] = si3::Coor3(one_world_mat(1, 1), one_world_mat(1, 2), one_world_mat(1, 3));
	normal_vecs[1] = si3::Coor3(one_world_mat(2, 1), one_world_mat(2, 2), one_world_mat(2, 3));
	normal_vecs[2] = si3::Coor3(one_world_mat(3, 1), one_world_mat(3, 2), one_world_mat(3, 3));
	normal_vecs[3] = si3::Coor3(ano_world_mat(1, 1), ano_world_mat(1, 2), ano_world_mat(1, 3));
	normal_vecs[4] = si3::Coor3(ano_world_mat(2, 1), ano_world_mat(2, 2), ano_world_mat(2, 3));
	normal_vecs[5] = si3::Coor3(ano_world_mat(3, 1), ano_world_mat(3, 2), ano_world_mat(3, 3));
}

void compute_OBB_lengthes(
	si3::Coor3 OBB_lengthes[6],
	const si3::Coor3 normal_vecs[6],
	const si3::Coor3 one_half_length,
	const si3::Coor3 ano_half_length)
{
	OBB_lengthes[0] = normal_vecs[0] * one_half_length.x;
	OBB_lengthes[1] = normal_vecs[1] * one_half_length.y;
	OBB_lengthes[2] = normal_vecs[2] * one_half_length.z;
	OBB_lengthes[3] = normal_vecs[3] * ano_half_length.x;
	OBB_lengthes[4] = normal_vecs[4] * ano_half_length.y;
	OBB_lengthes[5] = normal_vecs[5] * ano_half_length.z;
}


/**
 * @brief このOBB同士が交差する可能性があるかどうかを判定する。
 * @param
 *     axis_isolation: 分離軸になるかもしれない候補を指定する。
 *     OBB_lengthes[6]: OBBの長さ(半分)を6つ並べた配列を指定する。
 *     vec_ano2one: anoからoneへのベクトルを指定する。
 * @return
 *     true: 交差する可能性がないとは言い切れない。
 *     false: 交差する可能性は無い！
 */
bool is_NOT_crossable(const si3::Coor3 & axis_isolation, const si3::Coor3 OBB_lengthes[6], const si3::Coor3 & vec_ano2one)
{
	float total_length = 0.0f;	// The total length of half shadow.
	for (int j = 0; j < 6; ++j)
	{
		total_length += fabsf(si3::Coor3::dot(axis_isolation, OBB_lengthes[j]));
	}
	if (fabsf(si3::Coor3::dot(axis_isolation, vec_ano2one)) >= total_length)
	{
		return true;
	}
	return false;
}


bool is_colliding_OBB(const OBB & one, const OBB & ano)
{
	si3::Coor3 normal_vecs[6];
	extract_coor_axes(normal_vecs, one.get_world_mat(), ano.get_world_mat());

	si3::Coor3 OBB_lengthes[6];
	compute_OBB_lengthes(OBB_lengthes, normal_vecs, one.get_half_length3(), ano.get_half_length3());

	si3::Coor3 vec_ano2one = ano.get_world_center() - one.get_world_center();

	for (int i = 0; i < 6; ++i)
	{
		if (is_NOT_crossable(normal_vecs[i], OBB_lengthes, vec_ano2one))
		{
			return false;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int k = 3; k < 6; ++k)
		{
			si3::Coor3 candidate = si3::Coor3::cross(normal_vecs[i], normal_vecs[k]);
			candidate.normalize();
			if (is_NOT_crossable(candidate, OBB_lengthes, vec_ano2one))
			{
				return false;
			}
		}
	}

	return true;
}