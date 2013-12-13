#include "CCollision.h"

CCollision::CCollision()
{
	entityA=nullptr;
	entityB=nullptr;
}

CCollision::~CCollision()
{
}

std::vector<CCollision> CCollision::collision_list;