#ifndef OTHER_H
#define OTHER_H

#include "raylib.h"
#include <iostream>
#include <vector>
#include <random>
//// avoid conflicts with Windows.h near and far
//#if defined(_WIN32)           
//#define NOGDI // All GDI defines and routines
//#define NOUSER // All USER defines and routines
//#endif
//#include <Windows.h> // or any library that uses Windows.h
//#if defined(_WIN32) // raylib uses these names as function parameters
//#undef near
//#undef far
//#endif
//#include <exception>
//#include <stdexcept>
//#include <ostream>

using namespace std;

// center text
Vector2 GetCenterPos(Font font, string text, float fontSize, float spacing, float x, float y, float width, float height);
Vector2 GetCenterPos(Font font, string text, float fontSize, float spacing, Rectangle rect);
// draw text on box, return the position of the last character
Vector2 DrawTextOnBox(Rectangle boxShape, Font font, string text, Vector2 coord, float fontSize, float spacing, float lineGap, Color colorText);
float DrawTextOnBoxEx(Rectangle boxShape, Font font, vector<string> &text, Vector2 coord, float fontSize, float spacing, float lineGap, float paraGap, Color colorText);
int RandInt(int min, int max);
//class RaiiClipboard
//{
//public:
//  RaiiClipboard()
//  {
//    if (! OpenClipboard(nullptr))
//      throw runtime_error("Can't open clipboard.");
//      // ... or define some custom exception class for clipboard errors.
//  }
//
//  ~RaiiClipboard()
//  {
//    CloseClipboard();
//  }
//
//  // Ban copy   
//private:
//  RaiiClipboard(const RaiiClipboard&);
//  RaiiClipboard& operator=(const RaiiClipboard&);
//};
//
//class RaiiTextGlobalLock
//{
//public:
//  explicit RaiiTextGlobalLock(HANDLE hData)
//    : m_hData(hData)
//  {
//    m_psz = static_cast<const char*>(GlobalLock(m_hData));
//    if (! m_psz)
//      throw runtime_error("Can't acquire lock on clipboard text.");  
//  }
//
//  ~RaiiTextGlobalLock()
//  {
//    GlobalUnlock(m_hData);
//  }
//
//  const char* Get() const
//  { 
//    return m_psz;
//  }
//
//private:
//  HANDLE m_hData;
//  const char* m_psz;
//
//  // Ban copy
//  RaiiTextGlobalLock(const RaiiTextGlobalLock&);
//  RaiiTextGlobalLock& operator=(const RaiiTextGlobalLock&);
//};
//
//string GetClipboardText()
//{
//  RaiiClipboard clipboard;
//
//  HANDLE hData = GetClipboardData(CF_TEXT);
//  if (hData == nullptr)
//    throw runtime_error("Can't get clipboard text.");
//
//  RaiiTextGlobalLock textGlobalLock(hData);
//  string text( textGlobalLock.Get() );
//
//  return text;
//}
#endif