#pragma once

#include <Level/Level.h>
#include <string>

/*
 목표 갯수 필요
*/


class SmallParkLevel : public Craft::Level
{

	TYPE_DECLARATIONS(SmallParkLevel, Level)

public:
	SmallParkLevel();
	virtual~SmallParkLevel();

public:

	// 맵 초기화 함수.
	virtual void OnInitialized() override;

private:
	// 맵 로드.
	void LoadMap(const std::string& filename);

private:
	int garbageCount;
};

