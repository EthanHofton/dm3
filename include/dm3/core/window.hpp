#ifndef DM3_CORE_WINDOW_HPP
#define DM3_CORE_WINDOW_HPP

#include <functional>
#include <string>
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <dm3/windowDrivers/windowDriver.hpp>
#include <util/event.hpp>
#include <util/timer.hpp>

namespace dm3 {

class window {
public: 

    struct windowProps {
        std::string m_title;
        int m_width;
        int m_height;

        windowProps(const std::string& t_title = "untitled", const int& t_width = 500, const int& t_height = 500) 
        : m_title(t_title), m_width(t_width), m_height(t_height) {}
    };

    static std::shared_ptr<window> createWindow(const windowProps& t_props = windowProps());

protected:

    window(const windowProps& t_props, std::shared_ptr<windowDriver> t_driver);

public:

    virtual ~window();

    void run();
    void onEvent(dm3Event& t_event);

    inline void setWindowSize(const glm::vec2& t_size) { m_driver->setWindowSize(t_size); }
    inline void setWindowPos(const glm::vec2& t_pos) { m_driver->setWindowPos(t_pos); }
    inline void setWindowTitle(const std::string& t_title) { m_driver->setWindowTitle(t_title); }
    inline void setWindowIcon(const std::string& t_iconFile) { m_driver->setWindowIcon(t_iconFile); }
    inline void setWindowSwapInterval(const int& t_swapInterval) { m_driver->setWindowSwapInterval(t_swapInterval); }
    inline void setFPS(const int& t_fps) { m_fps = t_fps; }

    inline glm::vec2 getWindowSize() const { return m_driver->getWindowSize(); }
    inline glm::vec2 getWindowPos() const { return m_driver->getWindowPos(); }
    inline float getFPS() const { return m_fps; }

    inline void maxamizeWindow() { m_driver->maximizeWindow(); }
    inline void minamizeWindow() { m_driver->minimizeWindow(); }
    inline void restoreWindow() { m_driver->restoreWindow(); }
    inline void focusWindow() { m_driver->focusWindow(); }

    // * event layers
    inline void pushEventLayer(windowDriver::callbackFn t_callback) { onAttachEvent e; t_callback(e); m_eventFns.push_back(t_callback); }
    template<typename T> inline void pushEventClassLayer(T t_instance) { pushEventLayer(std::bind(&T::onEvent, t_instance, std::placeholders::_1)); }

    inline void pushEventOverlay(windowDriver::callbackFn t_callback) { onAttachEvent e; t_callback(e); m_eventFns.insert(m_eventFns.begin(), t_callback); }
    template<typename T> inline void pushEventClassOverlay(T t_instance) { pushEventOverlay(std::bind(&T::onEvent, t_instance, std::placeholders::_1)); }

protected:

    std::shared_ptr<windowDriver> m_driver;
    std::vector<windowDriver::callbackFn> m_eventFns;
    float m_fps = 120.0f;

private:

    util::manual_timer m_timer;
};

}

#endif
