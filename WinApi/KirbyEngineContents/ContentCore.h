#pragma once
#include <GameEngineCore/GameEngineCore.h>


// ���� :
class ContentCore : public CoreProcess
{
public:
	// constructer destructer
	ContentCore();
	~ContentCore();

	// delete Function
	ContentCore(const ContentCore& _Other) = delete;
	ContentCore(ContentCore&& _Other) noexcept = delete;
	ContentCore& operator = (const ContentCore& _Other) = delete;
	ContentCore& operator = (ContentCore&& _Other) noexcept = delete;

protected:

private:
	void Start() override;

	void Update(float _Delta) override;

	void Render(float _Delta) override;

	void Release() override;
};

