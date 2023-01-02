#include <dm3/windowDrivers/windowDriverGLFW.hpp>
#include <dm3/core/logging.hpp>
#include <memory>
#include <dm3/stb/stb_image.h>

namespace dm3 {

#ifdef DM3_GLFW_COMPATIBLE

struct GLFWInitalization {

    static std::shared_ptr<GLFWInitalization> s_instance;
    static void safeInit() {
        if (!s_instance->m_initalized) {
            if (!glfwInit()) {
                DM3_CRITICAL("failed to initlaize glfw");
                throw "failed to initalize glfw";
            }
            DM3_INFO("initlaized glfw");
            s_instance->m_initalized = true;
        }
    }

    GLFWInitalization() { DM3_INFO("created glfw instance"); }
    ~GLFWInitalization() {
        if (m_initalized) {
            DM3_INFO("terminated glfw");
            glfwTerminate();
        }

        DM3_INFO("delete glfw instance");
    }

private:

    bool m_initalized = false;
    
};

std::shared_ptr<GLFWInitalization> GLFWInitalization::s_instance = std::make_shared<GLFWInitalization>();

windowDriverGLFW::windowDriverGLFW() { DM3_INFO("creating GLFW driver"); }
windowDriverGLFW::~windowDriverGLFW() { DM3_INFO("deleting GLFW driver"); }

void windowDriverGLFW::createWindow(const int& t_width, const int& t_height, const std::string& t_title) {
    GLFWInitalization::safeInit();

    DM3_INFO("Creating window {}", t_title);
    m_window = glfwCreateWindow(t_width, t_height, t_title.c_str(), NULL, NULL);

    if (!m_window) {
        DM3_CRITICAL("failed to create window {}", t_title);
        throw "failed to create window";
    }

    DM3_INFO("Created window {}", t_title);
}

void windowDriverGLFW::destroyWindow() {
    DM3_INFO("Destroying window...");
    if (m_window) {
        glfwDestroyWindow(m_window);
    }
    DM3_INFO("Destroyed window");
}

void windowDriverGLFW::preRender() {}
void windowDriverGLFW::postRender() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

bool windowDriverGLFW::shouldCloseWindow() const { return glfwWindowShouldClose(m_window); }
void windowDriverGLFW::setWindowSize(const glm::vec2& t_size) { glfwSetWindowSize(m_window, t_size.x, t_size.y); }
void windowDriverGLFW::setWindowPos(const glm::vec2& t_pos) { glfwSetWindowPos(m_window, t_pos.x, t_pos.y); }
void windowDriverGLFW::setWindowTitle(const std::string& t_title) { glfwSetWindowTitle(m_window, t_title.c_str()); }
void windowDriverGLFW::setWindowIcon(const std::string& t_iconFile) {
    GLFWimage images[1]; 
    images[0].pixels = stbi_load(t_iconFile.c_str(), &images[0].width, &images[0].height, 0, 4); //rgba channels 
    glfwSetWindowIcon(m_window, 1, images); 
    stbi_image_free(images[0].pixels);
}
void windowDriverGLFW::setWindowSwapInterval(const int& t_swapInterval) { glfwSwapInterval(t_swapInterval); }
glm::vec2 windowDriverGLFW::getWindowSize() const { glm::ivec2 size; glfwGetWindowSize(m_window, &size.x, &size.y); return size; }
glm::vec2 windowDriverGLFW::getWindowPos() const { glm::ivec2 pos; glfwGetWindowPos(m_window, &pos.x, &pos.y); return pos; }
void windowDriverGLFW::minimizeWindow() { glfwMaximizeWindow(m_window); }
void windowDriverGLFW::maximizeWindow() { glfwIconifyWindow(m_window); }
void windowDriverGLFW::restoreWindow() { glfwRestoreWindow(m_window); }
void windowDriverGLFW::focusWindow() { glfwFocusWindow(m_window); }

#endif

}
