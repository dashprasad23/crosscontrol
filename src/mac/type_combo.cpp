#ifdef __APPLE__

#include <iostream>
#include <map>
#include <string>
#include <ApplicationServices/ApplicationServices.h>
#include "../mouse.h"

void typeKey(const char* key, bool isKeyDown) {
    static std::map<std::string, CGKeyCode> keyMap = {
        {"a", 0}, {"s", 1}, {"d", 2}, {"f", 3}, {"h", 4}, {"g", 5}, {"z", 6}, {"x", 7}, {"c", 8}, {"v", 9},
        {"b", 11}, {"q", 12}, {"w", 13}, {"e", 14}, {"r", 15}, {"y", 16}, {"t", 17},
        {"1", 18}, {"2", 19}, {"3", 20}, {"4", 21}, {"6", 22}, {"5", 23}, {"equal", 24}, {"9", 25}, {"7", 26},
        {"minus", 27}, {"8", 28}, {"0", 29}, {"rightbracket", 30}, {"o", 31}, {"u", 32}, {"leftbracket", 33},
        {"i", 34}, {"p", 35}, {"l", 37}, {"j", 38}, {"quote", 39}, {"k", 40}, {"semicolon", 41}, {"backslash", 42},
        {"comma", 43}, {"slash", 44}, {"n", 45}, {"m", 46}, {"period", 47}, {"tab", 48}, {"space", 49},
        {"return", 36}, {"delete", 51}, {"escape", 53}, {"ctrl", 59}, {"shift", 56}, {"alt", 58}, {"cmd", 55}
    };

    CGKeyCode code = keyMap.count(key) ? keyMap[key] : 0;
    CGEventRef evt = CGEventCreateKeyboardEvent(NULL, code, isKeyDown);
    CGEventPost(kCGHIDEventTap, evt);
    CFRelease(evt);
}

void typeKey(const char* key) {
    typeKey(key, true);
    typeKey(key, false);
}

void typeCombo(const char** keys, int count) {
    for (int i = 0; i < count; i++) {
        typeKey(keys[i], true);  // press
    }
    for (int i = count - 1; i >= 0; i--) {
        typeKey(keys[i], false); // release
    }
}

#endif