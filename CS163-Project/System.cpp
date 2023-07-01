#include "System.h"
#include "UI/Other.h"

void System::Construct() {
	windowWidth = 1460;
	windowHeight = 850;
	InitWindow(windowWidth, windowHeight, "Dictionary - CS163 Project (>'-'<)");

	Parable_Regular = LoadFont("../External/source/Font/Parable-Regular.ttf");

	Color defaultColor = { 113, 201, 206, 255 };
	Color touchedColor = { 63, 201, 250, 245 };
	Color clickedColor = { 113, 171, 206, 255 };

	reset.SetBox(0.062 * windowWidth, 0.051 * windowHeight, 0.129 * windowWidth, 0.078 * windowHeight, defaultColor, touchedColor, clickedColor);
	reset.SetText(Parable_Regular, "Reset", GetCenterPos(Parable_Regular, "Reset", 40, 0.5, reset.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	
	history.SetBox(0.055 * windowWidth, 0.438 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	history.SetText(Parable_Regular, "History", GetCenterPos(Parable_Regular, "History", 40, 0.5, history.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	
	favourite.SetBox(0.055 * windowWidth, 0.6 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	favourite.SetText(Parable_Regular, "Favourite", GetCenterPos(Parable_Regular, "Favourite", 40, 0.5, favourite.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);

	game.SetBox(0.055 * windowWidth, 0.762 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	game.SetText(Parable_Regular, "Game", GetCenterPos(Parable_Regular, "Game", 40, 0.5, game.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);

	addnew.SetBox(0.764 * windowWidth, 0.196 * windowHeight, 0.19 * windowWidth, 0.078 * windowHeight, defaultColor, touchedColor, clickedColor);
	addnew.SetText(Parable_Regular, "Add New", GetCenterPos(Parable_Regular, "Add New", 40, 0.5, addnew.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);

	searchBox.Construct(0.062 * windowWidth, 0.176 * windowHeight, 0.645 * windowWidth, 0.107 * windowHeight, Parable_Regular, { (float)0.14 * windowWidth, (float)0.201 * windowHeight }, 40, 1, 45);

	search_icon = LoadTexture("../External/source/Image/magnifyingGlass.png");
}

void System::Draw() {	

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground({ 255, 238, 226, 0 });

			DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);

			reset.DrawText();
			history.DrawText();
			favourite.DrawText();
			game.DrawText();
			addnew.DrawText();
			searchBox.Draw();
			DrawTextureEx(search_icon, { (float)0.071 * windowWidth, (float)0.184 * windowHeight }, 0, 0.2, WHITE);
			DrawRectangleLines(0.062 * windowWidth, 0.176 * windowHeight, 0.645 * windowWidth, 0.107 * windowHeight, BLACK);

		EndDrawing();
	}

	CloseWindow();
}