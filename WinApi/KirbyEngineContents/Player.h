#pragma once
#include "PlayActor.h"

enum class PlayerState
{
	Idle,
	Run,
	Max, // 일반적으로 사용하지 않는 값.
};

enum class PlayerDir
{
	Left,
	Right,
	Max,
};

// 설명 :
class Player : public PlayActor
{
private:
	static Player* MainPlayer;

public:
	static Player* GetMainPlayer()
	{
		return MainPlayer;
	}

public:
	// constructer destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator = (const Player& _Other) = delete;
	Player& operator = (Player&& _Other) noexcept = delete;

	GameEngineRenderer* MainRenderer = nullptr;

protected:
	void StateUpdate(float _Delta);
	void IdleStart();
	void RunStart();
	//클래스로 만들어도 되고
	void IdleUpdate(float _Delta);
	void RunUpdate(float _Delta);

	void ChangeState(PlayerState State);

	PlayerState State = PlayerState::Max;
	PlayerDir Dir = PlayerDir::Right;
	std::string CurState = "";

	GameEngineCollision* BodyCollision = nullptr;

	void DirCheck();

	void ChangeAnimationState(const std::string& _StateName);

private:
	void LevelStart() override;
	void Start() override;
	void Update(float _Delta) override;
	void Render() override;

	float JumpPower = 7.0f;
};

