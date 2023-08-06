#include "System.h"
#include "UI/Other.h"
#include <chrono>

Dictionary dictionary;

void System::Construct() {
	auto start = chrono::high_resolution_clock::now();
	dictionary.build();
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Time taken by loading data: " << duration.count() << " milliseconds" << endl;

	windowWidth = 1460;
	windowHeight = 850;
	InitWindow(windowWidth, windowHeight, "Dictionary - CS163 Project (>'-'<)");

	Parable_Regular = LoadFontEx("../External/source/Font/Parable-Regular.ttf", 96, 0, 0);
	Parable_Regular40 = LoadFontEx("../External/source/Font/Parable-Regular.ttf", 40, 0, 0);
	Raleway_Black = LoadFontEx("../External/source/Font/Raleway-Black.ttf", 40, 0, 0);
	Raleway_BlackBig = LoadFontEx("../External/source/Font/Raleway-Black.ttf", 72, 0, 0);
	Raleway_Bold = LoadFontEx("../External/source/Font/Raleway-Bold.ttf", 40, 0, 0);
	Raleway_Italic = LoadFontEx("../External/source/Font/Raleway-Italic.ttf", 40, 0, 0);
	RussoOne_Regular = LoadFontEx("../External/source/Font/RussoOne-Regular.ttf", 96, 0, 0);

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

	searchBox.Construct(0.294 * windowWidth, 0.185 * windowHeight, 0.645 * windowWidth, 0.094 * windowHeight, Parable_Regular40, { (float)0.312 * windowWidth, (float)0.2071 * windowHeight }, 40, 1, 300);
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
	remove_icon = LoadTexture("../External/source/Image/remove-icon.png");

	randWord = dictionary.randomAWord(dicNum + 1);
}

void System::Draw() {	

	SetTargetFPS(60);

	float timeline = 0;

	while (!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground({ 236, 249, 255, 255 });
			
			mouseCursor = MOUSE_CURSOR_DEFAULT;

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

			SetMouseCursor(mouseCursor);

		EndDrawing();
	}

	CloseWindow();
}

