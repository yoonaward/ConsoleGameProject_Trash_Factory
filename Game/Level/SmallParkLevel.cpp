#include "SmallParkLevel.h"
#include <Actor/Player.h>
#include <iostream>

using namespace Craft;

SmallParkLevel::SmallParkLevel()
{
	
}

SmallParkLevel::~SmallParkLevel()
{

}

void SmallParkLevel::BeginPlay()
{
	super::BeginPlay();

	// 플레이어 생성
	std::shared_ptr<Player> player = SpawnActor<Player>();

	// 안쪽에서 시작
	player->SetPosition(Vector2(18, 3));
}

void SmallParkLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);
}

void SmallParkLevel::Draw()
{
	// @Temp: 맵 출력.
	for (int y = 0; y < 8; ++y)
	{
		std::cout << map[y] << "\n";
	}


	// 액터 그리기.


	super::Draw();
}
