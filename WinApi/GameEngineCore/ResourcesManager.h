#pragma once

// ���� : �������� ���������� �˷��ִ� �̱���
// �̱����� ����??
// �̱����� ������������� 1990�� ���α׷��� ������
// ��ټ��� ���α׷��Ӱ� ����� �԰��� �ڵ��� �ϴ� ���� �����ϰ� �̸��� ���ΰ���
// ������ �����̶�� �ϴµ� �� �߿��� �ϳ��� ���ϸ�
// ���� ���п� �ش�
// ���� ��ü�� �����ϴ� ����� 
// 
// �� ���α׷����� �� ��ü�� 1���� �־����� ���ڴ�.
// �̱����� ���� ���� : static���� ����ؼ� �Լ��� �θ��� �Ǵ°�,
// ���� �̱������� ����, �Լ��� �θ� �ʿ䰡 �ֳ�.
class ResourcesManager
{
public:
	// constructer destructer
	ResourcesManager();
	~ResourcesManager();

	// delete Function
	ResourcesManager(const ResourcesManager& _Other) = delete;
	ResourcesManager(ResourcesManager&& _Other) noexcept = delete;
	ResourcesManager& operator = (const ResourcesManager& _Other) = delete;
	ResourcesManager& operator = (ResourcesManager&& _Other) noexcept = delete;

protected:

private:

};
