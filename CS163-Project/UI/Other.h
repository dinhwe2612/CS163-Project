#ifndef OTHER_H
#define OTHER_H

#include "raylib.h"
#include <iostream>
using namespace std;

Vector2 GetCenterPos(Font font, string text, float fontSize, float spacing, float x, float y, float width, float height);
Vector2 GetCenterPos(Font font, string text, float fontSize, float spacing, Rectangle rect);

#endif