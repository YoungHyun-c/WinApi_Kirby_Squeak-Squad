#include "GameEngineWindowTexture.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>

GameEngineWindowTexture::GameEngineWindowTexture()
{

}

GameEngineWindowTexture::~GameEngineWindowTexture()
{

}

void GameEngineWindowTexture::ResLoad(const std::string& _Path)
{
	// �ܼ��� ��Ʈ�ʸ� �ε��ϴ� �Լ��� �ƴ϶� �츮���� �׳� HANDLE�� �ش�.
	// ������ ������δ� Ŀ�� �����ܵ �̳༮���� �ε��� �� �־��� ���̴�

	// LoadBitMapA()

	// LPCSTR == const char*

	HANDLE ImageHandle = LoadImageA(nullptr, _Path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	if (nullptr == ImageHandle)
	{
		MsgBoxAssert("�̹��� �ε忡 �����߽��ϴ�." + _Path);
		return;
	}

	// �̹����� �ڵ��� ��
	BitMap = static_cast<HBITMAP>(ImageHandle);

	// ���� ������ ���Ӱ� ������ �Ѵ�.
	// window���� ���� DC
	ImageDC = CreateCompatibleDC(nullptr);
	// �̹����� ���� ������ ����� ����

	// ImageDc ���ѿ�
	// BitMap 2������ ���� ������ �����ض�
	OldBitMap = static_cast<HBITMAP>(SelectObject(ImageDC, BitMap));
	// ��� �̹� ��������ڸ��� ���ο� 1, 1 �̹����� ����Ǿ� �ְ�
	// ���� �ε��� �̹����� �� 1,1 ¥���� �о�� ��ü�ϴ� �۾��� �ϴµ�
	// �� �Լ��� ���ϰ��� ������ ����Ǿ��ִ� �긦 �������ִ� ��.

	ScaleCheck();

}

void GameEngineWindowTexture::ScaleCheck()
{
	GetObject(BitMap, sizeof(BITMAP), &Info);

	BITMAP OldInfo;

	GetObject(OldBitMap, sizeof(BITMAP), &OldInfo);
}

float4 GameEngineWindowTexture::GetScale()
{
	return { static_cast<float>(Info.bmWidth), static_cast<float>(Info.bmHeight) };
}

void GameEngineWindowTexture::BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos)
{
	BitCopy(_CopyTexture, _Pos, _CopyTexture->GetScale());
}

void GameEngineWindowTexture::BitCopy(
	GameEngineWindowTexture* _CopyTexture,
	const float4& _Pos,
	const float4& _Scale)
{
	HDC CopyImageDC = _CopyTexture->GetImageDC();

	// Ư�� DC�� ����� ������
	// Ư�� DC�� ��Ӻ����ϴ� �Լ��̴�.
	BitBlt(ImageDC,
		_Pos.iX() - _Scale.ihX(),
		_Pos.iY() - _Scale.ihY(),
		_Scale.ihX(),
		_Scale.ihY(),
		CopyImageDC,
		0,
		0,
		SRCCOPY);

}