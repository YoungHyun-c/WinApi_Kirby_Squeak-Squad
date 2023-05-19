#include "PlayLevel.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>

// Contents
#include "Player.h"
#include "BackGround.h"
#include "Monster.h"


PlayLevel::PlayLevel()
{

}

PlayLevel::~PlayLevel()
{

}

void PlayLevel::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("Test,Bmp"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\BackGround\\");
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("StageTestPixel.bmp"));
	}
	// ResourcesManager::GetInst().TextureLoad("AAA.Png", ���);

	// �÷��� ������ ���������.
	// �� �������� ���� �־����?
	// �÷��̾� �����
	// �� �����
	// ���� �����
	// ����

	// �̷��� ����� �ڱ� ���Ǵ�� ����ڴٴ� ���̶� ���� xxxxx
	// Player* NewPlayer = new Player();

	BackGround* Back = CreateActor<BackGround>();
	Back->Init("StageTest.Bmp");

	LevelPlayer = CreateActor<Player>();
}

void PlayLevel::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown('O'))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}
	//GameEngineCore::ChangeLevel("TitleLevel");

	if (1.0f <= GetLiveTime())
	{
		Monster* NewMonster = CreateActor<Monster>();
		ResetLiveTime();
	}
}

void PlayLevel::Render()
{

}

void PlayLevel::Release()
{

}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	if (nullptr == LevelPlayer)
	{
		MsgBoxAssert("�÷��̾ ���������� �ʾҽ��ϴ�.");
	}
	
	LevelPlayer->SetGroundTexture("StageTestPixel.bmp");
	//float4 WinScale = GameEngineWindow::MainWindow.GetScale();
	//LevelPlayer->SetPos(WinScale.Half());
	// 0 0
	// x y
	//GetMainCamera()->SetPos(LevelPlayer->GetPos() - WinScale.Half());
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}