#pragma once
#include "BaseScene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "ResultScene.h"
#include "Enemy.h"

enum SceneType
{
	Title,
	Game,
	Pause,
	Result
};

class Scene
{
private:

	SceneType m_nowScene;

	BaseScene* m_currentScene = nullptr;

	TitleScene  m_title;
	GameScene   m_game;
	PauseScene  m_pause;
	ResultScene m_result;


public:
	void Init();
	void Update();
	void Draw();
	void Release();
	void ImGuiUpdate();
	void ChangeScene(SceneType type);

	C_Enemy* GetEnemy()
	{
		if (m_currentScene == &m_game)
		{
			return m_game.GetEnemy();
		}
		return nullptr;
	}

	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}

};