#pragma once

#include "OBB.h"
#include "Character.h"

class JudgeMan
{
public:
	void clear();
	void register_chara(Character & chara);
	void judge();



private:
	fw::Array<Character *> chara_list;
};