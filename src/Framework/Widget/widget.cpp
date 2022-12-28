#include "widget.hpp"

namespace GUI
{
    Widget::Widget() : _focus(false), _activate(false) {}

    bool Widget::isFocused() const { return _focus; }

    void Widget::focusOn() { _focus = true; }
    void Widget::focusOff() { _focus = false; }

    bool Widget::isActive() const { return _activate; }
    void Widget::activeOn() { _activate = true; }
    void Widget::activeOff() { _activate = false; }

    void setCenterOrigin(sf::Transformable &object, const sf::FloatRect &local_bound)
    {
        object.setOrigin(getCenter(local_bound));
    }

    void setCenterPosition(sf::Transformable &object, const sf::FloatRect &global_bound)
    {
        object.setPosition(getCenter(global_bound));
    }

    sf::Vector2f getCenter(const sf::FloatRect &object)
    {
        return {object.left + object.width / 2.0f,
                object.top + object.height / 2.0f};
    }
}
