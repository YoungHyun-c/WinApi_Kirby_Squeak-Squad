#include "Player.h"
#pragma region Headers

#include "ContentsEnum.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCore.h>
#include "Bullet.h"
#include "Monster.h"
#include "PlayUIManager.h"
#include <GameEnginePlatform/GameEngineInput.h>

#pragma endregion

Player* Player::MainPlayer = nullptr;

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

	if (false == ResourcesManager::GetInst().IsLoadTexture("KirbyRightNormal.Bmp"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");

		GameEnginePath FolderPath = FilePath;

		FilePath.MoveChild("Resource\\Kirby\\");

		//ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Test.bmp"));

		GameEngineWindowTexture* T = ResourcesManager::GetInst().TextureCreate("Fade", { 1024, 576 });
		T->FillTexture(RGB(0, 0, 0));

		ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("KirbyRightNormal.bmp"), 5, 25);
		ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("KirbyLeftNormal.bmp"), 5, 25);
		
		//ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("BossStageAni.bmp"), 6, 2); //BOSS Stage

		//ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("KirbyTest.bmp"), 42, 1);
		//ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("Left_Kirby.bmp"), 42, 14);
		//ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("Right_Kirby.bmp"), 42, 14);
		/*ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("Left_Player.bmp"), 5, 17);
		ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("Right_Player.bmp"), 5, 17);*/
		
		//FolderPath.MoveChild("Resources\\Texture\\");
		//ResourcesManager::GetInst().CreateSpriteFolder("FolderPlayer", FolderPath.PlusFilePath("FolderPlayer"));
		
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Test.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("HPBar.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Star.bmp"));
	}

	{
		//MainRenderer = CreateRenderer(RenderOrder::Play);
		MainRenderer = CreateRenderer(RenderOrder::Play);

		//Folder
		/*MainRenderer->CreateAnimation("Test", "FolderPlayer");
		MainRenderer->CreateAnimation("Left_Idle", "Left_Player.bmp", 0, 2, 0.1f, true);
		MainRenderer->CreateAnimation("Right_Idle", "FolderPlayer");
		MainRenderer->CreateAnimation("Left_Run", "Left_Player.bmp", 3, 6, 0.1f, true);
		MainRenderer->CreateAnimation("Right_Run", "Right_Player.bmp", 20, 0, 0.1f, true);
		MainRenderer->ChangeAnimation("Test");
		MainRenderer->SetRenderScaleToTexture();*/
		//


		//MainRenderer->SetRenderScale({ 200, 200 });

		//MainRenderer->CreateAnimation("Left_Idle", "KirbyTest.bmp", 0, 1, 0.1f, true);
		//MainRenderer->CreateAnimation("Left_Run", "KirbyTest.bmp", 10, 19, 0.1f, true);
		//MainRenderer->CreateAnimation("Right_Idle", "KirbyTest.bmp", 0, 1, 0.1f, true);
		//MainRenderer->CreateAnimation("Right_Run", "KirbyTest.bmp", 10, 19, 0.1f, true);

		/*MainRenderer->CreateAnimation("Idle", "Kirby.bmp", 0, 1, 0.1f, true);
		MainRenderer->CreateAnimation("Run", "Kirby.bmp", 10, 19, 0.1f, true);*/

		//MainRenderer->CreateAnimation("Left_Idle", "Kirby.bmp", 0, 1, 0.1f, true);
		//MainRenderer->CreateAnimation("Right_Idle", "Kirby.bmp", 0, 1, 0.1f, true);

		//MainRenderer->CreateAnimation("Left_Run", "Kirby.bmp", 10, 19, 0.1f, true);
		//MainRenderer->CreateAnimation("Right_Run", "Kirby.bmp", 10, 19, 0.1f, true);
		//MainRenderer->CreateAnimation("Left_Idle", "Left_Player.bmp", 0, 2, 0.1f, true);
		//MainRenderer->CreateAnimation("Right_Idle", "Right_Player.bmp", 0, 2, 0.1f, true);

		//MainRenderer->CreateAnimation("Left_Run", "Left_Player.bmp", 3, 6, 0.1f, true);
		//MainRenderer->CreateAnimation("Right_Run", "Right_Player.bmp", 10, 0, 0.1f, true);

		MainRenderer->CreateAnimation("Left_Idle", "KirbyLeftNormal.bmp", 0, 1, 1.0f, true);
		MainRenderer->CreateAnimation("Right_Idle", "KirbyRightNormal.bmp", 0, 1, 1.0f, true);

		MainRenderer->CreateAnimation("Left_Run", "KirbyLeftNormal.bmp", 0, 13, 0.1f, true);
		MainRenderer->CreateAnimation("Right_Run", "KirbyRightNormal.bmp", 0, 13, 0.1f, true);

		//MainRenderer->CreateAnimation("Idle", "BossStageAni.bmp", 0, 11, 0.1f, true);
		//MainRenderer->ChangeAnimation("Idle");
		MainRenderer->ChangeAnimation("Right_Idle");
		
		MainRenderer->SetRenderScale({ 400, 400 });
		//MainRenderer->SetRenderScaleToTexture();

		/*GameEngineRenderer* Ptr = CreateRenderer("Test.Bmp", RenderOrder::Play);
* 
* 
		Ptr->SetRenderScale({ 50, 50 });
		Ptr->SetTexture("Test.Bmp");*/

	}

	{
		GameEngineRenderer* Ptr = CreateRenderer("HPbar.Bmp", RenderOrder::Play);
		Ptr->SetRenderPos({ -400, -270 });
		Ptr->SetRenderScale({ 200, 200 });
		Ptr->SetTexture("HPBar.Bmp");
		Ptr->SetText("HP");
	}

	{
		//GameEngineRenderer* Ptr = CreateRenderer("Fade", 6000);
		//Ptr->SetRenderScale({ 1024, 576 });
	}

	{
		BodyCollision = CreateCollision(CollisionOrder::PlayerBody);
		BodyCollision->SetCollisionScale({ 100, 100 });
		BodyCollision->SetCollisionType(CollisionType::Rect);

	}

	ChangeState(PlayerState::Idle);
	Dir = PlayerDir::Right;

	//float4 WinScale = GameEngineWindow::MainWindow.GetScale();
	//GetLevel()->GetMainCamera()->SetPos({ -WinScale.hX(), -WinScale.hY() });
	//SetPos(WinScale.Half());
	//GetLevel()->GetMainCamera()->SetPos({ -WinScale.hX(), -WinScale.hY() });
}

