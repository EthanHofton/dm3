#include <dm3/platform/windowsWindow.hpp>
#include <dm3/windowDrivers/windowDriverGLFW.hpp>
#include <dm3/windowDrivers/windowDriverSDL.hpp>
#include <dm3/windowDrivers/windowDriverCocoa.hpp>

#ifdef DM3_PLATFORM_WINDOWS

namespace dm3 {


std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<WindowsWindow>(t_props);
}

WindowsWindow::WindowsWindow(const window::windowProps& t_props) : window(t_props, 
#if defined(USE_WIN32)
    std::make_shared<windowDriverWIN32>()
#elif defined(USE_SDL)
    std::make_shared<windowDriverSDL>()
#else
    std::make_shared<windowDriverGLFW>()
#endif
) {}
WindowsWindow::~WindowsWindow() {}

}

#endif

