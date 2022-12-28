#include "manager.hpp"

namespace Engine
{
    States_Machine::States_Machine()
        : _push(false), _pop(false), _replace(false), _clear(false) {}

    void States_Machine::insert(State::pointer_type state, bool is_replace)
    {
        _temp_ptr = std::move(state);
        _push = true;
        _replace = is_replace;
    }

    void States_Machine::remove() { _pop = true; }

    void States_Machine::clear() { _clear = true; }

    void States_Machine::handleMachine()
    {
        if (_pop)
        {
            _machine.pop();
            _pop = false;
        }
        else if (_push)
        {
            if (_replace)
            {
                _machine.pop();
                _replace = false;
            }

            _machine.push(std::move(_temp_ptr));
            _push = false;
        }
        else if (_clear)
        {
            while (!_machine.empty())
                _machine.pop();
            _clear = false;
        }
    }

    bool States_Machine::isEmpty()
    {
        return _machine.empty();
    }

    Engine::State::pointer_type& States_Machine::current()
    {
        return _machine.top();
    }
}
