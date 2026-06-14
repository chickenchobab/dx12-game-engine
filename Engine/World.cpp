#include "pch.h"
#include "World.h"
#include "Actor.h"

World::World()
{
}

World::~World()
{
}

void World::InitWorld()
{
}

Actor* World::SpawnActor()
{
	Actors.emplace_back();
	return Actors.back().get();
}

void World::DestoryActor(Actor* InActor)
{
	auto It = std::find_if(begin(Actors), end(Actors), [InActor](const auto& ActorPtr) { return ActorPtr.get() == InActor; });

	if (It != Actors.end())
	{
		if (InActor)
		{
			InActor->DestroyActor();
		}
		Actors.erase(It);
	}
}
