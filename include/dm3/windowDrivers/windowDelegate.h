#ifndef DM3_WINDOWDRIVERS_WINDOW_DELEGATE_HPP
#define DM3_WINDOWDRIVERS_WINDOW_DELEGATE_HPP

#include <dm3/core/platformDetect.hpp>

#ifdef USE_COCOA

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@interface WindowDelegate : NSObject<NSWindowDelegate>

-(BOOL) windowShouldClose:(NSWindow*)sender;
-(id)init:(void*)_windowData isRunning:(bool*)t_running;

@property void* windowData;
@property bool* running;

@end

#endif

#endif
