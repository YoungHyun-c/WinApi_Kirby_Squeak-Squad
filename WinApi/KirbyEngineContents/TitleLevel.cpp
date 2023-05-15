#include "TitleLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

#include "BackGround.h"

TitleLevel::TitleLevel()
{

}

TitleLevel::~TitleLevel()
{

}

void TitleLevel::Start()
{
	BackGround* Back = CreateActor<BackGround>();
	Back->Init("Title.Bmp");
}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown('P'))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}
}