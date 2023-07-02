#include "System.h"
#include "UI/Other.h"

void System::Construct() {
	windowWidth = 1460;
	windowHeight = 850;
	InitWindow(windowWidth, windowHeight, "Dictionary - CS163 Project (>'-'<)");

	Parable_Regular = LoadFont("../External/source/Font/Parable-Regular.ttf");

	reset.SetBox(0.062 * windowWidth, 0.051 * windowHeight, 0.129 * windowWidth, 0.078 * windowHeight, defaultColor, touchedColor, clickedColor);
	reset.SetText(Parable_Regular, "Reset", GetCenterPos(Parable_Regular, "Reset", 40, 0.5, reset.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	
	back = reset;
	back.SetText(Parable_Regular, "Back", GetCenterPos(Parable_Regular, "Back", 40, 0.5, back.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);

	history.SetBox(0.055 * windowWidth, 0.438 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	history.SetText(Parable_Regular, "History", GetCenterPos(Parable_Regular, "History", 40, 0.5, history.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	
	favourite.SetBox(0.055 * windowWidth, 0.6 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	favourite.SetText(Parable_Regular, "Favourite", GetCenterPos(Parable_Regular, "Favourite", 40, 0.5, favourite.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);

	game.SetBox(0.055 * windowWidth, 0.762 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	game.SetText(Parable_Regular, "Game", GetCenterPos(Parable_Regular, "Game", 40, 0.5, game.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);

	addnew.SetBox(0.764 * windowWidth, 0.196 * windowHeight, 0.19 * windowWidth, 0.078 * windowHeight, defaultColor, touchedColor, clickedColor);
	addnew.SetText(Parable_Regular, "Add New", GetCenterPos(Parable_Regular, "Add New", 40, 0.5, addnew.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);

	changeTranslation.SetBox(0.708 * windowWidth, 0.051 * windowHeight, 0.247 * windowWidth, 0.078 * windowHeight, defaultColor, touchedColor, clickedColor);

	searchBox.Construct(0.062 * windowWidth, 0.176 * windowHeight, 0.645 * windowWidth, 0.107 * windowHeight, Parable_Regular, { (float)0.14 * windowWidth, (float)0.201 * windowHeight }, 40, 1, 45);
	searchBox.SetColorBox({ 255, 255, 255, 120 }, { 255, 255, 255, 80 }, { 255, 255, 255, 160 });

	search_icon = LoadTexture("../External/source/Image/magnifyingGlass.png");
	arrow_icon = LoadTexture("../External/source/Image/arrowDown.png");
}

void System::Draw() {	

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground({ 255, 238, 226, 0 });

			DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
			DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);

			searchBox.Draw();
			if (searchBox.isTyping == false && searchBox.currentInput.empty()) {
				DrawTextEx(Parable_Regular, "search bar", { (float)0.14 * windowWidth, (float)0.201 * windowHeight }, 40, 0.5, { 0, 0, 0, 170 });
			}

			DrawTextureEx(search_icon, { (float)0.071 * windowWidth, (float)0.184 * windowHeight }, 0, 0.2, WHITE);
			DrawRectangleLines(0.062 * windowWidth, 0.176 * windowHeight, 0.645 * windowWidth, 0.107 * windowHeight, BLACK);
			
			if (!isDropdownChangeTranslation) addnew.DrawText();
			DrawChangeTranslation();

			switch (menu)
			{
			default:
				DrawDefault();
				break;
			case HISTORY:
				DrawHistory();
				break;
			case FAVOURITE:
				break;
			case GAME:
				break;
			}

		EndDrawing();
	}

	CloseWindow();
}

void System::DrawDefault() {
	reset.DrawText();
	history.DrawText();
	favourite.DrawText();
	game.DrawText();

	if (history.state == RELEASED) {
		menu = HISTORY;
	}
}

void System::DrawHistory() {

	back.DrawText();

	if (back.state == RELEASED) {
		menu = DEFAULT;
	}
}

void System::DrawFavourite() {

	back.DrawText();

	if (back.state == RELEASED) {
		menu = DEFAULT;
	}
}

void System::DrawGame() {

	back.DrawText();

	if (back.state == RELEASED) {
		menu = DEFAULT;
	}
}

void System::DrawAddNew() {


}

void System::DrawChangeTranslation() {
	static int index = 0;
	static float szY = 0;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (CheckCollisionPointRec(GetMousePosition(), changeTranslation.buttonShape)) isDropdownChangeTranslation ^= true;
		//else isDropdownChangeTranslation = false;
		if (!isDropdownChangeTranslation) szY = 0;
	}
	
	float y = GetCenterPos(Parable_Regular, translation[index], 40, 1, changeTranslation.buttonShape).y;
	changeTranslation.SetText(Parable_Regular, translation[index], { (float)0.758 * windowWidth, y}, 40, 1, BLACK, BLACK, BLACK);
	changeTranslation.DrawText();
	DrawTextureEx(arrow_icon, { (float)0.901 * windowWidth, y }, 0, 0.15, WHITE);

	if (isDropdownChangeTranslation) {
		szY += 0.005 * windowHeight;
		if (szY > changeTranslation.buttonShape.height) szY = changeTranslation.buttonShape.height;
		Button temp = changeTranslation;
		temp.buttonShape.y += temp.buttonShape.height;
		temp.buttonShape.height = szY;
		for (int i = 0; i < 5; ++i) {
			if (i == index) continue;
			temp.SetText(Parable_Regular, translation[i], GetCenterPos(Parable_Regular, translation[i], 40, 1, temp.buttonShape), 40, 1, BLACK, BLACK, BLACK);
			if (szY == changeTranslation.buttonShape.height) {// button is clicked
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), temp.buttonShape)) {
					index = i;
					isDropdownChangeTranslation = false;
					szY = 0;
				}
			}
			temp.DrawText();
			temp.buttonShape.y += temp.buttonShape.height;
		}
	}
}