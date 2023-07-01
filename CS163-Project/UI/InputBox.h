#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "raylib.h"
#include <iostream>
#include <string.h>
using namespace std;

struct InputBox {
    string currentInput = "";
    Font font;
    Rectangle inputShape;
    Vector2 coordText;
    float szText, spacing;
    Color colorBoxDefault = RAYWHITE, colorBoxTouched = RAYWHITE, colorBoxTyping = RAYWHITE;
    Color colorTextDefault = BLACK, colorTextTouched = BLACK, colorTextTyping = BLACK;
    int MAX_SIZE = 0;
    bool isTyping = false;
    enum State { DEFAULT, TOUCHED, TYPING };

    void Construct(float x, float y, float width, float height, Font _font, Vector2 _coordText, int _szText, float _spacing, int _MAX_SIZE);
    void SetColorBox(Color colorDefault, Color colorTouched, Color colorTyping);
    void SetColorText(Color colorDefault, Color colorTouched, Color colorTyping);
    void Draw();
    bool isClicked();
    int getState();
    void reset();
};

#endif