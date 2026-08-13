#include "Garbage.h"



using namespace Craft;

/*
Garbage 클래스에 필요한 것
1. Garbage 위치
2. Garbage 문자
3. Garbage 삭제
4. Garbage 랜덤 스폰( 할 수 있으면 )
*/

Garbage::Garbage(const Vector2& position)
	:Actor("G", position, Color::Red)
{
	sortingOrder = 5;
}

Garbage::~Garbage()
{
}
