#ifndef DM3_PLATFORM_WINDOWS_WINDOW_HPP
#define DM3_PLATFORM_WINDOWS_WINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>
#include <dm3/windowDrivers/windowDriverGLFW.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_WINDOWS
#ifdef DM3_GLFW_COMPATIBLE

class WindowsWindow : public window {
public:

    ~WindowsWindow() override;
    WindowsWindow(const window::windowProps& t_props);
};

#endif
#endif

}

#endif
