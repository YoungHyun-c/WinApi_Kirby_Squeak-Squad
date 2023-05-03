#pragma once
#include <string>
// ��θ� �θ��°� �ʹ� ���� ���Ǳ� ������ std�� �ִ�.
#include <filesystem> // visualstdio�� ������ ������ ����� �� �ִ�. 17�̻� ����

// ���� :
class GameEnginePath
{
public:
	// constructer destructer
	GameEnginePath();
	~GameEnginePath();

	// delete Function
	GameEnginePath(const GameEnginePath& _Other) = delete;
	GameEnginePath(GameEnginePath&& _Other) noexcept = delete;
	GameEnginePath& operator = (const GameEnginePath& _Other) = delete;
	GameEnginePath& operator = (GameEnginePath&& _Other) noexcept = delete;

	void GetCurrentPath();

protected:

private:
	std::filesystem::path Path;

	//std::string Path;

};

