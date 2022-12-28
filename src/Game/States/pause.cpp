#include "pause.hpp"

PauseState::PauseState(Engine::Context::pointer_type context)
    : _context(context),
      _pause("Paused", context->fonts->get(FONT_LIST::MAIN_FONT), 30U)
{
    sf::FloatRect size(sf::Vector2f(0.f, 0.f), sf::Vector2f(context->window->getSize()));

    GUI::setCenterOrigin(_pause, _pause.getLocalBounds());
    GUI::setCenterPosition(_pause, size);
}

void PauseState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed &&
        ev.key.code == sf::Keyboard::P)
        _context->states->remove();
}

void PauseState::update(sf::Time dt) {}
void PauseState::draw()
{
    _context->window->draw(_pause);
}
