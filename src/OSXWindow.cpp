#include <dm3/concrete/OSXWindow.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_OSX

std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<OSXWindow>(t_props);
}

OSXWindow::OSXWindow(const window::windowProps& t_props) : window(t_props) {}
OSXWindow::~OSXWindow() {}

void OSXWindow::setWidth(const int& t_width) {
    m_props.m_width = t_width; 
}
void OSXWindow::setHeight(const int& t_height) {
    m_props.m_height = t_height; 
}
void OSXWindow::setTitle(const std::string& t_title) {
    m_props.m_title = t_title; 
}

#endif

}
