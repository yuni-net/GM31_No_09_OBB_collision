#include "JudgeMan.h"

void JudgeMan::clear()
{
	chara_list.zerosize();
}

void JudgeMan::register_chara(Character & chara)
{
	chara_list.add(&chara);
}

void JudgeMan::judge()
{
	for (fw::uint begindex = 0; begindex < chara_list.size(); ++begindex)
	{
		for (fw::uint targetdex = begindex + 1; targetdex < chara_list.size(); ++targetdex)
		{
			Character & one = *(chara_list[begindex]);
			Character & ano = *(chara_list[targetdex]);
			bool is_colliding = is_colliding_OBB(one.get_obb(), ano.get_obb());
			if (is_colliding)
			{
				one.collided();
				ano.collided();
			}
		}
	}
}
