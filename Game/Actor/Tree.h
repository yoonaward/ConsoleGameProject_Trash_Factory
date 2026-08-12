#pragma once

#include <Actor/Actor.h>


class Tree : public Craft::Actor
{
	TYPE_DECLARATIONS(Tree, Actor)

public:
	Tree(const Craft::Vector2& position);
	virtual ~Tree();

};

