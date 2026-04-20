#pragma once
#include "BaseScene.h"

class ResultScene : public BaseScene
{
public:
    void Init() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};