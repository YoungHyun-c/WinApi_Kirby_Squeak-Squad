#include "Player.h"
#include "ContentsEnum.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include "Bullet.h"
#include <GameEnginePlatform/GameEngineInput.h>

Player::Player()
{

}

Player::~Player()
{

}

void Player::Start()
{
	//if (false == ResourcesManager::GetInst().IsLoadTexture("Test.Bmp"))
	//{
	//	// 무조건 자동으로 현재 실행중인 위치가 된다.
	//	GameEnginePath FilePath;

	//	FilePath.GetCurrentPath();

	//	//ResourcesManager::GetInst().TextureLoad("Player_Idle.Bmp");

	//	FilePath.MoveParentToExistsChild("Resource");
	//	FilePath.MoveChild("Resource\\Kirby\\Test.Bmp");

	//	ResourcesManager::GetInst().TextureLoad(FilePath.GetStringPath());

	//}

	//CreateRenderer("Test.Bmp");

	//SetPos({ 200, 200 });
	//SetScale({ 100, 100 });

	if (false == ResourcesManager::GetInst().IsLoadTexture("Test.Bmp"))
	{
		GameEnginePath FilePath;
		FilePath.GetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");

		//GameEnginePath FolderPath = FilePath;

		FilePath.MoveChild("Resource\\Kirby\\");

		//ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Test.bmp"));

		ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("Kirby.bmp"), 43, 14);
		//ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("Left_Player.bmp"), 5, 17);
		
		//FolderPath.MoveChild("Resources\\Texture\\");

		//ResourcesManager::GetInst().CreateSpriteFolder("FolderPlayer", FolderPath.PlusFilePath("FolderPlayer"));
		
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("HPBar.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Star.bmp"));
	}

	{
		MainRenderer = CreateRenderer(RenderOrder::Play);
		MainRenderer->SetRenderScale({ 200, 200 });

		MainRenderer->CreateAnimation("Idle", "Kirby.bmp", 0, 1, 0.1f, true);
		MainRenderer->CreateAnimation("Run", "Kirby.bmp", 10, 19, 0.1f, true);
		/*MainRenderer->CreateAnimation("Idle", "Left_Player.bmp", 0, 2, 0.1f, true);
		MainRenderer->CreateAnimation("Run", "Left_Player.bmp", 3, 6, 0.1f, true);*/
		MainRenderer->ChangeAnimation("Idle");
		/*GameEngineRenderer* Ptr = CreateRenderer("Test.Bmp", RenderOrder::Play);
		Ptr->SetRenderScale({ 50, 50 });
		Ptr->SetTexture("Test.Bmp");*/
	}

	{
		GameEngineRenderer* Ptr = CreateRenderer("HPbar.Bmp", RenderOrder::Play);
		Ptr->SetRenderPos({ -400, -270 });
		Ptr->SetRenderScale({ 200, 10 });
		Ptr->SetTexture("HPBar.Bmp");
	}

	float4 WinScale = GameEngineWindow::MainWindow.GetScale();
	// GetLevel()->GetMainCamera()->SetPos({ -WinScale.hX(), -WinScale.hY() });
	SetPos(WinScale.Half());
	// GetLevel()->GetMainCamera()->SetPos({ -WinScale.hX(), -WinScale.hY() });
}

void Player::Update(float _Delta)
{
	// 아주 어리석은 짓 절대로 아마 안될 계산을 하는것이다.
	// Player->GetPos() == Monster->GetPos();
	// float Time = GameEngineTime::MainTimer.GetDeltaTime();

	/*GameEngineTime::MainTimer;

	float Time = GameEngineTime::MainTimer.GetDeltaTime();


	AddPos({ 100.0f* _Delta, 0.0f });*/

	//static float Frame = 0.0f;
	//Frame += Delta *= 10.0f;
	//MainRenderer->SetSprite("Left_Player.bmp", (int)Frame);

	float Speed = 1000.0f;

	float4 MovePos = float4::ZERO;

	if (true == GameEngineInput::IsPress('A'))
	{
		MovePos = { -Speed * _Delta, 0.0f };
	}
	if (true == GameEngineInput::IsPress('D'))
	{
		MovePos = { Speed * _Delta, 0.0f };
	}
	if (true == GameEngineInput::IsPress('W'))
	{
		MovePos = {0.0f ,  -Speed * _Delta };
	}
	if (true == GameEngineInput::IsPress('S'))
	{
		MovePos = { 0.0f , Speed * _Delta };
	}

	if (MovePos.X != 0.0f || MovePos.Y != 0.0f)
	{
		MainRenderer->ChangeAnimation("Run");
	}
	else
	{
		MainRenderer->ChangeAnimation("Idle");
	}

	/*if (0 != GetAsyncKeyState('A'))
	{
		MovePos = { -Speed * _Delta, 0.0f };
	}
	if (0 != GetAsyncKeyState('D'))
	{
		MovePos = { Speed * _Delta, 0.0f };
	}
	if (0 != GetAsyncKeyState('W'))
	{
		MovePos = { 0.0f, -Speed * _Delta };
	}
	if (0 != GetAsyncKeyState('S'))
	{
		MovePos = { 0.0f, Speed * _Delta };
	}*/

	
	//if (0 != GetAsyncKeyState('F'))
	if (true == GameEngineInput::IsUp(VK_LBUTTON))
	{
		float4 Pos = GameEngineWindow::MainWindow.GetMousePos();

		Bullet* NewBullet = GetLevel()->CreateActor<Bullet>();
		NewBullet->Renderer->SetTexture("Star.Bmp");
		// 방향을 표현하는 xy는 크기가 1이어야 한다.
		NewBullet->SetDir(float4::RIGHT);
		NewBullet->SetPos(GetPos());
	}

	AddPos(MovePos);
	GetLevel()->GetMainCamera()->AddPos(MovePos);
}

void Player::Render()
{
	// SetPos({ 200, 200 });
	// SetScale({ 100, 100 });

	// 그렸을때 화면에 나오는건 언제나 window에 있는 BackBuffer에 그려야 한다.
	// 모든건 다 Texture
	//GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	//GameEngineWindowTexture* FindTexture = ResourcesManager::GetInst().FindTexture("Test.Bmp");
	//BackBuffer->TransCopy(FindTexture, GetPos(), { 100, 100 }, {0, 0}, FindTexture->GetScale());

	//HDC WindowDC = GameEngineWindow::MainWindow.GetHDC();
	//GameEngineTexture* FindTexture = ResourcesManager::GetInst().FindTexture("Test.Bmp");
	//HDC ImageDC = FindTexture->GetImageDC();

	//// 특정 DC에 연결된 색상을
	//// 특정 DC에 고속복사하는 함수

	//BitBlt(WindowDC, 100, 100, 500, 500, ImageDC, 0, 0, SRCCOPY);


	///*Rectangle(WindowDC,
	//	GetPos().iX() - GetScale().ihX(),
	//	GetPos().iY() - GetScale().ihY(),
	//	GetPos().iX() + GetScale().ihX(),
	//	GetPos().iY() + GetScale().ihY()
	//);
	//*/

}

void Player::Release()
{

}