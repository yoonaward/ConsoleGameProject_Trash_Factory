#pragma once

#include <Level/Level.h>



class SmallParkLevel : public Craft::Level
{

	TYPE_DECLARATIONS(SmallParkLevel, Level)

public:
	SmallParkLevel();
	virtual~SmallParkLevel();

	virtual void BeginPlay() override;

	virtual void Tick(float deltaTime) override;

	virtual void Draw() override;

};

