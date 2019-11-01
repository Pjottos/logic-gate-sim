#include <logic/ComponentManager.hpp>

using namespace logic;

void ComponentManager::tick() {
    for(auto& component : this->components) {
        component.preTick();
    }
    for(auto& component : this->components) {
        component.onTick();
    }
    for(auto& component : this->components) {
        component.postTick();
    }
}

void ComponentManager::draw(sf::RenderTarget& target) const {
    for(auto& component : this->components) {
        target.draw(component);
    }
}
