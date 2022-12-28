#include "loading.hpp"

#include "menu.hpp"

LoadingTask::LoadingTask(Engine::Context::pointer_type context)
    : _context(context),
      _finished(false),
      _thread(&LoadingTask::_runTask, this) {}

void LoadingTask::execute()
{
    _finished = false;
    _thread.launch();
}

bool LoadingTask::isFinished()
{
    return _finished;
}

void LoadingTask::_runTask()
{
    sf::Lock lock(_mutex);

    _context->fonts->load(FONT_LIST::MAIN_FONT, "assets/fonts/IBMPlexMono.ttf");
    _context->fonts->load(FONT_LIST::BUTTON_FONT, "assets/fonts/visitor1.ttf");
    _context->textures->load(TEXTURE_LIST::BUTTON_NORMAL, "assets/images/bt_normal.png");
    _context->textures->load(TEXTURE_LIST::BUTTON_HOVER, "assets/images/bt_hover.png");
    _context->textures->load(TEXTURE_LIST::BUTTON_PRESS, "assets/images/bt_click.png");
    _context->textures->load(TEXTURE_LIST::WELCOME_SCREEN, "assets/images/welcome_bg.jpg");

    _finished = true;
}

LoadingState::LoadingState(Engine::Context::pointer_type context)
    : _context(context), _task(context)
{
    assert(_font.loadFromFile("assets/fonts/Sansation.ttf"));

    _text.setString("Loading...");
    _text.setFont(_font);
    _text.setCharacterSize(50u);
    centerOrigin(_text);

    _text.setPosition(_context->window->getView().getCenter());

    _task.execute();
}

void LoadingState::handleEvent(const sf::Event &ev) {}

void LoadingState::update(sf::Time dt)
{
    if (_task.isFinished())
    {
        _context->states->insert(std::make_unique<MenuState>(_context), true);
    }
}

void LoadingState::draw()
{
    _context->window->setView(_context->window->getDefaultView());
    _context->window->draw(_text);
}