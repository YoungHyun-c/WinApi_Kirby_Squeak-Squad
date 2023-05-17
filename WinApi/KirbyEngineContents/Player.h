#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class PlayerState
{
	Idle,
	Run,
	Max, // �Ϲ������� ������� �ʴ� ��.
};

// ���� :
class Player : public GameEngineActor
{
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
	//Ŭ������ ���� �ǰ�
	void IdleUpdate(float _Delta);
	void RunUpdate(float _Delta);
	void ChangeState(PlayerState State);
	PlayerState State = PlayerState::Max;

private:
	void Start() override;
	void Update(float _Delta) override;
	void Render() override;
};

