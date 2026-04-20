#include "TitleScene.h"
#include "Scene.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Scene::GetInstance().ChangeScene(Game);
	}
}

void TitleScene::Draw()
{
	
}

void TitleScene::Release()
{
}
