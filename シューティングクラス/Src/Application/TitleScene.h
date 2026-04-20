#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};