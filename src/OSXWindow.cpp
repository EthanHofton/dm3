#include <dm3/platform/OSXWindow.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_OSX
#ifdef DM3_GLFW_COMPATIBLE

std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<OSXWindow>(t_props);
}

OSXWindow::OSXWindow(const window::windowProps& t_props) : window(t_props, std::make_shared<windowDriverGLFW>()) {}
OSXWindow::~OSXWindow() {}

#endif
#endif

}