void Player::Update(float _Delta)
{
	std::vector<GameEngineCollision*> _Col;
	if (true == BodyCollision->Collision(CollisionOrder::MonsterBody, _Col
		, CollisionType::Rect
		, CollisionType::CirCle
	))
	{
		for (size_t i = 0; i < _Col.size(); i++)
		{
			GameEngineCollision* Collision = _Col[i];

			GameEngineActor* Actor = Collision->GetActor();

			Actor->Death();
		}
		// 나는 몬스터랑 충돌한거야.
	}


	if (true == GameEngineInput::IsDown('L'))
	{
		Monster::AllMonsterDeath();
	}

	if (true == GameEngineInput::IsDown('Y'))
	{
		//MainRenderer->SetOrder(100);
		GameEngineLevel::CollisionDebugRenderSwitch();
		//GravityOff();
	}

	if (true == GameEngineInput::IsPress('N'))
	{
		GameEngineWindow::MainWindow.AddDoubleBufferingCopyScaleRatio(-1.0f * _Delta);
	}

	if (true == GameEngineInput::IsPress('M'))
	{
		GameEngineWindow::MainWindow.AddDoubleBufferingCopyScaleRatio(1.0f * _Delta);
	}

	StateUpdate(_Delta);

	CameraFocus();

	// Gravity(); 항상 적용 되면 안됨.
	
	// 아주 어리석은 짓 절대로 아마 안될 계산을 하는것이다.
	// Player->GetPos() == Monster->GetPos();
	// float Time = GameEngineTime::MainTimer.GetDeltaTime();

	//GameEngineTime::MainTimer;

	//float Time = GameEngineTime::MainTimer.GetDeltaTime();


	//AddPos({ 100.0f* _Delta, 0.0f });

	//static float Frame = 0.0f;
	//Frame += Delta *= 10.0f;
	//MainRenderer->SetSprite("Left_Player.bmp", (int)Frame);

	//float Speed = 1000.0f;

	//float4 MovePos = float4::ZERO;

	//if (true == GameEngineInput::IsPress('A'))
	//{
	//	MovePos = { -Speed * _Delta, 0.0f };
	//}
	//if (true == GameEngineInput::IsPress('D'))
	//{
	//	MovePos = { Speed * _Delta, 0.0f };
	//}
	//if (true == GameEngineInput::IsPress('W'))
	//{
	//	MovePos = {0.0f ,  -Speed * _Delta };
	//}
	//if (true == GameEngineInput::IsPress('S'))
	//{
	//	MovePos = { 0.0f , Speed * _Delta };
	//}

	//if (MovePos.X != 0.0f || MovePos.Y != 0.0f)
	//{
	//	MainRenderer->ChangeAnimation("Run");
	//}
	//else
	//{
	//	MainRenderer->ChangeAnimation("Idle");
	//}

	///*if (0 != GetAsyncKeyState('A'))
	//{
	//	MovePos = { -Speed * _Delta, 0.0f };
	//}
	//if (0 != GetAsyncKeyState('D'))
	//{
	//	MovePos = { Speed * _Delta, 0.0f };
	//}
	//if (0 != GetAsyncKeyState('W'))
	//{
	//	MovePos = { 0.0f, -Speed * _Delta };
	//}
	//if (0 != GetAsyncKeyState('S'))
	//{
	//	MovePos = { 0.0f, Speed * _Delta };
	//}*/

	//
	////if (0 != GetAsyncKeyState('F'))
	if (true == GameEngineInput::IsUp(VK_LBUTTON))
	{
		float4 Pos = GameEngineWindow::MainWindow.GetMousePos();

		Bullet* NewBullet = GetLevel()->CreateActor<Bullet>();
		NewBullet->Renderer->SetTexture("Star.Bmp");
		// 방향을 표현하는 xy는 크기가 1이어야 한다.
		NewBullet->SetDir(float4::RIGHT);
		NewBullet->SetPos(GetPos());
	}

	//AddPos(MovePos);
	//GetLevel()->GetMainCamera()->AddPos(MovePos);
}

