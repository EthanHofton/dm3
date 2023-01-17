#include <dm3/core/window.hpp>
#include <dm3/events/windowEvent.hpp>

namespace dm3
{

window::window(const windowProps& t_props, std::shared_ptr<windowDriver> t_driver) : m_driver(t_driver) {
    m_driver->createWindow(t_props.m_width, t_props.m_height, t_props.m_title);
}

window::~window() {
    m_driver->destroyWindow();
}

void window::run() {
    while (!m_driver->shouldCloseWindow()) {

        m_timer.tick();

        // * lock to FPS
        if (m_timer.getDeltaTime() >= 1.0 / m_fps) {
            m_timer.reset();

            // * clear framebuffers
            // * clear color
            
            // * loop though layer stack

            // * imgui layer stuff

            // * call on window update
            windowUpdateEvent e;
            m_driver->sendEvent(e);
        }

        // * pre-render
        m_driver->preRender();

        // * render
        
        // * post render
        m_driver->postRender();
    }
}

}
