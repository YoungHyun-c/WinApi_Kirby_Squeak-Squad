#pragma once
#include "GameEngineObject.h"
#include "GameEngineActor.h"
#include <list>
#include <string>
#include <map>

// 설명 : 화면 혹은 장면을 표현한다.
// 타이틀 장면
// 플레이 장면
// 엔딩 장면
class GameEngineCamera;
class GameEngineLevel : public GameEngineObject
{
	friend class GameEngineCore;
	friend class GameEngineActor;

public:
	// constructer destructer
	GameEngineLevel();
	~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator = (const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator = (GameEngineLevel&& _Other) noexcept = delete;

	template<typename ActorType, typename EnumType>
	ActorType* CreateActor(EnumType _Order)
	{
		return CreateActor<ActorType>(static_cast<int>(_Order));
	}

	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0)
	{
		std::list<GameEngineActor*>& GroupList = AllActors[_Order];
		GameEngineActor* NewActor = new ActorType();
		ActorInit(NewActor, _Order);
		GroupList.push_back(NewActor);

		return dynamic_cast<ActorType*>(NewActor);
	}

	GameEngineCamera* GetMainCamera()
	{
		return MainCamera;
	}

protected:
	virtual void LevelStart(GameEngineLevel* _PrevLevel){}
	virtual void LevelEnd(GameEngineLevel* _NextLevel){}
private:
	// 맵
	// 몬스터
	// 플레이어

	// -10번 std::list<> 엑터 엑터 엑터
	// 0번 std::list<> 엑터 엑터 엑터
	// 1번 std::list<> 엑터 엑터 엑터
	GameEngineCamera* MainCamera;
	GameEngineCamera* UICamera;

	std::map<int, std::list<GameEngineActor*>> AllActors;

	void ActorInit(GameEngineActor* _Actor, int _Order);

	void ActorUpdate(float _Delta);
	void ActorRender(float _Delta);
	void ActorRelease();
};

