#include "GameEngineWindow.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <iostream>

HINSTANCE GameEngineWindow::Instance = nullptr;
GameEngineWindow GameEngineWindow::MainWindow;
bool GameEngineWindow::IsWindowUpdate = true;


GameEngineWindow::GameEngineWindow()
{

}

GameEngineWindow::~GameEngineWindow()
{

}

void GameEngineWindow::Open(const std::string& _Title, HINSTANCE _hInstance)
{
    Instance = _hInstance;
    Title = _Title;

    if (nullptr == Instance)
    {
        MsgBoxAssert("HInstance ���� �����츦 ���� �� �� �����ϴ�.");
        return;
    }

    MyRegisterClass();
    InitInstance();
}

void GameEngineWindow::InitInstance()
{
    // Title�� std::string �ڷ���, const char* �ڷ����� �ƴϹǷ� string�� �ڷ����� �ٲ� ��ߵ�
    // => Title.c_str()
    hWnd = CreateWindowA("DefaultClass", Title.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, Instance, nullptr);

    if (!hWnd)
    {
        MsgBoxAssert("������ ������ �����߽��ϴ�.")
        return;
    }

    Hdc = ::GetDC(hWnd);

    // CreateDC();

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
}

LRESULT CALLBACK GameEngineWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        IsWindowUpdate = false;
        //PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void GameEngineWindow::MyRegisterClass()
{
    static bool Check = false;

    if (true == Check)
    {
        return;
    }

    WNDCLASSEXA wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    // LRESULT(CALLBACK* WNDPROC)(HWMD, unsigned int, unsigned int, unsigned int);
    wcex.lpfnWndProc = GameEngineWindow::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = Instance;
    wcex.hIcon = nullptr;//LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSTESTPROJECT));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "DefaultClass";
    wcex.hIconSm = nullptr;
    
    // ��ȯ�� (ATOM �Լ��� �����ϸ� ��ȯ���� 0 �̴�)
    if (false == RegisterClassExA(&wcex))
    {
        MsgBoxAssert("������ Ŭ���� ��Ͽ� �����߽��ϴ�.");
        return;
    }
    Check = true;
}

void GameEngineWindow::MessageLoop(HINSTANCE _Inst, void(*_Start)(HINSTANCE), void(*_Update)(), void(*_End)())
{
    // ����Ű�� ����ϱ� ���� �ڵ�
    // HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSTESTPROJECT));

    if (nullptr != _Start)
    {
        _Start(_Inst);
    }

    MSG msg;

    while (IsWindowUpdate)
    {
        // �����쿡 �������� �ִ°� �ƴ϶� �޼����� �ֵ���� �����ؾߵȴ�.

        // GetMessage�� �����Լ� _getch() <= Ű�� ���������� �����.
        // (�Լ��� ����� ���������� ��ٸ��� �Լ����� ���� �Լ���� �Ѵ�.)
        // GetMessage�� �����Լ��̴�. �������� �޽����� �߻��Ҷ����� ��ٸ���.
        // �񵿱� �޼��� �Լ��� �ִ�.
        // PeekMessage�� ������ �޼����� ������ 0�� ���ϵǰ� �׳� �����Ѵ�.

        // �����Ӱ� ����Ÿ���� �ϼ��ƴ�.
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (nullptr != _Update)
            {
                _Update();
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;

        }


        // ������ �޽����� ���� �ð��� ����Ÿ���̶�� �Ѵ�.
        // ������ ����Ÿ�ӿ� ���ư��°� �����̴�.
        // �����߿� 2���� ������ �ִ�.
        // �����츦 �����̰ų� ũ�⸦ ���̸�
        // 1. ȭ���� �����ϴ� ����.
        // 2. ���� �׷� ������ �޽����� �߻���Ű�� ���߿��� ������ ��� ���ư��� ����

        // �̰� �ѹ����� ���� ���� ������
        // FPS
        // �ʴ� ȭ���� �׷����� Ƚ��
        // �ϵ����͵� ������ �ִ�. (�����)

        if (nullptr != _Update)
        {
            _Update();
        }
    }

    if (nullptr != _End)
    {
        _End();
    }


    //return (int)msg.wParam;
    return;
}