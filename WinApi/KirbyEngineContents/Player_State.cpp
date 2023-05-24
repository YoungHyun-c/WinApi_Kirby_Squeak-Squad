#include "Player.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>

void Player::IdleStart()
{
	ChangeAnimationState("Idle");
	//MainRenderer->ChangeAnimation("Right_Idle");
}

void Player::RunStart()
{
	ChangeAnimationState("Run");
	//MainRenderer->ChangeAnimation("Right_Run");
}

void Player::IdleUpdate(float _Delta)
{
	{
		unsigned int Color = GetGroundColor(RGB(255, 255, 255));
		if (RGB(255, 255, 255) == Color)
		{
			Gravity(_Delta);
		}
		else
		{
			unsigned int CheckColor = GetGroundColor(RGB(255, 255, 255), float4::UP);

			while (CheckColor != RGB(255, 255, 255))
			{
				CheckColor = GetGroundColor(RGB(255, 255, 255), float4::UP);
				AddPos(float4::UP);
			}


			GravityReset();
		}
	}

	
	if (true == GameEngineInput::IsDown('A')
		|| true == GameEngineInput::IsDown('W')
		|| true == GameEngineInput::IsDown('S')
		|| true == GameEngineInput::IsDown('D')
		)
	{
		DirCheck();
		ChangeState(PlayerState::Run);
		return;
	}

	// 줄줄이 사탕
	// if (true)
	// {
	//		ChangeState(PlayerState::Idle);
	// }
}

void Player::RunUpdate(float _Delta)
{
	{
		unsigned int Color = GetGroundColor(RGB(255, 255, 255));
		if (RGB(255, 255, 255) == Color)
		{
			Gravity(_Delta);
		}
		else
		{
			unsigned int CheckColor = GetGroundColor(RGB(255, 255, 255), float4::UP);

			while (CheckColor != RGB(255, 255, 255))
			{
				CheckColor = GetGroundColor(RGB(255, 255, 255), float4::UP);
				AddPos(float4::UP);
			}


			GravityReset();
		}
	}
	
	std::vector<GameEngineCollision*> _Col;
	if (true == BodyCollision->Collision(CollisionOrder::MonsterBody, _Col
		, CollisionType::Rect // 나를 사각형
		, CollisionType::Rect // 상대도 사각형으로 봐줘
		))
	{
		int a = 0;
		// 나는 몬스터랑 충돌한것.
	}


	DirCheck();

	float Speed = 500.0f;

	float4 MovePos = float4::ZERO;
	float4 CheckPos = float4::ZERO;

	if (true == GameEngineInput::IsPress('A') && Dir == PlayerDir::Left)
	{
		CheckPos = { -30.0f, -50.0f };

		MovePos = { -Speed * _Delta, 0.0f };
	}
	else if (true == GameEngineInput::IsPress('D') && Dir == PlayerDir::Right)
	{
		CheckPos = { 30.0f, -50.0f };
		MovePos = { Speed * _Delta, 0.0f };
	}
	if (true == GameEngineInput::IsPress('W'))
	{
		MovePos = { 0.0f, -Speed * _Delta };
	}
	if (true == GameEngineInput::IsPress('S'))
	{
		MovePos = { 0.0f, Speed * _Delta };
	}
	if (true == GameEngineInput::IsPress(VK_SPACE))
	{
		MovePos = { 0.0f, -Speed * _Delta * JumpPower };
	}

	if (MovePos == float4::ZERO)
	{
		DirCheck();
		ChangeState(PlayerState::Idle);
	}

	{
		unsigned int Color = GetGroundColor(RGB(255, 255, 255), CheckPos);

		if (Color == RGB(255, 255, 255))
		{
			AddPos(MovePos);
			GetLevel()->GetMainCamera()->AddPos(MovePos);
		}
	}
}