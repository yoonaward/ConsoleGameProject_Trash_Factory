#include "Game.h"

#include <Level/SmallParkLevel.h>
#include <Level/LargeParkLevel.h>
#include <Level/MenuLevel.h>

Game::Game()
{
    // 처음 플레이할 SmallParkLevel 생성.
    gameplayLevel = CreateStage(
        StageType::SmallPark
    );

    // 메뉴 레벨은 한 번만 생성하고 계속 보관.
    menuLevel = std::make_shared<MenuLevel>();

    // 시작 상태 설정.
    currentStage = StageType::SmallPark;
    gameState = GameState::Playing;

    // 최초 실행 레벨 설정.
    mainLevel = gameplayLevel;
}

Game& Game::Get()
{
    // Main.cpp에서 실제로 Game 객체를 생성하기 때문에
    // Engine 인스턴스를 Game으로 변환할 수 있다.
    return static_cast<Game&>(
        Craft::Engine::Get()
        );
}

std::shared_ptr<Craft::Level> Game::CreateStage(
    StageType stage)
{
    switch (stage)
    {
    case StageType::SmallPark:
        return std::make_shared<SmallParkLevel>();

    case StageType::LargePark:
        return std::make_shared<LargeParkLevel>();
    }

    // 예상하지 못한 StageType이 들어온 경우.
    return nullptr;
}

void Game::OpenMenu()
{
    // 게임 플레이 중이 아니면 메뉴를 열지 않는다.
    if (gameState != GameState::Playing)
    {
        return;
    }

    // 메뉴 상태로 변경.
    gameState = GameState::Menu;

    // 실제 레벨 교체는 Engine이 프레임 마지막에 처리한다.
    // gameplayLevel은 별도로 보관되므로 삭제되지 않는다.
    nextLevel = menuLevel;
}

void Game::ResumeGame()
{
    // 메뉴 상태가 아니면 처리하지 않는다.
    if (gameState != GameState::Menu)
    {
        return;
    }

    // 복귀할 게임 레벨이 없으면 처리하지 않는다.
    if (!gameplayLevel)
    {
        return;
    }

    // 게임 플레이 상태로 변경.
    gameState = GameState::Playing;

    // SmallPark 또는 LargePark 중
    // 메뉴를 열기 전에 실행하던 레벨로 복귀한다.
    nextLevel = gameplayLevel;
}

void Game::ChangeStage(StageType newStage)
{
    // 새로운 스테이지 레벨 생성.
    std::shared_ptr<Craft::Level> newLevel =
        CreateStage(newStage);

    // 생성 실패 확인.
    if (!newLevel)
    {
        return;
    }

    // 현재 스테이지 정보 갱신.
    currentStage = newStage;

    // 현재 게임 레벨을 새로운 레벨로 교체.
    gameplayLevel = newLevel;

    // 스테이지 전환 시 플레이 상태로 변경.
    gameState = GameState::Playing;

    // 실제 mainLevel 교체는 프레임 마지막에 처리.
    nextLevel = gameplayLevel;
}