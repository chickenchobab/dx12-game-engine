#include "pch.h"
#include "TransformComponent.h"
#include "Engine.h"

TransformComponent::TransformComponent()
	: Scale(Vec4(1.0f, 1.0f, 1.0f, 1.0f)), Position(Vec4(0.0f, 0.0f, 0.0f, 0.0f))
{
	XMStoreFloat4(&RotationQuat, XMQuaternionIdentity());
	XMStoreFloat4x4(&WorldTransform, XMMatrixIdentity());
}

void TransformComponent::Tick(float DeltaTime)
{
	XMMATRIX WorldTransformMat =
		XMMatrixScalingFromVector(XMLoadFloat4(&Scale)) *
		XMMatrixRotationQuaternion(XMLoadFloat4(&RotationQuat)) *
		XMMatrixTranslationFromVector(XMLoadFloat4(&Position));

	XMStoreFloat4x4(&WorldTransform, WorldTransformMat);
}

void TransformComponent::MoveX(float Speed)
{
	Vec4 DeltaLocation;
	XMStoreFloat4(
		&DeltaLocation,
		XMVector3Normalize(GetWorldTransform().r[0]) *
		Speed *
		GEngine->GetDeltaTime());

	ApplyDeltaToPosition(XMLoadFloat4(&DeltaLocation));
}

void TransformComponent::MoveY(float Speed)
{
	Vec4 DeltaLocation;
	XMStoreFloat4(
		&DeltaLocation,
		XMVector3Normalize(GetWorldTransform().r[1]) *
		Speed *
		GEngine->GetDeltaTime());

	ApplyDeltaToPosition(XMLoadFloat4(&DeltaLocation));
}

void TransformComponent::RotateAroundZ(float Speed)
{
	XMVECTOR DeltaQuatVec = XMQuaternionRotationAxis(XMVectorSet(0, 0, 1, 0), Speed);
	XMVECTOR RotationQuatVec = XMLoadFloat4(&RotationQuat);

	XMStoreFloat4(&RotationQuat, XMQuaternionNormalize(XMQuaternionMultiply(DeltaQuatVec, RotationQuatVec)));
}

void TransformComponent::RotateAroundY(float Speed)
{
	XMVECTOR DeltaQuatVec = XMQuaternionRotationAxis(XMVectorSet(0, 1, 0, 0), Speed);
	XMVECTOR RotationQuatVec = XMLoadFloat4(&RotationQuat);

	XMStoreFloat4(&RotationQuat, XMQuaternionNormalize(XMQuaternionMultiply(DeltaQuatVec, RotationQuatVec)));
}

inline void TransformComponent::ApplyDeltaToPosition(XMVECTOR Delta)
{
	XMVECTOR PositionVec = XMLoadFloat4(&Position);
	PositionVec = XMVectorAdd(PositionVec, Delta);
	XMStoreFloat4(&Position, PositionVec);
}
