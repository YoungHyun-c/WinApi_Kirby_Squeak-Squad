#include "GameEngineTime.h"


GameEngineTime GameEngineTime::MainTimer;

GameEngineTime::GameEngineTime()
{
	QueryPerformanceFrequency(&Count);
	QueryPerformanceCounter(&Cur);

}

GameEngineTime::~GameEngineTime()
{

}

void GameEngineTime::Update()
{
	
	// 8바이트 실수형, 훨씬 더 많은 실수를 표현할 수 있음.
	double DoubleDelta = 
}