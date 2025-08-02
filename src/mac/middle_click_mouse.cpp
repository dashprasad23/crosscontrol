#ifdef __APPLE__

#include <iostream>
#include <map>
#include <string>
#include <ApplicationServices/ApplicationServices.h>
#include "../mouse.h"

void middleClickMouse() {
    CGPoint pt = CGEventGetLocation(CGEventCreate(NULL));
    CGEventRef down = CGEventCreateMouseEvent(NULL, kCGEventOtherMouseDown, pt, kCGMouseButtonCenter);
    CGEventRef up = CGEventCreateMouseEvent(NULL, kCGEventOtherMouseUp, pt, kCGMouseButtonCenter);
    CGEventPost(kCGHIDEventTap, down);
    CGEventPost(kCGHIDEventTap, up);
    CFRelease(down);
    CFRelease(up);
}

#endif