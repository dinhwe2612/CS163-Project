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
		//DrawRectangleRec(buttonShape, colorBoxDefault);
		DrawRectangleRounded(buttonShape, roundness, segments, colorBoxDefault);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextDefault);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerDefault);
			DrawRectangleRoundedLines(buttonShape, roundness, segments, 4, colorCornerClicked);
		}
	}
	else if (state == TOUCHED) {
		//DrawRectangleRec(buttonShape, colorBoxTouched);
		DrawRectangleRounded(buttonShape, roundness, segments, colorBoxTouched);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextTouched);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerTouched);
			DrawRectangleRoundedLines(buttonShape, roundness, segments, 4, colorCornerClicked);
		}
	}
	else if (state == CLICKED) {
		//DrawRectangleRec(buttonShape, colorBoxClicked);
		DrawRectangleRounded(buttonShape, roundness, segments, colorBoxClicked);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextClicked);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerClicked);
			DrawRectangleRoundedLines(buttonShape, roundness, segments, 4, colorCornerClicked);
		}
	}
	
}

int Button::getState() {
	if (CheckCollisionPointRec(GetMousePosition(), buttonShape)) {
		if (state == CLICKED && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			return state = RELEASED;
		}
		else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			return state = CLICKED;
		}
		else {
			return state = TOUCHED;
		}
	}
	return state = DEFAULT;
}