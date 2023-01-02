#ifndef DM3_EVENTS_KEY_EVENT_HPP
#define DM3_EVENTS_KEY_EVENT_HPP

#include "events.hpp"
#include <util/event.hpp>
#include <sstream>

namespace dm3 {

class keyEvent : public dm3Event {
public:

    inline int getKeyCode() const { return m_keyCode; }

protected:

    keyEvent(const int& t_keyCode) : m_keyCode(t_keyCode) {}

    int m_keyCode;
};

class keyPressEvent : public keyEvent {
public:

    // * key pressed event constructor
    keyPressEvent(int t_keycode, int t_repeteCount) : keyEvent(t_keycode), m_repeteCount(t_repeteCount) {}

    // * repete count getter
    inline int getRepeteCount() const { return m_repeteCount; }

    // * implimentation of the toString method
    std::string toString() const override
    {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeteCount << " repeats)";
        return ss.str();
    }

    // * impliments all pure virtual functions
    // * impliments with type as eventType::keyPressed
    // * impliments functions getEventType() and getName() aswell as creating getStaticType()
    EVENT_CLASS_TYPE(dm3::dm3EventTypes, keyPressed)

private:

    // * store the ammount the key press was done
    int m_repeteCount;
};

class keyTypedEvent : public keyEvent
{
public:

    // * key pressed event constructor
    keyTypedEvent(int t_keycode) : keyEvent(t_keycode) {}

    // * implimentation of the toString method
    std::string toString() const override
    {
        std::stringstream ss;
        ss << "KeyTypedEvent: " << m_keyCode;
        return ss.str();
    }

    // * impliments all pure virtual functions
    // * impliments with type as eventType::keyPressed
    // * impliments functions getEventType() and getName() aswell as creating getStaticType()
    EVENT_CLASS_TYPE(dm3::dm3EventTypes, keyTyped);
};

class keyReleasedEvent : public keyEvent
{
public:

    // * key releaseted event constructor
    keyReleasedEvent(int t_keycode) : keyEvent(t_keycode) {}

    // * implimentation of the toString method
    std::string toString() const override
    {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << m_keyCode;
        return ss.str();
    }

    // * impliments all pure virtual functions
    // * impliments with type as eventType::keyPressed
    // * impliments functions getEventType() and getName() aswell as creating getStaticType()
    EVENT_CLASS_TYPE(dm3::dm3EventTypes, keyReleased);
};

}

#endif
