#ifndef DM3_PLATFORM_LINUX_WINDOW_HPP
#define DM3_PLATFORM_LINUX_WINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>
#include <dm3/windowDrivers/windowDriverGLFW.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_LINUX
#ifdef DM3_GLFW_COMPATIBLE

class LinuxWindow : public window {
public:

    ~LinuxWindow() override;
    LinuxWindow(const window::windowProps& t_props);
};

#endif
#endif

}

#endif
