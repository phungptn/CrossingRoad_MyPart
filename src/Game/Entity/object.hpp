#ifndef SRC_GAME_ENTITY_OBJECT
#define SRC_GAME_ENTITY_OBJECT
#include <SFML/Graphics.hpp>

struct Object : public sf::Drawable,
                public sf::Transformable,
                private sf::NonCopyable
{
    typedef std::unique_ptr<Object> pointer_type;

    virtual void update(sf::Time dt) = 0;
    virtual void handleEvent(const sf::Event &v) = 0;
};

#endif /* SRC_GAME_ENTITY_OBJECT */
