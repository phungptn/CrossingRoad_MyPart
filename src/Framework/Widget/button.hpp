#ifndef SRC_FRAMEWORK_WIDGET_BUTTON
#define SRC_FRAMEWORK_WIDGET_BUTTON
#include "widget.hpp"

#include <functional>

namespace GUI
{
    class Button : public Widget
    {
    public:
        typedef std::function<void(void)> Callback;

        Button(Engine::Context::pointer_type context);

        void setCallback(Callback callback);

        void setText(std::string text);

        void setHoverColor(sf::Color color);

        void setPosition(const sf::Vector2f &position);

        sf::Vector2f getSize() const;
        bool isInWidget(const sf::Vector2f &position) const;

        bool isSelectable() const;

        void focusOn();
        void focusOff();

        void activeOn();
        void activeOff();

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        void _centerButton();

        sf::Vector2f _pos;
        sf::RectangleShape _bound;
        sf::Text _text;
        sf::Font _font;
        sf::Color _color;
        Callback _callback;

        Engine::Context::pointer_type _context;
    };
}

#endif /* SRC_FRAMEWORK_WIDGET_BUTTON */
