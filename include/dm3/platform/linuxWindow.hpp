#ifndef DM3_PLATFORM_LINUX_WINDOW_HPP
#define DM3_PLATFORM_LINUX_WINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>

#ifdef DM3_PLATFORM_LINUX

namespace dm3 {

class LinuxWindow : public window {
public:

    ~LinuxWindow() override;
    LinuxWindow(const window::windowProps& t_props);
};

}

#endif

#endif
