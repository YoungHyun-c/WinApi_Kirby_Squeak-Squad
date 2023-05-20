#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class PlayActor : public GameEngineActor
{
public:
	// constructer destructer
	PlayActor();
	~PlayActor();

	// delete Function
	PlayActor(const PlayActor& _Other) = delete;
	PlayActor(PlayActor&& _Other) noexcept = delete;
	PlayActor& operator = (const PlayActor& _Other) = delete;
	PlayActor& operator = (PlayActor&& _Other) noexcept = delete;

	void Gravity(float _Delta);

	void CameraFocus();

	void GravityOff()
	{
		IsGravity = false;
	}

	void GravityReset()
	{
		GravityVector = float4::ZERO;
	}

	void SetGroundTexture(const std::string& _GroundTextureName);

	int GetGroundColor(unsigned int _DefaultColor, float4 _Pos = float4::ZERO);

protected:

private:
	class GameEngineWindowTexture* GroundTexture = nullptr;

	bool IsGravity = true;

	float GravityPower = 1.0f;
	float4 GravityVector = float4::ZERO;
};

