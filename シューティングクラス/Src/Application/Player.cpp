#include "Player.h"
#include "Scene.h"

C_Player::C_Player()
{
	
}

C_Player::~C_Player()
{
	
}

void C_Player::Init()
{
	m_pos.x = 0;
	m_pos.y = -200;

	m_bulletTex.Load("Texture/bullet.png");
	for (int i = 0;i < m_bulletNum;i++)
	{
		m_bullet[i].SetTex(&m_bulletTex);
		m_bullet[i].Init();
	}
}

void C_Player::Update(POINT mousePos)
{
	/*if (GetAsyncKeyState('W') & 0x8000)m_pos.y += m_movespeed;
	if (GetAsyncKeyState('S') & 0x8000)m_pos.y -= m_movespeed;*/
	if (GetAsyncKeyState('A') & 0x8000)m_pos.x -= m_movespeed;
	if (GetAsyncKeyState('D') & 0x8000)m_pos.x += m_movespeed;

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		for (int i = 0;i < m_bulletNum;i++)
		{
			if (!m_bullet[i].GetAlive())
			{
				const float x = mousePos.x - m_pos.x;
				const float y = mousePos.y - m_pos.y;
				const float radian = atan2(y, x);

				m_bullet[i].Shot(m_pos, radian);
				break;
			}
		}
	}

	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	for (int i = 0;i < m_bulletNum;i++)
	{
		m_bullet[i].Update();
	}
}

void C_Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex,Math::Rectangle(0,0,64,64),1.0f);

	for (int i = 0;i < m_bulletNum;i++)
	{
		m_bullet[i].Draw();
	}
}

void C_Player::HitBulletEnemy()
{
	 if (!m_owner) return;

    C_Enemy* enemy = m_owner->GetEnemy();
    if (!enemy) return;

    if (!enemy->GetAlive()) return;

	const Math::Vector2 enemyPos = enemy->GetPos();

	for (int i = 0;i < m_bulletNum;i++)
	{
		if (!m_bullet[i].GetAlive())continue;

		const Math::Vector2 bulletPos = m_bullet[i].GetPos();
		const float a = bulletPos.x - enemyPos.x;
		const float b = bulletPos.y - enemyPos.y;
		const float c = sqrt(a * a + b * b);

		const float sumRadius = enemy->GetRadius() + m_bullet[i].GetRadius();

		if (c < sumRadius)
		{
			enemy->Hit();
			m_bullet[i].Hit();
		}

	}
}

void C_Player::SetTex(KdTexture* tex)
{
	m_tex = tex;
}

void C_Player::SetOwner(Scene* owner)
{
	m_owner = owner;
}
