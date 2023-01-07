#ifndef DM3_WINDOWDRIVERS_WINDOW_DRIVER_GLFW_HPP
#define DM3_WINDOWDRIVERS_WINDOW_DRIVER_GLFW_HPP

#include "windowDriver.hpp"
#include <dm3/core/platformDetect.hpp>
#include <dm3/events/windowEvent.hpp>
#include <dm3/events/keyEvents.hpp>
#include <dm3/events/mouseEvent.hpp>

#ifdef USE_GLFW

#include <GLFW/glfw3.hpp>

namespace dm3 {

class windowDriverGLFW : public windowDriver {
public:

    windowDriverGLFW();
    virtual ~windowDriverGLFW() override;

    virtual void createWindow(const int& t_width, const int& t_size, const std::string& t_title) override;
    virtual void destroyWindow() override;

    virtual void preRender() override;
    virtual void postRender() override;
    
    virtual bool shouldCloseWindow() const override;

    // * window setters
    virtual void setWindowSize(const glm::vec2& t_size) override;
    virtual void setWindowPos(const glm::vec2& t_pos) override;
    virtual void setWindowTitle(const std::string& t_title) override;
    virtual void setWindowIcon(const std::string& t_iconFile) override;
    virtual void setWindowSwapInterval(const int& t_swapInterval) override;
    
    // * window getters
    virtual glm::vec2 getWindowSize() const override;
    virtual glm::vec2 getWindowPos() const override;

    virtual void minimizeWindow() override;
    virtual void maximizeWindow() override;
    virtual void restoreWindow() override;
    virtual void focusWindow() override;

    virtual int keyCodeToDM3(const int& t_keyCode) const override;
    virtual int mouseCodeToDM3(const int& t_mouseCode) const override;

private:

    GLFWwindow* m_window = nullptr;

};

}

#endif

#endif
