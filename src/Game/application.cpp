#include "application.hpp"

#include "States/loading.hpp"

Application::Application()
    : _context(std::make_shared<Engine::Context>())
{
    _context->window->create(sf::VideoMode(900, 900), "Snake Game", sf::Style::Close);

    assert(_frame_font.loadFromFile("assets/fonts/Sansation.ttf"));

    _frame_test.setFont(_frame_font);
    _frame_test.setPosition(5.f, 5.f);
    _frame_test.setCharacterSize(10u);
    _frame_test.setFillColor(sf::Color::Red);

    sf::Image icon;
    assert(icon.loadFromFile("assets/icon.png"));
    _context->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    _context->states->insert(std::make_unique<LoadingState>(_context));
}

void Application::start() { _gameLoop(); }

Application::~Application() { _context->window->close(); }

void Application::_gameLoop()
{
    sf::Clock clock;
    sf::Time last_update = sf::Time::Zero;
    sf::Event ev;

    _context->window->setKeyRepeatEnabled(false);

    while (_context->window->isOpen())
    {
        _context->states->handleMachine();

        if (_context->states->isEmpty())
            break;

        last_update += clock.restart();
        while (last_update > TIME_PER_FRAME)
        {
            last_update -= TIME_PER_FRAME;

            while (_context->window->pollEvent(ev))
            {
                if (ev.type == sf::Event::Closed)
                    _context->states->clear();
                _context->states->current()->handleEvent(ev);
            }

            _context->states->current()->update(TIME_PER_FRAME);
            // _updateTest(TIME_PER_FRAME);
        }

        _render();
    }
}

void Application::_render()
{
    _context->window->clear();
    _context->states->current()->draw();
    // _context->window->draw(_frame_test);
    _context->window->display();
}

void Application::_updateTest(sf::Time dt)
{
    _time += dt;
    _frame += 1;
    if (_time >= sf::seconds(1.f))
    {
        _frame_test.setString("FPS: " + std::to_string(_frame));
        _time -= sf::seconds(1.f);
        _frame = 0;
    }
}
