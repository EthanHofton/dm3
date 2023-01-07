#ifndef DM3_WINDOWDRIVERS_WINDOW_DRIVER_SDL_HPP
#define DM3_WINDOWDRIVERS_WINDOW_DRIVER_SDL_HPP

#include "windowDriver.hpp"
#include <dm3/core/platformDetect.hpp>

#ifdef DM3_SDL_COMPATIBLE

namespace dm3 {

class windowDriverSDL : public windowDriver {
public:

    windowDriverSDL();
    virtual ~windowDriverSDL() override;

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

private:
};

}

#endif

#endif
