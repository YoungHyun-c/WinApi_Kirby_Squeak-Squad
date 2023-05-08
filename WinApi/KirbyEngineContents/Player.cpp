#include "Player.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/ResourcesManager.h>

Player::Player()
{

}

Player::~Player()
{

}

void Player::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("Test.Bmp"))
	{
		// 무조건 자동으로 현재 실행중인 위치가 된다.
		GameEnginePath FilePath;

		FilePath.GetCurrentPath();

		//ResourcesManager::GetInst().TextureLoad("Player_Idle.Bmp");

		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\Kirby\\Test.Bmp");

		ResourcesManager::GetInst().TextureLoad(FilePath.GetStringPath());

	}

	SetPos({ 200, 200 });
	SetScale({ 100, 100 });
}

void Player::Update(float _Delta)
{
	// 아주 어리석은 짓 절대로 아마 안될 계산을 하는것이다.
	// Player->GetPos() == Monster->GetPos();
	// float Time = GameEngineTime::MainTimer.GetDeltaTime();

	GameEngineTime::MainTimer;

	float Time = GameEngineTime::MainTimer.GetDeltaTime();


	AddPos({ 100.0f* _Delta, 0.0f });
}

void Player::Render()
{
	// SetPos({ 200, 200 });
	// SetScale({ 100, 100 });

	HDC WindowDC = GameEngineWindow::MainWindow.GetHDC();
	GameEngineTexture* FindTexture = ResourcesManager::GetInst().FindTexture("Test.Bmp");
	HDC ImageDC = FindTexture->GetImageDC();

	// 특정 DC에 연결된 색상을
	// 특정 DC에 고속복사하는 함수

	BitBlt(WindowDC, 100, 100, 500, 500, ImageDC, 0, 0, SRCCOPY);


	/*Rectangle(WindowDC,
		GetPos().iX() - GetScale().ihX(),
		GetPos().iY() - GetScale().ihY(),
		GetPos().iX() + GetScale().ihX(),
		GetPos().iY() + GetScale().ihY()
	);
	*/

	// 그려야죠
}

void Player::Release()
{

}