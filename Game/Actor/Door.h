#pragma once

#include<Actor/Actor.h>

class Door : public Craft::Actor
{
	TYPE_DECLARATIONS(Door, Actor)

public:
	Door(const Craft::Vector2& position);
	virtual ~Door();

private:
};

