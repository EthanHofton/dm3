#ifndef DM3_EVENTS_EVENTS_HPP
#define DM3_EVENTS_EVENTS_HPP

#include <util/event.hpp>

namespace dm3 {

enum class dm3EventTypes {
    windowClosed, windowMoved, windowResize, windowFocus, windowLostFocus, // * window events
    windowMinimized, windowMaximized, windowRestored,

    onTick, onUpdate, onDraw, onAppBegin, onAppEnd,                       // * dm3 app events
    keyPressed, keyTyped, keyReleased,                                    // * key events
    mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseScrolled    // * mouse events
};

using dm3Event = util::event<dm3EventTypes>;

}

#endif
