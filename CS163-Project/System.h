#ifndef SYSTEM_H
#define SYSTEM_H

#include "UI/Button.h"
#include "UI/InputBox.h"
#include "string.h"

using namespace std;

struct System {
    float windowWidth, windowHeight;

    Font Parable_Regular;

    Button reset;
    Button addnew;
    Button history;
    Button favourite;
    Button game;
    Button select;
    Button back;
    Button changeTranslation;
    string translation[5] = { "eng - eng", "vn - eng", "eng - vn", "slang", "emoji" };

    InputBox searchBox;

    Texture search_icon;
    Texture hollowedHeart_icon;
    Texture filledHeart_icon;
    Texture arrow_icon;

    Color defaultColor = { 113, 201, 206, 255 };
    Color touchedColor = { 63, 201, 250, 245 };
    Color clickedColor = { 113, 171, 206, 255 };

    enum BoxState { NONE, TOUCHED, CLICKED, RELEASED };
    enum Menu {
        DEFAULT,
        HISTORY,
        FAVOURITE,
        GAME,
        ADDNEW,
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
    void DrawAddNew();
    void DrawReset();
    void DrawChangeTranslation();
};

#endif