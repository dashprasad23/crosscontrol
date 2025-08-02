#ifdef __APPLE__

#include <iostream>
#include <map>
#include <string>
#include <ApplicationServices/ApplicationServices.h>
#include "../mouse.h"

void getPixelColor(int x, int y, int &r, int &g, int &b) {
    CGImageRef image = CGDisplayCreateImageForRect(CGMainDisplayID(), CGRectMake(x, y, 1, 1));
    if (!image) return;

    CFDataRef data = CGDataProviderCopyData(CGImageGetDataProvider(image));
    const UInt8 *bytes = CFDataGetBytePtr(data);
    r = bytes[0];
    g = bytes[1];
    b = bytes[2];

    CFRelease(data);
    CGImageRelease(image);
}

#endif