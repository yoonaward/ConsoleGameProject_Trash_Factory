#pragma once

#include <Level/Level.h>
#include <Math/Color.h>

#include <memory>
#include <string>
#include <vector>

// 메뉴 하나의 정보를 저장하는 구조체
struct MenuItem
{
    // 메뉴를 선택했을 때 호출할 함수 포인터 타입
    using OnSelected = void(*)();

    MenuItem(
        const std::string& text,OnSelected onSelected): text(text), onSelected(onSelected)
    {
    }

    // 화면에 출력할 메뉴 이름
    std::string text;

    // 선택됐을 때 호출할 함수
    OnSelected onSelected = nullptr;
};

class MenuLevel : public Craft::Level
{
public:
    MenuLevel();
    virtual ~MenuLevel() = default;

private:
    // 메뉴 입력 처리
    virtual void Tick(float deltaTime) override;

    // 메뉴 출력
    virtual void Draw() override;

private:
    // 현재 선택된 메뉴 인덱스
    int currentIndex = 0;

    // 선택된 메뉴 색상
    Craft::Color selectedColor = Craft::Color::Green;

    // 선택되지 않은 메뉴 색상
    Craft::Color unselectedColor = Craft::Color::White;

    // 메뉴 목록
    std::vector<std::unique_ptr<MenuItem>> itemList;
};