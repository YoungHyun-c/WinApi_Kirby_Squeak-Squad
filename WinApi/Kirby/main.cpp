#include <GameEnginePlatform/GameEngineWindow.h>
#include <iostream>

void TestStart(HINSTANCE _Inst)
{
    GameEngineWindow::MainWindow.Open("MainWindow", _Inst);
}

void TestEnd()
{

}

void TestUpdate()
{

}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineWindow::MainWindow.MessageLoop(hInstance, TestStart, TestUpdate, TestEnd);
    

    //GameEngineWindow::MainWindow.Open("MainWindow", hInstance);
    //GameEngineWindow NewWindow;
    //NewWindow.Open("MainWindow1", hInstance);

    return 0;
}