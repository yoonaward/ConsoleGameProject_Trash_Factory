#include "Player.h"
#include <Engine/Engine.h>
#include <Input/Input.h>

using namespace Craft;

Player::Player()
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

void Player::OnCollision(const std::shared_ptr<Craft::Actor>& other)
{

}

void Player::Move(float xDirection, float yDirection, float deltaTime)
{
	xPosition += xDirection * moveSpeed * deltaTime;
	yPosition += yDirection * moveSpeed * deltaTime;

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

void Player::PickUpGarbage()
{

}
