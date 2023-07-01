#include "Button.h"

void Button::SetBox(float x, float y, float width, float height, Color colorDefault, Color colorTouched, Color colorClicked) {
	buttonShape.x = x;
	buttonShape.y = y;
	buttonShape.width = width;
	buttonShape.height = height;
	colorBoxDefault = colorDefault;
	colorBoxTouched = colorTouched;
	colorBoxClicked = colorClicked;
}

void Button::SetText(Font _font, string _Text, Vector2 _coordText, float _fontSize, float _spacing, Color colorDefault, Color colorTouched, Color colorClicked) {
	font = _font;
	Text = _Text;
	coordText = _coordText;
	fontSize = _fontSize;
	spacing = _spacing;
	colorTextDefault = colorDefault;
	colorTextTouched = colorTouched;
	colorTextClicked = colorClicked;
}

void Button::DrawText() {
	int state = getState();
	if (state == DEFAULT) {
		DrawRectangleRec(buttonShape, colorBoxDefault);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextDefault);
	}
	else if (state == TOUCHED) {
		DrawRectangleRec(buttonShape, colorBoxTouched);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextTouched);
	}
	else if (state == CLICKED) {
		DrawRectangleRec(buttonShape, colorBoxClicked);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextClicked);
	}
}

int Button::getState() {
	if (CheckCollisionPointRec(GetMousePosition(), buttonShape)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			return CLICKED;
		}
		else {
			return TOUCHED;
		}
	}
	return DEFAULT;
}