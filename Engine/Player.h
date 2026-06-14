#pragma once

class Actor;

class Player
{
public:
	Player();
	~Player();

	void InitPlayer(Actor* InPawn);

	Actor* GetPawn() const { return Pawn; }
	void Possess(Actor* InPawn);
	void UnPossess();

private:
	Actor* Pawn;
};

