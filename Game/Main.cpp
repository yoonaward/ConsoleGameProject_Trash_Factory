#include <Game/Game.h>
#include <Engine/Engine.h>

int main()
{
	//Craft::Engine engine;
	//engine.AddNewLevel<SmallParkLevel>();
	//engine.Run();

	SetConsoleTitleA("Sokoban Game");

	Game game;
	game.Run();

}