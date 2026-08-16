#pragma once

#include <Level/Level.h>
#include <string>

/*
 목표 갯수 필요
*/


class SmallParkLevel : public Craft::Level
{

	TYPE_DECLARATIONS(SmallParkLevel, Level)

public:
	SmallParkLevel();
	virtual~SmallParkLevel();

public:

	// 맵 초기화 함수
	virtual void OnInitialized() override;

	// LeafEffect 생성 함수
	void ShowLeafEffect();
	void StartLeafEffect();
	void EndLeafEffect();

	// TrashCan에 넣었을 때 호출
	void AddCGarbage();

	// Door와 상호작용할 때 호출
	void MoveNextStage();

	// 클리어 여부 확인
	bool IsStageClear() const;

private:
	// 맵 로드
	void LoadMap(const std::string& filename);

	void CheckStageClear();
	
private:
	// LeafEffect 중복을 막기 위한 상태
	bool onLeafEffect = false;

	// 스테이지 클리어 처리를 위한 garbage Count
	int garbageCount = 0;
	int goalGarbageCount = 1;

	bool isStageCleared = false;
};

