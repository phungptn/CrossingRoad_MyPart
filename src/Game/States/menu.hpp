#ifndef SRC_GAME_STATES_MENU
#define SRC_GAME_STATES_MENU
#include "../../Framework/pch.hpp"

#include <array>

class MenuState : public Engine::State
{
public:
    MenuState(Engine::Context::pointer_type context);
    
    void handleEvent(const sf::Event& ev);
    void update(sf::Time dt);
    void draw();

private:
    sf::Sprite _sprite;
    sf::Text _title;

    sf::Music _theme;

    std::array<std::unique_ptr<GUI::Button>, 3> _buttons;
    int _current_btn;

    Engine::Context::pointer_type _context;
};

#endif /* SRC_GAME_STATES_MENU */
