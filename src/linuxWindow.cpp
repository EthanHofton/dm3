#include <dm3/platform/linuxWindow.hpp>
#include <dm3/windowDrivers/windowDriverGLFW.hpp>
#include <dm3/windowDrivers/windowDriverSDL.hpp>
#include <dm3/windowDrivers/windowDriverCocoa.hpp>

#ifdef DM3_PLATFORM_LINUX

namespace dm3 {

std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<LinuxWindow>(t_props);
}

LinuxWindow::LinuxWindow(const window::windowProps& t_props) : window(t_props, 
#if defined(USE_SDL)
    std::make_shared<windowDriverSDL>()
#else
    std::make_shared<windowDriverGLFW>()
#endif
                                                                      ) {}
LinuxWindow::~LinuxWindow() {}

}

#endif
