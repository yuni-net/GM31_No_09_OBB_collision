#include <simplect3D.h>

/***
** ���E�{�b�N�X�����߁A
** ���̃{�b�N�X�̈�ӂ̒�����
** ���̒��S���W(���f���̃��[�J�����W)��Ԃ��܂�
*/
void compute_bounding(const si3::Model & model, si3::Coor3 & box_size, si3::Coor3 & center_pos)
{
	si3::Coor3 beggest = { 0.0f, 0.0f, 0.0f };
	si3::Coor3 smallest = { 0.0f, 0.0f, 0.0f };

	auto & modeld = model.model_data();

	auto top_list = modeld.lock_top_buffer();
	auto index_list = modeld.lock_index_buffer();

	for (unsigned long index_No = 0; index_No< modeld.index_num(); ++index_No)
	{
		unsigned short index = index_list[index_No];
		const si3::DxTop & top = top_list[index];
		const auto & pos = top.pos; // todo

		if (pos.x > beggest.x)
		{
			beggest.x = pos.x;
		}
		if (pos.y > beggest.y)
		{
			beggest.y = pos.y;
		}
		if (pos.z > beggest.z)
		{
			beggest.z = pos.z;
		}

		if (pos.x < smallest.x)
		{
			smallest.x = pos.x;
		}
		if (pos.y < smallest.y)
		{
			smallest.y = pos.y;
		}
		if (pos.z < smallest.z)
		{
			smallest.z = pos.z;
		}

#if 1
		box_size.x = (beggest.x >= abs(smallest.x)) ? beggest.x * 2 : abs(smallest.x) * 2;
		box_size.y = (beggest.y >= abs(smallest.y)) ? beggest.y * 2 : abs(smallest.y) * 2;
		box_size.z = (beggest.z >= abs(smallest.z)) ? beggest.z * 2 : abs(smallest.z) * 2;

		center_pos.x = 0.0f;
		center_pos.y = 0.0f;
		center_pos.z = 0.0f;
#else
		box_size.x = beggest.x - smallest.x;
		box_size.y = beggest.y - smallest.y;
		box_size.z = beggest.z - smallest.z;

		center_pos.x = smallest.x + box_size.x*0.5f;
		center_pos.y = smallest.y + box_size.y*0.5f;
		center_pos.z = smallest.z + box_size.z*0.5f;
#endif
	}

	modeld.unlock_index_buffer();
	modeld.unlock_top_buffer();

}
