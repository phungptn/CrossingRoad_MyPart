#ifndef SRC_GAME_APPLICATION
#define SRC_GAME_APPLICATION
#include "../Framework/pch.hpp"

class Application : private sf::NonCopyable
{
public:
    Application();
    ~Application();
    void start();

private:
    void _gameLoop();

    void _render();

    void _updateTest(sf::Time dt);
    sf::Font _frame_font;
    sf::Text _frame_test;
    sf::Time _time;
    unsigned _frame;

    Engine::Context::pointer_type _context;

    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
    const unsigned WIDTH = 1280, HEIGHT = 720;
};

#endif /* SRC_GAME_APPLICATION */
