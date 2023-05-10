#include "BackGround.h"
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineWindow.h>

#pragma comment(lib, "msimg32.lib")

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

void BackGround::Start()
{
	SetPos({ 640, 360 });
}

void BackGround::Update(float _Delta)
{

}

void BackGround::Render() 
{
	GameEngineWindowTexture* FindTexture = ResourcesManager::GetInst().FindTexture(FileName);
	
	if (nullptr == FindTexture)
	{
		return;
	}

	GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	// BackBuffer->BitCopy(FindTexture, GetPos());

	float4 Scale = FindTexture->GetScale();

	Scale *= 2.0f;

	//					BackBuffer에 그리려는 위치    크기
	// BackBuffer->TransCopy(FindTexture, GetPos(), Scale, { 0, 0}, FindTexture->GetScale());
	//							카피하려는 이미지의			시작위치, 크기
	// BackBuffer->TransCopy(FindTexture, GetPos(), Scale, { 0, 0}, FindTexture->GetScale());
	BackBuffer->TransCopy(FindTexture, GetPos(), Scale, { 0, 0 }, FindTexture->GetScale());
}

void BackGround::Release()
{

}

void BackGround::Init(const std::string& _FileName)
{
	FileName = _FileName;

	if (false == ResourcesManager::GetInst().IsLoadTexture(_FileName))
	{
		GameEnginePath FilePath;
		FilePath.GetCurrentPath();

		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\BackGround\\" + _FileName);

		GameEngineWindowTexture* Text = ResourcesManager::GetInst().TextureLoad(FilePath.GetStringPath());

		float4 Scale = Text->GetScale();

		Scale.X *= 5.0f;
		Scale.Y *= 5.0f;

		SetScale(Scale);
	}
}