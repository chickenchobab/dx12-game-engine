#include "pch.h"
#include "Player.h"
#include "Actor.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::InitPlayer(Actor* InPawn)
{
	Possess(InPawn);
}

void Player::Possess(Actor* InPawn)
{
	Pawn = InPawn;

	if (Pawn)
	{
		Pawn->SetPlayer(this);
	}
}

void Player::UnPossess()
{
	Pawn = nullptr;
}
