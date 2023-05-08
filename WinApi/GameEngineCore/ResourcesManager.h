#pragma once
#include <string>
#include <map>
#include <GameEngineBase/GameEnginePath.h>

// 설명 : 선생님이 마지막으로 알려주는 싱글톤
// 싱글톤이 뭐지??
// 싱글톤은 갱스오브포라는 1990대 프로그래머 집단이
// 대다수의 프로그래머가 비슷한 규격의 코딩을 하는 것을 정리하고 이름을 붙인것을
// 디자인 패턴이라고 하는데 그 중에서 하나의 패턴명
// 생성 구분에 해당
// 생성 객체를 생성하는 방법
// 
// 이 프로그램에서 이 객체가 1개만 있었으면 좋겠다.
// 싱글톤이 싫은 이유 : static으로 사용해서 함수를 부르면 되는걸,
// 굳이 싱글톤으로 참조, 함수를 부를 필요가 있나.
class GameEngineTexture;
class ResourcesManager
{
public:
	// delete Function
	ResourcesManager(const ResourcesManager& _Other) = delete;
	ResourcesManager(ResourcesManager&& _Other) noexcept = delete;
	ResourcesManager& operator = (const ResourcesManager& _Other) = delete;
	ResourcesManager& operator = (ResourcesManager&& _Other) noexcept = delete;

	// 3. 리턴해준다
	static ResourcesManager& GetInst()
	{
		return Inst;
	}

	//  파일명이 곧 찾기위한 이름이 된다.
	void TextureLoad(const std::string& _Path)
	{
		// _Path 파일명
		// TextureLoad();
		GameEnginePath LoadPath = _Path;
		TextureLoad(LoadPath.GetFileName(), _Path);
	}

	void TextureLoad(const std::string& _Name, const std::string& _Path);

	GameEngineTexture* FindTexture(const std::string& _Name);

	bool IsLoadTexture(const std::string& _Image);

protected:

private:
	// 2. 내부에 static 포인터든 값이든 뭐든 1개를 둔다.
	static ResourcesManager Inst;

	// static ResorcesManager* Inst;

	// 1. 생성자를 private안에 넣는다.
	ResourcesManager();
	~ResourcesManager();

	std::map<std::string, GameEngineTexture*> AllTexture;
};
