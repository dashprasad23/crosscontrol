#ifdef __APPLE__

#include <iostream>
#include <map>
#include <string>
#include <ApplicationServices/ApplicationServices.h>
#include "../mouse.h"

void getMousePosition(int &x, int &y) {
    CGPoint pt = CGEventGetLocation(CGEventCreate(NULL));
    x = static_cast<int>(pt.x);
    y = static_cast<int>(pt.y);
}

#endif