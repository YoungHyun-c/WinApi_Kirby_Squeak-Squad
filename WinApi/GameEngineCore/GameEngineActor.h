#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineObject.h"
#include <string>
#include <list>

// 설명 : 화면안에 존재하는 플레이어 몬스터 총알 등등등 존재한다고 치고
// 위치가 있다면 이 녀석으로 표현해야 한다.
class GameEngineLevel;
class GameEngineRenderer;
class GameEngineActor : public GameEngineObject
{
	friend GameEngineLevel;
public:
	// constructer destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator = (const GameEngineActor& _Other) = delete;
	GameEngineActor& operator = (GameEngineActor&& _Other) noexcept = delete;

	void SetPos(const float4& _Pos)
	{
		Pos = _Pos;
	}

	// 실수는 무조건 오차가 생기긴한다.
	void AddPos(const float4& _Pos)
	{
		Pos += _Pos;
	}


	float4 GetPos()
	{
		return Pos;
	}

	template<typename EnumType>
	GameEngineRenderer* CreateRenderer(const std::string& _ImageName, EnumType _Order)
	{
		return CreateRenderer(_ImageName, static_cast<int>(_Order));
	}

	GameEngineRenderer* CreateRenderer(const std::string& _ImageName, int _Order);

	GameEngineLevel* GetLevel()
	{
		return Level;
	}

protected:

private:
	GameEngineLevel* Level;

	float4 Pos = float4::ZERO;
	float4 Scale = float4::ZERO; // <= 크기는 엑터한테 필요 없다.

	std::list<GameEngineRenderer*> AllRenderer;

	void PushMainCameraRenderer(GameEngineRenderer*);

};

