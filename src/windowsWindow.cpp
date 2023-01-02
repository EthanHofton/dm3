#include <dm3/platform/windowsWindow.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_WINDOWS
#ifdef DM3_GLFW_COMPATIBLE

std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<WindowsWindow>(t_props);
}

WindowsWindow::WindowsWindow(const window::windowProps& t_props) : window(t_props, std::make_shared<windowDriverGLFW>()) {}
WindowsWindow::~WindowsWindow() {}

#endif
#endif

}

