#include "Monster.h"
#include "Player.h"
#include <GameEngineCore/ResourcesManager.h>
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>


std::list<Monster*> Monster::AllMonster;

Monster::Monster()
{
	AllMonster.push_back(this);
}

Monster::~Monster()
{

}

void Monster::AllMonsterDeath()
{
	for (Monster* Monster : AllMonster)
	{
		Monster->Death();
	}

	AllMonster.clear();
}

void Monster::Update(float _Delta)
{
	// Player::MainPlayer = nullptr;

	float4 Dir = Player::GetMainPlayer()->GetPos() - GetPos();

	Dir.Normalize();

	// Dir <= 거리가 일정하지 않다는게 문제
	// Dir *= 0.1f;

	AddPos(Dir * _Delta * 100.0f);
}

void Monster::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("Test.Bmp"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\Kirby\\");
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("HPBar.bmp"));
	}

	{
		GameEngineRenderer* Ptr = CreateRenderer("HpBar.bmp", RenderOrder::Play);
		Ptr->SetRenderScale({ 150, 150 });
		//Ptr->SetTexture("HPBar.bmp");
	}

	GameEngineCollision* BodyCollision = CreateCollision(CollisionOrder::MonsterBody);
	BodyCollision->SetCollisionScale({ 100, 100 });
	BodyCollision->SetCollisionType(CollisionType::CirCle);
}