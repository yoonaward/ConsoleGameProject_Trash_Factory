#pragma once

#include <Level/Level.h>
#include <string>

// 메뉴 아이템 구조체
struct MenuItem
{
	// 메뉴 선택 시 실행할 로직 저장을 위한 함수 포인터
	using OnSelected = void(*)();

	// 생성자
	MenuItem(const std::string& text, OnSelected onSelected)
		:text(text), onSelected(onSelected)
	{
	}

	//메뉴 텍스트
	std::string text;

	// 메뉴 선택 로직
	OnSelected onSelected = nullptr;
};

class MenuLevel : public Craft::Level
{
public:
	MenuLevel();

	
private:
	// 오버라이드 함수
	virtual void Tick(float deltaTime) override;

	virtual void Draw() override;

private:
	// 현재 활성화 된 메뉴 아이템
	int currentIndex = 0;

	// 선택 메뉴 색상
	Craft::Color selectedColor = Craft::Color::Green;

	// 미선택 메뉴 색상
	Craft::Color unSelectedColor = Craft::Color::White;

	// 메뉴 배열
	std::vector<std::unique_ptr<MenuItem>> itemList;

};

