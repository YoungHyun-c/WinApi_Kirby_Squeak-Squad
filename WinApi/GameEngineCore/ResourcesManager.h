#pragma once
#include <string>
#include <map>
#include <GameEngineBase/GameEnginePath.h>

// ���� : �������� ���������� �˷��ִ� �̱���
// �̱����� ����??
// �̱����� ������������� 1990�� ���α׷��� ������
// ��ټ��� ���α׷��Ӱ� ����� �԰��� �ڵ��� �ϴ� ���� �����ϰ� �̸��� ���ΰ���
// ������ �����̶�� �ϴµ� �� �߿��� �ϳ��� ���ϸ�
// ���� ���п� �ش�
// ���� ��ü�� �����ϴ� ���
// 
// �� ���α׷����� �� ��ü�� 1���� �־����� ���ڴ�.
// �̱����� ���� ���� : static���� ����ؼ� �Լ��� �θ��� �Ǵ°�,
// ���� �̱������� ����, �Լ��� �θ� �ʿ䰡 �ֳ�.
class GameEngineTexture;
class ResourcesManager
{
public:
	// delete Function
	ResourcesManager(const ResourcesManager& _Other) = delete;
	ResourcesManager(ResourcesManager&& _Other) noexcept = delete;
	ResourcesManager& operator = (const ResourcesManager& _Other) = delete;
	ResourcesManager& operator = (ResourcesManager&& _Other) noexcept = delete;

	// 3. �������ش�
	static ResourcesManager& GetInst()
	{
		return Inst;
	}

	//  ���ϸ��� �� ã������ �̸��� �ȴ�.
	void TextureLoad(const std::string& _Path)
	{
		// _Path ���ϸ�
		// TextureLoad();
		GameEnginePath LoadPath = _Path;
		TextureLoad(LoadPath.GetFileName(), _Path);
	}

	void TextureLoad(const std::string& _Name, const std::string& _Path);

	GameEngineTexture* FindTexture(const std::string& _Name);

	bool IsLoadTexture(const std::string& _Image);

protected:

private:
	// 2. ���ο� static �����͵� ���̵� ���� 1���� �д�.
	static ResourcesManager Inst;

	// static ResorcesManager* Inst;

	// 1. �����ڸ� private�ȿ� �ִ´�.
	ResourcesManager();
	~ResourcesManager();

	std::map<std::string, GameEngineTexture*> AllTexture;
};
