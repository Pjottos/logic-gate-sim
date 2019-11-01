#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>
#include <logic/Slot.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace logic {
    class Component : public sf::Drawable, public sf::Transformable {
    friend class ComponentManager;
    protected:
        std::string name;
        sf::Vector2<double> drawSize;
        sf::VertexArray shape;

        std::vector<Slot> inputs;
        std::vector<Slot> outputs;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        
        void preTick();
        virtual void onTick();
        void postTick();
    };
}

#endif