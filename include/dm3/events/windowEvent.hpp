#ifndef DM3_EVENTS_WINDOW_EVENT_HPP
#define DM3_EVENTS_WINDOW_EVENT_HPP

#include <sstream>
#include <util/event.hpp>
#include <glm/glm.hpp>
#include "events.hpp"

namespace dm3 {

class windowClosedEvent : public dm3Event {
public:

    windowClosedEvent() {}

    EVENT_CLASS_TYPE(dm3EventTypes, windowClosed)
};

class windowMinimizedEvent : public dm3Event {
public:

    windowMinimizedEvent() {}

    EVENT_CLASS_TYPE(dm3EventTypes, windowMinimized)
};

class windowMaximizedEvent : public dm3Event {
public:

    windowMaximizedEvent() {}

    EVENT_CLASS_TYPE(dm3EventTypes, windowMaximized)
};

class windowRestoredEvent : public dm3Event {
public:

    windowRestoredEvent() {}

    EVENT_CLASS_TYPE(dm3EventTypes, windowRestored)
};

class windowFocusedEvent : public dm3Event {
public:

    windowFocusedEvent() {}

    EVENT_CLASS_TYPE(dm3EventTypes, windowFocus)
};

class windowLostFocusEvent : public dm3Event {
public:

    windowLostFocusEvent() {}

    EVENT_CLASS_TYPE(dm3EventTypes, windowLostFocus)
};

class windowUpdateEvent : public dm3Event {
public:
    windowUpdateEvent(double t_deltaTime) : m_deltaTime(t_deltaTime) {}

    inline double getDataTime() { return m_deltaTime; }

    EVENT_CLASS_TYPE(dm3EventTypes, onUpdate)

private:

    double m_deltaTime;
};

class onAttachEvent : public dm3Event {
public:

    EVENT_CLASS_TYPE(dm3EventTypes, onAttach)
};

class onDetachEvent : public dm3Event {
public:

    EVENT_CLASS_TYPE(dm3EventTypes, onDetach)
};


class windowMovedEvent : public dm3Event {
public:

    windowMovedEvent(const glm::vec2& t_winPos) : m_windowPos(t_winPos) {}

    inline glm::vec2 getWindowPos() const { return m_windowPos; } 

    std::string toString() const override {
        std::stringstream ss;
        ss << "windowMovedEvent: " << "{" << m_windowPos.x << ", " << m_windowPos.y << "}";
        return ss.str();
    }

    EVENT_CLASS_TYPE(dm3::dm3EventTypes, windowMoved)

private:

    glm::vec2 m_windowPos;
};


class windowResizeEvent : public dm3Event {
public:

    windowResizeEvent(const glm::vec2& t_size) : m_windowSize(t_size) {}

    inline glm::vec2 getWindowSize() const { return m_windowSize; } 

    std::string toString() const override {
        std::stringstream ss;
        ss << "windowResizeEvent: " << "{" << m_windowSize.x << ", " << m_windowSize.y << "}";
        return ss.str();
    }

    EVENT_CLASS_TYPE(dm3::dm3EventTypes, windowResize)

private:

    glm::vec2 m_windowSize;
};

}

#endif
