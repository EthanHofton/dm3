#include <dm3/platform/linuxWindow.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_LINUX
#ifdef DM3_GLFW_COMPATIBLE

std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<LinuxWindow>(t_props);
}

LinuxWindow::LinuxWindow(const window::windowProps& t_props) : window(t_props, std::make_shared<windowDriverGLFW>()) {}
LinuxWindow::~LinuxWindow() {}

#endif
#endif

}
