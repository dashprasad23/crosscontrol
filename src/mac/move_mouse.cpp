#ifdef __APPLE__

#include <iostream>
#include <map>
#include <string>
#include <ApplicationServices/ApplicationServices.h>
#include "../mouse.h"

void moveMouse(int x, int y) {
    std::cout << "Moving mouse to: " << x << ", " << y << std::endl;
    CGPoint pt = CGPointMake(x, y);
    CGEventRef move = CGEventCreateMouseEvent(NULL, kCGEventMouseMoved, pt, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, move);
    CFRelease(move);
}

#endif