#include "GameEngineCamera.h"
#include <GameEngineBase/GameEngineDebug.h>

GameEngineCamera::GameEngineCamera()
{

}

GameEngineCamera::~GameEngineCamera()
{

}

void GameEngineCamera::Render()
{
	// for(const std::pair<int, std::list<GameEngineRenderer*>>& Pair : Renderers)
	
	std::map<int, std::list<GameEngineRenderer*>>::iterator GroupStartIter = Renderers.begin();
	std::map<int, std::list<GameEngineRenderer*>>::iterator GroupEndIter = Renderers.end();

	for (; GroupStartIter != GroupEndIter; ++GroupStartIter)
	{
		std::list<GameEngineRenderer*>& List = GroupStartIter->second;

		std::list<GameEngineRenderer*>::iterator RenderStartIter = List.begin();
		std::list<GameEngineRenderer*>::iterator RenderEndIter = List.end();

		for (; RenderStartIter != RenderEndIter; ++RenderStartIter)
		{
			GameEngineRenderer* Render = *RenderStartIter;

			if (false == Render->IsUpdate())
			{
				continue;
			}

			Render->Render(this);
		}
	}
}

void GameEngineCamera::PushRenderer(GameEngineRenderer* _Renderer, int _Order)
{
	if (nullptr == _Renderer)
	{
		MsgBoxAssert("nullptr�� �������� �׷쿡 ���ϰ� �Ϸ��� �����ϴ�.");
	}

	Renderers[_Order].push_back(_Renderer);
}

void GameEngineCamera::Release()
{
	std::map<int, std::list<GameEngineRenderer*>>::iterator GroupStartIter = Renderers.begin();
	std::map<int, std::list<GameEngineRenderer*>>::iterator GroupEndIter = Renderers.end();

	// ������ �̶� ������ ���̷��� ��.
	std::list<GameEngineRenderer*>::iterator ActorStartIter;
	std::list<GameEngineRenderer*>::iterator ActorEndIter;

	for (; GroupStartIter != GroupEndIter ; ++GroupStartIter)
	{
		std::list<GameEngineRenderer*>& Group = GroupStartIter->second;

		std::list<GameEngineRenderer*>::iterator ActorStartIter = Group.begin();
		std::list<GameEngineRenderer*>::iterator ActorEndIter = Group.end();

		for (; ActorStartIter != ActorEndIter;)
		{
			GameEngineRenderer* Object = *ActorStartIter;
			if (false == Object->IsDeath())
			{
				++ActorStartIter;
				continue;
			}

			if (nullptr == Object)
			{
				MsgBoxAssert("nullptr�� �������� ������ ����Ʈ�� �� �־����ϴ�.");
				continue;
			}

			ActorStartIter = Group.erase(ActorStartIter);
		}
	}
}