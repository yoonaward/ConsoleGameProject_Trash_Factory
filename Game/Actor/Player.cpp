#include "Player.h"
#include <Engine/Engine.h>
#include <Input/Input.h>

using namespace Craft;

Player::Player()
	:Actor("@", Vector2::Zero, Color::Green)
{
	// 생성 위치 설정.
	int x = Engine::Get().GetWidth() / 2;
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
	// 오른쪽.
	if (Input::Get().GetKey(VK_RIGHT))
	{
		// 이동하려는 위치 값 만들기.
		Vector2 newPosition = GetPosition();
		newPosition.x += 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_LEFT))
	{
		Vector2 newPosition = GetPosition();
		newPosition.x -= 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_UP))
	{
		Vector2 newPosition = GetPosition();
		newPosition.y -= 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_DOWN))
	{
		Vector2 newPosition = GetPosition();
		newPosition.y += 1;
		SetPosition(newPosition);
	}
}

void Player::OnCollision(const std::shared_ptr<Craft::Actor>& other)
{

}

void Player::Move(float direction, float deltaTime)
{

}

void Player::PickUpGarbage()
{

}
