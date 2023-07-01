#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include <iostream>
#include <string.h>

using namespace std;

struct Button {
    Rectangle buttonShape;
    Color colorBoxDefault = RAYWHITE, colorBoxTouched = RAYWHITE, colorBoxClicked = RAYWHITE, colorText = BLACK;
    bool drawCorner = true;

    //Box
    enum BoxState { DEFAULT, TOUCHED, CLICKED };

    //Text
    Font font;
    string Text;
    Vector2 coordText;
    float fontSize;
    float spacing;
    Color colorTextDefault = BLACK, colorTextTouched = BLACK, colorTextClicked = BLACK;

    //
    void SetBox(float x, float y, float width, float height, Color colorDefault, Color colorTouched, Color colorClicked);

    //For Button Text
    void SetText(Font _font, string _Text, Vector2 _coordText, float _fontSize, float _spacing, Color colorDefault, Color colorTouched, Color colorClicked);
    void DrawText();

    int getState();
};

#endif