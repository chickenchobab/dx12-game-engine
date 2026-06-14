#pragma once
class Component
{
public:
	Component();
	~Component();

	virtual void Tick(float DeltaTime);

protected:
	shared_ptr<class Actor> Owner;
};

