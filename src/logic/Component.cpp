#include <logic/Component.hpp>

using namespace logic;

void Component::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= this->getTransform();
    target.draw(this->shape, states);
}

void Component::preTick() {
    for(auto& output : this->outputs) {
        output.send();
    }
}

void Component::onTick() {}

void Component::postTick() {
    for(auto& input : this->inputs) {
        input.reset();
    }
}