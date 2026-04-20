#include "PauseScene.h"
#include "Scene.h"

void PauseScene::Init()
{
}

void PauseScene::Update()
{
    // スペースでゲームに戻る
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        Scene::GetInstance().ChangeScene(Game);
    }

    // ESCでタイトルに戻る（デバッグ用）
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        Scene::GetInstance().ChangeScene(Title);
    }
}

void PauseScene::Draw()
{
 
}

void PauseScene::Release()
{
}