void System::DrawDefault() {
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.262 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);
	// draw addnew button
	addnew.DrawText(mouseCursor);
	DrawTextureEx(add_icon, { addnew.coordText.x - (float)0.003 * windowWidth, addnew.coordText.y }, 0, 0.05, WHITE);
	// draw reset, history, favourite, game button
	reset.DrawText(mouseCursor);
	history.DrawText(mouseCursor);
	favourite.DrawText(mouseCursor);
	game.DrawText(mouseCursor);
	if (isDropdownChangeTranslation) {
		history.state = DEFAULT;
		favourite.state = DEFAULT;
	}
	// draw random word
	DrawRandomWord();

	// draw mode button
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	// draw seach bar
	DrawSearchBar();

	if (history.state == RELEASED) {
		menu = HISTORY;
		historyWords = dictionary.viewHistory();
	}
	if (favourite.state == RELEASED) {
		menu = FAVOURITE;
		favourWords = dictionary.viewFavourite(dicNum + 1);
	}
	if (game.state == RELEASED) {
		if (!mode) dictionary.randomWord(dicNum + 1, randData);
		else dictionary.randomDef(dicNum + 1, randData);

		menu = GAME;
	}
	if (addnew.state == RELEASED) {
		menu = MODIFY;
		isAddNewWord = true;
	}
	if (searchBox.getState() == TOUCHED) {
		mouseCursor = MOUSE_CURSOR_IBEAM;
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
	mainpage.DrawText(mouseCursor);

	// draw mode button
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	// draw seach bar
	DrawSearchBar();

	if (mainpage.state == RELEASED) {
		menu = DEFAULT;
		isFavour = dictionary.isFavourite(randWord[0]);
	}

	// draw list of history word
	float coordX[2] = { 0.32 * windowWidth, 0.64 * windowWidth };
	float coordY = 0.422 * windowHeight;
	static Button historyButton[100];
	static Button heartButton[100];
	static Button editButton[100];
	float gap = 0.155 * windowHeight;
	float szY = 0.127 * windowHeight;
	static float scrollY = 0;
	scrollY += GetMouseWheelMove() * 0.08 * windowHeight;
	if (scrollY + coordY + gap * (historyWords.size() + 1) / 2 < 0.99 * windowHeight)
		scrollY = 0.99 * windowHeight - coordY - gap * (historyWords.size() + 1) / 2;
	if (scrollY > 0) scrollY = 0;
	for (int i = 0; i < historyWords.size(); ++i) {
		historyButton[i].SetBox(coordX[i & 1], coordY + gap * (i / 2) + scrollY, 0.309 * windowWidth, szY, { 203, 241, 245, 255 }, { 203, 241, 245, 255 }, { 203, 241, 255, 255 });
		historyButton[i].SetText(RussoOne_Regular, historyWords[i], { coordX[i & 1] + (float)0.02 * windowWidth, coordY + (float)gap * (i / 2) + (float)0.03 * windowHeight + scrollY }, 40, 0.7, BLACK, BLACK, BLACK);
		historyButton[i].roundness = 0.65;
		historyButton[i].DrawText(mouseCursor);
		heartButton[i].SetBox(coordX[i & 1] + (float)0.268 * windowWidth, coordY + gap * (i / 2) + (float)0.012 * windowHeight + scrollY, hollowedHeart_icon.width * 0.085, hollowedHeart_icon.height * 0.085 - (float)0.01 * windowHeight, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		heartButton[i].DrawText(mouseCursor);
		editButton[i].SetBox(coordX[i & 1] + (float)0.271 * windowWidth, coordY + gap * (i / 2) + (float)0.072 * windowHeight + scrollY, hollowedHeart_icon.width * 0.085, hollowedHeart_icon.height * 0.085 - (float)0.01 * windowHeight, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		editButton[i].DrawText(mouseCursor);
		if (heartButton[i].state == DEFAULT && editButton[i].state == DEFAULT && historyButton[i].state == RELEASED) {
			menu = SEARCH_RESULT;
			search_result = dictionary.searchKeyword(historyWords[i], dicNum + 1);
		}
		if (heartButton[i].state == RELEASED) {
			dictionary.removeAFavourite(dicNum + 1, favourWords[i]);
			favourWords = dictionary.viewFavourite(dicNum + 1);
		}
		DrawTextureEx(filledHeart_icon, { coordX[i & 1] + (float)0.268 * windowWidth, coordY + (float)gap * (i / 2) + (float)0.01 * windowHeight + scrollY }, 0, 0.085, (heartButton[i].state == CLICKED ? Fade(WHITE, 0.4) : WHITE));
		DrawTextureEx(edit_icon, { coordX[i & 1] + (float)0.272 * windowWidth, coordY + (float)gap * (i / 2) + (float)0.06 * windowHeight + scrollY }, 0, 0.085, (editButton[i].state == CLICKED ? Fade(WHITE, 0.4) : WHITE));
	}

	if (searchBox.getState() == TOUCHED) {
		mouseCursor = MOUSE_CURSOR_IBEAM;
	}
}

void System::DrawFavourite() {
	// draw list of favourite word
	float coordX[2] = { 0.32 * windowWidth, 0.64 * windowWidth  };
	float coordY = 0.422 * windowHeight;
	static Button favourButton[100];
	static Button heartButton[100];
	static Button editButton[100];
	float gap = 0.155 * windowHeight;
	float szY = 0.127 * windowHeight;
	static float scrollY = 0;
	scrollY += GetMouseWheelMove() * 0.08 * windowHeight;
	if (scrollY + coordY + gap * (favourWords.size() + 1) / 2 < 0.99 * windowHeight)
		scrollY = 0.99 * windowHeight - coordY - gap * (favourWords.size() + 1) / 2;
	if (scrollY > 0) scrollY = 0;
	for (int i = 0; i < favourWords.size(); ++i) {
		favourButton[i].SetBox(coordX[i & 1], coordY + gap * (i/2) + scrollY, 0.309 * windowWidth, szY, { 203, 241, 245, 255 }, { 203, 241, 245, 255 }, { 203, 241, 255, 255 });
		favourButton[i].SetText(RussoOne_Regular, favourWords[i], { coordX[i & 1] + (float)0.02 * windowWidth, coordY + (float)gap * (i/2) + (float)0.03 * windowHeight + scrollY }, 40, 0.7, BLACK, BLACK, BLACK);
		favourButton[i].roundness = 0.65;
		favourButton[i].DrawText(mouseCursor);
		heartButton[i].SetBox(coordX[i & 1] + (float)0.268 * windowWidth, coordY + gap * (i / 2) + (float)0.012 * windowHeight + scrollY, hollowedHeart_icon.width * 0.085, hollowedHeart_icon.height * 0.085 - (float)0.01 * windowHeight, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		heartButton[i].DrawText(mouseCursor);
		editButton[i].SetBox(coordX[i & 1] + (float)0.271 * windowWidth, coordY + gap * (i / 2) + (float)0.072 * windowHeight + scrollY, hollowedHeart_icon.width * 0.085, hollowedHeart_icon.height * 0.085 - (float)0.01 * windowHeight, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		editButton[i].DrawText(mouseCursor);
		if (heartButton[i].state == DEFAULT && editButton[i].state == DEFAULT && favourButton[i].state == RELEASED) {
			menu = SEARCH_RESULT;
			search_result = dictionary.searchKeyword(favourWords[i], dicNum + 1);
		}
		if (heartButton[i].state == RELEASED) {
			dictionary.removeAFavourite(dicNum + 1, favourWords[i]);
			favourWords = dictionary.viewFavourite(dicNum + 1);
		}
		DrawTextureEx(filledHeart_icon, { coordX[i & 1] + (float)0.268 * windowWidth, coordY + (float)gap * (i/2) + (float)0.01 * windowHeight + scrollY }, 0, 0.085, (heartButton[i].state == CLICKED ? Fade(WHITE, 0.4) : WHITE));
		DrawTextureEx(edit_icon, { coordX[i & 1] + (float)0.272 * windowWidth, coordY + (float)gap * (i/2) + (float)0.06 * windowHeight + scrollY }, 0, 0.085, (editButton[i].state == CLICKED ? Fade(WHITE, 0.4) : WHITE));
	}

	DrawRectangle(0, 0, windowWidth, 0.342 * windowHeight, { 236, 249, 255, 255 });
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.262 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);
	DrawTextEx(Raleway_BlackBig, "Favourite", { (float)0.061 * windowWidth, (float)0.422 * windowHeight }, 72, 0.5, BLACK);

	mainpage.buttonShape.x = 0.061 * windowWidth;
	mainpage.buttonShape.y = 0.568 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);
	mainpage.DrawText(mouseCursor);

	// draw mode button
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	// draw seach bar
	DrawSearchBar();

	if (mainpage.state == RELEASED) {
		menu = DEFAULT;
		isFavour = dictionary.isFavourite(randWord[0]);
	}

	if (searchBox.getState() == TOUCHED) {
		mouseCursor = MOUSE_CURSOR_IBEAM;
	}
}

void System::DrawGame() {
	static Button choiceButton[4];
	static bool isAnswered = false;
	static float timeline = 0;
	Rectangle choiceShape[4] = {
			{(float)0.027 * windowWidth, (float)0.541 * windowHeight, (float)0.445 * windowWidth, (float)0.176 * windowHeight},
			{(float)0.527 * windowWidth, (float)0.541 * windowHeight, (float)0.445 * windowWidth, (float)0.176 * windowHeight},
			{(float)0.027 * windowWidth, (float)0.776 * windowHeight, (float)0.445 * windowWidth, (float)0.176 * windowHeight},
			{(float)0.527 * windowWidth, (float)0.776 * windowHeight, (float)0.445 * windowWidth, (float)0.176 * windowHeight}
	};
	if (timeline <= 10) timeline += GetFrameTime();
	// draw Game 
	DrawTextEx(Parable_Regular, "Game", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	mainpage.buttonShape.x = 0.039 * windowWidth;
	mainpage.buttonShape.y = 0.071 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);
	mainpage.DrawText(mouseCursor);

	// draw mode button
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1, dictionary.randomDef(dicNum + 1, randData);
	else if (modeKey.getState() == RELEASED) mode ^= 1, dictionary.randomWord(dicNum + 1, randData);

	if (mainpage.state == RELEASED) {
		timeline = 0;
		isAnswered = false;
		menu = DEFAULT;
		isFavour = dictionary.isFavourite(randWord[0]);
	}

	// draw multiple choice
	//if (!mode) {// word given
		Rectangle wordShape = { (float)0.039 * windowWidth, (float)0.194 * windowHeight, (float)0.922 * windowWidth, (float)0.271 * windowHeight };
		DrawRectangleRoundedLines(wordShape, 0.1, 5, 2, { 113, 201, 206, 255});
		DrawTextEx(Raleway_Black, randData.second[0].c_str(), GetCenterPos(Raleway_Black, randData.second[0], 48, 1, wordShape), 48, 1, BLACK);
		for (int i = 0; i < 4; i++) {
			choiceButton[i].SetBox(choiceShape[i].x, choiceShape[i].y, choiceShape[i].width, choiceShape[i].height, {113, 201, 206, 0}, {113, 201, 206, 15}, {113, 201, 206, 30});
			choiceButton[i].roundness = 0.2;
			choiceButton[i].drawCorner = true;
			choiceButton[i].colorCornerDefault = choiceButton[i].colorCornerClicked = choiceButton[i].colorCornerTouched = {113, 201, 206, 255};
			if (isAnswered && randData.first == i + 1) {
				choiceButton[i].colorBoxDefault = choiceButton[i].colorBoxClicked = choiceButton[i].colorBoxTouched = { 0, 179, 0, 255 };
			}
			choiceButton[i].DrawText(mouseCursor);
			choiceShape[i].x += 0.01 * windowWidth;
			choiceShape[i].y += 0.005 * windowHeight;
			choiceShape[i].width -= 0.015 * windowWidth;
			choiceShape[i].height -= 0.007 * windowHeight;
			DrawCircle(choiceShape[i].x + 0.01 * windowHeight, choiceShape[i].y + 0.023 * windowHeight, 0.02 * windowHeight, { 203, 241, 245, 255 });
			DrawTextEx(Raleway_Bold, to_string(i + 1).c_str(), { choiceShape[i].x + (float)0.001 * windowHeight, choiceShape[i].y + (float)0.002 * windowHeight }, 30, 0.5, BLACK);
			DrawTextOnBox(choiceShape[i], Raleway_Italic, randData.second[i + 1], { choiceShape[i].x + (float)0.02 * windowWidth, choiceShape[i].y + (float)0.01 * windowHeight }, 30, 0.5, 0.03 * windowHeight, BLACK);
			if (!isAnswered && choiceButton[i].state == RELEASED) {
				if (randData.first == i + 1) {
					isAnswered = true;
					timeline = 0;
				}
			}
		}
	//}
	//else {// definition given
	//	Rectangle defShape = { (float)0.039 * windowWidth, (float)0.194 * windowHeight, (float)0.922 * windowWidth, (float)0.271 * windowHeight };
	//	DrawRectangleRoundedLines(defShape, 0.1, 5, 2, { 113, 201, 206, 255 });
	//	DrawTextEx(Raleway_Black, randData.second[0].c_str(), GetCenterPos(Raleway_Black, randData.second[0], 48, 1, defShape), 48, 1, BLACK);

	//}
	if (isAnswered) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && timeline >= 1) {
			isAnswered = false;
			timeline = 0;
			if (!mode) {
				dictionary.randomWord(dicNum + 1, randData);
			}
			else {
				dictionary.randomDef(dicNum + 1, randData);
			}
		}
		DrawRectangle(0, 0, windowWidth, windowHeight, Fade(BLACK, 0.5));
		DrawTextEx(Raleway_BlackBig, "Correctly!", { (float)0.39 * windowWidth, (float)0.45 * windowHeight }, 68, 0.7, { 50, 205, 50, 255 });
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
	enter.DrawText(mouseCursor);
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
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	mainpage.DrawText(mouseCursor);
	if (mainpage.state == RELEASED) {
		menu = DEFAULT;
		isFavour = dictionary.isFavourite(randWord[0]);
	}
	if (menu != MODIFY) {
		modifyKeyBox.currentInput = "";
		modifyKeyBox.posCursor = 0;
		modifyDefBox.currentInput = "";
		modifyDefBox.posCursor = 0;
		dialog = false;
	}
	if (searchBox.getState() == TOUCHED) {
		mouseCursor = MOUSE_CURSOR_IBEAM;
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
	changeTranslation.DrawText(mouseCursor);

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
			temp.DrawText(mouseCursor);
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

	static Button Heart; 
	Heart.SetBox(0.825 * windowWidth, 0.515 * windowHeight, filledHeart_icon.width * 0.085, filledHeart_icon.height * 0.085, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
	Heart.DrawText(mouseCursor);
	if (isFavour) {
		DrawTextureEx(filledHeart_icon, { (float)0.825 * windowWidth, (float)0.515 * windowHeight }, 0, 0.085, Heart.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
		if (Heart.state == RELEASED) {
			dictionary.removeAFavourite(dicNum + 1, randWord[0]);
			isFavour = false;
		}
	} else {
		DrawTextureEx(hollowedHeart_icon, { (float)0.825 * windowWidth, (float)0.515 * windowHeight }, 0, 0.085, Heart.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
		if (Heart.state == RELEASED) {
			dictionary.addFavourite(dicNum + 1, randWord[0]);
			isFavour = true;
		}
	}
	static Button edit;
	edit.SetBox(0.868 * windowWidth, 0.515 * windowHeight, edit_icon.width * 0.075, edit_icon.height * 0.075, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
	edit.DrawText(mouseCursor);
	DrawTextureEx(edit_icon, { (float)0.868 * windowWidth, (float)0.515 * windowHeight }, 0, 0.075, edit.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
	
	static Button reload;
	reload.SetBox(0.9043 * windowWidth, 0.515 * windowHeight, reload_icon.width * 0.085, reload_icon.height * 0.085, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
	reload.DrawText(mouseCursor);
	DrawTextureEx(reload_icon, { (float)0.9043 * windowWidth, (float)0.515 * windowHeight }, 0, 0.085, reload.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
	if (reload.state == RELEASED) {
		randWord = dictionary.randomAWord(dicNum + 1);
		isFavour = dictionary.isFavourite(randWord[0]);
	}

	static Button Word;
	Vector2 szWord = MeasureTextEx(Raleway_Bold, randWord[0].c_str(), 40, 1);
	Word.SetBox(0.364 * windowWidth, 0.534 * windowHeight, szWord.x, szWord.y, Fade(WHITE, 0), Fade(WHITE, 0.5), Fade(BLACK, 0.5));
	DrawTextEx(Raleway_Bold, randWord[0].c_str(), { (float)0.364 * windowWidth, (float)0.534 * windowHeight }, 40, 1, BLACK);
	Word.DrawText(mouseCursor);
	BoxContent.x += 0.016 * windowWidth;
	BoxContent.width -= 0.016 * windowWidth;
	DrawTextOnBoxEx(BoxContent, Raleway_Italic, randWord, { (float)0.364 * windowWidth, (float)0.59 * windowHeight }, 39, 0.7, 0.037 * windowHeight, 0.045 * windowHeight, BLACK);

	if (Word.state == RELEASED) {
		search_result = dictionary.searchKeyword(randWord[0], dicNum + 1);
		isFavour = dictionary.isFavourite(randWord[0]);
		menu = SEARCH_RESULT;
	}
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
		DrawTextEx(Parable_Regular40, "search bar", { (float)0.312 * windowWidth, (float)0.207 * windowHeight }, 40, 0.5, { 0, 0, 0, 170 });
	}
	// draw magnifying glass button
	ok.DrawText(mouseCursor);
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
	if (isDropdown && !mode) {// search by keyword
		if (timeline == 30) suggestions = dictionary.predictKeyword(searchBox.getInput(), dicNum + 1);// dicNum + 1 because dicNum begin from 0
		for (int i = 0; i < suggestions.size(); ++i) {
			suggestion[i].SetBox(searchBox.inputShape.x, searchBox.inputShape.y + (i + 1) * searchBox.inputShape.height, searchBox.inputShape.width, searchBox.inputShape.height, { 227, 253, 253, 253 }, { 238, 253, 253, 245 }, { 204, 227, 227, 255 });
			suggestion[i].SetText(Parable_Regular40, suggestions[i], { (float)0.35 * windowWidth ,GetCenterPos(Parable_Regular40, suggestions[i], 40, 1, suggestion[i].buttonShape).y }, 40, 1, { 178, 178, 178, 255 }, { 178, 178, 178, 255 }, { 178, 178, 178, 255 });
			suggestion[i].DrawText(mouseCursor);
			DrawTextureEx(search_icon, { searchBox.inputShape.x + (float)0.01 * windowWidth, searchBox.inputShape.y + (i + 1) * searchBox.inputShape.height + (float)0.01 * windowHeight }, 0, 0.16, WHITE);
			if (suggestion[i].state == RELEASED) {
				searchBox.currentInput = suggestions[i];
				searchBox.posCursor = searchBox.currentInput.size();
				isDropdown = false;
				search_result = dictionary.searchKeyword(searchBox.getInput(), dicNum + 1);
				isFavour = dictionary.isFavourite(searchBox.getInput());
				menu = SEARCH_RESULT;
				searchBox.isTyping = false;
				isDropdown = false;
				dictionary.addHistory(searchBox.getInput());
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
			else {
				isFavour = dictionary.isFavourite(search_result[0]);
				dictionary.addHistory(search_result[0]);
			}
			menu = SEARCH_RESULT;
			searchBox.isTyping = false;
			isDropdown = false;
		}
	}
	if (searchBox.isTyping == false) timeline = 0;
}

void System::DrawDialogBox() {
	DrawRectangle(0.32 * windowWidth, 0.422 * windowHeight, 0.36 * windowWidth, 0.176 * windowHeight, { 255, 255, 255, 230 });
	DrawRectangleLines(0.32 * windowWidth, 0.422 * windowHeight, 0.36 * windowWidth, 0.176 * windowHeight, BLACK);
	DrawTextEx(Parable_Regular40, "Do you want to continue?", { GetCenterPos(Parable_Regular40, "Do you want to continue?", 40, 0.5, 0.32 * windowWidth, 0.422 * windowHeight, 0.36 * windowWidth, 0.156 * windowHeight).x, (float)0.45 * windowHeight}, 40, 0.5, BLACK);
	yes.SetBox(0.35 * windowWidth, 0.52 * windowHeight, 0.1 * windowWidth, 0.05 * windowHeight, defaultColor, touchedColor, clickedColor);
	yes.SetText(Parable_Regular40, "Yes", GetCenterPos(Parable_Regular40, "Yes", 40, 1, yes.buttonShape), 40, 1, BLACK, BLACK, BLACK);
	yes.DrawText(mouseCursor);
	no.SetBox(0.55 * windowWidth, 0.52 * windowHeight, 0.1 * windowWidth, 0.05 * windowHeight, defaultColor, touchedColor, clickedColor);
	no.SetText(Parable_Regular40, "No", GetCenterPos(Parable_Regular40, "No", 40, 1, no.buttonShape), 40, 1, BLACK, BLACK, BLACK);
	no.DrawText(mouseCursor);
}

void System::DrawSearchResult() {
	static float scrollY = 0;// scroll 
	static float height = 0;// height of the search result box
	static bool dialog = false;
	scrollY += GetMouseWheelMove() * 30;
	if (0.55 * windowHeight + height + scrollY + 0.1 * windowHeight < windowHeight) scrollY = windowHeight - 0.55 * windowHeight - height - 0.1 * windowHeight;
	if (scrollY > 0) scrollY = 0;
	// draw mainpage button
	mainpage.SetBox(0.743 * windowWidth, 0.406 * windowHeight + scrollY, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	mainpage.SetText(Raleway_Black, "Main Page", GetCenterPos(Raleway_Black, "Main Page", 40, 1, mainpage.buttonShape), 40, 1, BLACK, BLACK, BLACK);
	if (mainpage.buttonShape.y + mainpage.buttonShape.height >= 0.342 * windowHeight) {
		mainpage.DrawText(mouseCursor);
		if (mainpage.state == RELEASED) {
			menu = DEFAULT;
			isFavour = dictionary.isFavourite(randWord[0]);
			scrollY = 0;
			height = 0;
		}
	}

	// draw search result
	// draw keyword
	DrawTextEx(RussoOne_Regular, search_result[0].c_str(), { (float)0.061 * windowWidth, (float)0.389 * windowHeight + scrollY }, 96, 1, BLACK);
	static Button Heart, edit, remove;
	if (search_result.size() > 1) {
		// draw definition box
		Rectangle boxShape = { (float)0.061 * windowWidth, (float)0.55 * windowHeight + scrollY, (float)0.878 * windowWidth, (float)height };
		DrawRectangleRounded(boxShape, 0.25 - 0.00000013 * height * height, 10, {203, 241, 245, 255});
		boxShape.x += 0.013 * windowWidth;
		boxShape.width -= 0.023 * windowWidth;
		height = DrawTextOnBoxEx(boxShape, Raleway_Italic, search_result, { (float)0.09 * windowWidth, (float)0.61 * windowHeight + scrollY }, 40, 0.5, 0.04 * windowHeight, 0.055 * windowHeight, BLACK) - boxShape.y + 0.05 * windowHeight;

		Heart.SetBox(0.815 * windowWidth, boxShape.y + 0.01 * windowHeight, filledHeart_icon.width * 0.085, filledHeart_icon.height * 0.085, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		Heart.DrawText(mouseCursor);
		if (isFavour) {
			DrawTextureEx(filledHeart_icon, { (float)0.815 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.085, Heart.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
			if (Heart.state == RELEASED) {
				dictionary.removeAFavourite(dicNum + 1, randWord[0]);
				isFavour = false;
			}
		}
		else {
			DrawTextureEx(hollowedHeart_icon, { (float)0.815 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.085, Heart.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
			if (Heart.state == RELEASED) {
				dictionary.addFavourite(dicNum + 1, randWord[0]);
				isFavour = true;
			}
		}
		edit.SetBox(0.858 * windowWidth, boxShape.y + 0.01 * windowHeight, edit_icon.width * 0.075, edit_icon.height * 0.075, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		edit.DrawText(mouseCursor);
		DrawTextureEx(edit_icon, { (float)0.858 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.075, edit.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);

		remove.SetBox(0.893 * windowWidth, boxShape.y + 0.01 * windowHeight, remove_icon.width * 0.08, remove_icon.height * 0.08, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		remove.DrawText(mouseCursor);
		DrawTextureEx(remove_icon, { (float)0.893 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.08, remove.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
		if (remove.state == RELEASED) {
			dialog = true;
		}
	}
	if (dialog) {
		DrawDialogBox();
		if (yes.state == RELEASED) {
			dictionary.removeAWord(dicNum + 1, search_result[0]);
			menu = DEFAULT;
			dialog = false;
		}
		if (no.state == RELEASED) {
			dialog = false;
		}
	}
	// draw title
	DrawRectangle(0, 0, windowWidth, 0.342 * windowHeight, { 236, 249, 255, 255 });
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.338 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.262 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);
	// draw search bar
	DrawSearchBar();
	// draw mode button
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	if (searchBox.getState() == TOUCHED) {
		mouseCursor = MOUSE_CURSOR_IBEAM;
	}
}