//void Player::Render()
//{
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
//}

void Player::StateUpdate(float _Delta)
{
	switch (State)

	{
	case PlayerState::Idle:
		return IdleUpdate(_Delta);
	case PlayerState::Run:
		return RunUpdate(_Delta);
	default:
		break;
	}
}

void Player::ChangeState(PlayerState _State)
{
	if (_State != State)
	{
		switch (_State)

		{
		case PlayerState::Idle:
			IdleStart();
			break;
		case PlayerState::Run:
			RunStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Player::DirCheck()
{
	PlayerDir CheckDir = PlayerDir::Max;

	if (true == GameEngineInput::IsDown('A'))
	{
		CheckDir = PlayerDir::Left;
	}
	else if (true == GameEngineInput::IsDown('D'))
	{
		CheckDir = PlayerDir::Right;
	}

	bool ChangeDir = false;

	if (CheckDir != PlayerDir::Max)
	{
		Dir = CheckDir;
		ChangeDir = true;
	}

	if (CheckDir != PlayerDir::Max && true == ChangeDir)
	{
		ChangeAnimationState(CurState);
	}
}

void Player::ChangeAnimationState(const std::string& _StateName)
{
	// "Idle"
	// _StateName

	std::string AnimationName;

	switch (Dir)
	{
	case PlayerDir::Right:
		AnimationName = "Right_";
		break;
	case PlayerDir::Left:
		AnimationName = "Left_";
		break;
	default:
		break;
	}
	AnimationName += _StateName;

	CurState = _StateName;

	MainRenderer->ChangeAnimation(AnimationName);
}

void Player::LevelStart()
{
	MainPlayer = this;
}

void Player::Render(float _Delta)
{
	std::string Text = "";

	Text += "플레이어 테스트 값 : ";
	Text += std::to_string(1.0f / _Delta);
	HDC dc = GameEngineWindow::MainWindow.GetBackBuffer()->GetImageDC();
	TextOutA(dc, 800, 3, Text.c_str(), static_cast<int>(Text.size()));

	CollisionData Data;

	Data.Pos = ActorCameraPos();
	Data.Scale = { 180, 80};
	//Rectangle(dc, Data.iLeft(), Data.iTop(), Data.iRight(), Data.iBot());

	// 커피가 공격할 범위
	Data.Pos = ActorCameraPos() + LeftCheck;
	Rectangle(dc, Data.iLeft(), Data.iTop(), Data.iRight(), Data.iBot());

	Data.Pos = ActorCameraPos() + RightCheck;
	Rectangle(dc, Data.iLeft(), Data.iTop(), Data.iRight(), Data.iBot());
}

