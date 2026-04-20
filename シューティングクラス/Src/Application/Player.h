#pragma once
#include"bullet.h"

class Scene;//‘O•ûéŒ¾

class C_Player
{
public:
	C_Player();
	~C_Player();

	void Init();
	void Update(POINT mousePos);
	void Draw();
	void HitBulletEnemy();

	
	void SetTex(KdTexture* tex);
	void SetOwner(Scene* owner);


private:

	Scene* m_owner;

	static const int m_bulletNum = 100;
	C_Bullet m_bullet[m_bulletNum];
	KdTexture m_bulletTex;

	const float m_movespeed = 10.0f;

	KdTexture *m_tex;
	Math::Vector2 m_pos;//À•W
	Math::Matrix m_mat;

};
