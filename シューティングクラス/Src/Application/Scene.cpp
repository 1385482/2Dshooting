#include "Scene.h"

void Scene::Init()
{
	ChangeScene(Title); // 最初はタイトル
}

void Scene::Update()
{
	if (m_currentScene) m_currentScene->Update();
}

void Scene::Draw()
{
	if (m_currentScene) m_currentScene->Draw();
}

void Scene::Release()
{
	if (m_currentScene)
	{
		m_currentScene->Release();
	}
}

void Scene::ChangeScene(SceneType type)
{
    if (m_currentScene)
    {
        m_currentScene->Release();
    }

    m_nowScene = type; // ←追加

    switch (type)
    {
    case Title:
        m_currentScene = &m_title;
        break;

    case Game:
        m_currentScene = &m_game;
        break;

    case Pause:
        m_currentScene = &m_pause;
        break;

    case Result:
        m_currentScene = &m_result;
        break;
    }

    if (m_currentScene)
    {
        m_currentScene->Init();
    }
}
void Scene::ImGuiUpdate()
{
    ImGui::Begin("Scene");

    switch (m_nowScene)
    {
    case Title:  ImGui::Text("Title Scene"); break;
    case Game:   ImGui::Text("Game Scene"); break;
    case Pause:  ImGui::Text("Pause Scene"); break;
    case Result: ImGui::Text("Result Scene"); break;
    }

    ImGui::End();
}

