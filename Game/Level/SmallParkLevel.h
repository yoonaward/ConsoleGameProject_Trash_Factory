#pragma once

#include <Level/Level.h>
#include <string>



class SmallParkLevel : public Craft::Level
{

	TYPE_DECLARATIONS(SmallParkLevel, Level)


	bool CheckGameClear();
public:
	SmallParkLevel();
	virtual~SmallParkLevel();

	virtual void BeginPlay() override;

	virtual void Tick(float deltaTime) override;

	virtual void Draw() override;

private:
	// 클리어 조건 여부.
	bool isGameClear = false;


};

