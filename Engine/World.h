#pragma once

class Actor;

class World
{
public:
	World();
	~World();

	void InitWorld();

	Actor* SpawnActor();
	void DestoryActor(Actor* InActor);

private:
	vector<unique_ptr<Actor>> Actors;
};

