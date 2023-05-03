#pragma once
#include <string>
// 경로를 부르는건 너무 많이 사용되기 때문에 std도 있다.
#include <filesystem> // visualstdio의 버전을 높여야 사용할 수 있다. 17이상 부터

// 설명 :
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

