#include "GameEngineSound.h"

GameEngineSound::GameEngineSound()
{

}

GameEngineSound::~GameEngineSound()
{

}

class SoundSystemCreator
{
public:
	SoundSystemCreator()
	{
	}

	~SoundSystemCreator()
	{
	}

};

SoundSystemCreator SoundInitObject = SoundSystemCreator();

//void GameEngineSound::Init()
//{
//	static bool IsOnce = false;
//
//	if (true == IsOnce)
//	{
//		return;
//	}
//
//	//FMOD�� ����ϱ� ���� �غ� �ϴ� �Լ�
//	ISOnce = true;
//}


void GameEngineSound::SoundLoad(std::string& _Name, std::string& _Path)
{

}

void GameEngineSound::SoundPlay(std::string& _Name)
{

}

// 1���� ����� �ϰ� ���� Ư�� ���� �ȴ�.
void GameEngineSound::PlayBgm(std::string& _Name)
{

}

// Ư�� �����Ǵ� ���� ����� �����.
void GameEngineSound::StopBgm()
{

}