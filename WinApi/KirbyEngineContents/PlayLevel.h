#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// ���� :
class PlayLevel : public GameEngineLevel
{
public:
	// constructer destructer
	PlayLevel();
	~PlayLevel();

	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator = (const PlayLevel& _Other) = delete;
	PlayLevel& operator = (PlayLevel&& _Other) noexcept = delete;

protected:

private:

};
