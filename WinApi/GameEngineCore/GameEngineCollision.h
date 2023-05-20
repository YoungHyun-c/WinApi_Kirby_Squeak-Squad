#pragma once
#include "GameEngineObject.h"
#include <GameEngineBase/GameEngineMath.h>
#include <string>
#include <map>
#include <vector>


// Ό³Έν :
class GameEngineCollision : public GameEngineObject
{
public:
	// constructer destructer
	GameEngineCollision();
	~GameEngineCollision();

	// delete Function
	GameEngineCollision(const GameEngineCollision& _Other) = delete;
	GameEngineCollision(GameEngineCollision&& _Other) noexcept = delete;
	GameEngineCollision& operator = (const GameEngineCollision& _Other) = delete;
	GameEngineCollision& operator = (GameEngineCollision&& _Other) noexcept = delete;

protected:

private:

};

