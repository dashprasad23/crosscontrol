// mouse.h
#ifndef MOUSE_H
#define MOUSE_H

void moveMouse(int x, int y);
void clickMouse();
void getMousePosition(int &x, int &y);
void typeKey(const char* key);                    // original
void typeKey(const char* key, bool isKeyDown);    // new overload
void getPixelColor(int x, int y, int &r, int &g, int &b);
void rightClickMouse();
void middleClickMouse();
void typeCombo(const char** keys, int count);

#endif