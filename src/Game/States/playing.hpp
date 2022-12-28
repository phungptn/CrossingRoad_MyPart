#ifndef SRC_GAME_STATES_PLAYING
#define SRC_GAME_STATES_PLAYING
#include "../../Framework/pch.hpp"

class PlayingState : public Engine::State
{
public:
    PlayingState(Engine::Context::pointer_type context);

    void handleEvent(const sf::Event& ev);
    void update(sf::Time dt);
    void draw();

private:
    void pause_game();

    Engine::Context::pointer_type _context;

    sf::Text _testing;
};

#endif /* SRC_GAME_STATES_PLAYING */
