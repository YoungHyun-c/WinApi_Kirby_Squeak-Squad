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

	float Speed = 500.0f;
	float4 MovePos = float4::ZERO;
	float4 CheckPos = float4::ZERO;

	if (true == MainRenderer->IsAnimationEnd())
	{
		++TestValue;
	}

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

	if (true == GameEngineInput::IsPress(VK_SPACE))
	{
		MovePos = { 0.0f, -Speed * _Delta * JumpPower };
		return;
	}

	if (MovePos == float4::ZERO)
	{
		DirCheck();
		ChangeState(PlayerState::Run);
	}

	unsigned int Color = GetGroundColor(RGB(255, 255, 255), CheckPos);

	if (Color == RGB(255, 255, 255))
	{
		AddPos(MovePos);
		GetLevel()->GetMainCamera()->AddPos(MovePos);
	}

	//if (true == GameEngineInput::IsDown(VK_SPACE))
	//{
	//	//float4::ZERO
	//	JumpDir_ = { 0.0f, -500 * _Delta * JumpPower };
	//	//JumpDir_ = float4::UP * 700.0f * _Delta;
	//	JumpUp();
	//	return;
	//}

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
	
	//std::vector<GameEngineCollision*> _Col;
	//if (true == BodyCollision->Collision(CollisionOrder::MonsterBody, _Col
	//	, CollisionType::Rect // 나를 사각형
	//	, CollisionType::Rect // 상대도 사각형으로 봐줘
	//	))
	//{
	//	int a = 0;
	//	// 나는 몬스터랑 충돌한것.
	//}


	DirCheck();

	float Speed = 500.0f;

	float4 MovePos = float4::ZERO;
	float4 CheckPos = float4::ZERO;

	if (true == GameEngineInput::IsPress('A') && Dir == PlayerDir::Left)
	{
		CheckPos = LeftCheck;

		MovePos = { -Speed * _Delta, 0.0f };
	}
	else if (true == GameEngineInput::IsPress('D') && Dir == PlayerDir::Right)
	{
		CheckPos = RightCheck;

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

//void Player::JumptStart()
//{
//	SetGravityVector(float4::UP * 1000.0f);
//}
//
//int A = 0;
//
//void Player::JumpUpdate(float _Delta)
//{
//	Gravity(_Delta);
//
//	// for (size_t i = 0; i < 1000000; i++)
//	/*{
//		++A;
//	}*/
//
//	{
//		unsigned int Color = GetGroundColor(RGB(255, 255, 255))
//		{
//			if (RGB(255, 255, 255) != Color)
//			{
//				ChangeState(PlayerState::Idle);
//				return;
//			}
//		}
//	}
//}

void Player::LeftRightCheck()
{
	//if (ShootMoveActive == true || DrainMonsterActive == true)
	//{
	//	//몬스터의 흡수가 시작됐거나 무언가를 발사하는 애니메이션이 시작됐으면 좌우입력 체크를 막는다
	//	return;
	//}

	PlayerDir PrevDirectionState = dirstate_;
	//내 지금의 LEFT,RIGHT 상태를 받는 Prev

	//좌우체크를 어디서 하느냐에 따라 들어가는 위치가 다를것이다
	if (true == GameEngineInput::IsPress('L'))
	{
		dirstate_ = PlayerDir::Left;
	}
	else if (true == GameEngineInput::IsPress('R'))
	{
		dirstate_ = PlayerDir::Right;
	}


	////키입력이 들어와서 방향이 바뀌엇을땐 애니메이션을 이곳에서 바꿔준다
	//if (PrevDirectionState != dirstate_)
	//{

	//	switch (AbilityType_)
	//	{
	//	case PlayerState::Normal:
	//		MainRender_->GH_ChangeAnimation(AbilityStateName_ + StateName_ + GH_GetDirString());
	//		if (stateType_ == GH_PlayerState::DrainING)
	//		{
	//			DrainEffectRender_->GH_ChangeAnimation("DrainAfterDrainEffect" + GH_GetDirString());
	//		}
	//		break;
	//	case GH_KirbyAbilityState::DrainAfter:
	//		DrainAfterRender_->GH_ChangeAnimation(AbilityStateName_ + StateName_ + GH_GetDirString());
	//		break;
	//	case GH_KirbyAbilityState::Beam:
	//		BeamRender_->GH_ChangeAnimation(AbilityStateName_ + StateName_ + GH_GetDirString());
	//		break;
	//	case GH_KirbyAbilityState::Cutter:
	//		CutterRender_->GH_ChangeAnimation(AbilityStateName_ + StateName_ + GH_GetDirString());
	//		break;
	//	default:
	//		break;
	//	}

		//애니메이션 이름은 내 상태이름+ L or R 이므로
		//내가 왼쪽상태면 L붙은 애니메이션을,
		//오른쪽 상태면 R붙은 애니메이션을 렌더할 것이다
	//}

}


void Player::JumpUp()
{
	//EffectPlayer->GH_PlayAlone("KirbyJump.wav", 0);
	//EffectPlayer->GH_PlayCountReset(1);

	LeftRightCheck();
	//MonsterCollisionCheck();
	//MonsterAttackCollisionCheck();

	//if (true == GameEngineInput::IsDown(VK_SPACE))
	//{
	//	switch (AbilityType_)
	//	{
	//	case GH_KirbyAbilityState::Normal:
	//		GH_ChangeState(GH_KirbyAbilityState::Normal, GH_PlayerState::Fly);
	//		break;
	//	//case GH_KirbyAbilityState::Beam:
	//	//	GH_ChangeState(GH_KirbyAbilityState::Beam, GH_PlayerState::Fly);
	//	//	break;
	//	//case GH_KirbyAbilityState::Cutter:
	//	//	GH_ChangeState(GH_KirbyAbilityState::Cutter, GH_PlayerState::Fly);
	//	//	break;
	//	default:
	//		break;
	//	}
	//}

}