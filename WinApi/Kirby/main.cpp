#include <iostream>
#include <GameEngineCore/GameEngineCore.h>

#include <KirbyEngineContents/PlayLevel.h>
#include <KirbyEngineContents/TitleLevel.h>
#include <list>


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineCore::EngineStart("MyWindow", hInstance);
    GameEngineCore::EngineStart("MyWindow1", hInstance);

    // callback ���
    // core�� ������.
    //GameEngineWindow::MainWindow.MessageLoop(hInstance, TestStart, TestUpdate, TestEnd);
    

    //GameEngineWindow::MainWindow.Open("MainWindow", hInstance);
    //GameEngineWindow NewWindow;
    //NewWindow.Open("MainWindow1", hInstance);

    return 0;
}