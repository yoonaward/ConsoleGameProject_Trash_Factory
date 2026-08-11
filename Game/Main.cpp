#include <Engine/Engine.h>
#include <Level/SmallParkLevel.h>
int main()
{
	Craft::Engine engine;
	engine.AddNewLevel<SmallParkLevel>();
	engine.Run();

}