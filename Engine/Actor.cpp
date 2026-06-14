#include "pch.h"
#include "Actor.h"
#include "Player.h"
#include "TransformComponent.h"

Actor::Actor()
{
	TransformComponentIndex = Components.size();
	Components.push_back(make_shared<TransformComponent>());
}

void Actor::DestroyActor()
{
	if (ControllingPlayer)
	{
		ControllingPlayer->UnPossess();
	}
}

inline TransformComponent* Actor::GetTransform() const
{
	return dynamic_cast<TransformComponent*>(Components[TransformComponentIndex].get());
}
