#ifndef DM3_CORE_WINDOWSWINDOW_HPP
#define DM3_CORE_WINDOWSWINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_WINDOWS

class WindowsWindow : public window {
public:

    ~WindowsWindow();
    WindowsWindow(const window::windowProps& t_props);

    void setWidth(const int& t_width);
    void setHeight(const int& t_height);
    void setTitle(const std::string& t_title);

};

#endif

}

#endif
