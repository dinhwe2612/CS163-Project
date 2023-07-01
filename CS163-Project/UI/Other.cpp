#include "Other.h"

Vector2 GetCenterPos(Font font, string text, float fontSize, float spacing, float x, float y, float width, float height) {
	Vector2 centerPos;
	centerPos.x = x + (width - MeasureTextEx(font, text.c_str(), fontSize, spacing).x) / 2;
	centerPos.y = y + (height - MeasureTextEx(font, text.c_str(), fontSize, spacing).y) / 2;
	return centerPos;
}