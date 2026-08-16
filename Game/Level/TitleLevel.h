#pragma once

#include <Level/Level.h>

#include <memory>
#include <string>
#include <vector>

struct TitleMenuItem
{
    using OnSelected = void(*)();

    TitleMenuItem(
        const std::string& text,
        OnSelected onSelected)
        : text(text),
        onSelected(onSelected)
    {
    }

    std::string text;
    OnSelected onSelected = nullptr;
};

class TitleLevel : public Craft::Level
{
public:
    TitleLevel();
    virtual ~TitleLevel() = default;

private:
    virtual void Tick(float deltaTime) override;
    virtual void Draw() override;

private:
    int currentIndex = 0;

    Craft::Color selectedColor =
        Craft::Color::Green;

    Craft::Color unselectedColor =
        Craft::Color::White;

    std::vector<
        std::unique_ptr<TitleMenuItem>
    > itemList;
};