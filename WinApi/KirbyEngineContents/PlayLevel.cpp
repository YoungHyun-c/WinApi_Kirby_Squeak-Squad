#include "PlayLevel.h"
#include "Player.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>

PlayLevel::PlayLevel()
{

}

PlayLevel::~PlayLevel()
{

}

void PlayLevel::Start()
{
	// ResourcesManager::GetInst().TextureLoad("AAA.Png", ���);

	// �÷��� ������ ���������.
	// �� �������� ���� �־����?
	// �÷��̾� �����
	// �� �����
	// ���� �����
	// ����

	// �̷��� ����� �ڱ� ���Ǵ�� ����ڴٴ� ���̶� ���� xxxxx
	// Player* NewPlayer = new Player();
	CreateActor<Player>();
}

void PlayLevel::Update(float _Delta)
{
	//GameEngineCore::ChangeLevel("TitleLevel");
}

void PlayLevel::Render()
{

}

void PlayLevel::Release()
{

}