#include "PlayLevel.h"
#include "Player.h"
#include <GameEngineCore/GameEngineCore.h>

PlayLevel::PlayLevel()
{

}

PlayLevel::~PlayLevel()
{

}

void PlayLevel::Start()
{
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

void PlayLevel::Update()
{
	//GameEngineCore::ChangeLevel("TitleLevel");
}

void PlayLevel::Render()
{

}

void PlayLevel::Release()
{

}