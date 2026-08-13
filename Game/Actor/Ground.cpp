#include "Ground.h"

using namespace Craft;

/* 땅 클래스에 필요한 것
1. 땅 위치
2. 표시할 문자
3. 쓰레기가 사라져도 땅으로 처리 할 우선순위

*/

Ground::Ground(const Vector2& position)
	:Actor(" ", position)
{
	sortingOrder = 0;
}

Ground::~Ground()
{

}
