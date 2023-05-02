#include "GameEngineTime.h"
#include <Windows.h>

GameEngineTime::GameEngineTime()
{
	LARGE_INTEGER Count;
	LARGE_INTEGER Cur;
	LARGE_INTEGER Prev;

	QueryPerformanceFrequency(&Count);
	QueryPerformanceCounter(&Cur);
}

GameEngineTime::~GameEngineTime()
{

}