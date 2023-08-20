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

void Button::DrawText(int &mouseCursor) {
	int state = getState();
	Rectangle currentShape = buttonShape;
	if (isZoom) {
		if (state == DEFAULT) {

		}
		else if (state == TOUCHED) {
			currentShape.x -= 0.01 * buttonShape.width;
			currentShape.y -= 0.01 * buttonShape.height;
			currentShape.width *= 1.02;
			currentShape.height *= 1.02;
		}
		else if (state == CLICKED || state == RELEASED) {
			currentShape.x += 0.02 * buttonShape.width;
			currentShape.y += 0.02 * buttonShape.height;
			currentShape.width *= 0.96;
			currentShape.height *= 0.96;
		}
	}
	if (state == DEFAULT) {
		//DrawRectangleRec(buttonShape, colorBoxDefault);
		DrawRectangleRounded(currentShape, roundness, segments, colorBoxDefault);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextDefault);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerDefault);
			DrawRectangleRoundedLines(currentShape, roundness, segments, 4, colorCornerClicked);
		}
	}
	else if (state == TOUCHED) {
		//DrawRectangleRec(buttonShape, colorBoxTouched);
		DrawRectangleRounded(currentShape, roundness, segments, colorBoxTouched);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextTouched);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerTouched);
			DrawRectangleRoundedLines(currentShape, roundness, segments, 4, colorCornerClicked);
		}
		if (setMouse) {
			mouseCursor = MOUSE_CURSOR_POINTING_HAND;
		}
	}
	else if (state == CLICKED || state == RELEASED) {
		//DrawRectangleRec(buttonShape, colorBoxClicked);
		DrawRectangleRounded(currentShape, roundness, segments, colorBoxClicked);
		DrawTextEx(font, Text.c_str(), coordText, fontSize, spacing, colorTextClicked);
		if (drawCorner) {
			//DrawRectangleLinesEx(buttonShape, 4, colorCornerClicked);
			DrawRectangleRoundedLines(currentShape, roundness, segments, 4, colorCornerClicked);
		}
		if (setMouse) {
			mouseCursor = MOUSE_CURSOR_POINTING_HAND;
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