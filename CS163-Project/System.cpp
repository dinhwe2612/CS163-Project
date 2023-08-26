#include "System.h"
#include "UI/Other.h"
#include <chrono>

void System::Construct() {
	auto start = chrono::high_resolution_clock::now();
	dictionary.build();
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Time taken by loading data: " << duration.count() << " milliseconds" << endl;

	// Init window
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	windowWidth = 1460;
	windowHeight = 850;
	InitWindow(windowWidth, windowHeight, "Dictionary - CS163 Project (>'-'<)");
	Image window_icon = LoadImage("../External/source/Image/book.png");
	SetWindowIcon(window_icon);

	Parable_Regular = LoadFontEx("../External/source/Font/Parable-Regular.ttf", 96, 0, 0);
	Parable_Regular40 = LoadFontEx("../External/source/Font/Parable-Regular.ttf", 40, 0, 0);
	Raleway_Black = LoadFontEx("../External/source/Font/Raleway-Black.ttf", 40, 0, 0);
	Raleway_Black48 = LoadFontEx("../External/source/Font/Raleway-Black.ttf", 48, 0, 0);
	Raleway_BlackBig = LoadFontEx("../External/source/Font/Raleway-Black.ttf", 72, 0, 0);
	Raleway_Bold = LoadFontEx("../External/source/Font/Raleway-Bold.ttf", 40, 0, 0);
	Raleway_Bold48 = LoadFontEx("../External/source/Font/Raleway-Bold.ttf", 48, 0, 0);
	Raleway_Bold30 = LoadFontEx("../External/source/Font/Raleway-Bold.ttf", 30, 0, 0);
	Raleway_Italic = LoadFontEx("../External/source/Font/Raleway-Italic.ttf", 40, 0, 0);
	Raleway_Italic30 = LoadFontEx("../External/source/Font/Raleway-Italic.ttf", 30, 0, 0);
	Raleway_Italic48 = LoadFontEx("../External/source/Font/Raleway-Italic.ttf", 48, 0, 0);
	RussoOne_Regular = LoadFontEx("../External/source/Font/RussoOne-Regular.ttf", 96, 0, 0);
	Parable_Regular100 = LoadFontEx("../External/source/Font/Parable-Regular.ttf", 100, 0, 0);

	modeDef.SetBox(0.81 * windowWidth, 0.101 * windowHeight, 0.129 * windowWidth, 0.059 * windowHeight, defaultColor, touchedColor, clickedColor);
	modeDef.SetText(Raleway_Black, "Definition", GetCenterPos(Raleway_Black, "Definition", 30, 0.5, modeDef.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);
	modeKey = modeDef;
	modeKey.SetText(Raleway_Black, "Keyword", GetCenterPos(Raleway_Black, "Keyword", 30, 0.5, modeKey.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);
	modeKey.isZoom = true;

	reset.SetBox(0.673 * windowWidth, 0.399 * windowHeight, 0.099 * windowWidth, 0.066 * windowHeight, defaultColor, touchedColor, clickedColor);
	reset.SetText(Raleway_Black, "Reset", GetCenterPos(Raleway_Black, "Reset", 30, 0.5, reset.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);
	reset.roundness = 0.65;
	reset.isZoom = true;

	back = reset;
	back.SetText(Raleway_Black, "Back", GetCenterPos(Raleway_Black, "Back", 30, 0.5, back.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);
	back.isZoom = true;

	history.SetBox(0.055 * windowWidth, 0.438 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	history.SetText(Raleway_Black, "History", GetCenterPos(Raleway_Black, "History", 40, 0.5, history.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	history.roundness = 0.65;
	history.isZoom = true;

	favourite.SetBox(0.055 * windowWidth, 0.6 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	favourite.SetText(Raleway_Black, "Favourite", GetCenterPos(Raleway_Black, "Favourite", 40, 0.5, favourite.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	favourite.roundness = 0.65;
	favourite.isZoom = true;

	game.SetBox(0.055 * windowWidth, 0.762 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	game.SetText(Raleway_Black, "Game", GetCenterPos(Raleway_Black, "Game", 40, 0.5, game.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	game.roundness = 0.65;
	game.isZoom = true;

	addnew.SetBox(0.795 * windowWidth, 0.399 * windowHeight, 0.144 * windowWidth, 0.066 * windowHeight, defaultColor, touchedColor, clickedColor);
	addnew.SetText(Raleway_Black, "     Add New", GetCenterPos(Raleway_Black, "     Add New", 30, 0.5, addnew.buttonShape), 30, 0.5, BLACK, BLACK, BLACK);
	addnew.roundness = 0.65;
	addnew.isZoom = true;

	changeTranslation.SetBox(0.061 * windowWidth, 0.185 * windowHeight, 0.233 * windowWidth, 0.094 * windowHeight, defaultColor, touchedColor, clickedColor);

	mainpage.SetBox(0.743 * windowWidth, 0.835 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	mainpage.SetText(Raleway_Black, "Main Page", GetCenterPos(Raleway_Black, "Main Page", 40, 0.5, mainpage.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	mainpage.roundness = 0.65;
	mainpage.isZoom = true;

	searchBox.Construct(0.294 * windowWidth, 0.185 * windowHeight, 0.645 * windowWidth, 0.094 * windowHeight, Parable_Regular40, { (float)0.312 * windowWidth, (float)0.2071 * windowHeight }, 40, 1, 300);
	searchBox.SetColorBox({ 255, 255, 255, 120 }, { 255, 255, 255, 80 }, { 255, 255, 255, 160 });
	searchBox.lengthText -= 0.06 * windowWidth;

	//modifyDefBox.Construct(0.303 * windowWidth, 0.626 * windowHeight, 0.636 * windowWidth, 0.12 * windowHeight, Raleway_Italic, { (float)0.323 * windowWidth, (float)0.658 * windowHeight }, 40, 1, 300);
	//modifyDefBox.SetColorBox({ 203, 241, 245, 120 }, { 203, 241, 245, 80 }, { 203, 241, 245, 160 });
	//modifyDefBox.roundness = 0.28;
	
	modifyKeyBox.Construct(0.303 * windowWidth, 0.416 * windowHeight, 0.636 * windowWidth, 0.12 * windowHeight, Raleway_Bold, { (float)0.323 * windowWidth, (float)0.448 * windowHeight }, 40, 1, 300);
	modifyKeyBox.SetColorBox({ 203, 241, 245, 120 }, { 203, 241, 245, 80 }, { 203, 241, 245, 160 });
	
	ok.SetBox(0.886 * windowWidth, 0.195 * windowHeight, 0.042 * windowWidth, 0.072 * windowHeight, defaultColor, touchedColor, clickedColor);
	ok.roundness = 1.5;
	
	enter.roundness = 0.65;
	enter.isZoom = true;

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
	history_icon = LoadTexture("../External/source/Image/history-icon.png");
	reset_icon = LoadTexture("../External/source/Image/reset-icon.png");
	dinosaur_icon = LoadTexture("../External/source/Image/dinosaur-icon.png");
	rdinosaur_icon = LoadTexture("../External/source/Image/rdinosaur-icon.png");
	dinosaur2_icon = LoadTexture("../External/source/Image/dinosaur2-icon.png");
	dinosaur3_icon = LoadTexture("../External/source/Image/dinosaur3-icon.png");

	randWord = dictionary.randomAWord(dicNum + 1);
	historyWords = dictionary.viewHistory(dicNum + 1);
}

void System::Destruct() {
	dictionary.save();
	dictionary.clear();
	randData.second.clear();
	favourWords.clear();
	historyWords.clear();

	UnloadTexture(search_icon);
	UnloadTexture(arrow_icon);
	UnloadTexture(dictionary_icon);
	UnloadTexture(add_icon);
	UnloadTexture(zoom_icon);
	UnloadTexture(edit_icon);
	UnloadTexture(filledHeart_icon);
	UnloadTexture(hollowedHeart_icon);
	UnloadTexture(reload_icon);
	UnloadTexture(remove_icon);
	UnloadTexture(history_icon);
	UnloadTexture(reset_icon);
	UnloadTexture(dinosaur_icon);
	UnloadTexture(rdinosaur_icon);
	UnloadTexture(dinosaur2_icon);
	UnloadTexture(dinosaur3_icon);

	UnloadFont(Parable_Regular);
	UnloadFont(Parable_Regular100);
	UnloadFont(Parable_Regular40);
	UnloadFont(Raleway_Black);
	UnloadFont(Raleway_Black48);
	UnloadFont(Raleway_BlackBig);
	UnloadFont(Raleway_Bold);
	UnloadFont(Raleway_Bold30);
	UnloadFont(Raleway_Bold48);
	UnloadFont(Raleway_Italic);
	UnloadFont(Raleway_Italic30);
	UnloadFont(Raleway_Italic48);
	UnloadFont(RussoOne_Regular);
}

void System::Draw() {	

	SetTargetFPS(60);

	float timeline = 0;

	while (!WindowShouldClose()) {
		if (IsWindowResized() && !IsWindowFullscreen())
		{
			windowWidth = GetScreenWidth();
			windowHeight = GetScreenHeight();
		}

		// check for alt + enter
		if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
		{
			// see what display we are on right now
			int display = GetCurrentMonitor();


			if (IsWindowFullscreen())
			{
				// if we are full screen, then go back to the windowed size
				SetWindowSize(windowWidth, windowHeight);
			}
			else
			{
				// if we are not full screen, set the window size to match the monitor we are on
				SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
			}

			// toggle the state
			ToggleFullscreen();
		}

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
			case SEARCH_DEF_RESULT:
				DrawSearchDefResult();
				break;
			}
			SetMouseCursor(mouseCursor);

		EndDrawing();
	}

	CloseWindow();
}

void System::DrawTitle() {
	DrawTextEx(Parable_Regular, "Dictionary", { (float)0.398 * windowWidth, (float)0.023 * windowHeight }, 96, 0.5, BLACK);
	DrawTextureEx(dictionary_icon, { (float)0.322 * windowWidth, (float)0.023 * windowHeight }, 0, 0.2, Fade(WHITE, 0.8));
	DrawLine(0, 0.342 * windowHeight, windowWidth, 0.342 * windowHeight, BLACK);
}

void System::DrawDefault() {
	static bool isDialogOpen = false;
	DrawTitle();
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
	if (!isDialogOpen) {
		if (history.state == RELEASED) {
			menu = HISTORY;
			historyWords = dictionary.viewHistory(dicNum + 1);
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
		if (ok.state == DEFAULT && searchBox.getState() == TOUCHED) {
			mouseCursor = MOUSE_CURSOR_IBEAM;
		}
	}
	if (isDialogOpen) menu = DEFAULT;
	if (isDialogOpen) {
		DrawDialogBox();
		if (no.state == RELEASED) {
			isDialogOpen = false;
		}
		if (yes.state == RELEASED) {
			isDialogOpen = false;
			ResetDictionary();
		}
	}
	if (reset.state == RELEASED) {
		isDialogOpen = true;
		cout << "Reset dictionary?" << endl;
	}
}

void System::DrawReset(string content) {
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	DrawRectangle(0.294 * windowWidth, 0.37 * windowHeight, 0.412 * windowWidth, 0.3 * windowHeight, WHITE);
	DrawRectangle(0.294 * windowWidth, 0.37 * windowHeight, 0.412 * windowWidth, 0.05 * windowHeight, RAYWHITE);
	DrawRectangleLines(0.294 * windowWidth, 0.37 * windowHeight, 0.412 * windowWidth, 0.3 * windowHeight, Fade(BLACK, 0.7));
	DrawTextureEx(reset_icon, { (float)0.296 * windowWidth, (float)0.374 * windowHeight }, 0, 0.07, WHITE);
	DrawTextEx(Raleway_Italic, (content + "LOADING...").c_str(), GetCenterPos(Raleway_Italic, content + "LOADING..", 40, 0.5, 0.294 * windowWidth, 0.37 * windowHeight, 0.412 * windowWidth, 0.3 * windowHeight), 40, 0.5, BLACK);
	DrawTextEx(Raleway_Bold30, "Reset", GetCenterPos(Raleway_Bold30, "Reset", 30, 0.5, 0.294 * windowWidth, 0.37 * windowHeight, 0.412 * windowWidth, 0.05 * windowHeight), 30, 0.5, BLACK);
	EndDrawing();
}

void System::ResetDictionary() {
	DrawReset("0% ");
	dictionary.engEng.clear();
	dictionary.vieEng.clear();
	dictionary.engVie.clear();
	dictionary.slang.clear();
	dictionary.emotional.clear();
	DrawReset("5% ");
	dictionary.engEng_def.deleteDefinition();
	dictionary.vieEng_def.deleteDefinition();
	dictionary.engVie_def.deleteDefinition();
	dictionary.slang_def.deleteDefinition();
	dictionary.emotional_def.deleteDefinition();
	DrawReset("10% ");
	dictionary.engEng_key.deleteKeyword();
	DrawReset("25% ");
	dictionary.vieEng_key.deleteKeyword();
	dictionary.engVie_key.deleteKeyword();
	DrawReset("35% ");
	dictionary.slang_key.deleteKeyword();
	dictionary.emotional_key.deleteKeyword();
	DrawReset("40% ");
	dictionary.favourite.removeAll();
	dictionary.history.removeAll();
	DrawReset("45% ");
	ifstream fin;
	fin.open("../Data/engEng/engEng_origin.txt");
	int cnt = 0;
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		int id = dictionary.engEng_key.insert(key, def);
		bool add = dictionary.engEng_def.add(def, id);
		if (add) {
			if (id >= dictionary.engEng.size()) {
				dictionary.engEng.emplace_back();
				dictionary.engEng[id].key = key;
			}
			dictionary.engEng[id].def.push_back(def);
		}
		if (++cnt == 60000) DrawReset("56% ");
		else if (cnt == 85000) DrawReset("64% ");
	}
	fin.close();
	DrawReset("70% ");
	fin.open("../Data/engVie/engVie_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		int id = dictionary.engVie_key.insert(key, def);
		bool add = dictionary.engVie_def.add(def, id);
		if (add) {
			if (id >= dictionary.engVie.size()) {
				dictionary.engVie.emplace_back();
				dictionary.engVie[id].key = key;
			}
			dictionary.engVie[id].def.push_back(def);
		}
	}
	fin.close();
	DrawReset("78% ");
	fin.open("../Data/vieEng/vieEng_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		int id = dictionary.vieEng_key.insert(key, def);
		bool add = dictionary.vieEng_def.add(def, id);
		if (add) {
			if (id >= dictionary.vieEng.size()) {
				dictionary.vieEng.emplace_back();
				dictionary.vieEng[id].key = key;
			}
			dictionary.vieEng[id].def.push_back(def);
		}
	}
	fin.close();
	DrawReset("82% ");
	fin.open("../Data/slang/slang_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		int id = dictionary.slang_key.insert(key, def);
		bool add = dictionary.slang_def.add(def, id);
		if (add) {
			if (id >= dictionary.slang.size()) {
				dictionary.slang.emplace_back();
				dictionary.slang[id].key = key;
			}
			dictionary.slang[id].def.push_back(def);
		}
	}
	fin.close();
	DrawReset("96% ");
	fin.open("../Data/emotional/emotional_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		int id = dictionary.emotional_key.insert(key, def);
		bool add = dictionary.emotional_def.add(def, id);
		if (add) {
			if (id >= dictionary.emotional.size()) {
				dictionary.emotional.emplace_back();
				dictionary.emotional[id].key = key;
			}
			dictionary.emotional[id].def.push_back(def);
		}
	}
	fin.close();
	DrawReset("100% ");
	WaitTime(0.5);
	randWord = dictionary.randomAWord(dicNum + 1);
	cout << "Reset dictionary successfully!" << endl;
}

void System::DrawHistory() {
	DrawTitle();
	DrawTextEx(Raleway_BlackBig, "History", { (float)0.083 * windowWidth, (float)0.422 * windowHeight }, 72, 0.5, BLACK);

	mainpage.buttonShape.x = 0.061 * windowWidth;
	mainpage.buttonShape.y = 0.568 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);
	mainpage.DrawText(mouseCursor);

	// draw dinosour
	DrawTextureEx(dinosaur3_icon, { (float)0.073 * windowWidth, (float)0.68 * windowHeight }, 0, 0.35, WHITE);

	// draw mode button
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	if (mainpage.state == RELEASED) {
		menu = DEFAULT;
		isFavour = dictionary.isFavourite(randWord[0]);
	}

	// draw list of history word
	float coordX[2] = { 0.32 * windowWidth, 0.64 * windowWidth };
	float coordY = 0.422 * windowHeight;
	float gap = 0.155 * windowHeight;
	float szY = 0.127 * windowHeight;
	static float scrollY = 0;
	scrollY += GetMouseWheelMove() * 0.08 * windowHeight;
	if (scrollY + coordY + gap * (historyWords.size() + 1) / 2 < 0.99 * windowHeight)
		scrollY = 0.99 * windowHeight - coordY - gap * (historyWords.size() + 1) / 2;
	if (scrollY > 0) scrollY = 0;
	BeginScissorMode(0, 0.342 * windowHeight, windowWidth, 0.658 * windowHeight);
	for (int i = 0; i < historyWords.size(); ++i) {
		if (coordY + gap * (i / 2) + scrollY + szY < 0.342 * windowHeight) continue;
		historyButton[i].SetBox(coordX[i & 1], coordY + gap * (i / 2) + scrollY, 0.309 * windowWidth, szY, { 203, 241, 245, 255 }, { 203, 241, 245, 255 }, { 203, 241, 245, 255 });
		historyButton[i].SetText(RussoOne_Regular, PartialText(RussoOne_Regular, historyWords[i].word, 40, 0.7, 0.25 * windowWidth), {coordX[i & 1] + (float)0.02 * windowWidth, coordY + (float)gap * (i / 2) + (float)0.03 * windowHeight + scrollY}, 40, 0.7, BLACK, BLACK, BLACK);
		historyButton[i].roundness = 0.65;
		historyButton[i].DrawText(mouseCursor);
		removeButton[i].SetBox(coordX[i & 1] + (float)0.271 * windowWidth, coordY + gap * (i / 2) + (float)0.032 * windowHeight + scrollY, remove_icon.width * 0.085, remove_icon.height * 0.085 - (float)0.01 * windowHeight, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		removeButton[i].DrawText(mouseCursor);
		if (removeButton[i].state == DEFAULT && historyButton[i].state == RELEASED) {
			mode = historyWords[i].isKey ? false : true;
			if (!mode) {
				menu = SEARCH_RESULT;
				search_result = dictionary.searchKeyword(historyWords[i].word, dicNum + 1);
				isFavour = dictionary.isFavourite(historyWords[i].word);
			}
			else {
				menu = SEARCH_DEF_RESULT;
				searchDef_result = dictionary.searchHashDefinition(historyWords[i].word, dicNum + 1);
				if (!searchDef_result.empty()) isFavour = dictionary.isFavourite(searchDef_result[0][0]);
			}
		}
		if (removeButton[i].state == RELEASED) {
			dictionary.removeAHistory(dicNum + 1, historyWords[i].word);
			historyWords = dictionary.viewHistory(dicNum + 1);
		}
		DrawTextureEx(remove_icon, { coordX[i & 1] + (float)0.271 * windowWidth, coordY + gap * (i / 2) + (float)0.032 * windowHeight + scrollY }, 0, 0.085, removeButton[i].state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
	}
	EndScissorMode();

	// draw seach bar
	DrawSearchBar();

	if (ok.state == DEFAULT && searchBox.getState() == TOUCHED) {
		mouseCursor = MOUSE_CURSOR_IBEAM;
	}
}

void System::DrawFavourite() {
	// draw list of favourite word
	float coordX[2] = { 0.32 * windowWidth, 0.64 * windowWidth  };
	float coordY = 0.422 * windowHeight;
	//static Button heartButton[100];
	//static Button editButton[100];
	float gap = 0.155 * windowHeight;
	float szY = 0.127 * windowHeight;
	static float scrollY = 0;
	scrollY += GetMouseWheelMove() * 0.08 * windowHeight;
	if (scrollY + coordY + gap * (favourWords.size() + 1) / 2 < 0.99 * windowHeight)
		scrollY = 0.99 * windowHeight - coordY - gap * (favourWords.size() + 1) / 2;
	if (scrollY > 0) scrollY = 0;
	for (int i = 0; i < favourWords.size(); ++i) {
		favourButton[i].SetBox(coordX[i & 1], coordY + gap * (i/2) + scrollY, 0.309 * windowWidth, szY, { 203, 241, 245, 255 }, { 203, 241, 245, 255 }, { 203, 241, 245, 255 });
		favourButton[i].SetText(RussoOne_Regular, favourWords[i], { coordX[i & 1] + (float)0.02 * windowWidth, coordY + (float)gap * (i/2) + (float)0.03 * windowHeight + scrollY }, 40, 0.7, BLACK, BLACK, BLACK);
		favourButton[i].roundness = 0.65;
		favourButton[i].DrawText(mouseCursor);
		//heartButton[i].SetBox(coordX[i & 1] + (float)0.268 * windowWidth, coordY + gap * (i / 2) + (float)0.012 * windowHeight + scrollY, hollowedHeart_icon.width * 0.085, hollowedHeart_icon.height * 0.085 - (float)0.01 * windowHeight, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		//heartButton[i].DrawText(mouseCursor);
		//editButton[i].SetBox(coordX[i & 1] + (float)0.271 * windowWidth, coordY + gap * (i / 2) + (float)0.072 * windowHeight + scrollY, hollowedHeart_icon.width * 0.085, hollowedHeart_icon.height * 0.085 - (float)0.01 * windowHeight, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		//editButton[i].DrawText(mouseCursor);
		removeButton[i].SetBox(coordX[i & 1] + (float)0.271 * windowWidth, coordY + gap * (i / 2) + (float)0.032 * windowHeight + scrollY, remove_icon.width * 0.085, remove_icon.height * 0.085 - (float)0.01 * windowHeight, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		removeButton[i].DrawText(mouseCursor);
		if (removeButton[i].state == DEFAULT && favourButton[i].state == RELEASED) {
			menu = SEARCH_RESULT;
			search_result = dictionary.searchKeyword(favourWords[i], dicNum + 1);
			isFavour = dictionary.isFavourite(favourWords[i]);
		}
		if (removeButton[i].state == RELEASED) {
			dictionary.removeAFavourite(dicNum + 1, favourWords[i]);
			favourWords = dictionary.viewFavourite(dicNum + 1);
		}
		//DrawTextureEx(filledHeart_icon, { coordX[i & 1] + (float)0.268 * windowWidth, coordY + (float)gap * (i/2) + (float)0.01 * windowHeight + scrollY }, 0, 0.085, (heartButton[i].state == CLICKED ? Fade(WHITE, 0.4) : WHITE));
		//DrawTextureEx(edit_icon, { coordX[i & 1] + (float)0.272 * windowWidth, coordY + (float)gap * (i/2) + (float)0.06 * windowHeight + scrollY }, 0, 0.085, (editButton[i].state == CLICKED ? Fade(WHITE, 0.4) : WHITE));
		DrawTextureEx(filledHeart_icon, { coordX[i & 1] + (float)0.271 * windowWidth, coordY + gap * (i / 2) + (float)0.032 * windowHeight + scrollY }, 0, 0.088, removeButton[i].state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
	}

	DrawRectangle(0, 0, windowWidth, 0.342 * windowHeight, { 236, 249, 255, 255 });
	DrawTitle();
	DrawTextEx(Raleway_BlackBig, "Favourite", { (float)0.061 * windowWidth, (float)0.422 * windowHeight }, 72, 0.5, BLACK);

	mainpage.buttonShape.x = 0.061 * windowWidth;
	mainpage.buttonShape.y = 0.568 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);
	mainpage.DrawText(mouseCursor);

	// draw dinosour
	DrawTextureEx(dinosaur2_icon, { (float)0.073 * windowWidth, (float)0.68 * windowHeight }, 0, 1, WHITE);

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

	if (ok.state == DEFAULT && searchBox.getState() == TOUCHED) {
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
	DrawTextEx(Parable_Regular100, "Game", { (float)0.43 * windowWidth, (float)0.023 * windowHeight }, 100, 0.5, BLACK);
	DrawTextureEx(dinosaur_icon, { (float)0.326 * windowWidth, (float)0.023 * windowHeight }, 0, 0.5, WHITE);
	DrawTextureEx(rdinosaur_icon, { (float)0.596 * windowWidth, (float)0.023 * windowHeight }, 0, 0.5, WHITE);
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
	Rectangle wordShape = { (float)0.039 * windowWidth, (float)0.194 * windowHeight, (float)0.922 * windowWidth, (float)0.271 * windowHeight };
	DrawRectangleRoundedLines(wordShape, 0.1, 5, 2, { 113, 201, 206, 255});
	Vector2 pos = GetCenterPos(Raleway_Black48, randData.second[0], 48, 1, wordShape);
	if (pos.x < wordShape.x) {
		wordShape.x += 0.01 * windowWidth;
		DrawTextOnBox(wordShape, !mode ? Raleway_Black48 : Raleway_Italic48, randData.second[0], { wordShape.x + (float)0.02 * windowWidth, wordShape.y + (float)0.015 * windowHeight }, 48, 1, 0.042 * windowHeight, BLACK);
	}
	else DrawTextEx(!mode ? Raleway_Black48 : Raleway_Italic48, randData.second[0].c_str(), GetCenterPos(Raleway_Black48, randData.second[0], 48, 1, wordShape), 48, 1, BLACK);
	static float scrollY[4] = { 0, 0, 0, 0 };
	static bool isChoosed[4] = { false, false, false, false };
	for (int i = 0; i < 4; i++) {
		choiceButton[i].SetBox(choiceShape[i].x, choiceShape[i].y, choiceShape[i].width, choiceShape[i].height, {113, 201, 206, 0}, {113, 201, 206, 15}, {113, 201, 206, 30});
		choiceButton[i].roundness = 0.2;
		choiceButton[i].drawCorner = true;
		choiceButton[i].colorCornerDefault = choiceButton[i].colorCornerClicked = choiceButton[i].colorCornerTouched = {113, 201, 206, 255};
		if (isAnswered && randData.first == i + 1) {
			choiceButton[i].colorBoxDefault = choiceButton[i].colorBoxClicked = choiceButton[i].colorBoxTouched = { 0, 179, 0, 255 };
		}
		choiceButton[i].DrawText(mouseCursor);
		if (isChoosed[i]) {
			DrawRectangleRounded(choiceShape[i], 0.2, 4, {239, 83, 80, 150});
		}
		DrawCircle(choiceShape[i].x + 0.009 * windowWidth + 0.01 * windowHeight, choiceShape[i].y + 0.005 * windowHeight + 0.023 * windowHeight, 0.02 * windowHeight, { 203, 241, 245, 255 });
		DrawTextEx(Raleway_Bold30, to_string(i + 1).c_str(), { choiceShape[i].x + (float)0.009 * windowWidth + (float)0.001 * windowHeight, choiceShape[i].y + (float)0.005 * windowHeight + (float)0.002 * windowHeight }, 30, 0.5, BLACK);
		
		choiceShape[i].x += 0.03 * windowWidth;
		choiceShape[i].y += 0.005 * windowHeight;
		choiceShape[i].width -= 0.035 * windowWidth;
		choiceShape[i].height -= 0.007 * windowHeight;
		Vector2 posLast = DrawTextOnBox(choiceShape[i], !mode ? Raleway_Italic30 : Raleway_Bold30, randData.second[i + 1], { choiceShape[i].x + (float)0.01 * windowWidth, choiceShape[i].y + (float)0.01 * windowHeight + scrollY[i]}, 30, 0.5, 0.036 * windowHeight, BLACK);
		if (!isAnswered && choiceButton[i].state == TOUCHED) {
			float szY = posLast.y - (choiceShape[i].y + (float)0.01 * windowHeight + scrollY[i]);
			scrollY[i] += GetMouseWheelMove() * 0.05 * windowHeight;
			float endY = choiceShape[i].y + choiceShape[i].height;
			if (choiceShape[i].y + (float)0.01 * windowHeight + scrollY[i] + szY < 0.95 * endY) scrollY[i] = 0.95 * endY - (choiceShape[i].y + (float)0.01 * windowHeight + szY);
			if (scrollY[i] > 0) scrollY[i] = 0;
		}
		if (!isAnswered && choiceButton[i].state == RELEASED) {
			if (randData.first == i + 1) {
				isAnswered = true;
				timeline = 0;
			} else {
				isChoosed[i] = true;
			}
		}
	}

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
			for (int i = 0; i < 4; ++i) {
				scrollY[i] = 0;
				isChoosed[i] = false;
			}

		}
		DrawRectangle(0, 0, windowWidth, windowHeight, Fade(BLACK, 0.5));
		DrawTextEx(Raleway_BlackBig, "Correctly!", { (float)0.39 * windowWidth, (float)0.45 * windowHeight }, 68, 0.7, { 50, 205, 50, 255 });
	}
}

void System::DrawModify() {
	static bool dialog = false;
	static float timeline = 0;
	static float scrollY = 0;
	scrollY += GetMouseWheelMove() * 0.08 * windowHeight;
	if (0.75 * windowHeight + scrollY + (0.12 * windowHeight + 0.04 * windowHeight) * (int)modifyDefBox.size() + 0.142 * windowHeight < 0.985 * windowHeight) {
		scrollY = 0.985 * windowHeight - (0.75 * windowHeight + (0.12 * windowHeight + 0.04 * windowHeight) * (int)modifyDefBox.size() + 0.142 * windowHeight);
	}
	if (scrollY > 0) scrollY = 0;
	if (timeline <= 10) timeline += GetFrameTime();

	// draw keyword input box
	DrawTextEx(Raleway_Bold48, "Keyword", { (float)0.061 * windowWidth, (float)0.448 * windowHeight + scrollY }, 48, 1, BLACK);
	modifyKeyBox.Construct(0.303 * windowWidth, 0.416 * windowHeight + scrollY, 0.636 * windowWidth, 0.12 * windowHeight, Raleway_Bold, { (float)0.323 * windowWidth, (float)0.448 * windowHeight + scrollY }, 40, 1, 300);
	modifyKeyBox.Draw();
	// draw number of definition
	decreaseButton.SetBox(0.38 * windowWidth, 0.603 * windowHeight + scrollY, 0.04 * windowWidth, 0.05 * windowHeight, defaultColor, touchedColor, clickedColor);
	decreaseButton.SetText(Raleway_Bold48, "<", GetCenterPos(Raleway_Bold48, "<", 48, 1, decreaseButton.buttonShape), 48, 1, BLACK, BLACK, RAYWHITE);
	decreaseButton.DrawText(mouseCursor);
	increaseButton.SetBox(0.47 * windowWidth, 0.603 * windowHeight + scrollY, 0.04 * windowWidth, 0.05 * windowHeight, defaultColor, touchedColor, clickedColor);
	increaseButton.SetText(Raleway_Bold48, ">", GetCenterPos(Raleway_Bold48, ">", 48, 1, increaseButton.buttonShape), 48, 1, BLACK, BLACK, RAYWHITE);
	increaseButton.DrawText(mouseCursor);
	if (increaseButton.state == RELEASED) {
		if ((int)modifyDefBox.size() < 10) {
			modifyDefBox.emplace_back();
		}
	}
	if (decreaseButton.state == RELEASED) {
		if ((int)modifyDefBox.size() > 0) {
			modifyDefBox.pop_back();
		}
	}
	DrawTextEx(Raleway_Bold48, "Number of definition:", { (float)0.061 * windowWidth, (float)0.6 * windowHeight + scrollY }, 48, 1, BLACK);
	DrawTextEx(Raleway_Bold48, to_string((int)modifyDefBox.size()).c_str(), GetCenterPos(Raleway_Bold48, to_string((int)modifyDefBox.size()), 48, 1, 0.42 * windowWidth, 0.603 * windowHeight + scrollY, 0.05 * windowWidth, 0.05 * windowHeight), 48, 1, BLACK);
	// draw definition input box
	float szXBox = 0.636 * windowWidth;
	float szYBox = 0.12 * windowHeight;
	float gapBox = 0.04 * windowHeight;
	float yBox = 0.75 * windowHeight + scrollY;
	for (int i = 0; i < (int)modifyDefBox.size(); ++i) {
		DrawTextEx(Raleway_Bold48, ("Definition " + to_string(i + 1) + ":").c_str(), {(float)0.061 * windowWidth, yBox + (float)0.032 * windowHeight + (szYBox + gapBox) * i }, 48, 1, BLACK);
		modifyDefBox[i].Construct(0.303 * windowWidth, yBox + (szYBox + gapBox) * i, szXBox, szYBox, Raleway_Bold, { (float)0.323 * windowWidth, yBox + (float)0.032 * windowHeight + (szYBox + gapBox) * i }, 40, 1, 300);
		modifyDefBox[i].Draw();
		removeButton[i].SetBox((float)0.317 * windowWidth + szXBox, yBox + (szYBox + gapBox) * i + (float)0.032 * windowHeight, remove_icon.width * 0.1, remove_icon.height * 0.1, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		removeButton[i].DrawText(mouseCursor);
		DrawTextureEx(remove_icon, { (float)0.317 * windowWidth + szXBox, yBox + (szYBox + gapBox) * i + (float)0.032 * windowHeight }, 0, 0.1, removeButton[i].state == CLICKED ? Fade(BLACK, 0.4) : BLACK);
		if (removeButton[i].state == RELEASED) {
			modifyDefBox.erase(modifyDefBox.begin() + i);
		}
	}
	
	// draw enter button
	enter.SetBox(0.5 * windowWidth, yBox + (szYBox + gapBox) * (int)modifyDefBox.size() + 0.06 * windowHeight, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	enter.SetText(Raleway_Black, "Enter", GetCenterPos(Raleway_Black, "Enter", 40, 0.5, enter.buttonShape), 40, 0.5, BLACK, BLACK, BLACK);
	enter.DrawText(mouseCursor);
	// draw mainpage button
	mainpage.buttonShape.x = 0.743 * windowWidth;
	mainpage.buttonShape.y = yBox + (szYBox + gapBox) * (int)modifyDefBox.size() + 0.06 * windowHeight;
	mainpage.coordText = GetCenterPos(mainpage.font, mainpage.Text, mainpage.fontSize, mainpage.spacing, mainpage.buttonShape);
	
	if (enter.state == RELEASED) {
		bool isEmpty = false;
		for (InputBox &tmp : modifyDefBox) {
			isEmpty |= tmp.getInput().empty();
		}
		if (isEmpty || modifyDefBox.empty()) {

		}
		else {
			if (!isAddNewWord) {
				dictionary.removeAWord(dicNum + 1, modifyKeyBox.getInput());
			}
			cout << modifyKeyBox.getInput() << '\n';
			for (int i = 0; i < (int)modifyDefBox.size(); ++i) {
				if (dictionary.addNewWord(dicNum + 1, modifyKeyBox.getInput(), modifyDefBox[i].getInput())) {

				}
			}
			timeline = 0;
			dialog = true;
		}
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

	DrawRectangle(0, 0, windowWidth, 0.342 * windowHeight, { 236, 249, 255, 255 });
	DrawTitle();

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
		randWord = dictionary.searchKeyword(randWord[0], dicNum + 1);
	}
	if (menu != MODIFY) {
		modifyKeyBox.posCursor = 0;
		dialog = false;
		timeline = 0;
		isAddNewWord = false;
		modifyKeyBox.currentInput = "";
		modifyKeyBox.noTyping = false;
		modifyDefBox.clear();
	}
	if (ok.state == DEFAULT && searchBox.getState() == TOUCHED) {
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
					randWord = dictionary.randomAWord(dicNum + 1);
					isFavour = dictionary.isFavourite(randWord[0]);
					historyWords = dictionary.viewHistory(dicNum + 1);
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

void System::SetModify(string key) {
	search_result = dictionary.searchKeyword(key, dicNum + 1);
	modifyKeyBox.currentInput = search_result[0];
	modifyKeyBox.manipulate();
	cout << search_result[0] << 1 << '\n';
	modifyKeyBox.noTyping = true;
	modifyDefBox.clear();
	for (int i = 1; i < search_result.size(); ++i) {
		InputBox tmp;
		tmp.currentInput = search_result[i];
		modifyDefBox.push_back(tmp);
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
	if (edit.state == RELEASED) {
		SetModify(randWord[0]);
		menu = MODIFY;
	}

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
	Rectangle dropdownBox = { searchBox.inputShape.x, searchBox.inputShape.y + searchBox.inputShape.height, searchBox.inputShape.width, searchBox.inputShape.height * min(6, (int)max(suggestions.size(), historyWords.size()))};
	if (CheckCollisionPointRec(GetMousePosition(), dropdownBox) == false && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		isDropdown = false;
		timeline = 0;
	}
	isDropdown |= (searchBox.isTyping && searchBox.currentInput.empty() == false);
	// draw suggestions
	static Button suggestion[6];
	if (isDropdown && !mode && !searchBox.getInput().empty()) {// search by keyword
		if (timeline == 30) suggestions = dictionary.predictKeyword(searchBox.getInput(), dicNum + 1);// dicNum + 1 because dicNum begin from 0
		for (int i = 0; i < suggestions.size() && i < 6; ++i) {
			suggestion[i].SetBox(searchBox.inputShape.x, searchBox.inputShape.y + (i + 1) * searchBox.inputShape.height, searchBox.inputShape.width, searchBox.inputShape.height, { 227, 253, 253, 253 }, { 238, 253, 253, 245 }, { 204, 227, 227, 255 });
			suggestion[i].SetText(Parable_Regular40, suggestions[i], { (float)0.35 * windowWidth ,GetCenterPos(Parable_Regular40, suggestions[i], 40, 1, suggestion[i].buttonShape).y }, 40, 1, { 178, 178, 178, 255 }, { 178, 178, 178, 255 }, { 178, 178, 178, 255 });
			suggestion[i].roundness = 0.65;
			suggestion[i].DrawText(mouseCursor);
			DrawTextureEx(search_icon, { searchBox.inputShape.x + (float)0.01 * windowWidth, searchBox.inputShape.y + (i + 1) * searchBox.inputShape.height + (float)0.01 * windowHeight }, 0, 0.16, WHITE);
			if (suggestion[i].state == RELEASED) {
				searchBox.currentInput = suggestions[i];
				searchBox.posCursor = searchBox.currentInput.size();
				isDropdown = false;
				search_result = dictionary.searchKeyword(suggestions[i], dicNum + 1);
				isFavour = dictionary.isFavourite(suggestions[i]);
				menu = SEARCH_RESULT;
				searchBox.isTyping = false;
				dictionary.removeAHistory(dicNum + 1, suggestions[i]);
				dictionary.addHistory(dicNum + 1, suggestions[i], !mode);
				historyWords = dictionary.viewHistory(dicNum + 1);
				choosen = 0;
			}
		}
	}
	// draw history
	static Button hisButton[7];
	if (isDropdown && searchBox.getInput().empty()) {
		
		for (int i = 0; i < min(6, (int)historyWords.size()); ++i) {
			hisButton[i].SetBox(searchBox.inputShape.x, searchBox.inputShape.y + (i + 1) * searchBox.inputShape.height, searchBox.inputShape.width, searchBox.inputShape.height, { 227, 253, 253, 253 }, { 238, 253, 253, 245 }, { 204, 227, 227, 255 });
			hisButton[i].SetText(Parable_Regular40, historyWords[i].word, { (float)0.35 * windowWidth ,GetCenterPos(Parable_Regular40, historyWords[i].word, 40, 1, hisButton[i].buttonShape).y }, 40, 1, { 178, 178, 178, 255 }, { 178, 178, 178, 255 }, { 178, 178, 178, 255 });
			hisButton[i].DrawText(mouseCursor);
			DrawTextureEx(history_icon, { searchBox.inputShape.x + (float)0.01 * windowWidth, searchBox.inputShape.y + (i + 1) * searchBox.inputShape.height + (float)0.01 * windowHeight }, 0, 0.1, WHITE);
			if (hisButton[i].state == RELEASED) {
				searchBox.currentInput = historyWords[i].word;
				searchBox.posCursor = searchBox.currentInput.size();
				isDropdown = false;
				mode = !historyWords[i].isKey;
				if (mode) {
					searchDef_result = dictionary.searchHashDefinition(historyWords[i].word, dicNum + 1);
					menu = SEARCH_DEF_RESULT;
					choosen = 0;
				}
				else {
					search_result = dictionary.searchKeyword(historyWords[i].word, dicNum + 1);
					menu = SEARCH_RESULT;
				}
				isFavour = dictionary.isFavourite(historyWords[i].word);
				searchBox.isTyping = false;
				dictionary.removeAHistory(dicNum + 1, historyWords[i].word);
				dictionary.addHistory(dicNum + 1, historyWords[i].word, !mode);
				historyWords = dictionary.viewHistory(dicNum + 1);
			}
		}
	}

	// draw search result
	if (searchBox.isTyping && searchBox.getInput().empty() == false) {
		if (IsKeyReleased(KEY_ENTER) || ok.state == RELEASED) {
			dictionary.removeAHistory(dicNum + 1, searchBox.getInput());
			dictionary.addHistory(dicNum + 1, searchBox.getInput(), !mode);
			historyWords = dictionary.viewHistory(dicNum + 1);
			if (mode) {// mode == true -> search by definition, click modeDef or modeKey to change mode
				searchDef_result = dictionary.searchHashDefinition(searchBox.getInput(), dicNum + 1);// dicNum + 1 because dicNum begin from 0
				choosen = 0;
				if (!searchDef_result.empty()) isFavour = dictionary.isFavourite(searchDef_result[0][0]);
			} else {
				search_result = dictionary.searchKeyword(searchBox.getInput(), dicNum + 1);
			}
			if (!search_result.empty()) isFavour = dictionary.isFavourite(search_result[0]);
			if (mode) menu = SEARCH_DEF_RESULT;
			else menu = SEARCH_RESULT;
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
	if (search_result.size() < 2) {
		DrawTextEx(RussoOne_Regular, "No result!", { (float)0.061 * windowWidth, (float)0.389 * windowHeight + scrollY }, 96, 1, BLACK);
	}
	else DrawTextEx(RussoOne_Regular, search_result[0].c_str(), { (float)0.061 * windowWidth, (float)0.389 * windowHeight + scrollY }, 96, 1, BLACK);
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
				dictionary.removeAFavourite(dicNum + 1, search_result[0]);
				isFavour = false;
			}
		}
		else {
			DrawTextureEx(hollowedHeart_icon, { (float)0.815 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.085, Heart.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
			if (Heart.state == RELEASED) {
				dictionary.addFavourite(dicNum + 1, search_result[0]);
				isFavour = true;
			}
		}
		edit.SetBox(0.858 * windowWidth, boxShape.y + 0.01 * windowHeight, edit_icon.width * 0.075, edit_icon.height * 0.075, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		edit.DrawText(mouseCursor);
		DrawTextureEx(edit_icon, { (float)0.858 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.075, edit.state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
		if (edit.state == RELEASED) {
			SetModify(search_result[0]);
			menu = MODIFY;
		}
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
	DrawTitle();
	// draw search bar
	DrawSearchBar();
	// draw mode button
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	if (ok.state == DEFAULT && searchBox.getState() == TOUCHED) {
		mouseCursor = MOUSE_CURSOR_IBEAM;
	}
}

void System::DrawSearchDefResult() {
	static float scrollY = 0;// scroll 
	static float height = 0;// height of the search result box
	static bool dialog = false;
	static Button Heart[100], edit[100], remove[100];
	scrollY += GetMouseWheelMove() * 30;
	if (0.55 * windowHeight + height + scrollY + 0.1 * windowHeight < windowHeight) scrollY = windowHeight - 0.55 * windowHeight - height - 0.1 * windowHeight;
	if (scrollY > 0) scrollY = 0;
	// draw mainpage button
	mainpage.SetBox(0.743 * windowWidth, 0.406 * windowHeight + scrollY, 0.196 * windowWidth, 0.082 * windowHeight, defaultColor, touchedColor, clickedColor);
	mainpage.SetText(Raleway_Black, "Main Page", GetCenterPos(Raleway_Black, "Main Page", 40, 1, mainpage.buttonShape), 40, 1, BLACK, BLACK, BLACK);
	static Button prev, next;
	prev.SetBox(0.543 * windowWidth, 0.426 * windowHeight + scrollY, 0.058 * windowWidth, 0.052 * windowHeight, defaultColor, touchedColor, clickedColor);
	prev.SetText(Raleway_Black, "<", GetCenterPos(Raleway_Black, "<", 40, 1, prev.buttonShape), 40, 1, BLACK, BLACK, BLACK);
	next.SetBox(0.661 * windowWidth, 0.426 * windowHeight + scrollY, 0.058 * windowWidth, 0.052 * windowHeight, defaultColor, touchedColor, clickedColor);
	next.SetText(Raleway_Black, ">", GetCenterPos(Raleway_Black, ">", 40, 1, next.buttonShape), 40, 1, BLACK, BLACK, BLACK);
	if (mainpage.buttonShape.y + mainpage.buttonShape.height >= 0.342 * windowHeight) {
		mainpage.DrawText(mouseCursor);
		if (choosen != 0) prev.DrawText(mouseCursor);
		if (choosen + 1 != (int)searchDef_result.size()) next.DrawText(mouseCursor);
		DrawTextEx(Raleway_Black48, to_string(choosen + 1).c_str(), GetCenterPos(Raleway_Black48, to_string(choosen + 1), 48, 0.5, { prev.buttonShape.x + prev.buttonShape.width, prev.buttonShape.y, next.buttonShape.x - (prev.buttonShape.x + prev.buttonShape.width), prev.buttonShape.height }), 48, 0.5, BLACK);
		string totalPage = "of " + to_string(searchDef_result.size()) + (searchDef_result.size() > 1 ? " pages" : " page");
		DrawTextEx(Raleway_Bold30, totalPage.c_str(), { GetCenterPos(Raleway_Bold30, totalPage, 30, 0.5, { prev.buttonShape.x + prev.buttonShape.width, prev.buttonShape.y + prev.buttonShape.height, next.buttonShape.x - (prev.buttonShape.x + prev.buttonShape.width), prev.buttonShape.height }).x, (float)0.5 * windowHeight + scrollY }, 30, 0.5, BLACK);
		if (mainpage.state == RELEASED) {
			menu = DEFAULT;
			isFavour = dictionary.isFavourite(randWord[0]);
			scrollY = 0;
			height = 0;
			choosen = 0;
		}
		if (prev.state == RELEASED) {
			prev.state = CLICKED;
			if (choosen > 0) --choosen;
			scrollY = 0;
			height = 0;
			isFavour = dictionary.isFavourite(searchDef_result[choosen][0]);
		}
		if (next.state == RELEASED) {
			next.state = CLICKED;
			if (choosen + 1 < searchDef_result.size()) {
				++choosen;
				scrollY = 0;
				height = 0;
				isFavour = dictionary.isFavourite(searchDef_result[choosen][0]);
			}
		}
	}

	// draw search result
	// draw keyword
	if (searchDef_result.empty() || searchDef_result[0].size() < 2) {
		DrawTextEx(RussoOne_Regular, "No result!", { (float)0.061 * windowWidth, (float)0.389 * windowHeight + scrollY }, 96, 1, BLACK);
	}
	else {
		DrawTextEx(RussoOne_Regular, searchDef_result[choosen][0].c_str(), { (float)0.061 * windowWidth, (float)0.389 * windowHeight + scrollY }, 96, 1, BLACK);
		// draw definition box
		Rectangle boxShape = { (float)0.061 * windowWidth, (float)0.55 * windowHeight + scrollY, (float)0.878 * windowWidth, (float)height };
		DrawRectangleRounded(boxShape, 0.25 - 0.00000012 * height * height, 10, { 203, 241, 245, 255 });
		boxShape.x += 0.013 * windowWidth;
		boxShape.width -= 0.023 * windowWidth;
		height = DrawTextOnBoxEx(boxShape, Raleway_Italic, searchDef_result[choosen], {(float)0.09 * windowWidth, (float)0.61 * windowHeight + scrollY}, 40, 0.5, 0.04 * windowHeight, 0.055 * windowHeight, BLACK) - boxShape.y + 0.05 * windowHeight;

		Heart[choosen].SetBox(0.815 * windowWidth, boxShape.y + 0.01 * windowHeight, filledHeart_icon.width * 0.085, filledHeart_icon.height * 0.085, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		Heart[choosen].DrawText(mouseCursor);
		if (isFavour) {
			DrawTextureEx(filledHeart_icon, { (float)0.815 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.085, Heart[choosen].state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
			if (Heart[choosen].state == RELEASED) {
				dictionary.removeAFavourite(dicNum + 1, searchDef_result[choosen][0]);
				isFavour = false;
			}
		}
		else {
			DrawTextureEx(hollowedHeart_icon, { (float)0.815 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.085, Heart[choosen].state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
			if (Heart[choosen].state == RELEASED) {
				dictionary.addFavourite(dicNum + 1, searchDef_result[choosen][0]);
				isFavour = true;
			}
		}
		edit[choosen].SetBox(0.858 * windowWidth, boxShape.y + 0.01 * windowHeight, edit_icon.width * 0.075, edit_icon.height * 0.075, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		edit[choosen].DrawText(mouseCursor);
		DrawTextureEx(edit_icon, { (float)0.858 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.075, edit[choosen].state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
		if (edit[choosen].state == RELEASED) {
			SetModify(searchDef_result[choosen][0]);
			menu = MODIFY;
		}
		remove[choosen].SetBox(0.893 * windowWidth, boxShape.y + 0.01 * windowHeight, remove_icon.width * 0.08, remove_icon.height * 0.08, Fade(WHITE, 0), Fade(WHITE, 0), Fade(WHITE, 0));
		remove[choosen].DrawText(mouseCursor);
		DrawTextureEx(remove_icon, { (float)0.893 * windowWidth, boxShape.y + (float)0.01 * windowHeight }, 0, 0.08, remove[choosen].state == CLICKED ? Fade(WHITE, 0.4) : WHITE);
		if (remove[choosen].state == RELEASED) {
			dialog = true;
		}
	}
	if (dialog) {
		DrawDialogBox();
		if (yes.state == RELEASED) {
			dictionary.removeAWord(dicNum + 1, searchDef_result[choosen][0]);
			searchDef_result.erase(searchDef_result.begin() + choosen);
			if (choosen == searchDef_result.size()) --choosen;
			dialog = false;
		}
		if (no.state == RELEASED) {
			dialog = false;
		}
	}
	// draw title
	DrawRectangle(0, 0, windowWidth, 0.342 * windowHeight, { 236, 249, 255, 255 });
	DrawTitle();
	// draw search bar
	DrawSearchBar();
	// draw mode button
	if (mode) modeDef.DrawText(mouseCursor);
	else modeKey.DrawText(mouseCursor);
	if (modeDef.getState() == RELEASED) mode ^= 1;
	else if (modeKey.getState() == RELEASED) mode ^= 1;

	if (ok.state == DEFAULT && searchBox.getState() == TOUCHED) {
		mouseCursor = MOUSE_CURSOR_IBEAM;
	}
}