#ifndef SRC_FRAMEWORK_WIDGET_WIDGET
#define SRC_FRAMEWORK_WIDGET_WIDGET
#include <SFML/Graphics.hpp>

#include "../State/state.hpp"
#include "../Util/context.hpp"

namespace GUI
{
    class Widget : public sf::Drawable,
                   public sf::Transformable,
                   private sf::NonCopyable
    {
    public:
        Widget();

        /**
         * Position of the widget
         */

        virtual void setPosition(const sf::Vector2f &position) = 0;
        virtual sf::Vector2f getSize() const = 0;
        virtual bool isInWidget(const sf::Vector2f &position) const = 0;

        virtual bool isSelectable() const = 0;

    protected:
        bool isFocused() const;
        virtual void focusOn();
        virtual void focusOff();

        virtual bool isActive() const;
        virtual void activeOn();
        virtual void activeOff();

    private:
        bool _focus, _activate;
    };

    void setCenterOrigin(sf::Transformable &, const sf::FloatRect &);
    void setCenterPosition(sf::Transformable &, const sf::FloatRect &);

    sf::Vector2f getCenter(const sf::FloatRect &);
}

#endif /* SRC_FRAMEWORK_WIDGET_WIDGET */
