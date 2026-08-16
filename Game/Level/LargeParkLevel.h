#pragma once

#include <Level/Level.h>

class LargeParkLevel : public Craft::Level
{

	TYPE_DECLARATIONS(LargeParkLevel, Level)


public:

	LargeParkLevel();
	virtual ~LargeParkLevel();

	virtual void OnInitialized() override;

	// Leaf Effect 호출
	void ShowLeafEffect();

	// onLeafEffect true
	void StartLeafEffect();

	// onLeafEffect false
	void EndLeafEffect();

	// TrashCan에 넣었을 때 호출
	void AddCGarbage();

	// Door와 상호작용할 때 호출
	void MoveNextStage();

	// Stage 클리어 처리
	void ClearStage();

	// 클리어 여부 확인
	bool IsStageClear() const;

private:
	// 맵 로드
	void LoadMap(const std::string& filename);

private:
	// LeafEffect 중복을 막기 위한 상태
	bool onLeafEffect = false;

	// 스테이지 클리어 처리를 위한 garbage Count
	int garbageCount = 0;
	int goalGarbageCount = 1;

	bool isStageCleared = false;
};

