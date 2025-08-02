#ifdef __APPLE__

#include <iostream>
#include <map>
#include <string>
#include <ApplicationServices/ApplicationServices.h>
#include "../mouse.h"

void clickMouse() {
    std::cout << "Clicking mouse" << std::endl;
    CGPoint pt = CGEventGetLocation(CGEventCreate(NULL));
    CGEventRef down = CGEventCreateMouseEvent(NULL, kCGEventLeftMouseDown, pt, kCGMouseButtonLeft);
    CGEventRef up = CGEventCreateMouseEvent(NULL, kCGEventLeftMouseUp, pt, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, down);
    CGEventPost(kCGHIDEventTap, up);
    CFRelease(down);
    CFRelease(up);
}

#endif