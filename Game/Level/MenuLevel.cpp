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
            "게임 계속하기",
            []()
            {
                Game::Get().ResumeGame();
            }
        )
    );

    // 게임 종료 메뉴.
    itemList.emplace_back(
        std::make_unique<MenuItem>(
            "게임 나가기",
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
    // 메뉴 제목.
    Renderer::Get().Submit(
        "Trash Factory",
        Vector2::Zero
    );

    const int menuCount =
        static_cast<int>(itemList.size());

    for (int index = 0;
        index < menuCount;
        ++index)
    {
        // 현재 선택된 메뉴만 초록색으로 표시.
        const Color textColor = index == currentIndex ? selectedColor : unselectedColor;

        Renderer::Get().Submit(itemList[index]->text, Vector2(0, 2 + index), textColor);
    }
}