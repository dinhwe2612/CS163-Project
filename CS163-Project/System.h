#ifndef SYSTEM_H
#define SYSTEM_H

#include "UI/Button.h"
#include "UI/InputBox.h"
#include "string.h"
#include "Dictionary.h"
#include <random>
#include <chrono>

using namespace std;

struct System {
    float windowWidth, windowHeight;

    Font Parable_Regular;
    Font Parable_Regular40;
    Font Raleway_Black;
    Font Raleway_Black48;
    Font Raleway_BlackBig;
    Font Raleway_Bold;
    Font Raleway_Bold30;
    Font Raleway_Bold48;
    Font Raleway_Italic;
    Font Raleway_Italic30;
    Font Raleway_Italic48;
    Font RussoOne_Regular;

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
    Button enter;
    Button Background;
    Button yes, no;
    Button decreaseButton, increaseButton;
    Button historyButton[100];
    Button favourButton[100];
    Button removeButton[100];
    Button heartButton[100];
    string translation[5] = { "eng - eng", "vn - eng", "eng - vn", "slang", "emoji" };
    vector<string> search_result;
    vector<string> suggestions;

    InputBox searchBox;
    InputBox modifyKeyBox;
    vector<InputBox> modifyDefBox;

    Texture search_icon;
    Texture hollowedHeart_icon;
    Texture filledHeart_icon;
    Texture arrow_icon;
    Texture dictionary_icon;
    Texture add_icon;
    Texture zoom_icon;
    Texture edit_icon;
    Texture reload_icon;
    Texture remove_icon;
    Texture history_icon;
    Texture reset_icon;

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
        SEARCH_RESULT,
    };
    pair<int, vector<string>> randData; // for game
    vector<string> randWord; // for mainpage
    vector<string> favourWords; // list of keyword favourite
    vector<his> historyWords; // list of keyword history
    bool isFavour = false;
    int dicNum = 0; // which dictionary is selected
    int menu = DEFAULT;
    int mouseCursor = MOUSE_CURSOR_DEFAULT;
    bool isDropdownChangeTranslation = false;
    bool isAddNewWord = false;

    void Construct();
    void Draw();
    void DrawDefault();
    void DrawHistory();
    void DrawFavourite();
    void DrawGame();
    void DrawModify();
    void DrawReset(string content);
    void DrawChangeTranslation();
    void DrawRandomWord();
    void DrawSearchBar();
    void DrawSearchResult();
    void DrawDialogBox();
    void SetModify(string key);
    void ResetDictionary();
};

#endif