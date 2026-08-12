#pragma once

#include <Level/Level.h>
#include <Math/Vector2.h>


#include <string>




class GameState : public Craft :: Level
{
	TYPE_DECLARATIONS(GameState, Level)

private:
	// 맵 초기화 함수.
	virtual void OnInitialized() override;

	// 그리기.
	virtual void Draw() override;

	// 맵 로드.
	void LoadMap(const std::string& filename);

};

