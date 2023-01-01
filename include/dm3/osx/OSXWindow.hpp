#ifndef DM3_CORE_OSXWINDOW_HPP
#define DM3_CORE_OSXWINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_OSX

class OSXWindow : public window {
public:

    ~OSXWindow();
    OSXWindow(const window::windowProps& t_props);

    void setWidth(const int& t_width);
    void setHeight(const int& t_height);
    void setTitle(const std::string& t_title);

};

#endif

}

#endif
