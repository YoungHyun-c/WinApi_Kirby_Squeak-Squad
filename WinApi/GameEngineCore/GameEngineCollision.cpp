#include "GameEngineCollision.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <list>

GameEngineCollision::GameEngineCollision()
{

}

GameEngineCollision::~GameEngineCollision()
{

}

bool (*GameEngineCollision::CollisionFunction[static_cast<int>(CollisionType::Max)][static_cast<int>(CollisionType::Max)])(GameEngineCollision* _Left, GameEngineCollision* _Right) = { nullptr };

bool GameEngineCollision::PointToPoint(GameEngineCollision* _Left, GameEngineCollision* _Right)	 
{
	return false;
}
bool GameEngineCollision::PointToRect(GameEngineCollision* _Left, GameEngineCollision* _Right)	 
{
	return false;
}
bool GameEngineCollision::PointToCirCle(GameEngineCollision* _Left, GameEngineCollision* _Right) 
{
	return false;
}
																								 
bool GameEngineCollision::RectToPoint(GameEngineCollision* _Left, GameEngineCollision* _Right)	 
{
	return false;
}
bool GameEngineCollision::RectToRect(GameEngineCollision* _Left, GameEngineCollision* _Right)	 
{
	return false;
}
bool GameEngineCollision::RectToCirCle(GameEngineCollision* _Left, GameEngineCollision* _Right)	 
{
	return false;
}
																								 
bool GameEngineCollision::CirCleToPoint(GameEngineCollision* _Left, GameEngineCollision* _Right) 
{
	return false;
}
bool GameEngineCollision::CirCleToRect(GameEngineCollision* _Left, GameEngineCollision* _Right)	 
{
	return false;
}
bool GameEngineCollision::CirCleToCirCle(GameEngineCollision* _Left, GameEngineCollision* _Right)
{
	return false;
}

class CollisionInitClass
{
public:
	CollisionInitClass()
	{
		GameEngineCollision::CollisionFunction[static_cast<size_t>(CollisionType::Point)][static_cast<size_t>(CollisionType::Point)] = &GameEngineCollision::PointToPoint;
	}
};

CollisionInitClass ColInitInst = CollisionInitClass();

bool GameEngineCollision::Collision(int _Order,
	std::vector<GameEngineCollision*>& _Result,
	CollisionType _ThisType,
	CollisionType _OtherType)
{
	if (false == IsUpdate())
	{
		return false;
	}

	std::list<GameEngineCollision*>& OtherCollision = Master->GetLevel()->AllCollision[_Order];

	if (0 == OtherCollision.size())
	{
		return false;
	}

	bool Check = false;

	for (GameEngineCollision* Collision : OtherCollision)
	{
		if (nullptr == Collision)
		{
			MsgBoxAssert("존재하지 않는 콜리전이 있습니다.");
			return false;
		}

		if (false == Collision->IsUpdate())
		{
			continue;
		}

		// 어느순간에 콜리전은 레벨에 들어가는가?
		// 언제 관리되는가?
		// 어떻게 꺼내오는가?
		// Level

		// 상대랑 나랑 충돌을 해보는 것.
		if (true == CollisionCheck(Collision, _ThisType, _OtherType))
		{
			_Result.push_back(Collision);
			Check = true;
		}
	}

	return Check;
}

void GameEngineCollision::SetOrder(int _Order)
{
	std::list<GameEngineCollision*>& PrevCollisions = Master->GetLevel()->AllCollision[GetOrder()];
	PrevCollisions.remove(this);

	GameEngineObject::SetOrder(_Order);

	std::list<GameEngineCollision*>& NextCollisions = Master->GetLevel()->AllCollision[GetOrder()];
	NextCollisions.push_back(this);
}

bool GameEngineCollision::CollisionCheck(GameEngineCollision* _Other
	, CollisionType _ThisType
	, CollisionType _OtherType)
{
	return false;
	return CollisionFunction[static_cast<int>(_ThisType)][static_cast<int>(_OtherType)](this, _Other);
}