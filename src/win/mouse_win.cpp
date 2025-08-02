#ifdef _WIN32

#include <windows.h>
#include <map>
#include <string>
#include "../mouse.h"

void moveMouse(int x, int y) {
    SetCursorPos(x, y);
}

void clickMouse() {
    INPUT input[2] = {};
    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    input[1].type = INPUT_MOUSE;
    input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(2, input, sizeof(INPUT));
}

void getMousePosition(int &x, int &y) {
    POINT pt;
    GetCursorPos(&pt);
    x = pt.x;
    y = pt.y;
}

void getPixelColor(int x, int y, int &r, int &g, int &b) {
    HDC hdc = GetDC(NULL);
    COLORREF color = GetPixel(hdc, x, y);
    ReleaseDC(NULL, hdc);
    r = GetRValue(color);
    g = GetGValue(color);
    b = GetBValue(color);
}

void rightClickMouse() {
    INPUT input[2] = {};
    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    input[1].type = INPUT_MOUSE;
    input[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(2, input, sizeof(INPUT));
}

void middleClickMouse() {
    INPUT input[2] = {};
    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
    input[1].type = INPUT_MOUSE;
    input[1].mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
    SendInput(2, input, sizeof(INPUT));
}

// Helper function to map key names to virtual key codes
WORD keyToVK(const std::string &key) {
    static std::map<std::string, WORD> keyMap = {
        {"a", 0x41}, {"b", 0x42}, {"c", 0x43}, {"d", 0x44}, {"e", 0x45},
        {"f", 0x46}, {"g", 0x47}, {"h", 0x48}, {"i", 0x49}, {"j", 0x4A},
        {"k", 0x4B}, {"l", 0x4C}, {"m", 0x4D}, {"n", 0x4E}, {"o", 0x4F},
        {"p", 0x50}, {"q", 0x51}, {"r", 0x52}, {"s", 0x53}, {"t", 0x54},
        {"u", 0x55}, {"v", 0x56}, {"w", 0x57}, {"x", 0x58}, {"y", 0x59},
        {"z", 0x5A}, {"0", 0x30}, {"1", 0x31}, {"2", 0x32}, {"3", 0x33},
        {"4", 0x34}, {"5", 0x35}, {"6", 0x36}, {"7", 0x37}, {"8", 0x38},
        {"9", 0x39}, {"space", VK_SPACE}, {"enter", VK_RETURN},
        {"ctrl", VK_CONTROL}, {"shift", VK_SHIFT}, {"alt", VK_MENU},
        {"tab", VK_TAB}, {"escape", VK_ESCAPE}, {"backspace", VK_BACK}
    };

    return keyMap.count(key) ? keyMap[key] : 0;
}

void typeKey(const char* key, bool isKeyDown) {
    WORD vk = keyToVK(key);
    if (!vk) return;

    INPUT input = {};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vk;
    input.ki.dwFlags = isKeyDown ? 0 : KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void typeKey(const char* key) {
    typeKey(key, true);
    typeKey(key, false);
}

void typeCombo(const char** keys, int count) {
    for (int i = 0; i < count; i++) {
        typeKey(keys[i], true);
    }
    for (int i = count - 1; i >= 0; i--) {
        typeKey(keys[i], false);
    }
}

#endif
