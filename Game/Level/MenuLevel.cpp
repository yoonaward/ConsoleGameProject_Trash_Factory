#include "MenuLevel.h"

#include <Game/Game.h>
#include <Input/Input.h>
#include <Render/Renderer.h>

#include <cassert>

using namespace Craft;

MenuLevel::MenuLevel()
{
    // 게임 재개 메뉴.
    itemList.emplace_back(
        std::make_unique<MenuItem>(
            "RESUME GMAE",
            []()
            {
                Game::Get().ResumeGame();
            }
        )
    );

    // 게임 종료 메뉴.
    itemList.emplace_back(
        std::make_unique<MenuItem>(
            "QUIT GAME",
            []()
            {
                Engine::Get().Quit();
            }
        )
    );
}

void MenuLevel::Tick(float deltaTime)
{
    // MenuLevel에 Actor가 추가될 가능성을 고려해 부모 호출.
    Level::Tick(deltaTime);

    // ESC를 누르면 기존 게임으로 복귀.
    if (Input::Get().GetKeyDown(VK_ESCAPE))
    {
        Game::Get().ResumeGame();

        // 다음에 메뉴를 열 때 첫 번째 항목 선택.
        currentIndex = 0;
        return;
    }

    const int menuCount =
        static_cast<int>(itemList.size());

    // 메뉴가 없으면 아래 계산을 하지 않는다.
    if (menuCount <= 0)
    {
        return;
    }

    // 이전 메뉴 선택.
    if (Input::Get().GetKeyDown(VK_UP))
    {
        currentIndex =
            (currentIndex - 1 + menuCount)
            % menuCount;
    }

    // 다음 메뉴 선택.
    if (Input::Get().GetKeyDown(VK_DOWN))
    {
        currentIndex =
            (currentIndex + 1)
            % menuCount;
    }

    // 현재 메뉴 실행.
    if (Input::Get().GetKeyDown(VK_RETURN))
    {
        assert(
            currentIndex >= 0 && currentIndex < menuCount && itemList[currentIndex] && itemList[currentIndex]->onSelected);

        if (currentIndex < 0 || currentIndex >= menuCount)
        {
            return;
        }

        if (!itemList[currentIndex])
        {
            return;
        }

        if (!itemList[currentIndex]->onSelected)
        {
            return;
        }

        itemList[currentIndex]->onSelected();
    }
}

void MenuLevel::Draw()
{
    // 문자열을 화면 중앙에 출력하는 지역 함수.
    auto SubmitCentered =
        [](const std::string& text,
            int y,
            Color color,
            int sortingOrder = 100)
        {
            const int screenWidth =
                Engine::Get().GetWidth();

            int x =
                (screenWidth
                    - static_cast<int>(text.length()))
                / 2;

            if (x < 0)
            {
                x = 0;
            }

            Renderer::Get().Submit(
                text,
                Vector2(x, y),
                color,
                sortingOrder
            );
        };

    // 상단 장식.
    SubmitCentered(
        "+----------------------------------------------------+",
        6,
        Color::Brown
    );

    SubmitCentered(
        "|                                                    |",
        7,
        Color::Brown
    );

    SubmitCentered(
        "|                   G A M E   P A U S E D                 |",
        8,
        Color::Yellow
    );

    SubmitCentered(
        "|                                                    |",
        9,
        Color::Brown
    );

    SubmitCentered(
        "+----------------------------------------------------+",
        10,
        Color::Brown
    );

    // 안내 문구.
    SubmitCentered(
        "원하는 메뉴를 선택해 주세요.",
        13,
        Color::Cyan
    );

    // 조작 안내.
    SubmitCentered(
        "UP / DOWN / RIGHT / LEFT : MOVE",
        24,
        Color::White
    );

    SubmitCentered(
        "UP / DOWN : SELECT",
        25,
        Color::White
    );

    SubmitCentered(
        "ENTER : CONFIRM",
        26,
        Color::White
    );

    // 메뉴 출력.
    const int menuCount =
        static_cast<int>(itemList.size());

    const int menuStartY = 17;

    for (int index = 0;
        index < menuCount;
        ++index)
    {
        const bool isSelected =
            index == currentIndex;

        std::string menuText;

        if (isSelected)
        {
            menuText =
                ">  [ "
                + itemList[index]->text
                + " ]  <";
        }
        else
        {
            menuText =
                itemList[index]->text;
        }

        const Color textColor =
            isSelected
            ? Color::Green
            : Color::BrightWhite;

        SubmitCentered(
            menuText,
            menuStartY + index * 2,
            textColor
        );
    }
}