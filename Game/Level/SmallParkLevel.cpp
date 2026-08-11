#include "SmallParkLevel.h"
#include <Actor/Player.h>

using namespace Craft;

SmallParkLevel::SmallParkLevel()
{
	

	SpawnActor<Player>();
}

SmallParkLevel::~SmallParkLevel()
{

}

void SmallParkLevel::BeginPlay()
{
	Level::BeginPlay();
}

void SmallParkLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);
}

void SmallParkLevel::Draw()
{
	super::Draw();
}
