#include "Water.h"

using namespace Craft;

// 사용자의 움직임을 느리게 하는 액터
// 1. 플레이어가 물에 들어가있는 동안은 느려진다
// 2. 플레이어가 물에서 나오면 원래 속도값을 가진다.

Water::Water(const Craft::Vector2& position)
	:Actor("~", position, Color::Blue)
{
}

Water::~Water()
{
}
