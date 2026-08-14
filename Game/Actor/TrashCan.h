#pragma once

#include <Actor/Actor.h>

// 쓰레기를 넣는 쓰레기통 클래스
// 필요한 기능
// 문자 표시
// 충돌처리
// 반환하면서 CountUP


class TrashCan : public Craft::Actor 
{
	TYPE_DECLARATIONS(TrashCan, Actor);

public:
	TrashCan(const Craft::Vector2& position);

	virtual ~TrashCan();

private:

};

