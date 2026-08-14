#pragma once

#include <Actor/Actor.h>

// 비슷한 기능을 하는 액터들을 묶어서 처리

class Obstacle :public Craft::Actor
{
	TYPE_DECLARATIONS(Obstacle, Actor)

// 열거형 클래스로 타입 관리
public:
	enum class ObstacleType
	{
		// 기본값
		None,
		Wall,
		Bench
	};

public:
	// 타입에 매개 변수를 넣어 타입 구분
	Obstacle(ObstacleType type, Craft::Vector2& position);

	virtual ~Obstacle();

	// 반환 자료형  함수이름       
	ObstacleType GetObstacleType() const;

private:
	
	// 종류에 맞춰 문자와 색상 설정.
	void InitializeByType();

private:
	// 초기값 설정
	ObstacleType obstacleType = ObstacleType::None;
};

