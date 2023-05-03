#pragma once

// ���� : ��� �⺻���� �ൿ�� �����ϴ� Ŭ����
// �����ϴ� Ŭ����
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

	// �����ϰ�
	virtual void Start() {}

	// �ൿ�ϰ�
	virtual void Update(float _Delta) {}

	// �׷�����
	virtual void Render() {}

	// �����ȴ�.
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
	bool IsUpdateValue = true; // �̰� false�� ����� �ȴ�.
	bool IsDeathValue = false; // �ƿ� �޸𸮿��� ���ְ� ������ ���� �ȴ�.
};

