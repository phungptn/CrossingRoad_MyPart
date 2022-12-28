#ifndef SRC_INCLUDE_ENGINE_ASSET_MANAGER
#define SRC_INCLUDE_ENGINE_ASSET_MANAGER
#include <SFML/Audio/Music.hpp>
#include <SFML/System/NonCopyable.hpp>

#include <cassert>
#include <map>
#include <memory>
#include <string>

namespace Engine
{
    template <typename Identifier, typename Asset>
    class Media_Machine
    {
    public:
        typedef Identifier key_type;
        typedef Asset value_type;

        typedef std::unique_ptr<Asset> pointer_type;

        void load(Identifier identifier, std::string path)
        {
            Media_Machine::pointer_type ptr(new Asset());

            if (!ptr->loadFromFile(path))
                throw std::runtime_error("Assets_Management::load(): " + path + " load failed.");

            _insert(identifier, std::move(ptr));
        }

        template <typename Arg>
        void load(Identifier identifier, std::string path, Arg second)
        {
            Media_Machine::pointer_type ptr(new Asset());

            if (!ptr->loadFromFile(path, second))
                throw std::runtime_error("Assets_Management::load(): " + path + " load failed.");

            _insert(id, std::move(ptr));
        }

        Asset &get(Identifier identifier)
        {
            auto find = _machine.find(identifier);
            assert(find != _machine.end());
            return *find->second;
        }

        const Asset &get(Identifier identifier) const
        {
            auto find = _machine.find(identifier);
            assert(find != _machine.end());
            return *find->second;
        }

    private:
        void _insert(Identifier identifier, Media_Machine::pointer_type resource)
        {
            auto insert = _machine.insert(std::make_pair(identifier, std::move(resource)));
            assert(insert.second);
        }

        std::map<Identifier, Media_Machine::pointer_type> _machine;
    };
}

#endif /* SRC_INCLUDE_ENGINE_ASSET_MANAGER */
