#ifndef SYSTEM_H
#define SYSTEM_H

#include "UI/Button.h"
#include "UI/InputBox.h"

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

    InputBox searchBox;

    Texture search_icon;
    Texture hollowedHeart_icon;
    Texture filledHeart_icon;

    void Construct();
    void Draw();
};

#endif