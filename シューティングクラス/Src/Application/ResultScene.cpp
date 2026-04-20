#include "ResultScene.h"
#include "Scene.h"

void ResultScene::Init()
{
}

void ResultScene::Update()
{
    // スペースでタイトルへ
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        Scene::GetInstance().ChangeScene(Title);
    }
}

void ResultScene::Draw()
{


  
}

void ResultScene::Release()
{
}