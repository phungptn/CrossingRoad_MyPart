#ifndef SRC_FRAMEWORK_STATE_MANAGER
#define SRC_FRAMEWORK_STATE_MANAGER
#include "state.hpp"

#include <memory>
#include <stack>

namespace Engine
{
    class States_Machine
    {
    public:
        typedef std::unique_ptr<States_Machine> pointer_type;

        States_Machine();

        void insert(State::pointer_type state, bool is_replace = false);
        void remove();
        void clear();
        void handleMachine();

        bool isEmpty();
        Engine::State::pointer_type& States_Machine::current();
    private:
        bool _push, _pop, _replace, _clear;
        std::stack<State::pointer_type> _machine;
        State::pointer_type _temp_ptr;
    };
}

#endif /* SRC_FRAMEWORK_STATE_MANAGER */
