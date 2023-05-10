#pragma once
#include "GameEngineObject.h"
#include "GameEngineActor.h"
#include <list>
#include <string>
#include <map>

// ���� : ȭ�� Ȥ�� ����� ǥ���Ѵ�.
// Ÿ��Ʋ ���
// �÷��� ���
// ���� ���
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

	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0)
	{
		std::list<GameEngineActor*>& GroupList = AllActors[_Order];
		GameEngineActor* NewActor = new ActorType();
		ActorInit(NewActor);
		GroupList.push_back(NewActor);

		return dynamic_cast<ActorType*>(NewActor);
	}

protected:

private:
	// ��
	// ����
	// �÷��̾�

	// -10�� std::list<> ���� ���� ����
	// 0�� std::list<> ���� ���� ����
	// 1�� std::list<> ���� ���� ����
	GameEngineCamera* MainCamera;
	GameEngineCamera* UICamera;

	std::map<int, std::list<GameEngineActor*>> AllActors;

	void ActorInit(GameEngineActor* _Actor);

	void ActorUpdate(float _Delta);
	void ActorRender();

};

