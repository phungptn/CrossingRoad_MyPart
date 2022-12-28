#ifndef SRC_GAME_STATES_LOADING
#define SRC_GAME_STATES_LOADING
#include "../../Framework/pch.hpp"

class LoadingTask
{
public:
    LoadingTask(Engine::Context::pointer_type context);

    void execute();
    bool isFinished();

private:
    void _runTask();

    sf::Thread _thread;
    sf::Mutex _mutex;
    bool _finished;

    Engine::Context::pointer_type _context;
};

class LoadingState : public Engine::State
{
public:
    LoadingState(Engine::Context::pointer_type context);

    void handleEvent(const sf::Event &ev);
    void update(sf::Time dt);
    void draw();

private:
    sf::Font _font;
    sf::Text _text;

    Engine::Context::pointer_type _context;
    LoadingTask _task;
};

#endif /* SRC_GAME_STATES_LOADING */
