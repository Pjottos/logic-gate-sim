#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include <forward_list>
#include <logic/Component.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace logic {
    class ComponentManager {
    public:
        void tick();
        void draw(sf::RenderTarget& target) const;

    private:
        std::forward_list<Component> components;
    };
}

#endif