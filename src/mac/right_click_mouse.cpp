#ifdef __APPLE__

#include <iostream>
#include <map>
#include <string>
#include <ApplicationServices/ApplicationServices.h>
#include "../mouse.h"

void rightClickMouse() {
    CGPoint pt = CGEventGetLocation(CGEventCreate(NULL));
    CGEventRef down = CGEventCreateMouseEvent(NULL, kCGEventRightMouseDown, pt, kCGMouseButtonRight);
    CGEventRef up = CGEventCreateMouseEvent(NULL, kCGEventRightMouseUp, pt, kCGMouseButtonRight);
    CGEventPost(kCGHIDEventTap, down);
    CGEventPost(kCGHIDEventTap, up);
    CFRelease(down);
    CFRelease(up);
}

#endif