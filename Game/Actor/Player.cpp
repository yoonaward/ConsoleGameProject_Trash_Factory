#include "Player.h"
#include <Engine/Engine.h>
#include <Input/Input.h>
#include <Actor/Garbage.h>
#include <Actor/Wall.h>
#include <Actor/Tree.h>
#include <Actor/Bench.h>
#include <Actor/TrashCan.h>


using namespace Craft;

/* 
플레이어 클래스에 필요한 것
1. 이동 설정(위치 값)
2. 문자 표시
3. 쓰레기를 집는 기능(스페이스 키)
4. 장애물 충돌
5. 물,돌뿌리 위에서 속도가 감소 처리
쓰레기를 스페이스로 줍는 과정
쓰레기 근처로 간다.
쓰레기가 근처에 있는 지 확인한다. CheckGarbage()
쓰레기를 스페이스바를 눌러 줍는다 VK_SPACE
쓰레기를 삭제한다. Destory()
쓰레기를 쓰레기통에 넣으면 카운트가 올라간다 ++ garbageCount
*/

Player::Player(const Vector2& position)
	:Actor("@", Vector2::Zero, Color::Green)
{
	// 생성 위치 설정.
	int x = Engine::Get().GetWidth() / 2 - (width / 2);
	int y = Engine::Get().GetHeight() / 2;
	SetPosition(Vector2(x, y));

	// x 위치 저장.
	xPosition = static_cast<float>(x);

	// y 위치 저장.
	yPosition = static_cast<float>(y);

	sortingOrder = 10;


}




void Player::Tick(float deltaTime)
{
	// 상위 계층의 Tick 호출
	super::Tick(deltaTime);

	// @temp 강제 종료.
	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		QuitGame();
	}

	// Todo: 메뉴 토글 기능


	// 움직임 처리.
	
	float xDirection = 0.0f;
	float yDirection = 0.0f;

	// 오른쪽.
	if (Input::Get().GetKey(VK_RIGHT))
	{
		// 이동하려는 위치 값 만들기.
		xDirection = 1.0f;
	}

	if (Input::Get().GetKey(VK_LEFT))
	{
		xDirection = -1.0f;
	}

	if (Input::Get().GetKey(VK_UP))
	{
		yDirection = -1.0f;
	}

	if (Input::Get().GetKey(VK_DOWN))
	{
		yDirection = 1.0f;
	}


	Move(xDirection, yDirection, deltaTime);




}

// 충돌 이벤트
void Player::OnCollision(const std::shared_ptr<Actor>& other)
{
	//  벽 충돌처리
	if (other->IsTypeOf<Wall>())
	{
		SetPosition(GetPreviousPosition());

		xPosition =
			static_cast<float>(GetPreviousPosition().x);

		yPosition =
			static_cast<float>(GetPreviousPosition().y);
	}

	//  나무 충돌 처리
	if (other->IsTypeOf<Tree>())
	{
		SetPosition(GetPreviousPosition());

		xPosition =
			static_cast<float>(GetPreviousPosition().x);

		yPosition =
			static_cast<float>(GetPreviousPosition().y);
	}

	//  밴치 충돌 처리
	if (other->IsTypeOf<Bench>())
	{
		SetPosition(GetPreviousPosition());

		xPosition =
			static_cast<float>(GetPreviousPosition().x);

		yPosition =
			static_cast<float>(GetPreviousPosition().y);
	}

	// 쓰레기 줍는 과정 처리 근데 스페이스를 누르면 처리 되게 해야하는데
	if (!Input::Get().GetKey(VK_SPACE))
	{
		return;
	}
		
	if (other->IsTypeOf<Garbage>())
		{
			// 잡고 있는 상태 변환
		isGrab = true;

			// 이미 잡고 있다면 안되게 처리
		if (!isGrab)
		{
			return;
		}

		// 잡고 있는 이미지 추가
			ChangeImage("&");


		// 삭제 요청
		other->Destroy();
		}

	if (other->IsTypeOf<TrashCan>())
	{
		// 놓는 상태로 변환.
		isGrab = false;

		// 이미 잡고 있다면 안되게 처리
		if (isGrab)
		{
			return;
		}

		// 잡고 있는 이미지 변경
		ChangeImage("@");


		// Todo: 스코어 증가 처리.
		
	}
}
void Player::Move(float xDirection, float yDirection, float deltaTime)
{
	xPosition += xDirection * xMoveSpeed * deltaTime;
	yPosition += yDirection * yMoveSpeed * deltaTime;

	// 화면 왼쪽 막힘 처리.
	if (xPosition < 0)
	{
		xPosition = 0.0f;
	}

	// 화면 오른쪽 막힘 처리.
	if (xPosition + width >= Engine::Get().GetWidth())
	{
		xPosition = static_cast<float>(Engine::Get().GetWidth() - width);
	}

	// 화면 위쪽 막힘 처리.
	if (yPosition < 0)
	{
		yPosition = 0.0f;
	}

	// 화면 아래쪽 막힘 처리.
	if (yPosition >= Engine::Get().GetHeight())
	{
		yPosition =static_cast<float>(Engine::Get().GetHeight() - 1);
	}

	// 위치 업데이트
	Vector2 newPosition = GetPosition();
	// float 값을 int로 형변환할 때 소숫점 값은 버림 처리된다는 점 주의.
	newPosition.x = static_cast<int>(xPosition);
	newPosition.y = static_cast<int>(yPosition);
	SetPosition(newPosition);

}


