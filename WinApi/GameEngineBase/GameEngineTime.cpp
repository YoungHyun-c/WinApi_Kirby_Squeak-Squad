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
	
	// 8����Ʈ �Ǽ���, �ξ� �� ���� �Ǽ��� ǥ���� �� ����.
	double DoubleDelta = 
}