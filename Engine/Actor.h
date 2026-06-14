#pragma once

class TransformComponent;
class Player;

class Actor
{
public:

	Actor();

	void DestroyActor();

	void SetPlayer(Player* InPlayer) { ControllingPlayer = InPlayer; }


	inline TransformComponent* GetTransform() const;
	
private:
	vector<shared_ptr<class Component>> Components;

	uint8 TransformComponentIndex;

	Player* ControllingPlayer;
};

