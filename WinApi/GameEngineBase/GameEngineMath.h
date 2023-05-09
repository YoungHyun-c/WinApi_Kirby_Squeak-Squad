#pragma once

// ���� :
class GameEngineMath
{
};

class float4
{
public:
	static const float4 ZERO;
	// �Ǽ��� �⺻������ 1.0f == 1.0f (�´ٰ�� ����)
	// == �� ���� �Ұ����ϴ�.
	// �ص� ��Ȯ���� �ʴ´�. �Ǽ��� ó���ϴ� ����� ���ʿ� ��Ȯ���� �ʱ� �����̴�.
	// �ε��Ҽ��� ������� �⺻������ ������ ������ �ְ�
	// + - ���� �� �� �����е��� �������� �ٸ� ���� ������ ���ɼ��� ����.
	// ���� ����� ����� �Ƹ� �ȵ� ����� �ϴ� ���̴�.
	// Player->GetPos() == Monster->GetPos();
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;
	float W = 1.0f;

	inline int iX() const
	{
		return static_cast<int>(X);
	}

	inline int iY() const
	{
		return static_cast<int>(Y);
	}

	inline int ihX() const
	{
		return static_cast<int>(X * 0.5f);
	}

	inline int ihY() const
	{
		return static_cast<int>(Y * 0.5f);
	}

	float4& operator+=(const float4& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		Z += _Other.Z;
		
		return *this;
	}
};