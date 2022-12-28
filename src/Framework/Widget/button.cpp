#include "button.hpp"

#include "../Util/identifier.hpp"

namespace GUI
{
    Button::Button(Engine::Context::pointer_type context)
        : _font(context->fonts->get(FONT_LIST::BUTTON_FONT))
    {
        _bound.setFillColor(sf::Color::Transparent);
        _text.setFont(_font);
        _text.setOutlineThickness(5.f);
        _text.setOutlineColor(sf::Color::Black);
        _text.setCharacterSize(55U);
    }

    bool Button::isSelectable() const { return true; }

    void Button::focusOn()
    {
        Widget::focusOn();
        _text.setFillColor(_color);
    }

    void Button::focusOff()
    {
        Widget::focusOff();
        _text.setFillColor(sf::Color::White);
    }

    void Button::activeOn()
    {
        Widget::activeOn();

        if (_callback)
            _callback();

        activeOff();
    }

    void Button::activeOff()
    {
        Widget::activeOff();

        _text.setFillColor(isFocused() ? _color : sf::Color::White);
    }

    void Button::setCallback(Callback callback)
    {
        _callback = std::move(callback);
    }

    void Button::setText(std::string text)
    {
        _text.setString(std::move(text));
        _bound.setSize({_text.getGlobalBounds().width, _text.getGlobalBounds().height});
    }

    void Button::setHoverColor(sf::Color color)
    {
        _color = std::move(color);
    }

    void Button::setPosition(const sf::Vector2f &position)
    {
        _pos = std::move(position);
        setCenterOrigin(_bound, _bound.getLocalBounds());
        _bound.setPosition(_pos);
        _centerButton();
    }

    sf::Vector2f Button::getSize() const
    {
        return _bound.getSize();
    }

    bool Button::isInWidget(const sf::Vector2f &position) const
    {
        return _bound.getGlobalBounds().contains(position);
    }

    void Button::_centerButton()
    {
        setCenterOrigin(_text, _text.getLocalBounds());
        setCenterPosition(_text, _bound.getGlobalBounds());
    }

    void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        target.draw(_bound, states);
        target.draw(_text, states);
    }
}
