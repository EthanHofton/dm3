#ifndef DM3_WINDOW_DRIVERS_WINDOW_DRIVER_HPP
#define DM3_WINDOW_DRIVERS_WINDOW_DRIVER_HPP

#include <glm/glm.hpp>
#include <string>

namespace dm3 {

class windowDriver {
public:

    inline virtual ~windowDriver() {}

    virtual void createWindow(const int& t_width, const int& t_height, const std::string& t_title) = 0;
    virtual void destroyWindow() = 0;

    virtual void preRender() = 0;
    virtual void postRender() = 0;
    
    virtual bool shouldCloseWindow() const = 0;

    // * window setters
    virtual void setWindowSize(const glm::vec2& t_size) = 0;
    virtual void setWindowPos(const glm::vec2& t_pos) = 0;
    virtual void setWindowTitle(const std::string& t_title) = 0;
    virtual void setWindowIcon(const std::string& t_iconFile) = 0;
    virtual void setWindowSwapInterval(const int& t_swapInterval) = 0;

    // * window getters
    virtual glm::vec2 getWindowSize() const = 0;
    virtual glm::vec2 getWindowPos() const = 0;

    virtual void minimizeWindow() = 0;
    virtual void maximizeWindow() = 0;
    virtual void restoreWindow() = 0;
    virtual void focusWindow() = 0;
};

}

#endif

