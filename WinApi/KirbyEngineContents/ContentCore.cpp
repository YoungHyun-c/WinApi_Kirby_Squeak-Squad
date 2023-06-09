#include "ContentCore.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>

ContentCore::ContentCore()
{

}

ContentCore::~ContentCore()
{

}

void ContentCore::Start()
{
	GameEngineWindow::MainWindow.SetPosAndScale({ 0, 0 }, { 1024, 576 });
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::CreateLevel<EndingLevel>("EndingLevel");

	// 이 레벨이 화면에 보여라.
	GameEngineCore::ChangeLevel("PlayLevel");
}

// 행동하고
void ContentCore::Update(float _Delta)
{

}

// 그려지고
void ContentCore::Render(float _Delta)
{

}

// 정리된다.
void ContentCore::Release()
{

}
