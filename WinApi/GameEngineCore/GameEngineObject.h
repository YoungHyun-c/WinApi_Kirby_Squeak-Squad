#pragma once

// 설명 : 모든 기본적인 행동을 제안하는 클래스
// 제안하는 클래스
class GameEngineObject
{
	friend class GameEngineLevel;
	friend class GameEngineCore;
public:
	// constructer destructer
	GameEngineObject();
	virtual ~GameEngineObject();

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
	virtual void Render(float _Delta) {}

	// 정리된다.
	virtual void Release() {}

	virtual void On()
	{
		IsUpdateValue = true;
	}

	virtual void Off()
	{
		IsUpdateValue = false;
	}

	void Death()
	{
		this->IsDeathValue = true;
	}

	bool IsUpdate()
	{
		return true == IsUpdateValue && false == IsDeathValue;
	}

	virtual bool IsDeath()
	{
		return IsDeathValue;
	}

	int GetOrder()
	{
		return Order;
	}

	template<typename EnumType>
	void SetOrder(EnumType _Order)
	{
		SetOrder(static_cast<int>(_Order));
	}

	virtual void SetOrder(int _Order)
	{
		Order = _Order;
	}

	float GetLiveTime()
	{
		return LiveTime;
	}

	void ResetLiveTime()
	{
		LiveTime = 0.0f;
	}

protected:

private:
	float LiveTime = 0.0f;
	int Order = 0;
	bool IsUpdateValue = true; // 이걸 false로 만들면 된다.
	bool IsDeathValue = false; // 아예 메모리에서 없애고 싶으면 쓰면 된다.

	void AddLiveTime(float _DeltaTime)
	{
		LiveTime += _DeltaTime;
	}
};

