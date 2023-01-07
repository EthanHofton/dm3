#ifndef DM3_PLATFORM_OSX_WINDOW_HPP
#define DM3_PLATFORM_OSX_WINDOW_HPP

#include <dm3/core/window.hpp>
#include <dm3/core/platformDetect.hpp>

#ifdef DM3_PLATFORM_OSX

namespace dm3 {

class OSXWindow : public window {
public:

    ~OSXWindow() override;
    OSXWindow(const window::windowProps& t_props);
};

}

#endif

#endif
