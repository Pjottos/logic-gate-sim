#include <logic/Gate.hpp>

using namespace logic;

void Gate::onTick() {
    this->outputs[0].setValue(this->logic(inputs[0].value(), inputs[1].value()));
}