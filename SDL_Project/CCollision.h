#pragma once
#include "CEntity.h"
#include <vector>

class CCollision
{
public:
	CCollision();
	~CCollision();

	CEntity* entityA;
	CEntity* entityB;

	static std::vector<CCollision> collision_list;
};