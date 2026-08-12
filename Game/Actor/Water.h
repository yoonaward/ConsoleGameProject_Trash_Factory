#pragma once

#include <Actor/Actor.h>

class Water:public Craft ::Actor 
{
	TYPE_DECLARATIONS(Water, Actor)

public:
	Water(const Craft::Vector2& position);
	virtual ~Water();
};

