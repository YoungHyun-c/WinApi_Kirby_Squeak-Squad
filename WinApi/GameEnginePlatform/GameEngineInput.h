#pragma once
#include <Windows.h>

// ���� :
class GameEngineInput
{
public:
	// constructer destructer
	GameEngineInput();
	~GameEngineInput();

	// delete Function
	GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) noexcept = delete;
	GameEngineInput& operator = (const GameEngineInput& _Other) = delete;
	GameEngineInput& operator = (GameEngineInput&& _Other) noexcept = delete;

protected:

private:

};

