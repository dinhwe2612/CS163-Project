#ifndef SYSTEM_H
#define SYSTEM_H

#include "UI/Button.h"
#include "UI/InputBox.h"
#include "string.h"

using namespace std;

struct System {
    float windowWidth, windowHeight;

    Font Parable_Regular;
    Font Raleway_Black;
    Font Raleway_BlackBig;
    Font Raleway_Bold;
    Font Raleway_Italic;

    Button reset;
    Button addnew;
    Button history;
    Button favourite;
    Button game;
    Button select;
    Button back;
    Button ok; // for search
    Button modeDef, modeKey; bool mode = false;
    Button changeTranslation;
    Button mainpage;
    string translation[5] = { "eng - eng", "vn - eng", "eng - vn", "slang", "emoji" };

    InputBox searchBox;
    InputBox modifyKeyBox;
    InputBox modifyDefBox;

    Texture search_icon;
    Texture hollowedHeart_icon;
    Texture filledHeart_icon;
    Texture arrow_icon;
    Texture dictionary_icon;
    Texture add_icon;
    Texture zoom_icon;
    Texture edit_icon;
    Texture reload_icon;

    Color defaultColor = { 113, 201, 206, 255 };
    Color touchedColor = { 63, 201, 250, 245 };
    Color clickedColor = { 113, 171, 206, 255 };

    enum BoxState { NONE, TOUCHED, CLICKED, RELEASED };
    enum Menu {
        DEFAULT,
        HISTORY,
        FAVOURITE,
        GAME,
        MODIFY,
        RESET,
    };
    int menu = DEFAULT;
    bool isDropdownChangeTranslation = false;

    void Construct();
    void Draw();
    void DrawDefault();
    void DrawHistory();
    void DrawFavourite();
    void DrawGame();
    void DrawModify();
    void DrawReset();
    void DrawChangeTranslation();
    void DrawRandomWord();
    void DrawSearchBar();
};

#endif