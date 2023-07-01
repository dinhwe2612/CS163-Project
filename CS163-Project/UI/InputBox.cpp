#include "InputBox.h"

void InputBox::Construct(float x, float y, float width, float height, Font _font, Vector2 _coordText, int _szText, float _spacing, int _MAX_SIZE) {
	inputShape = { x, y, width, height };
	font = _font;
	coordText = _coordText;
	szText = _szText;
	spacing = _spacing;
	MAX_SIZE = _MAX_SIZE;
}

void InputBox::SetColorBox(Color colorDefault, Color colorTouched, Color colorTyping) {
	colorBoxDefault = colorDefault;
	colorBoxTouched = colorTouched;
	colorBoxTyping = colorTyping;
}

void InputBox::SetColorText(Color colorDefault, Color colorTouched, Color colorTyping) {
	colorTextDefault = colorDefault;
	colorTextTouched = colorTouched;
	colorTextTyping = colorTyping;
}

void InputBox::Draw() {
	static int timeline = 0;

	timeline += 60;
	if (timeline > 6000) timeline = 0;

	// add | to the end of currentInput
	bool add = false;

	// check if the input box is clicked
	isTyping ^= isClicked();
	
	if (isTyping) {
		int key = GetCharPressed();
		while (key >= 32 && key <= 126 && currentInput.length() < MAX_SIZE) {
			currentInput += (char)key;
			key = GetCharPressed();
			add = true;
		}
		key = GetKeyPressed();
		while (key == KEY_BACKSPACE && currentInput.length() > 0) {
			currentInput.pop_back();
			key = GetKeyPressed();
			add = true;
		}
	}
	if (isTyping && (add || timeline <= 3000)) {
		currentInput += "|";
		add = true;
	}

	if (getState() == DEFAULT) {
		DrawRectangleRec(inputShape, colorBoxDefault);
		DrawTextEx(font, currentInput.c_str(), { coordText.x, coordText.y }, szText, spacing, colorTextDefault);
	}
	else if (getState() == TOUCHED) {
		DrawRectangleRec(inputShape, colorBoxTouched);
		DrawTextEx(font, currentInput.c_str(), { coordText.x, coordText.y }, szText, spacing, colorTextTouched);
	}
	else if (getState() == TYPING) {
		DrawRectangleRec(inputShape, colorBoxTyping);
		DrawTextEx(font, currentInput.c_str(), { coordText.x, coordText.y }, szText, spacing, colorTextTyping);
	}

	if (add) {
		currentInput.pop_back();
	}
}

bool InputBox::isClicked() {
	if (CheckCollisionPointRec(GetMousePosition(), inputShape)) {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			return true;
		}
	}
	return false;
}

void InputBox::reset() {
	currentInput = "";
	isTyping = false;
}

int InputBox::getState() {
	if (CheckCollisionPointRec(GetMousePosition(), inputShape)) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			return TYPING;
		}
		else {
			return TOUCHED;
		}
	}
	return DEFAULT;
}