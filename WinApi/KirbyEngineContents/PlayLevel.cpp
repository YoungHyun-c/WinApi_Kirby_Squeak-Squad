#include "PlayLevel.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/TileMap.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include "PlayUIManager.h"

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
	// ResourcesManager::GetInst().TextureLoad("AAA.Png", ���);
	if (false == ResourcesManager::GetInst().IsLoadTexture("Test,Bmp"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\BackGround\\");
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("BoSSTest1_1.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Tile.bmp"));
		ResourcesManager::GetInst().CreateSpriteSheet("Tile.bmp", 24, 40);
	}

	GameEngineSound::SetGlobalVolume(0.5f);
	if (nullptr == GameEngineSound::FindSound("Stage1.mp3"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\Sound\\");

		GameEngineSound::SoundLoad(FilePath.PlusFilePath("Stage1.mp3"));
	}

	// �÷��� ������ ���������.
	// �� �������� ���� �־����?
	// �÷��̾� �����
	// �� �����
	// ���� �����
	// ����

	// �̷��� ����� �ڱ� ���Ǵ�� ����ڴٴ� ���̶� ���� xxxxx
	// Player* NewPlayer = new Player();

	//GameEngineWindow::MainWindow.CursorOff(); //Ŀ�� ���ֱ�
	
	TileObject = CreateActor<TileMap>();


	BackGroundPtr = CreateActor<BackGround>();
	BackGroundPtr->Init("BoSSTest.Bmp", "BoSSTest1_1.bmp");
	//BackGroundPtr->CreateRenderer("BoSSTest.bmp", 0);
	//BackGroundPtr->CreateRenderer("BoSSTest1_1.bmp", 0);
	TileObject->CreateRenderer("Tile.bmp", 1);
	
	TileObject->CreateTileMap("Tile.bmp", 20, 20, { 50, 50 }, 0);
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			TileObject->SetTile(x, y, 0);
		}
	}

	/*BackGround* Back = CreateActor<BackGround>();
	Back->Init("StageTest.Bmp");*/

	LevelPlayer = CreateActor<Player>();
	LevelPlayer->SetGroundTexture("BoSSTest1_1.bmp");
	//LevelPlayer->OverOn();

	CreateActor<PlayUIManager>();
}

void PlayLevel::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown('O'))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	if (true == GameEngineInput::IsDown('T'))
	{
		TileObject->SetTile(LevelPlayer->GetPos(), 3);
	}
	//GameEngineCore::ChangeLevel("TitleLevel");

	if (true == GameEngineInput::IsDown('P'))
	{
		BGMPlayer.Stop();
	}

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


void PlayLevel::Release()
{

}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	if (nullptr == LevelPlayer)
	{
		MsgBoxAssert("�÷��̾ ���������� �ʾҽ��ϴ�.");
	}
	
	BGMPlayer = GameEngineSound::SoundPlay("Stage1.mp3");

	LevelPlayer->SetGroundTexture("BoSSTest1_1.bmp");
	//float4 WinScale = GameEngineWindow::MainWindow.GetScale();
	//LevelPlayer->SetPos(WinScale.Half());
	// 0 0
	// x y
	//GetMainCamera()->SetPos(LevelPlayer->GetPos() - WinScale.Half());
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}