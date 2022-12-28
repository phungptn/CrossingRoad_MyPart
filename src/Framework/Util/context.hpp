#ifndef SRC_FRAMEWORK_UTIL_CONTEXT
#define SRC_FRAMEWORK_UTIL_CONTEXT
#include <SFML/Graphics.hpp>

#include "../Asset/manager.hpp"
#include "../State/manager.hpp"

#include <memory>

enum class TEXTURE_LIST;
enum class FONT_LIST;

namespace Engine
{
    struct Context
    {
        typedef std::shared_ptr<Context> pointer_type;

        std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>();
        std::unique_ptr<States_Machine> states = std::make_unique<States_Machine>();
        std::unique_ptr<Media_Machine<TEXTURE_LIST, sf::Texture>> textures 
            = std::make_unique<Media_Machine<TEXTURE_LIST, sf::Texture>>();
        std::unique_ptr<Media_Machine<FONT_LIST, sf::Font>> fonts 
            = std::make_unique<Media_Machine<FONT_LIST, sf::Font>>();
    };
}

#endif /* SRC_FRAMEWORK_UTIL_CONTEXT */
