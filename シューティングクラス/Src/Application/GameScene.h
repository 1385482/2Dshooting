#pragma once
#include "BaseScene.h"
#include "Enemy.h"
#include "Player.h"

class Scene; // ‘O•ûéŒ¾

class GameScene : public BaseScene
{
public:
    C_Enemy* GetEnemy()
    {
        return &m_enemy;
    }

    void Init() override;
    void Update() override;
    void Draw() override;
    void Release() override;

private:
    C_Player m_player;
    C_Enemy  m_enemy;

    KdTexture m_playerTex;
    KdTexture m_enemyTex;

};