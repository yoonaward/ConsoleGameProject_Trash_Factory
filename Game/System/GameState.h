#pragma once

class GameState 
{
public:
	// 아이템 사기
	void Buy();


private:
	// 클리어 확인
	bool CheckGameClear();

private:
	// 클리어 조건 여부.
	bool isGameClear = false;

	// 돈.
	int money = 0;

	// 쓰레기 도감.
	

	// 쓰레기 카운트.
	int GarbageCount = 0;
};

