#pragma once

// 설명 :
class GameEngineMath
{
};

class float4
{
public:
	// 실수는 기본적으로 1.0f == 1.0f (맞다고는 나옴)
	// == 이 거의 불가능하다.
	// 해도 정확하지 않는다. 실수를 처리하는 방식이 애초에 정확하지 않기 때문이다.
	// 
	// 아주 어리석은 절대로 아마 안될 계산을 하는 것이다.
	// Player->GetPos() == Monster->GetPos();
	float X;
	float Y;
	float Z;
	float W;

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