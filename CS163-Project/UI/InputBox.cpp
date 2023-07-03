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
	if (timeline > 5000) timeline = 0;

	// add | to the end of currentInput
	bool add = false;

	// check if the input box is clicked
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (CheckCollisionPointRec(GetMousePosition(), inputShape)) {
			isTyping = true;
			add = true;
			timeline = 0;
		} else {
			isTyping = false;
		}
	}
	
	if (isTyping) {
		// for typing
		int key = GetCharPressed();
		if (key >= 32 && key <= 126 && currentInput.length() < MAX_SIZE) {
			currentInput.insert(posCursor++, 1, key);
			add = true;
			timeline = 0;
		}
		int key2 = GetKeyPressed();
		// for arrow keys
		key2 = (IsKeyDown(KEY_LEFT) && timeline % 540 == 0 ? KEY_LEFT : key2);
		if (key2 == KEY_LEFT && posCursor > 0) {
			posCursor--;
			add = true;
			timeline = 0;
		}
		key2 = (IsKeyDown(KEY_RIGHT) && timeline % 540 == 0 ? KEY_RIGHT : key2);
		if (key2 == KEY_RIGHT && posCursor < currentInput.length()) {
			posCursor++;
			add = true;
			timeline = 0;
		}
		// for backspace
		key2 = (IsKeyDown(KEY_BACKSPACE) && timeline % 540 == 0 ? KEY_BACKSPACE : key2);
		if (key2 == KEY_BACKSPACE && currentInput.length() > 0 && posCursor) {
			currentInput.erase(--posCursor, 1);
			if (posCursor < 0) posCursor = 0;
			add = true;
			timeline = 0;
		}
		// for delete
		key2 = (IsKeyDown(KEY_DELETE) && timeline % 540 == 0 ? KEY_DELETE : key2);
		if (key2 == KEY_DELETE && currentInput.length() > 0 && posCursor < currentInput.length()) {
			currentInput.erase(posCursor, 1);
			add = true;
			timeline = 0;
		}
	}
	if (isTyping && (add || timeline <= 2500)) {
		currentInput.insert(posCursor, "|");
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
		currentInput.erase(posCursor, 1);
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