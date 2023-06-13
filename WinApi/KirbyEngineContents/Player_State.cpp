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

	// ������ ����
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
	//	, CollisionType::Rect // ���� �簢��
	//	, CollisionType::Rect // ��뵵 �簢������ ����
	//	))
	//{
	//	int a = 0;
	//	// ���� ���Ͷ� �浹�Ѱ�.
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
	//	//������ ����� ���۵ưų� ���𰡸� �߻��ϴ� �ִϸ��̼��� ���۵����� �¿��Է� üũ�� ���´�
	//	return;
	//}

	PlayerDir PrevDirectionState = dirstate_;
	//�� ������ LEFT,RIGHT ���¸� �޴� Prev

	//�¿�üũ�� ��� �ϴ��Ŀ� ���� ���� ��ġ�� �ٸ����̴�
	if (true == GameEngineInput::IsPress('L'))
	{
		dirstate_ = PlayerDir::Left;
	}
	else if (true == GameEngineInput::IsPress('R'))
	{
		dirstate_ = PlayerDir::Right;
	}


	////Ű�Է��� ���ͼ� ������ �ٲ������ �ִϸ��̼��� �̰����� �ٲ��ش�
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

		//�ִϸ��̼� �̸��� �� �����̸�+ L or R �̹Ƿ�
		//���� ���ʻ��¸� L���� �ִϸ��̼���,
		//������ ���¸� R���� �ִϸ��̼��� ������ ���̴�
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