#include "playing.hpp"

#include "pause.hpp"

PlayingState::PlayingState(Engine::Context::pointer_type context)
    : _context(context),
      _testing("In playing state", context->fonts->get(FONT_LIST::MAIN_FONT), 30U)
{
    sf::FloatRect size(sf::Vector2f(0.f, 0.f), sf::Vector2f(context->window->getSize()));

    GUI::setCenterOrigin(_testing, _testing.getLocalBounds());
    GUI::setCenterPosition(_testing, size);
}

void PlayingState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed &&
        ev.key.code == sf::Keyboard::P)
        _context->states->insert(std::make_unique<PauseState>(_context));
}

void PlayingState::update(sf::Time dt) {}

void PlayingState::draw()
{
    _context->window->draw(_testing);
}

void PlayingState::pause_game()
{
}
