#pragma once

// Ό³Έν :
class GameEngineCore
{
public:
	// constructer destructer
	GameEngineCore();
	~GameEngineCore();

	// delete Function
	GameEngineCore(const GameEngineCore& _Other) = delete;
	GameEngineCore(GameEngineCore&& _Other) noexcept = delete;
	GameEngineCore& operator = (const GameEngineCore& _Other) = delete;
	GameEngineCore& operator = (GameEngineCore&& _Other) noexcept = delete;

protected:

private:

};

