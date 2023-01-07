#ifndef DM3_WINDOW_DRIVERS_WINDOW_DRIVER_HPP
#define DM3_WINDOW_DRIVERS_WINDOW_DRIVER_HPP

#include <dm3/events/events.hpp>
#include <dm3/events/mouseEvent.hpp>
#include <dm3/events/keyEvents.hpp>
#include <dm3/events/windowEvent.hpp>
#include <functional>
#include <glm/glm.hpp>
#include <string>

namespace dm3 {

class windowDriver {
public:
    using callbackFn = std::function<void(dm3Event&)>;

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

    // * mappings
    virtual int keyCodeToDM3(const int& t_keyCode) const = 0;
    virtual int mouseCodeToDM3(const int& t_mouseCode) const = 0;

    inline void setEventFunction(callbackFn t_eventFn) { m_driverData.m_eventFn = t_eventFn; }

public:

    struct driverData {
        windowDriver& m_windowDriver;
        const std::function<int(const int&)> keyToDM3= std::bind(&windowDriver::keyCodeToDM3, &m_windowDriver, std::placeholders::_1);
        const std::function<int(const int&)> mouseToDM3= std::bind(&windowDriver::mouseCodeToDM3, &m_windowDriver, std::placeholders::_1);
        glm::vec2 m_lastMousePos;
        bool m_firstMouseMove;
        callbackFn m_eventFn = [](dm3Event&){};
        driverData(windowDriver& t_this) : m_windowDriver(t_this) {}
    };

protected:

     driverData m_driverData = driverData(*this);

};

}

#endif

