#pragma once
#include <Windows.h>
#include <string>
#include <assert.h>


//// ���� :
class GameEngineDebug
{
public:
	// constructer destructer
	GameEngineDebug();
	~GameEngineDebug();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator = (const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator = (GameEngineDebug&& _Other) noexcept = delete;

	static void LeckCheck();

protected:

private:

};

//#define MsgBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false);
#define MsgBoxAssert(Text) \
std::string Value = Text; \
MessageBoxA(nullptr, Value.c_str(), "Error", MB_OK); assert(false);
