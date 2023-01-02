#include <dm3/core/window.hpp>

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
        // * pre-render
        m_driver->preRender();

        // * render
        
        // * post render
        m_driver->postRender();
    }
}

}
