#include "pch.h"
#include "Component.h"

Component::Component()
	: Owner(nullptr)
{
}

Component::~Component()
{
}

void Component::Tick(float DeltaTime)
{
}
