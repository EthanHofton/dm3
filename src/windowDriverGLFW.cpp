#include <dm3/core/logging.hpp>
#include <dm3/stb/stb_image.h>
#include <dm3/windowDrivers/windowDriverGLFW.hpp>
#include <memory>

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

    GLFWInitalization() {
        DM3_INFO("created glfw instance");
    }
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

std::shared_ptr<GLFWInitalization> GLFWInitalization::s_instance =
    std::make_shared<GLFWInitalization>();

windowDriverGLFW::windowDriverGLFW() {
    DM3_INFO("creating GLFW driver");
}
windowDriverGLFW::~windowDriverGLFW() {
    DM3_INFO("deleting GLFW driver");
}

void windowDriverGLFW::createWindow(const int &t_width, const int &t_height,
                                    const std::string &t_title) {
    GLFWInitalization::safeInit();

    DM3_INFO("Creating window {}", t_title);
    m_window = glfwCreateWindow(t_width, t_height, t_title.c_str(), NULL, NULL);

    if (!m_window) {
        DM3_CRITICAL("failed to create window {}", t_title);
        throw "failed to create window";
    }

    DM3_INFO("Created window {}", t_title);

    // * setup all event functions
    glfwSetWindowUserPointer(m_window, &m_driverData);

    // * window resize callback
    glfwSetWindowSizeCallback(
    m_window, [](GLFWwindow *t_window, int t_width, int t_height) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);

        windowResizeEvent e({t_width, t_height});
        data.m_eventFn(e);
    });

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow *t_window) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);

        windowClosedEvent e;
        data.m_eventFn(e);
    });

    glfwSetWindowPosCallback(
    m_window, [](GLFWwindow *t_window, int t_x, int t_y) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);

        windowMovedEvent e({t_x, t_y});
        data.m_eventFn(e);
    });

    glfwSetWindowFocusCallback(m_window, [](GLFWwindow *t_window, int t_focused) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);

        if (t_focused) {
            // * window moved into focus
            windowFocusedEvent e;
            data.m_eventFn(e);
        } else {
            // * window moved out of focus
            windowLostFocusEvent e;
            data.m_eventFn(e);
        }
    });

    glfwSetWindowMaximizeCallback(
    m_window, [](GLFWwindow *t_window, int t_maximized) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);

        if (t_maximized) {
            // * window maximized
            windowMaximizedEvent e;
            data.m_eventFn(e);
        } else {
            // * window restored
            windowRestoredEvent e;
            data.m_eventFn(e);
        }
    });

    glfwSetWindowIconifyCallback(
    m_window, [](GLFWwindow *t_window, int t_iconified) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);

        if (t_iconified) {
            // * window maximized
            windowMinimizedEvent e;
            data.m_eventFn(e);
        } else {
            // * window restored
            windowRestoredEvent e;
            data.m_eventFn(e);
        }
    });

    glfwSetKeyCallback(m_window, [](GLFWwindow *t_window, int t_key,
    int t_scancode, int t_action, int t_mods) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);
        t_key = data.keyToDM3(t_key);
        switch (t_action) {
            case GLFW_PRESS: {
                keyPressEvent e(t_key, 0);
                data.m_eventFn(e);
                break;
            }
            case GLFW_RELEASE: {
                keyReleasedEvent e(t_key);
                data.m_eventFn(e);
                break;
            }
            case GLFW_REPEAT: {
                keyPressEvent e(t_key, 1);
                data.m_eventFn(e);
                break;
            }
        }
    });

    glfwSetCharCallback(m_window, [](GLFWwindow *t_window, unsigned int t_char) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);
        keyTypedEvent e(t_char);
        data.m_eventFn(e);
    });

    glfwSetMouseButtonCallback(m_window, [](GLFWwindow *t_window, int t_button, int t_action, int t_mods) {
        driverData &data = *(driverData *)glfwGetWindowUserPointer(t_window);
        t_button = data.mouseToDM3(t_button);
        switch (t_action) {
            case GLFW_PRESS: {
                mouseButtonPressedEvent e(t_button);
                data.m_eventFn(e);
                break;
            }
            case GLFW_RELEASE: {
                mouseButtonReleasedEvent e(t_button);
                data.m_eventFn(e);
                break;
            }
        }
    });

    glfwSetScrollCallback(m_window, [](GLFWwindow *t_window, double t_x, double t_y) {
        driverData &wdata = *(driverData*)glfwGetWindowUserPointer(t_window);
        mouseScrolledEvent e({t_x, t_y});
        wdata.m_eventFn(e);
    });

    glfwSetCursorPosCallback(m_window, [](GLFWwindow *t_window, double t_x, double t_y) {
        driverData &wdata = *(driverData*)glfwGetWindowUserPointer(t_window);
        if (wdata.m_firstMouseMove)
        {
            wdata.m_lastMousePos = {t_x, t_y};
            wdata.m_firstMouseMove = false;
        }

        glm::vec2 mousePosOffset = {t_x - wdata.m_lastMousePos.x, wdata.m_lastMousePos.y - t_y};
        wdata.m_lastMousePos = {t_x, t_y};

        // * create a mouse scroll event
        mouseMovedEvent event({t_x, t_y}, mousePosOffset);
        // * run the window event callback function with the created event
        wdata.m_eventFn(event);
    });
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

bool windowDriverGLFW::shouldCloseWindow() const {
    return glfwWindowShouldClose(m_window);
}
void windowDriverGLFW::setWindowSize(const glm::vec2 &t_size) {
    glfwSetWindowSize(m_window, t_size.x, t_size.y);
}
void windowDriverGLFW::setWindowPos(const glm::vec2 &t_pos) {
    glfwSetWindowPos(m_window, t_pos.x, t_pos.y);
}
void windowDriverGLFW::setWindowTitle(const std::string &t_title) {
    glfwSetWindowTitle(m_window, t_title.c_str());
}
void windowDriverGLFW::setWindowIcon(const std::string &t_iconFile) {
    GLFWimage images[1];
    images[0].pixels = stbi_load(t_iconFile.c_str(), &images[0].width,
                                 &images[0].height, 0, 4); // rgba channels
    glfwSetWindowIcon(m_window, 1, images);
    stbi_image_free(images[0].pixels);
}
void windowDriverGLFW::setWindowSwapInterval(const int &t_swapInterval) {
    glfwSwapInterval(t_swapInterval);
}
glm::vec2 windowDriverGLFW::getWindowSize() const {
    glm::ivec2 size;
    glfwGetWindowSize(m_window, &size.x, &size.y);
    return size;
}
glm::vec2 windowDriverGLFW::getWindowPos() const {
    glm::ivec2 pos;
    glfwGetWindowPos(m_window, &pos.x, &pos.y);
    return pos;
}
void windowDriverGLFW::minimizeWindow() {
    glfwMaximizeWindow(m_window);
}
void windowDriverGLFW::maximizeWindow() {
    glfwIconifyWindow(m_window);
}
void windowDriverGLFW::restoreWindow() {
    glfwRestoreWindow(m_window);
}
void windowDriverGLFW::focusWindow() {
    glfwFocusWindow(m_window);
}
int windowDriverGLFW::keyCodeToDM3(const int &t_keyCode) const {
    return t_keyCode;
}
int windowDriverGLFW::mouseCodeToDM3(const int &t_mouseCode) const {
    return t_mouseCode;
}

#endif

} // namespace dm3
