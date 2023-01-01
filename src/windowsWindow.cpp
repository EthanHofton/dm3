#include <dm3/concrete/windowsWindow.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_WINDOWS

std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<WindowsWindow>(t_props);
}

WindowsWindow::WindowsWindow(const window::windowProps& t_props) : window(t_props) { throw "windows not impl yet"; }
WindowsWindow::~WindowsWindow() {}

void WindowsWindow::setWidth(const int& t_width) {
    m_props.m_width = t_width; 
}
void WindowsWindow::setHeight(const int& t_height) {
    m_props.m_height = t_height; 
}
void WindowsWindow::setTitle(const std::string& t_title) {
    m_props.m_title = t_title; 
}

#endif

}
