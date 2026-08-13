#pragma once

#include <Actor/Actor.h>

/*
플레이어 클래스에 필요한 것
1. 이동 설정(위치 값)
2. 문자 표시
3. 쓰레기를 집는 기능(스페이스 키)
4. 잡고 있는 지 확인하는 기능
4. 장애물 충돌
5. 물,돌뿌리 위에서 속도가 감소 처리
*/

// 상, 하, 좌, 우로 이동/ 스페이스 키로 쓰레기를 수집하는 플레이어.
class Player : public Craft::Actor
{
	// 커스텀 타입 등록.
	TYPE_DECLARATIONS(Player, Actor)

public:
	// 생성자.
	Player(const Craft::Vector2& position);

private:
	
	// 이벤트 함수 오버라이드.
	virtual void Tick(float deltaTime) override;

	// 충돌 이벤트 함수 오버라이드.
	virtual void OnCollision(const std::shared_ptr<Craft::Actor>& other) override;

	// 이동 처리 함수.
	void Move(float xDirection, float yDirection, float deltaTime);

	// 옮길 수 있는지
	void CanCarrying();

	// 쓰레기 수집 키 함수.
	// 스페이스를 누르면 수집 및 쓰레기 갯수 + , 도감 등록
	void PickUpGarbage();

private:
	// 이동 처리에 필요한 변수.
	float xPosition = 0.0f;
	float yPosition = 0.0f;
	

	// 이동 속도 변수.
	float xMoveSpeed = 10.0f;
	float yMoveSpeed = 5.82f;

private:
	bool isGrab = false;

};

