#pragma once

// Ό³Έν :
class GameEngineSprite
{
public:
	// constructer destructer
	GameEngineSprite();
	~GameEngineSprite();

	// delete Function
	GameEngineSprite(const GameEngineSprite& _Other) = delete;
	GameEngineSprite(GameEngineSprite&& _Other) noexcept = delete;
	GameEngineSprite& operator = (const GameEngineSprite& _Other) = delete;
	GameEngineSprite& operator = (GameEngineSprite&& _Other) noexcept = delete;

protected:

private:

};

