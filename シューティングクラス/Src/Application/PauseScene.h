#pragma once
#include "BaseScene.h"

class PauseScene : public BaseScene
{
public:
    void Init() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};