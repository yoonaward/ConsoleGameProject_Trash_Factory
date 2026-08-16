#pragma once

#include <Engine/Engine.h>
#include <memory>

// 현재 게임 화면 상태
enum class GameState
{   
    Title,
    Playing,
    Menu
};

// 플레이 가능한 스테이지 종류
enum class StageType
{
    SmallPark,
    LargePark
};

// 게임 전체 화면 및 스테이지 전환 담당
class Game : public Craft::Engine
{
public:
    Game();
    virtual ~Game() = default;

    // 현재 실행 중인 Game 객체에 접근
    static Game& Get();

    // 메뉴 열기
    void OpenMenu();

    // 메뉴에서 기존 게임으로 복귀
    void ResumeGame();

    // 게임 스테이지 변경
    void ChangeStage(StageType newStage);

    // 타이틀 메뉴
    void StartNewGame();

private:
    // StageType에 맞는 레벨 객체 생성
    std::shared_ptr<Craft::Level> CreateStage(
        StageType stage);

private:
    // 현재 플레이 중인 레벨
    // SmallParkLevel 또는 LargeParkLevel을 가리킨다.
    std::shared_ptr<Craft::Level> gameplayLevel;

    // 메뉴 레벨
    std::shared_ptr<Craft::Level> menuLevel;

    // 타이틀 레벨
    std::shared_ptr<Craft::Level> titleLevel;

    // 초기 화면 상태
    GameState gameState = GameState::Title;

    // 현재 플레이 중인 스테이지
    StageType currentStage = StageType::SmallPark;
};