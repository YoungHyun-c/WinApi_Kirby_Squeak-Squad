#pragma once

// 설명 : 모든 기본적인 행동을 제안하는 클래스
// 제안하는 클래스
class GameEngineObject
{
public:
	// constructer destructer
	GameEngineObject();
	~GameEngineObject();

	// delete Function
	GameEngineObject(const GameEngineObject& _Other) = delete;
	GameEngineObject(GameEngineObject&& _Other) noexcept = delete;
	GameEngineObject& operator = (const GameEngineObject& _Other) = delete;
	GameEngineObject& operator = (GameEngineObject&& _Other) noexcept = delete;

	// 시작하고
	virtual void Start() {}

	// 행동하고
	virtual void Update(float _Delta) {}

	// 그려지고
	virtual void Render() {}

	// 정리된다.
	virtual void Release() {}

	void On()
	{
		IsUpdateValue = true;
	}

	void Off()
	{
		IsUpdateValue = false;
	}

	void Death()
	{
		IsUpdateValue = true;
	}

	bool IsUpdate()
	{
		return true == IsUpdateValue && false == IsDeathValue;
	}

	bool IsDeath()
	{
		return IsDeathValue;
	}

protected:

private:
	bool IsUpdateValue = true; // 이걸 false로 만들면 된다.
	bool IsDeathValue = false; // 아예 메모리에서 없애고 싶으면 쓰면 된다.
};

