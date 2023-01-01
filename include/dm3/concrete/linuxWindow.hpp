#ifndef DM3_CORE_LINUXWINDOW_HPP
#define DM3_CORE_LINUXWINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_LINUX

class LinuxWindow : public window {
public:

    ~LinuxWindow();
    LinuxWindow(const window::windowProps& t_props);

    void setWidth(const int& t_width);
    void setHeight(const int& t_height);
    void setTitle(const std::string& t_title);

};

#endif

}

#endif

