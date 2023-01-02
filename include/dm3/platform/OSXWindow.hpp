#ifndef DM3_PLATFORM_OSX_WINDOW_HPP
#define DM3_PLATFORM_OSX_WINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>
#include <dm3/windowDrivers/windowDriverGLFW.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_OSX
#ifdef DM3_GLFW_COMPATIBLE

class OSXWindow : public window {
public:

    ~OSXWindow() override;
    OSXWindow(const window::windowProps& t_props);
};

#endif
#endif

}

#endif
