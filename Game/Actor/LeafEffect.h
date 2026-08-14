#pragma once

#include <Actor/Actor.h>
#include <Util/Util.h>

// 나무 충돌 감지로 인한 시야 방해 요소
// 1. 플레이어가 나무와 충돌한다
// 2. 나무와 충돌한 게 맞는지 체크
// 3. 텍스트 파일을 읽어와서 화면 가리기
// 4. 일정 시간이 지나가면 원래대로 돌아오기

class LeafEffect : public Craft ::Actor 
{
	TYPE_DECLARATIONS(LeafEffect, Actor)
public:
	LeafEffect();
	virtual ~LeafEffect();

private:
	virtual void Tick(float deltaTime) override;

	virtual void Draw() override;

	void LoadEffect(const std::string& filename);

private:
	// 파일에서 읽은 값 줄로 저장
	std::vector<std::string> effectLines;

	// 가리는 시간
	float elapsedTime = 0.0f;
	float duration = 5.0f;
};

