#pragma once
#include <Windows.h>
#include <string>
#include "GameEngineWindowTexture.h"

// 설명 :
class GameEngineWindow
{
public:
	static GameEngineWindow MainWindow;

	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator = (const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator = (GameEngineWindow&& _Other) noexcept = delete;

	void Open(const std::string& _Title, HINSTANCE _hInstance);

	static void MessageLoop(HINSTANCE _Inst, void(*_Start)(HINSTANCE), void(*_Update)(), void(*_End)());

	HDC GetHDC()
	{
		return Hdc;
	}

	float4 GetSCale()
	{
		return Scale;
	}

	GameEngineWindowTexture* GetBackBuffer()
	{
		return BackBuffer;
	}

	void SetPosAndScale(const float4& _Pos, const float4& _Scale);

	static void WindowLoopOff()
	{
		IsWindowUpdate = false;
	}

protected:

private:
	static bool IsWindowUpdate;
	static HINSTANCE Instance;
	std::string Title = "";
	HWND hWnd = nullptr;

	float4 Scale;
	GameEngineWindowTexture* BackBuffer = nullptr;

	// 2차원 배열형식의 색깔들의 집합이 존재하고
	// 거기에 그림을 그리거나 수정할 수 있는 권한을 HDC
	HDC Hdc = nullptr;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void InitInstance();
	void MyRegisterClass();
};

