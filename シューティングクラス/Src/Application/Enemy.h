#pragma once

class C_Enemy
{
public:
	C_Enemy();
	~C_Enemy();

	void Init();
	void Update();
	void Draw();
	void Hit();

	void SetTex(KdTexture* tex);

	bool GetAlive();
	Math::Vector2 GetPos();
	float GetRadius();

private:

	const float m_movespeed = 5.0f;
	const float m_radius = 32.0f;

	KdTexture* m_tex;
	Math::Vector2 m_pos;//ç¿ïW
	Math::Vector2 m_move;
	Math::Matrix m_mat;
	bool m_alive;
};