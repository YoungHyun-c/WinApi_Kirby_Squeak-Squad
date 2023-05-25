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
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Stage1_1.bmp"));
	}
	// ResourcesManager::GetInst().TextureLoad("AAA.Png", 경로);

	// 플레이 레벨이 만들어졌다.
	// 이 레벨에는 뭐가 있어야지?
	// 플레이어 만들고
	// 맵 만들고
	// 몬스터 만들고
	// 액터

	// 이렇게 만들면 자기 임의대로 만들겠다는 것이라 절대 xxxxx
	// Player* NewPlayer = new Player();

	BackGroundPtr = CreateActor<BackGround>();
	BackGroundPtr->Init("StageTest.Bmp", "Stage1_1.bmp");
	
	/*BackGround* Back = CreateActor<BackGround>();
	Back->Init("StageTest.Bmp");*/

	LevelPlayer = CreateActor<Player>();
	LevelPlayer->SetGroundTexture("Stage1_1.bmp");
}

void PlayLevel::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown('O'))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}
	//GameEngineCore::ChangeLevel("TitleLevel");

	if (true == GameEngineInput::IsDown('J'))
	{
		BackGroundPtr->SwitchRender();
	}

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
		MsgBoxAssert("플레이어를 세팅해주지 않았습니다.");
	}
	
	LevelPlayer->SetGroundTexture("Stage1_1.bmp");
	//float4 WinScale = GameEngineWindow::MainWindow.GetScale();
	//LevelPlayer->SetPos(WinScale.Half());
	// 0 0
	// x y
	//GetMainCamera()->SetPos(LevelPlayer->GetPos() - WinScale.Half());
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}