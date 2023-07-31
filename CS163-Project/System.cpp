#include "System.h"
#include "UI/Other.h"

Dictionary dictionary;

void System::Construct() {
	dictionary.buildFromOrigin();

	windowWidth = 1460;
	windowHeight = 850;
	InitWindow(windowWidth, windowHeight, "Dictionary - CS163 Project (>'-'<)");

	Parable_Regular = LoadFontEx("../External/source/Font/Parable-Regular.ttf", 96, 0, 0);
	Raleway_Black = LoadFontEx("../External/source/Font/Raleway-Black.ttf", 40, 0, 0);
	Raleway_BlackBig = LoadFontEx("../External/source/Font/Raleway-Black.ttf", 72, 0, 0);
	Raleway_Bold = LoadFontEx("../External/source/Font/Raleway-Bold.ttf", 40, 0, 0);
	Raleway_Italic = LoadFontEx("../External/source/Font/Raleway-Italic.ttf", 40, 0, 0);

	modeDef.SetBox(0.81 * windowWidth, 0.101 * windowHeight, 0.129 * windowWidth, 0.059 * windowHeight, defaultColor, touchedColor, clickedColor);
	modeDef.SetText(Raleway_Black, "Definition", GetCenterPos(Raleway_Black, "Definition", 30, 0.5, modeDef.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);
	modeKey = modeDef;
	modeKey.SetText(Raleway_Black, "Keyword", GetCenterPos(Raleway_Black, "Keyword", 30, 0.5, modeKey.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);

	reset.SetBox(0.673 * windowWidth, 0.399 * windowHeight, 0.099 * windowWidth, 0.066 * windowHeight, defaultColor, touchedColor, clickedColor);
	reset.SetText(Raleway_Black, "Reset", GetCenterPos(Raleway_Black, "Reset", 30, 0.5, reset.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);
	reset.roundness = 0.65;

	back = reset;
	back.SetText(Raleway_Black, "Back", GetCenterPos(Raleway_Black, "Back", 30, 0.5, back.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);

	history.SetBox(0.055 * windowWidth, 0.438 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	history.SetText(Raleway_Black, "History", GetCenterPos(Raleway_Black, "History", 40, 0.5, history.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	history.roundness = 0.65;

	favourite.SetBox(0.055 * windowWidth, 0.6 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	favourite.SetText(Raleway_Black, "Favourite", GetCenterPos(Raleway_Black, "Favourite", 40, 0.5, favourite.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	favourite.roundness = 0.65;

	game.SetBox(0.055 * windowWidth, 0.762 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	game.SetText(Raleway_Black, "Game", GetCenterPos(Raleway_Black, "Game", 40, 0.5, game.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	game.roundness = 0.65;

	addnew.SetBox(0.795 * windowWidth, 0.399 * windowHeight, 0.144 * windowWidth, 0.066 * windowHeight, defaultColor, touchedColor, clickedColor);
	addnew.SetText(Raleway_Black, "     Add New", GetCenterPos(Raleway_Black, "     Add New", 30, 0.5, addnew.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);
	addnew.roundness = 0.65;

	changeTranslation.SetBox(0.061 * windowWidth, 0.185 * windowHeight, 0.233 * windowWidth, 0.094 * windowHeight, defaultColor, touchedColor, clickedColor);

	mainpage.SetBox(0.743 * windowWidth, 0.835 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	mainpage.SetText(Raleway_Black, "Main Page", GetCenterPos(Raleway_Black, "Main Page", 40, 0.5, mainpage.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	mainpage.roundness = 0.65;

	searchBox.Construct(0.294 * windowWidth, 0.185 * windowHeight, 0.645 * windowWidth, 0.094 * windowHeight, Parable_Regular, { (float)0.312 * windowWidth, (float)0.2071 * windowHeight }, 40, 1, 300);
	searchBox.SetColorBox({ 255, 255, 255, 120 }, { 255, 255, 255, 80 }, { 255, 255, 255, 160 });
	searchBox.lengthText -= 0.06 * windowWidth;

	modifyDefBox.Construct(0.303 * windowWidth, 0.626 * windowHeight, 0.636 * windowWidth, 0.12 * windowHeight, Raleway_Italic, { (float)0.323 * windowWidth, (float)0.658 * windowHeight }, 40, 1, 300);
	modifyDefBox.SetColorBox({ 203, 241, 245, 120 }, { 203, 241, 245, 80 }, { 203, 241, 245, 160 });
	modifyDefBox.roundness = 0.28;
	modifyKeyBox.Construct(0.303 * windowWidth, 0.416 * windowHeight, 0.636 * windowWidth, 0.12 * windowHeight, Raleway_Bold, { (float)0.323 * windowWidth, (float)0.448 * windowHeight }, 40, 1, 300);
	modifyKeyBox.SetColorBox({ 203, 241, 245, 120 }, { 203, 241, 245, 80 }, { 203, 241, 245, 160 });
	modifyKeyBox.roundness = 0.28;

	ok.SetBox(0.886 * windowWidth, 0.195 * windowHeight, 0.042 * windowWidth, 0.072 * windowHeight, defaultColor, touchedColor, clickedColor);
	ok.roundness = 1.5;
	
	enter.SetBox(0.5 * windowWidth, 0.835 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	enter.SetText(Raleway_Black, "Enter", GetCenterPos(Raleway_Black, "Enter", 40, 0.5, enter.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	enter.roundness = 0.65;

	search_icon = LoadTexture("../External/source/Image/magnifyingGlass.png");
	arrow_icon = LoadTexture("../External/source/Image/arrowDown.png");
	dictionary_icon = LoadTexture("../External/source/Image/dictionary.png");
	add_icon = LoadTexture("../External/source/Image/add-icon.png");
	zoom_icon = LoadTexture("../External/source/Image/magnifyingGlass2.png");
	edit_icon = LoadTexture("../External/source/Image/edit-icon.png");
	filledHeart_icon = LoadTexture("../External/source/Image/filled-heart.png");
	hollowedHeart_icon = LoadTexture("../External/source/Image/heart - Copy.png");
	reload_icon = LoadTexture("../External/source/Image/reload-icon.png");
}

void System::Draw() {	

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground({ 236, 249, 255, 0 });

			switch (menu)
			{
			default:
				DrawDefault();
				break;
			case HISTORY:
				DrawHistory();
				break;
			case FAVOURITE:
				DrawFavourite();
				break;
			case GAME:
				DrawGame();
				break;
			case MODIFY:
				DrawModify();
				break;
			case SEARCH_RESULT:
				DrawSearchResult();
				break;
			}

		EndDrawing();
	}

	CloseWindow();
}

void System::DrawDefault() {
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.262 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);
	// draw addnew button
	addnew.DrawText();
	DrawTextureEx(add_icon, { addnew.coordText.x - (float)0.003 * windowWidth, addnew.coordText.y }, 0, 0.05, WHITE);
	// draw reset, history, favourite, game button
	reset.DrawText();
	history.DrawText();
	favourite.DrawText();
	game.DrawText();
	// draw random word
	DrawRandomWord();

	// draw mode button
	if (mode) modeDef.DrawText();
	else modeKey.DrawText();
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	// draw seach bar
	DrawSearchBar();

	if (history.state == RELEASED) {
		menu = HISTORY;
	}
	if (favourite.state == RELEASED) {
		menu = FAVOURITE;
	}
	if (game.state == RELEASED) {
		menu = GAME;
	}
	if (addnew.state == RELEASED) {
		menu = MODIFY;
		isAddNewWord = true;
	}
}

void System::DrawHistory() {
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.262 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);
	DrawTextEx(Raleway_BlackBig, "History", { (float)0.083 * windowWidth, (float)0.422 * windowHeight }, 72, 0.5, BLACK);

	mainpage.buttonShape.x = 0.061 * windowWidth;
	mainpage.buttonShape.y = 0.568 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);
	mainpage.DrawText();

	// draw mode button
	if (mode) modeDef.DrawText();
	else modeKey.DrawText();
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	// draw seach bar
	DrawSearchBar();

	if (mainpage.state == RELEASED) {
		menu = DEFAULT;
	}
}

void System::DrawFavourite() {
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.262 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);
	DrawTextEx(Raleway_BlackBig, "Favourite", { (float)0.061 * windowWidth, (float)0.422 * windowHeight }, 72, 0.5, BLACK);

	mainpage.buttonShape.x = 0.061 * windowWidth;
	mainpage.buttonShape.y = 0.568 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);
	mainpage.DrawText();

	// draw mode button
	if (mode) modeDef.DrawText();
	else modeKey.DrawText();
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	// draw seach bar
	DrawSearchBar();

	if (mainpage.state == RELEASED) {
		menu = DEFAULT;
	}
}

void System::DrawGame() {
	// draw Game 
	DrawTextEx(Parable_Regular, "Game", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	mainpage.buttonShape.x = 0.039 * windowWidth;
	mainpage.buttonShape.y = 0.071 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);
	mainpage.DrawText();

	// draw mode button
	if (mode) modeDef.DrawText();
	else modeKey.DrawText();
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	if (mainpage.state == RELEASED) {
		menu = DEFAULT;
	}
}

void System::DrawModify() {
	static bool dialog = false;
	static float timeline = 0;
	if (timeline <= 10) timeline += GetFrameTime();
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.262 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawTextEx(Raleway_Black, "keyword", { (float)0.061 * windowWidth, (float)0.448 * windowHeight }, 48, 1, BLACK);
	DrawTextEx(Raleway_Black, "definition", { (float)0.061 * windowWidth, (float)0.653 * windowHeight }, 48, 1, BLACK);

	mainpage.buttonShape.x = 0.743 * windowWidth;
	mainpage.buttonShape.y = 0.835 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);

	// draw keyword input box
	modifyKeyBox.Draw();
	// draw definition input box
	modifyDefBox.Draw();
	
	// draw enter button
	enter.DrawText();
	if (enter.state == RELEASED) {
		if (isAddNewWord) {
			if (dictionary.addNewWord(dicNum + 1, modifyKeyBox.getInput(), modifyDefBox.getInput())) {
				dialog = true;
				timeline = 0;
			}
		} 
		//else {
		//	if (dictionary.editDefinition(dicNum + 1, modifyKeyBox.getInput(), modifyDefBox.getInput(), modifyDefBox.getInput())) {
		//		dialog = true;
		//		timeline = 0;
		//	}
		//}
	}
	// draw dialog successfully adding new word in middle of screen
	if (dialog) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && timeline >= 2) {
			dialog = false;
			timeline = 0;
		}
		DrawRectangle(0, 0, windowWidth, windowHeight, Fade(BLACK, 0.5));
		DrawTextEx(Raleway_BlackBig, "Successfully!", { (float)0.35 * windowWidth, (float)0.5 * windowHeight }, 68, 0.7, { 50, 205, 50, 255 });
	}
	// draw seach bar
	DrawSearchBar();

	// draw mode button
	if (mode) modeDef.DrawText();
	else modeKey.DrawText();
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	mainpage.DrawText();
	if (mainpage.state == RELEASED) {
		menu = DEFAULT;
	}
	if (menu != MODIFY) {
		modifyKeyBox.currentInput = "";
		modifyDefBox.currentInput = "";
		dialog = false;
	}
}

void System::DrawChangeTranslation() {
	static float szY = 0;
	static int rotation = 90;

	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		if (CheckCollisionPointRec(GetMousePosition(), changeTranslation.buttonShape)) isDropdownChangeTranslation ^= true;
		//else isDropdownChangeTranslation = false;
	}
	
	// Draw box
	Vector2 pos = GetCenterPos(Raleway_Bold, translation[dicNum], 40, 1, changeTranslation.buttonShape);
	changeTranslation.SetText(Raleway_Bold, translation[dicNum], pos, 40, 1, BLACK, BLACK, BLACK);
	changeTranslation.DrawText();

	// Draw arrow
	if (isDropdownChangeTranslation) rotation -= 10;
	else rotation += 10;
	if (rotation > 135) rotation = 135;
	if (rotation < 0) rotation = 0;
	float scale = 0.13;
	Vector2 origin = { (float)arrow_icon.width * scale / 2, (float)arrow_icon.height * scale / 2 };
	Rectangle src = { 0, 0, arrow_icon.width, arrow_icon.height };
	Rectangle dst = { changeTranslation.buttonShape.x + (float)0.013 * windowWidth + (float)arrow_icon.width * scale / 2, pos.y - (float)0.003 * windowHeight + (float)arrow_icon.height * scale / 2, (float)arrow_icon.width * scale, (float)arrow_icon.height * scale};
	DrawTexturePro(arrow_icon, src, dst, origin, rotation, { 63, 201, 250, 170 });

	// Draw dropdown
	szY += 0.005 * windowHeight * (isDropdownChangeTranslation ? 1.5 : -2.5);
	if (szY > changeTranslation.buttonShape.height) szY = changeTranslation.buttonShape.height;
	if (szY < 0) szY = 0;

	if (szY > 0) {
		Button temp = changeTranslation;
		temp.drawCorner = false;
		temp.buttonShape.y += temp.buttonShape.height;
		temp.buttonShape.height = szY;
		temp.colorBoxDefault = { 227, 253, 253, 255 };
		for (int i = 0; i < 5; ++i) {
			if (i == dicNum) continue;
			temp.SetText(Raleway_Bold, translation[i], GetCenterPos(Raleway_Bold, translation[i], 40, 1, temp.buttonShape), 40, 1, BLACK, BLACK, BLACK);
			if (szY == changeTranslation.buttonShape.height) {// button is clicked
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), temp.buttonShape)) {
					dicNum = i;
					isDropdownChangeTranslation = false;
				}
			}
			temp.DrawText();
			temp.buttonShape.y += temp.buttonShape.height;
		}
		temp.buttonShape.height = temp.buttonShape.y - changeTranslation.buttonShape.y - changeTranslation.buttonShape.height;
		temp.buttonShape.y = changeTranslation.buttonShape.y + changeTranslation.buttonShape.height;
		DrawRectangleLinesEx(temp.buttonShape, 2, defaultColor);
	}
}

void System::DrawRandomWord() {
	Rectangle BoxContent = { (float)0.345 * windowWidth, (float)0.5 * windowHeight, (float)0.594 * windowWidth, (float)0.366 * windowHeight };
	DrawRectangleRounded(BoxContent, 0.25, 10, { 203, 241, 245, 255 });

	Button Heart; 
	Heart.SetBox(0.825 * windowWidth, 0.515 * windowHeight, filledHeart_icon.width * 0.085, filledHeart_icon.height * 0.085, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
	Heart.DrawText();
	DrawTextureEx(filledHeart_icon, { (float)0.825 * windowWidth, (float)0.515 * windowHeight }, 0, 0.085, WHITE);
	
	Button edit;
	edit.SetBox(0.868 * windowWidth, 0.515 * windowHeight, edit_icon.width * 0.075, edit_icon.height * 0.075, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
	edit.DrawText();
	DrawTextureEx(edit_icon, { (float)0.868 * windowWidth, (float)0.515 * windowHeight }, 0, 0.075, edit.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
	
	Button reload;
	reload.SetBox(0.9043 * windowWidth, 0.515 * windowHeight, reload_icon.width * 0.085, reload_icon.height * 0.085, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
	reload.DrawText();
	DrawTextureEx(reload_icon, { (float)0.9043 * windowWidth, (float)0.515 * windowHeight }, 0, 0.085, reload.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
}

void System::DrawSearchBar() {
	static bool isDropdown = false;
	static int timeline = 0;
	timeline += 1;
	if (timeline > 30) timeline = 0;
	// draw change translation button
	DrawChangeTranslation();
	// draw seach bar
	searchBox.Draw();
	if (searchBox.isTyping == false && searchBox.currentInput.empty()) {
		DrawTextEx(Parable_Regular, "search bar", { (float)0.312 * windowWidth, (float)0.207 * windowHeight }, 40, 0.5, { 0, 0, 0, 170 });
	}
	// draw magnifying glass button
	ok.DrawText();
	DrawTextureEx(zoom_icon, { (float)0.893 * windowWidth, (float)0.207 * windowHeight }, 0, 0.11, WHITE);
	// check if dropdown
	Rectangle dropdownBox = { searchBox.inputShape.x, searchBox.inputShape.y + searchBox.inputShape.height, searchBox.inputShape.width, searchBox.inputShape.height * suggestions.size() };
	if (CheckCollisionPointRec(GetMousePosition(), dropdownBox) == false && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		isDropdown = false;
		timeline = 0;
	}
	isDropdown |= (searchBox.isTyping && searchBox.currentInput.empty() == false);
	// draw suggestions
	static Button suggestion[6];
	if (isDropdown) {// search by keyword
		if (timeline == 30) suggestions = dictionary.predictKeyword(searchBox.getInput(), dicNum + 1);// dicNum + 1 because dicNum begin from 0
		for (int i = 0; i < suggestions.size(); ++i) {
			suggestion[i].SetBox(searchBox.inputShape.x, searchBox.inputShape.y + (i + 1) * searchBox.inputShape.height, searchBox.inputShape.width, searchBox.inputShape.height, { 227, 253, 253, 253 }, { 238, 253, 253, 245 }, { 204, 227, 227, 255 });
			suggestion[i].SetText(Parable_Regular, suggestions[i], { (float)0.35 * windowWidth ,GetCenterPos(Parable_Regular, suggestions[i], 40, 1, suggestion[i].buttonShape).y }, 40, 1, { 178, 178, 178, 255 }, { 178, 178, 178, 255 }, { 178, 178, 178, 255 });
			suggestion[i].DrawText();
			DrawTextureEx(search_icon, { searchBox.inputShape.x + (float)0.01 * windowWidth, searchBox.inputShape.y + (i + 1) * searchBox.inputShape.height + (float)0.01 * windowHeight }, 0, 0.16, WHITE);
			if (suggestion[i].state == RELEASED) {
				searchBox.currentInput = suggestions[i];
				searchBox.posCursor = searchBox.currentInput.size();
				isDropdown = false;
				search_result = dictionary.searchKeyword(searchBox.getInput(), dicNum + 1);
				menu = SEARCH_RESULT;
				searchBox.isTyping = false;
				isDropdown = false;
			}
		}

	}

	// draw search result
	if (searchBox.isTyping && searchBox.currentInput.empty() == false) {
		if (IsKeyReleased(KEY_ENTER) || ok.state == RELEASED) {
			if (mode) {// mode == true -> search by definition, click modeDef or modeKey to change mode
				search_result = dictionary.searchDefinition(searchBox.getInput(), dicNum + 1);// dicNum + 1 because dicNum begin from 0
			} else {
				search_result = dictionary.searchKeyword(searchBox.getInput(), dicNum + 1);
			}
			if (search_result.empty()) {
				search_result.push_back("No result!");
			}
			menu = SEARCH_RESULT;
			searchBox.isTyping = false;
			isDropdown = false;
		}
	}
	if (searchBox.isTyping == false) timeline = 0;
}

void System::DrawSearchResult() {
	static float scrollY = 0;// scroll 
	static float height = 0;// height of the search result box
	scrollY += GetMouseWheelMove() * 30;
	if (0.55 * windowHeight + height + scrollY + 0.1 * windowHeight < windowHeight) scrollY = windowHeight - 0.55 * windowHeight - height - 0.1 * windowHeight;
	if (scrollY > 0) scrollY = 0;
	// draw mainpage button
	mainpage.SetBox(0.743 * windowWidth, 0.406 * windowHeight + scrollY, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	mainpage.SetText(Raleway_Black, "Main Page", GetCenterPos(Raleway_Black, "Main Page", 40, 1, mainpage.buttonShape), 40, 1, BLACK, BLACK, BLACK);
	if (mainpage.buttonShape.y + mainpage.buttonShape.height >= 0.342 * windowHeight) {
		mainpage.DrawText();
		if (mainpage.state == RELEASED) {
			menu = DEFAULT;
			scrollY = 0;
			height = 0;
		}
	}

	// draw search result
	// draw keyword
	DrawTextEx(Parable_Regular, search_result[0].c_str(), { (float)0.061 * windowWidth, (float)0.389 * windowHeight + scrollY }, 96, 1, BLACK);
	if (search_result.size() > 1) {
		// draw definition box
		Rectangle boxShape = { (float)0.061 * windowWidth, (float)0.55 * windowHeight + scrollY, (float)0.878 * windowWidth, (float)height };
		DrawRectangleRounded(boxShape, 0.25 - 0.00000013 * height * height, 10, {203, 241, 245, 255});
		boxShape.x += 0.013 * windowWidth;
		boxShape.width -= 0.023 * windowWidth;
		height = DrawTextOnBoxEx(boxShape, Raleway_Italic, search_result, { (float)0.09 * windowWidth, (float)0.61 * windowHeight + scrollY }, 40, 0.5, 0.04 * windowHeight, 0.055 * windowHeight, BLACK) - boxShape.y + 0.05 * windowHeight;

		Button Heart;
		Heart.SetBox(0.815 * windowWidth, boxShape.y + 0.01 * windowHeight, filledHeart_icon.width * 0.085, filledHeart_icon.height * 0.085, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		Heart.DrawText();
		DrawTextureEx(filledHeart_icon, { (float)0.815 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.085, WHITE);

		Button edit;
		edit.SetBox(0.858 * windowWidth, boxShape.y + 0.01 * windowHeight, edit_icon.width * 0.075, edit_icon.height * 0.075, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		edit.DrawText();
		DrawTextureEx(edit_icon, { (float)0.858 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.075, edit.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);

		Button reload;
		reload.SetBox(0.8943 * windowWidth, boxShape.y + 0.01 * windowHeight, reload_icon.width * 0.085, reload_icon.height * 0.085, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		reload.DrawText();
		DrawTextureEx(reload_icon, { (float)0.8943 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.085, reload.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
	}

	// draw title
	DrawRectangle(0, 0, windowWidth, 0.342 * windowHeight, { 236, 249, 255, 255 });
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.262 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);
	// draw search bar
	DrawSearchBar();
	// draw mode button
	if (mode) modeDef.DrawText();
	else modeKey.DrawText();
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;
}