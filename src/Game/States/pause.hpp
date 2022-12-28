#ifndef SRC_GAME_STATES_PAUSE
#define SRC_GAME_STATES_PAUSE
#include "../../Framework/pch.hpp"

class PauseState : public Engine::State
{
public:
    PauseState(Engine::Context::pointer_type context);

    void handleEvent(const sf::Event &ev);
    void update(sf::Time dt);
    void draw();

private:
    sf::Text _pause;

    Engine::Context::pointer_type _context;
};

#endif /* SRC_GAME_STATES_PAUSE */
