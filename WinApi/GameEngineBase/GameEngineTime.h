#pragma once

// ���� :
class GameEngineTime
{
public:
	// constructer destructer
	static GameEngineTime MainTimer;

	GameEngineTime();
	~GameEngineTime();

	// delete Function
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime&& _Other) noexcept = delete;
	GameEngineTime& operator = (const GameEngineTime& _Other) = delete;
	GameEngineTime& operator = (GameEngineTime&& _Other) noexcept = delete;

	float GetDeltaTime()
	{
		return 0.0f;
	}

protected:

private:
	//LARGE_INTEGER Count;
	//LARGE_INTEGER Cur;
	//LARGE_INTEGER Prev;
};

