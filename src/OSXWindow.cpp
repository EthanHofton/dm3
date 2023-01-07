#include <dm3/platform/OSXWindow.hpp>
#include <dm3/windowDrivers/windowDriverGLFW.hpp>
#include <dm3/windowDrivers/windowDriverSDL.hpp>
#include <dm3/windowDrivers/windowDriverCocoa.hpp>

#ifdef DM3_PLATFORM_OSX

namespace dm3 {

std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<OSXWindow>(t_props);
}

OSXWindow::OSXWindow(const window::windowProps& t_props) : window(t_props, 
#if defined(USE_COCOA)
    std::make_shared<windowDriverCocoa>()
#elif defined(USE_SDL)
    std::make_shared<windowDriverSDL>()
#else
    std::make_shared<windowDriverGLFW>()
#endif
                                                                  ) {}

OSXWindow::~OSXWindow() {}

}

#endif
