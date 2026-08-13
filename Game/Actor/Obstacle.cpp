#include "Obstacle.h"

using namespace Craft;

Obstacle::Obstacle(ObstacleType type, Craft::Vector2& position)
	: Actor("?", position, Color::White), obstacleType(type)
{
	InitializeByType();
}

Obstacle::~Obstacle()
{
}

Obstacle::ObstacleType Obstacle::GetObstacleType() const
{
	return obstacleType;
}

void Obstacle::InitializeByType()
{
    switch (obstacleType)
    {
    case ObstacleType::Wall:
        ChangeImage("#");
        color = Color::White;
        break;

    case ObstacleType::Bench:
        ChangeImage("=");
        color = Color::Yellow;
        break;
    }
}
