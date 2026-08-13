#include "TrashCan.h"
#include <Actor/Player.h>
#include <Input/Input.h>

using namespace Craft;

// 쓰레기를 넣는 쓰레기통 클래스
// 필요한 기능
// 문자 표시
// 충돌처리
// 반환하면서 CountUP

TrashCan::TrashCan(const Vector2& position)
	:Actor("U", position, Color::Purple)
{
	sortingOrder = 5;
}

TrashCan::~TrashCan()
{
}

void TrashCan::OnCollision(const std::shared_ptr<Craft::Actor>& other)
{

}
