#include "GameScene.h"
#include "Scene.h"

void GameScene::Init()
{
    m_playerTex.Load("Texture/player.png");
    m_enemyTex.Load("Texture/enemy.png");

    m_player.SetTex(&m_playerTex);
    m_enemy.SetTex(&m_enemyTex);

    m_player.Init();
    m_enemy.Init();

    m_player.SetOwner(&Scene::GetInstance());
}

void GameScene::Update()
{
    POINT mousePos;
    GetCursorPos(&mousePos);
    ScreenToClient(GetActiveWindow(), &mousePos);

    m_player.Update(mousePos);
    m_enemy.Update();

    m_player.HitBulletEnemy();

    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        Scene::GetInstance().ChangeScene(Pause);
    }

}

void GameScene::Draw()
{
    m_player.Draw();
    m_enemy.Draw();
}

void GameScene::Release()
{
}