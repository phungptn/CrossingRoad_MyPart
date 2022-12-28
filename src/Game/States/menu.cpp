#include "menu.hpp"

#include "playing.hpp"

#include <iostream>

MenuState::MenuState(Engine::Context::pointer_type context)
    : _context(context),
      _title("Crossing Road", context->fonts->get(FONT_LIST::MAIN_FONT), 60),
      _current_btn(-1)
{
    _title.setOutlineColor(sf::Color::Black);
    _title.setOutlineThickness(5);
    _title.setString("Crossing Road");
    _title.setOrigin(_title.getLocalBounds().left + _title.getLocalBounds().width / 2,
                     _title.getLocalBounds().top + _title.getLocalBounds().height / 2);
    _title.setPosition(_context->window->getView().getCenter().x,
                       _context->window->getView().getCenter().y - 250.f);
    _sprite.setTexture(_context->textures->get(TEXTURE_LIST::WELCOME_SCREEN));

    assert(_theme.openFromFile("assets/sounds/intro.wav"));

    sf::Vector2u size = _context->window->getSize();

    _sprite.setScale(
        size.x / _sprite.getLocalBounds().width,
        size.y / _sprite.getLocalBounds().height);

    for (std::unique_ptr<GUI::Button> &ptr : _buttons)
        ptr = std::make_unique<GUI::Button>(context);

    _buttons[0]->setText("PLAY");
    _buttons[0]->setHoverColor(sf::Color(255, 219, 62));
    _buttons[0]->setPosition(_context->window->getView().getCenter() - sf::Vector2f(0, 100.f));
    _buttons[0]->setCallback(
        [this]()
        {
            _context->states->insert(std::make_unique<PlayingState>(_context));
            // _theme.pause();
        });

    _buttons[1]->setText("LOAD");
    _buttons[1]->setHoverColor(sf::Color(111, 225, 62));
    _buttons[1]->setPosition(_context->window->getView().getCenter());
    _buttons[1]->setCallback([]()
                             { std::cout << "Load button pressed!" << std::endl; });

    _buttons[2]->setText("EXIT");
    _buttons[2]->setHoverColor(sf::Color(226, 16, 16));
    _buttons[2]->setPosition(_context->window->getView().getCenter() + sf::Vector2f(0, 100.f));
    _buttons[2]->setCallback([this]()
                             { _context->states->remove(); });

    // _theme.setLoop(true);
    // _theme.play();
}

void MenuState::handleEvent(const sf::Event &ev)
{
    int i, size = _buttons.size();

    sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(*_context->window));

    switch (ev.type)
    {
    case sf::Event::MouseMoved:
        for (i = 0; i < size; i++)
            if (_buttons[i]->isInWidget(pos))
                _current_btn = i;
        break;
    case sf::Event::MouseButtonPressed:
        if (ev.mouseButton.button == sf::Mouse::Left)
        {
            if (_current_btn >= 0 &&
                _buttons[_current_btn]->isInWidget(pos))
            {
                _buttons[_current_btn]->activeOn();
            }
        }
        break;
    case sf::Event::KeyPressed:
        switch (ev.key.code)
        {
        case sf::Keyboard::Down:
        case sf::Keyboard::S:
            _current_btn = (_current_btn + 1) % size;
            break;
        case sf::Keyboard::Up:
        case sf::Keyboard::W:
            if (_current_btn == -1)
                _current_btn = size - 1;
            else
            {
                --_current_btn;
                if (_current_btn < 0)
                    _current_btn += size;
            }
            break;
        case sf::Keyboard::Enter:
            if (_current_btn != -1)
            {
                _buttons[_current_btn]->activeOn();
            }
        default:
            break;
        }
    }
}

void MenuState::update(sf::Time dt)
{
    int i, size = _buttons.size();

    for (i = 0; i < size; i++)
    {
        if (i == _current_btn)
            _buttons[i]->focusOn();
        else
            _buttons[i]->focusOff();
    }
}

void MenuState::draw()
{
    _context->window->draw(_sprite);
    _context->window->draw(_title);

    for (std::unique_ptr<GUI::Button> &ptr : _buttons)
        _context->window->draw(*ptr);
}
