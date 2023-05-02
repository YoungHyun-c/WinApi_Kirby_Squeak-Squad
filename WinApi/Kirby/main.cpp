#include <iostream>
#include <GameEngineCore/GameEngineCore.h>
#include <KirbyEngineContents/ContentCore.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineCore::EngineStart<ContentCore>("MyWindow", hInstance);
    //GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
  
    //GameEngineCore::EngineStart("MyWindow", hInstance);

    // callback 방식
    // core에 숨기자.
    //GameEngineWindow::MainWindow.MessageLoop(hInstance, TestStart, TestUpdate, TestEnd);
    

    //GameEngineWindow::MainWindow.Open("MainWindow", hInstance);
    //GameEngineWindow NewWindow;
    //NewWindow.Open("MainWindow1", hInstance);

    return 0;
}