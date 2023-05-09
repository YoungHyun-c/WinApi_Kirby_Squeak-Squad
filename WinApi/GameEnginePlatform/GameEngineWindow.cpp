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
    if (nullptr != BackBuffer)
    {
        delete BackBuffer;
        BackBuffer = nullptr;
    }
}

void GameEngineWindow::Open(const std::string& _Title, HINSTANCE _hInstance)
{
    Instance = _hInstance;
    Title = _Title;

    if (nullptr == Instance)
    {
        MsgBoxAssert("HInstance 없이 윈도우를 만들 수 는 없습니다.");
        return;
    }

    MyRegisterClass();
    InitInstance();
}

void GameEngineWindow::InitInstance()
{

    //WS_OVERLAPPED | \
    //    WS_CAPTION | \
    //    WS_SYSMENU | \
    //    WS_THICKFRAME | \
    //    WS_MINIMIZEBOX | \
    //    WS_MAXIMIZEBOX


    // int Test = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME ;


    // Title은 std::string 자료형, const char* 자료형이 아니므로 string의 자료형을 바꿔 줘야됨
    // => Title.c_str()
    hWnd = CreateWindowA("DefaultClass", Title.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, Instance, nullptr);

    if (!hWnd)
    {
        MsgBoxAssert("윈도우 생성에 실패했습니다.")
        return;
    }

    Hdc = ::GetDC(hWnd);

    BackBuffer = new GameEngineWindowTexture();
    BackBuffer->ResCreate(Hdc);

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
    
    // 반환값 (ATOM 함수가 실패하면 반환값은 0 이다)
    if (false == RegisterClassExA(&wcex))
    {
        MsgBoxAssert("윈도우 클래스 등록에 실패했습니다.");
        return;
    }
    Check = true;
}

void GameEngineWindow::MessageLoop(HINSTANCE _Inst, void(*_Start)(HINSTANCE), void(*_Update)(), void(*_End)())
{
    // 단축키를 사용하기 위한 핸들
    // HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSTESTPROJECT));

    if (nullptr != _Start)
    {
        _Start(_Inst);
    }

    MSG msg;

    while (IsWindowUpdate)
    {
        // 윈도우에 무슨일이 있는게 아니라 메세지가 있든없든 동작해야된다.

        // GetMessage는 동기함수 _getch() <= 키가 눌릴때까지 멈춘다.
        // (함수가 제대로 끝날때까지 기다리는 함수들을 동기 함수라고 한다.)
        // GetMessage는 동기함수이다. 윈도우의 메시지가 발생할때까지 기다린다.
        // 비동기 메세지 함수가 있다.
        // PeekMessage는 윈도우 메세지가 없으면 0이 리턴되고 그냥 리턴한다.

        // 프레임과 데드타임이 완성됐다.
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


        // 윈도우 메시지가 없는 시간을 데드타임이라고 한다.
        // 게임은 데드타임에 돌아가는게 보통이다.
        // 게임중에 2가지 종류가 있다.
        // 윈도우를 움직이거나 크기를 줄이면
        // 1. 화면이 정지하는 게임.
        // 2. 내가 그런 윈도우 메시지를 발생시키는 와중에도 게임은 계속 돌아가는 게임

        // 이게 한바퀴가 도는 것을 프레임
        // FPS
        // 초당 화면이 그려지는 횟수
        // 하드웨어와도 연관이 있다. (모니터)

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

void GameEngineWindow::SetPosAndScale(const float4& _Pos, const float4& _Scale)
{
    //Window에서 LP 포인터라는 뜻 LongPointer

    Scale = _Scale;

    RECT Rc = { 0 , 0, _Scale.iX(), _Scale.iY() };

    AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);

    SetWindowPos(hWnd, nullptr, _Pos.iX(), _Pos.iY(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}