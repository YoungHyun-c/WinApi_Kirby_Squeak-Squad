#pragma once

// Ό³Έν :
class GameEngineDirectory
{
public:
	// constructer destructer
	GameEngineDirectory();
	~GameEngineDirectory();

	// delete Function
	GameEngineDirectory(const GameEngineDirectory& _Other) = delete;
	GameEngineDirectory(GameEngineDirectory&& _Other) noexcept = delete;
	GameEngineDirectory& operator = (const GameEngineDirectory& _Other) = delete;
	GameEngineDirectory& operator = (GameEngineDirectory&& _Other) noexcept = delete;

protected:

private:

};

