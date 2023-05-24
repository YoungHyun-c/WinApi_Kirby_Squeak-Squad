#pragma once
#include "GameEngineObject.h"
#include <GameEngineBase/GameEngineMath.h>
#include <string>
#include <map>
#include <vector>


enum class CollisionType
{
	Point,  // 점
	Rect,   // 사각형
	Circle, // 원
	Max,	// 확인용
};

// 설명 :
class GameEngineActor;
class CollisionInitClass;
class GameEngineCollision : public GameEngineObject
{
	static bool(*CollisionFunction[static_cast<int>(CollisionType::Max)][static_cast<int>(CollisionType::Max)])(GameEngineCollision* _Left, GameEngineCollision* _Right);

	friend CollisionInitClass;
	friend GameEngineActor;

public:
	static bool PointToPoint(GameEngineCollision* _Left, GameEngineCollision* _Right);
	static bool PointToRect(GameEngineCollision* _Left, GameEngineCollision* _Right);
	static bool PointToCirCle(GameEngineCollision* _Left, GameEngineCollision* _Right);

	static bool RectToPoint(GameEngineCollision* _Left, GameEngineCollision* _Right);
	static bool RectToRect(GameEngineCollision* _Left, GameEngineCollision* _Right);
	static bool RectToCirCle(GameEngineCollision* _Left, GameEngineCollision* _Right);

	static bool CirCleToPoint(GameEngineCollision* _Left, GameEngineCollision* _Right);
	static bool CirCleToRect(GameEngineCollision* _Left, GameEngineCollision* _Right);
	static bool CirCleToCirCle(GameEngineCollision* _Left, GameEngineCollision* _Right);


	// constructer destructer
	GameEngineCollision();
	~GameEngineCollision();

	// delete Function
	GameEngineCollision(const GameEngineCollision& _Other) = delete;
	GameEngineCollision(GameEngineCollision&& _Other) noexcept = delete;
	GameEngineCollision& operator = (const GameEngineCollision& _Other) = delete;
	GameEngineCollision& operator = (GameEngineCollision&& _Other) noexcept = delete;

	void SetCollisionScale(const float4 _Value)
	{
		CollisionScale = _Value;
	}

	// 플레이어 위치기준
	void SetCollisionPos(const float4& _Value)
	{
		CollisionPos = _Value;
	}

	// 몇가지 문제가 있다
	// 1. 몬스터에 몬스터랑

	// 나는 사각형
	// int _Order => 나는 _Order 랑 충돌
	// CollisionType _ThisType 나를 점으로, 사각형으로 봐죠
	// CollisionType _OtherType 상대는 원으로 봐줘, 사각형으로 봐죠
	// std::vector<GameEngineCollision*>& _Result 충돌된 애들 여기에 담아줘.

	template<typename EnumType>
	bool Collision(EnumType _Order, std::vector<GameEngineCollision*>& _Result
		, CollisionType _ThisType = CollisionType::Circle
		, CollisionType _OtherType = CollisionType::Circle)
	{
		return Collision(static_cast<int>(_Order), _Result, _ThisType, _OtherType);
	}

	bool Collision(int _Order, std::vector<GameEngineCollision*>& _Result
		, CollisionType _ThisType = CollisionType::Circle
		, CollisionType _OtherType = CollisionType::Circle);

	void SetOrder(int _Order) override;

	GameEngineActor* GetActor()
	{
		return Master;
	}
	
	bool CollisionCheck(GameEngineCollision* _Other
		, CollisionType _ThisType
		, CollisionType _OtherType);

protected:

private:
	GameEngineActor* Master = nullptr;
	float4 CollisionPos;
	float4 CollisionScale;

};

