#ifndef DM3_PLATFORM_WINDOWS_WINDOW_HPP
#define DM3_PLATFORM_WINDOWS_WINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>

#ifdef DM3_PLATFORM_WINDOWS

namespace dm3 {

class WindowsWindow : public window {
public:

    ~WindowsWindow() override;
    WindowsWindow(const window::windowProps& t_props);
};

}

#endif

#endif
