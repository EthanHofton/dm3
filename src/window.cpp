#include <dm3/core/window.hpp>
#include <dm3/events/windowEvent.hpp>

namespace dm3
{

window::window(const windowProps& t_props, std::shared_ptr<windowDriver> t_driver) : m_driver(t_driver) {
    m_driver->setEventFunction(std::bind(&window::onEvent, this, std::placeholders::_1));
    m_driver->createWindow(t_props.m_width, t_props.m_height, t_props.m_title);
}

window::~window() {
    for (auto it = m_eventFns.begin(); it != m_eventFns.end();) {
        onDetachEvent e;
        (*it++)(e);
    }

    m_driver->destroyWindow();
}

void window::onEvent(dm3Event& t_event) {
    for (auto it = m_eventFns.begin(); it != m_eventFns.end();) {
        (*it++)(t_event);

        if (t_event.handled()) {
            break;
        }
    }
}

void window::run() {
    while (!m_driver->shouldCloseWindow()) {

        m_timer.tick();

        // * lock to FPS
        if (m_timer.getDeltaTime() >= 1.0 / m_fps) {
            m_timer.reset();

            // * pre-render
            m_driver->preRender();

            // * clear framebuffers
            // * clear color
            
            // * loop though layer stack

            // * imgui layer stuff

            // * call on window update
            windowUpdateEvent e(m_timer.getDeltaTime());
            m_driver->sendEvent(e);

            // * post render
            m_driver->postRender();
        }
    }
}

}
