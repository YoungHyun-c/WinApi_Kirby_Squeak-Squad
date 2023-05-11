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
	//	// ������ �ڵ����� ���� �������� ��ġ�� �ȴ�.
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
		FilePath.MoveChild("Resource\\Kirby\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Test.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("HPBar.bmp"));
	}

	{
		GameEngineRenderer* Ptr = CreateRenderer("Test.Bmp", RenderOrder::Play);
		Ptr->SetRenderScale({ 50, 50 });
		Ptr->SetTexture("Test.Bmp");
	}

	{
		GameEngineRenderer* Ptr = CreateRenderer("HPbar.Bmp", RenderOrder::Play);
		Ptr->SetRenderPos({ -400, -270 });
		Ptr->SetRenderScale({ 200, 10 });
		Ptr->SetTexture("HPBar.Bmp");
	}

	float4 WinScale = GameEngineWindow::MainWindow.GetSCale();
	// GetLevel()->GetMainCamera()->SetPos({ -WinScale.hX(), -WinScale.hY() });
	SetPos(WinScale.Half());
	// GetLevel()->GetMainCamera()->SetPos({ -WinScale.hX(), -WinScale.hY() });
}

void Player::Update(float _Delta)
{
	// ���� ����� �� ����� �Ƹ� �ȵ� ����� �ϴ°��̴�.
	// Player->GetPos() == Monster->GetPos();
	// float Time = GameEngineTime::MainTimer.GetDeltaTime();

	/*GameEngineTime::MainTimer;

	float Time = GameEngineTime::MainTimer.GetDeltaTime();


	AddPos({ 100.0f* _Delta, 0.0f });*/

	float Speed = 200.0f;

	float4 MovePos = float4::ZERO;

	if (0 != GetAsyncKeyState('A'))
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
	}

	AddPos(MovePos);
	GetLevel()->GetMainCamera()->AddPos(MovePos);
}

void Player::Render()
{
	// SetPos({ 200, 200 });
	// SetScale({ 100, 100 });

	// �׷����� ȭ�鿡 �����°� ������ window�� �ִ� BackBuffer�� �׷��� �Ѵ�.
	// ���� �� Texture
	//GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	//GameEngineWindowTexture* FindTexture = ResourcesManager::GetInst().FindTexture("Test.Bmp");
	//BackBuffer->TransCopy(FindTexture, GetPos(), { 100, 100 }, {0, 0}, FindTexture->GetScale());

	//HDC WindowDC = GameEngineWindow::MainWindow.GetHDC();
	//GameEngineTexture* FindTexture = ResourcesManager::GetInst().FindTexture("Test.Bmp");
	//HDC ImageDC = FindTexture->GetImageDC();

	//// Ư�� DC�� ����� ������
	//// Ư�� DC�� ��Ӻ����ϴ� �Լ�

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