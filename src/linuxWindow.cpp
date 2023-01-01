#include <dm3/concrete/linuxWindow.hpp>

namespace dm3 {

#ifdef DM3_PLATFORM_LINUX

std::shared_ptr<window> window::createWindow(const windowProps& t_props) {
    return std::make_shared<LinuxWindow>(t_props);
}

LinuxWindow::LinuxWindow(const window::windowProps& t_props) : window(t_props) { throw "linux not impl yet"; }
LinuxWindow::~LinuxWindow() {}

void LinuxWindow::setWidth(const int& t_width) {
    m_props.m_width = t_width; 
}
void LinuxWindow::setHeight(const int& t_height) {
    m_props.m_height = t_height; 
}
void LinuxWindow::setTitle(const std::string& t_title) {
    m_props.m_title = t_title; 
}

#endif

}
