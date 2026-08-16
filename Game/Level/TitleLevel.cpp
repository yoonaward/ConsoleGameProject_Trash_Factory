#include "TitleLevel.h"

#include <Game/Game.h>
#include <Input/Input.h>
#include <Render/Renderer.h>

#include <cassert>

using namespace Craft;

TitleLevel::TitleLevel()
{
    // 게임 시작
    itemList.emplace_back(
        std::make_unique<TitleMenuItem>(
            "Start Game",
            []()
            {
                Game::Get().StartNewGame();
            }
        )
    ); 

    // 게임 나가기
    itemList.emplace_back(
        std::make_unique<TitleMenuItem>(
            "Quit Game",
            []()
            {
                Engine::Get().Quit();
            }
        )
    );
}

void TitleLevel::Tick(float deltaTime)
{
    Level::Tick(deltaTime);

    const int menuCount =
        static_cast<int>(itemList.size());

    if (menuCount <= 0)
    {
        return;
    }

    // 위 방향키
    if (Input::Get().GetKeyDown(VK_UP))
    {
        currentIndex =
            (currentIndex - 1 + menuCount)
            % menuCount;
    }

    // 아래 방향키
    if (Input::Get().GetKeyDown(VK_DOWN))
    {
        currentIndex =
            (currentIndex + 1)
            % menuCount;
    }

    // 엔터
    if (Input::Get().GetKeyDown(VK_RETURN))
    {
        assert(
            currentIndex >= 0
            && currentIndex < menuCount
            && itemList[currentIndex]
            && itemList[currentIndex]->onSelected
        );

        if (currentIndex < 0
            || currentIndex >= menuCount)
        {
            return;
        }

        if (!itemList[currentIndex]
            || !itemList[currentIndex]->onSelected)
        {
            return;
        }

        itemList[currentIndex]->onSelected();
    }
}

void TitleLevel::Draw()
{
    // 문자열을 화면 중앙에 출력하는 함수.
    auto SubmitCentered =
        [](const std::string& text, int y, Color color)
        {
            const int screenWidth =
                Engine::Get().GetWidth();

            int x =
                (screenWidth
                    - static_cast<int>(text.length()))
                / 2;

            // 문자열이 화면보다 길 경우를 대비.
            if (x < 0)
            {
                x = 0;
            }

            Renderer::Get().Submit(
                text,
                Vector2(x, y),
                color
            );
        };

    // 공장 실루엣.
    SubmitCentered(
        "_________________________________________________",
        3,
        Color::Brown
    );

    SubmitCentered(
        "|                                               |",
        4,
        Color::Brown
    );

    SubmitCentered(
        "|                                               |",
        5,
        Color::Brown
    );

    SubmitCentered(
        "|                                               |",
        6,
        Color::Brown
    );

    // 게임 제목.
    SubmitCentered(
        "|            T R A S H   F A C T O R Y            |",
        7,
        Color::Green
    );

    SubmitCentered(
        "|                                               |",
        8,
        Color::Brown
    );

    SubmitCentered(
        "|                                               |",
        9,
        Color::Brown
    );

    SubmitCentered(
        "|                                               |",
        10,
        Color::Brown
    );

    SubmitCentered(
        "|_______________________________________________|",
        11,
        Color::Brown
    );

    // 게임 부제.
    SubmitCentered(
        "공원을 청소하세요!",
        15,
        Color::Cyan
    );

    // 메뉴 출력.
    const int menuCount =
        static_cast<int>(itemList.size());

    for (int index = 0;
        index < menuCount;
        ++index)
    {
        const bool isSelected =
            index == currentIndex;

        // 선택된 항목에 커서와 괄호 표시.
        std::string menuText;

        if (isSelected)
        {
            menuText =
                ">  [ " + itemList[index]->text + " ]  <";
        }
        else
        {
            menuText =
                "     " + itemList[index]->text + "     ";
        }

        const Color textColor =
            isSelected
            ? Color::Yellow
            : Color::BrightWhite;

        SubmitCentered(
            menuText,
            19 + index * 2,
            textColor
        );
    }

    // 조작 안내.
    SubmitCentered(
        "UP / DOWN : SELECT",
        26,
        Color::White
    );

    SubmitCentered(
        "ENTER : CONFIRM",
        27,
        Color::White
    );
}