#ifndef SRC_INCLUDE_FRAMEWORK_ENGINE_STATE_STATE
#define SRC_INCLUDE_FRAMEWORK_ENGINE_STATE_STATE
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>

namespace Engine
{
    class State
    {
    public:
        typedef std::unique_ptr<State> pointer_type;

        virtual ~State() = default;

        /**
         * Prerequisite task of a state
         */

        virtual void handleEvent(const sf::Event& ev) = 0;
        virtual void update(sf::Time dt) = 0;
        virtual void draw() = 0;
    };
}

#endif /* SRC_INCLUDE_FRAMEWORK_ENGINE_STATE_STATE */
