#pragma once
#include "Component.h"
class TransformComponent :
    public Component
{
public:
    TransformComponent();

    virtual void Tick(float DeltaTime) override;

    XMMATRIX GetWorldTransform() const { return XMLoadFloat4x4(&WorldTransform); }

    void MoveX(float Speed);
    void MoveY(float Speed);
    void RotateAroundZ(float Speed);
    void RotateAroundY(float Speed);

protected:
    Matrix WorldTransform;
    Vec4 Scale;
    Vec4 RotationQuat;
    Vec4 Position;

private:

    inline void ApplyDeltaToPosition(XMVECTOR Delta);
};

