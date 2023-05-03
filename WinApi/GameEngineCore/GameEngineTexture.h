#pragma once
#include <Windows.h>

// ���� :
class GameEngineTexture
{
public:
	// constructer destructer
	GameEngineTexture();
	~GameEngineTexture();

	// delete Function
	GameEngineTexture(const GameEngineTexture& _Other) = delete;
	GameEngineTexture(GameEngineTexture&& _Other) noexcept = delete;
	GameEngineTexture& operator = (const GameEngineTexture& _Other) = delete;
	GameEngineTexture& operator = (GameEngineTexture&& _Other) noexcept = delete;

protected:

private:

};
