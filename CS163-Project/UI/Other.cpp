#include "Other.h"
#include <sstream>
Vector2 GetCenterPos(Font font, string text, float fontSize, float spacing, float x, float y, float width, float height) {
	Vector2 centerPos;
	centerPos.x = x + (width - MeasureTextEx(font, text.c_str(), fontSize, spacing).x) / 2;
	centerPos.y = y + (height - MeasureTextEx(font, text.c_str(), fontSize, spacing).y) / 2;
	return centerPos;
}

Vector2 GetCenterPos(Font font, string text, float fontSize, float spacing, Rectangle rect) {
	return GetCenterPos(font, text, fontSize, spacing, rect.x, rect.y, rect.width, rect.height);
}

Vector2 DrawTextOnBox(Rectangle boxShape, Font font, string text, Vector2 coord, float fontSize, float spacing, float lineGap, Color colorText) {
	float x = coord.x, y = coord.y;
	float limitX = boxShape.x + boxShape.width;
	float limitY = boxShape.y + boxShape.height;
	stringstream ss(text);
	string line = "", word;
	Vector2 size;
	while (ss >> word) {
		size = MeasureTextEx(font, line.c_str(), fontSize, spacing);
		Vector2 wordSize = MeasureTextEx(font, word.c_str(), fontSize, spacing);
		if (x + size.x + wordSize.x > limitX) {
			DrawTextEx(font, line.c_str(), { x, y }, fontSize, spacing, colorText);
			x = boxShape.x;
			y += lineGap;
			line = word + " ";
		}
		else {
			line += word + " ";
		}
		if (y + size.y > limitY) {
			return { x, y };
		}
	}
	DrawTextEx(font, line.c_str(), { x, y }, fontSize, spacing, colorText);
	
	return { x + MeasureTextEx(font, line.c_str(), fontSize, spacing).x, y };
}

float DrawTextOnBoxEx(Rectangle boxShape, Font font, vector<string> &text, Vector2 coord, float fontSize, float spacing, float lineGap, float paraGap, Color colorText) {
	 float y = coord.y;
	 for (int i = 1; i < text.size(); i++) {
		 Vector2 pos = DrawTextOnBox(boxShape, font, to_string(i) + ". " + text[i], {coord.x, y}, fontSize, spacing, lineGap, colorText);
		 y = pos.y + paraGap;
	 }
	 return y;
}

int RandInt(int min, int max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(min, max);
	return dist(mt);
}

string PartialText(Font font, string text, float fontSize, float spacing, float width) {
	if (MeasureTextEx(font, text.c_str(), fontSize, spacing).x <= width) {
		return text;
	}
	string line = "";
	for (char& c : text) {
		if (MeasureTextEx(font, (line + c + "...").c_str(), fontSize, spacing).x > width) {
			return line + "...";
		}
		line += c;
	}
	return line + "...";
}