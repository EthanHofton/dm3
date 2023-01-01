#ifndef DM3_CORE_WINDOW_HPP
#define DM3_CORE_WINDOW_HPP

#include <string>
#include <memory>

namespace dm3 {

class window {
public: 

    struct windowProps {
        std::string m_title;
        int m_width;
        int m_height;

        windowProps(const std::string& t_title = "untitled", const int& t_width = 500, const int& t_height = 500) 
        : m_title(t_title), m_width(t_width), m_height(t_height) {}
    };

    static std::shared_ptr<window> createWindow(const windowProps& t_props = windowProps());

protected:

    window(const windowProps& t_props) : m_props(t_props) {}

public:

    virtual ~window() {}

    inline int getWidth()  const { return m_props.m_width; }
    inline int getHeight() const { return m_props.m_width; }
    inline int getTitle()  const { return m_props.m_width; }

    virtual void setWidth(const int& t_width) = 0;
    virtual void setHeight(const int& t_height) = 0;
    virtual void setTitle(const std::string& t_title) = 0;

protected:

    windowProps m_props;
};

}

#endif
