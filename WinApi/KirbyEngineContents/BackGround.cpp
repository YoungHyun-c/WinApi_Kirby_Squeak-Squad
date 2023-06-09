#include "BackGround.h"
#include "ContentsEnum.h"
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRenderer.h>

#pragma comment(lib, "msimg32.lib")

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

void BackGround::Start()
{
	SetPos({ 512, 288 });
	Renderer = CreateRenderer(RenderOrder::BackGround);

	DebugRenderer = CreateRenderer(RenderOrder::BackGround);

	Renderer->On();
	DebugRenderer->Off();

}

void BackGround::Update(float _Delta)
{

}

//void BackGround::Render() 
//{
	//GameEngineWindowTexture* FindTexture = ResourcesManager::GetInst().FindTexture(FileName);
	//
	//if (nullptr == FindTexture)
	//{
	//	return;
	//}

	//GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	//// BackBuffer->BitCopy(FindTexture, GetPos());

	//float4 Scale = FindTexture->GetScale();

	//Scale *= 2.0f;

	////					BackBuffer에 그리려는 위치    크기
	//// BackBuffer->TransCopy(FindTexture, GetPos(), Scale, { 0, 0}, FindTexture->GetScale());
	////							카피하려는 이미지의			시작위치, 크기
	//// BackBuffer->TransCopy(FindTexture, GetPos(), Scale, { 0, 0}, FindTexture->GetScale());
	//BackBuffer->TransCopy(FindTexture, GetPos(), Scale, { 0, 0 }, FindTexture->GetScale());
//}

void BackGround::Release()
{

}

void BackGround::Init(const std::string& _FileName, const std::string& _DebugFileName)
{
	FileName = _FileName;

	if (false == ResourcesManager::GetInst().IsLoadTexture(_FileName))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();

		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\BackGround\\" + _FileName);

		GameEngineWindowTexture* Text = ResourcesManager::GetInst().TextureLoad(FilePath.GetStringPath());
	}

	GameEngineWindowTexture* Texture = ResourcesManager::GetInst().FindTexture(_FileName);
	float4 Scale = Texture->GetScale();
	Renderer->SetTexture(_FileName);
	Renderer->SetRenderScale(Scale);
	DebugRenderer->SetTexture(_DebugFileName);
	DebugRenderer->SetRenderScale(Scale);
	SetPos({ Scale.hX(), Scale.hY() });

		//float4 Scale = Text->GetScale();

		//Scale.X *= 2.0f;
		//Scale.Y *= 2.0f;

		////SetScale(Scale);

		//GameEngineRenderer* Render = CreateRenderer(_FileName, RenderOrder::BackGround);
		//Render->SetRenderScale(Scale);

		//SetPos({ Scale.hX(), Scale.hY() });

		// Render->SetRenderPos({ Scale.hX(), 0.0f});
}

void BackGround::SwitchRender()
{
	SwitchRenderValue = !SwitchRenderValue;

	if (SwitchRenderValue)
	{
		Renderer->On();
		DebugRenderer->Off();
	}
	else {
		Renderer->Off();
		DebugRenderer->On();
	}

}