#pragma once

#include <Actor/Actor.h>

class Bench : public Craft::Actor
{
	TYPE_DECLARATIONS(Bench, Actor)

	Bench(const Craft::Vector2& position);
	virtual ~Bench();
};

